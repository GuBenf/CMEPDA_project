/**
 * @file construction.cc
 * @brief Implementation of the MyDetectorConstruction class.
 * 
 * This file contains the implementation of the `MyDetectorConstruction` class methods,
 * which are responsible for constructing the geometry, materials, and detector setup
 * in a Geant4 simulation. It includes the creation of scintillators, waveguides, PMTs,
 * and the placement of detector layers. It also defines material properties and
 * sets up sensitive detectors.
 */

#include "construction.hh"

/**
 * @brief Default constructor for `MyDetectorConstruction`.
 * 
 * This constructor initializes the `MyDetectorConstruction` object but does not perform
 * any specific setup. Actions are defined in the `Build` method.
 */
MyDetectorConstruction::MyDetectorConstruction(){
  // No initialization logic needed here.
}

/**
 * @brief Destructor for `MyDetectorConstruction`.
 * 
 * Cleans up resources used by the `MyDetectorConstruction` object, if any.
 */
MyDetectorConstruction::~MyDetectorConstruction(){
  // No specific cleanup required.
}


/**
 * @brief Constructs a detector layer at a specified position.
 * 
 * Constructs a detector layer consisting of scintillators and waveguides placed
 * in a specified position within the logical world volume.
 * 
 * @param posX X-coordinate where the detector layer is positioned.
 * @param posY Y-coordinate where the detector layer is positioned.
 * @param posZ Z-coordinate where the detector layer is positioned.
 * @param logicWorld Reference to the logical volume representing the world.
 * @param i Identifier index for the detector layer.
 * 
 * @return A tuple containing pointers to the physical volumes of the scintillator and waveguide.
 */
std::tuple<G4VPhysicalVolume *, G4VPhysicalVolume *> MyDetectorConstruction::DetectorLayer(G4double posX, G4double posY, G4double posZ, G4LogicalVolume *logicWorld, G4int i)
{
  // --------------------Define the material for the scintillator--------------------

  G4MaterialPropertiesTable *mptScint = new G4MaterialPropertiesTable();
  G4double rindex[2] = {1.587, 1.587}; // Refractive index for the scintillator material.
  G4double fraction[2] = {1.0, 1.0}; // Fraction values for scintillation components. Set to 1.0 as default.

  mptScint->AddProperty("RINDEX", energy, rindex, 2); // Setting the refraction index.
  mptScint->AddProperty("SCINTILLATIONCOMPONENT1", energy, fraction, 2); // Setting only fast component of scintillation (not both fast and slow).
  mptScint->AddConstProperty("SCINTILLATIONYIELD", 100./MeV); // Setting the scintillation yield (A true value would be 10k, this is needed for optimization).
  mptScint->AddConstProperty("RESOLUTIONSCALE", 1.); // Sigma of the distribution.
  mptScint->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 2.4 * ns); // Setting the scintillation time for fast component.

  scint_material->SetMaterialPropertiesTable(mptScint);

  //--------------------Create the geometry of scintillators--------------------
  G4ThreeVector det_pos(posX, posY, posZ); // Position of the detector.
  G4Box *solidDetector = new G4Box("solidDetector", det_x , det_y , det_z); // (name, halfx, halfy, halfz)
  G4LogicalVolume *logicalDetector = new G4LogicalVolume(solidDetector, scint_material , "logicalDetector");
  G4VPhysicalVolume *physDetector = new G4PVPlacement(0, det_pos, logicalDetector, "physDetector", logicWorld, false, i, true);

  //--------------------Build the wave guides--------------------
  G4ThreeVector wg_pos(posX, posY ,(det_z+d_z)); // Position of the waveguide.
  G4Trd *solidWaveGuide = new G4Trd("solidWaveLine", d_x1, d_x2 , d_y1, d_y2 , d_z); // (name, halfx, halfy, halfz)
  G4LogicalVolume *logicWaveGuide = new G4LogicalVolume(solidWaveGuide, scint_material , "logicWaveGuide");
  G4VPhysicalVolume *physWaveGuide = new G4PVPlacement(0, wg_pos, logicWaveGuide, "physWaveGuide", logicWorld, false, i, true);


  //-------------------- Return a tuple containing physical volumes --------------------
  return std::make_tuple(physDetector, physWaveGuide);
}

/**
 * @brief Constructs the main detector geometry and places it within the world volume.
 * 
 * Constructs the logical and physical volumes for the Geant4 simulation's world,
 * initializes detector layers, scintillators, waveguides, and PMTs, and places
 * everything in their designated positions according to the simulation setup.
 *
 * @return A pointer to the physical world volume containing all detector components.
 */
G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  //-------------------- Define the world material --------------------
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  G4MaterialPropertiesTable *mptAir = new G4MaterialPropertiesTable();
  G4double rindex_air[2] = {1.0, 1.0};

  mptAir->AddProperty("RINDEX", energy, rindex_air, 2);
  worldMat->SetMaterialPropertiesTable(mptAir);


  //-------------------- Build the world geometry --------------------
  G4Box *solidWorld = new G4Box("solidWorld", 1.*m, 1.*m, 1.*m); // (name, halfx, halfy, halfz)
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //(rotation, center, logic volume, name,mother/son volume, check for overlaps)


  //-------------------- Create detector layers --------------------
  for (G4int i = 1; i < nDetectors +1; i++){
    DetectorLayer(0.*cm, i * 10.*cm, 0.*cm, logicWorld, i);
  }
  
  
  G4Box *solidPMT = new G4Box("solidPMT", pmt_x , pmt_y , pmt_z);
  logicDetector = new G4LogicalVolume(solidPMT,scint_material,"logicDetector");
  for (G4int i = 1; i < nDetectors +1; i++){
    G4ThreeVector pmt_pos(0.*cm, i * 10.*cm ,(det_z+2*d_z+pmt_z)); //position
    G4VPhysicalVolume *physPMT = new G4PVPlacement(0,pmt_pos,logicDetector,"physPMT",logicWorld,false,i,true);
  }

  ////-------------------- Return the physical world --------------------
  return physWorld;
}

/**
 * @brief Constructs the sensitive detectors and fields.
 * 
 * Sets up sensitive detectors by associating the `MySensitiveDetector` class with
 * the logical volume representing the PMTs. This enables the detection of energy deposition by photons.
 */
void MyDetectorConstruction::ConstructSDandField()
{
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDet");
  if(logicDetector != NULL)
        logicDetector->SetSensitiveDetector(sensDet);
}

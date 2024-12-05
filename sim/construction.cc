#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction(){

}

MyDetectorConstruction::~MyDetectorConstruction(){

}

std::tuple<G4VPhysicalVolume *, G4VPhysicalVolume *> MyDetectorConstruction::DetectorLayer(G4double posX, G4double posY, G4double posZ, G4LogicalVolume *logicWorld, G4int i)
{
  // --------------------Define the material for the scintillator--------------------

  G4MaterialPropertiesTable *mptScint = new G4MaterialPropertiesTable();
  G4double rindex[2] = {1.587, 1.587};
  G4double fraction[2] = {1.0, 1.0};

  mptScint->AddProperty("RINDEX", energy, rindex, 2);
  mptScint->AddProperty("SCINTILLATIONCOMPONENT1", energy, fraction, 2);
  mptScint->AddConstProperty("SCINTILLATIONYIELD", 100./MeV);
  mptScint->AddConstProperty("RESOLUTIONSCALE", 1.); //sigma of the distribution
  mptScint->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 2.4 * ns);

  scint_material->SetMaterialPropertiesTable(mptScint);

  //--------------------Create the geometry of scintillators--------------------
  G4ThreeVector det_pos(posX, posY, posZ); //position
  G4Box *solidDetector = new G4Box("solidDetector", det_x , det_y , det_z); //dimensions are defined as private members of the class
  G4LogicalVolume *logicalDetector = new G4LogicalVolume(solidDetector, scint_material , "logicalDetector");
  G4VPhysicalVolume *physDetector = new G4PVPlacement(0, det_pos, logicalDetector, "physDetector", logicWorld, false, i, true);

  //--------------------Build the wave guides--------------------
  G4ThreeVector wg_pos(posX, posY ,(det_z+d_z)); //position
  G4Trd *solidWaveGuide = new G4Trd("solidWaveLine", d_x1, d_x2 , d_y1, d_y2 , d_z); //dimensions are defined as private members of the class
  G4LogicalVolume *logicWaveGuide = new G4LogicalVolume(solidWaveGuide, scint_material , "logicWaveGuide");
  G4VPhysicalVolume *physWaveGuide = new G4PVPlacement(0, wg_pos, logicWaveGuide, "physWaveGuide", logicWorld, false, i, true);


  //--------------------return--------------------
  return std::make_tuple(physDetector, physWaveGuide);
}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  //--------------------Define the world material--------------------
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  G4MaterialPropertiesTable *mptAir = new G4MaterialPropertiesTable();
  G4double rindex_air[2] = {1.0, 1.0};

  mptAir->AddProperty("RINDEX", energy, rindex_air, 2);
  worldMat->SetMaterialPropertiesTable(mptAir);


  //--------------------Build the world--------------------
  G4Box *solidWorld = new G4Box("solidWorld", 1.*m, 1.*m, 1.*m); //(name, halfx, halfy, halfz)
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //(rotation, center, logic volume, name,mother/son volume, check for overlaps)


  //--------------------Create the layers--------------------
  for (G4int i = 1; i < nDetectors +1; i++){
    DetectorLayer(0.*cm, i * 10.*cm, 0.*cm, logicWorld, i);
  }
  
  
  G4Box *solidPMT = new G4Box("solidPMT", pmt_x , pmt_y , pmt_z);
  logicDetector = new G4LogicalVolume(solidPMT,scint_material,"logicDetector"); //The initialization is different caus this is also used as a sensitive detector
  for (G4int i = 1; i < nDetectors +1; i++){
    G4ThreeVector pmt_pos(0.*cm, i * 10.*cm ,(det_z+2*d_z+pmt_z)); //position
    G4VPhysicalVolume *physPMT = new G4PVPlacement(0,pmt_pos,logicDetector,"physPMT",logicWorld,false,i,true);
  }

  


  ////--------------------Return the world//--------------------
  return physWorld;
}


void MyDetectorConstruction::ConstructSDandField()
{
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDet");
  if(logicDetector != NULL)
        logicDetector->SetSensitiveDetector(sensDet);
}

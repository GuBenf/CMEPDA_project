#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction(){

}

MyDetectorConstruction::~MyDetectorConstruction(){

}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  //This is something idk------------------------------------------------------------------------------------------------------------------------
  G4NistManager *nist = G4NistManager::Instance();


  // Define the material for the scintillator------------------------------------------------------------------------------------------------------------------------
  G4Material *scint_material = nist->FindOrBuildMaterial("G4_POLYSTYRENE");

  G4MaterialPropertiesTable *mptScint = new G4MaterialPropertiesTable();
  G4double energy[2] = {1.95*eV, 1.95*eV};
  G4double rindex[2] = {1.587, 1.587};
  G4double fraction[2] = {1.0, 1.0};

  mptScint->AddProperty("RINDEX", energy, rindex, 2);
  mptScint->AddProperty("SCINTILLATIONCOMPONENT1", energy, fraction, 2);
  mptScint->AddConstProperty("SCINTILLATIONYIELD", 10000./MeV);
  mptScint->AddConstProperty("RESOLUTIONSCALE", 1.); //sigma of the distribution
  mptScint->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 2.4 * ns);

  scint_material->SetMaterialPropertiesTable(mptScint);


  // Define the material for the coating------------------------------------------------------------
  G4Material *coat_material = nist->FindOrBuildMaterial("G4_POLYVINYL_CHLORIDE");

  G4MaterialPropertiesTable *mptCoat = new G4MaterialPropertiesTable();
  G4double rindex_coat[2] = {1.49, 1.49};

  mptCoat->AddProperty("RINDEX", energy, rindex_coat, 2);
  coat_material->SetMaterialPropertiesTable(mptCoat);


  // Define the world material-----------------------------------------------------------------------
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  G4MaterialPropertiesTable *mptAir = new G4MaterialPropertiesTable();
  G4double rindex_air[2] = {1.0, 1.0};

  mptAir->AddProperty("RINDEX", energy, rindex_air, 2);
  worldMat->SetMaterialPropertiesTable(mptAir);

  
  // Build the "worlds"------------------------------------------------------------------------------
  G4Box *solidWorld = new G4Box("solidWorld", 1.*m, 1.*m, 1.*m); //(name, halfx, halfy, halfz)
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //(rotation, center, logic volume, name,mother/son volume, check for overlaps)


  // Build the "detectors"---------------------------------------------------------------------------
  G4double det_x = 20.*cm;
  G4double det_y = 0.5*cm;
  G4double det_z = 24*cm;
  G4double wrapUp1 = 1.*mm;
  G4double wrapDown1 = 1.*mm;
  G4double wrapSide11 = 1.*mm;
  G4double wrapSide12 = 1.*mm;
  G4double wrapSide13 = 1.*mm;


  //Scintillators-solid------------------------------------------------------------------------------------------------------------------------
  G4Box *solidDetector1 = new G4Box("solidDetector1", det_x , det_y , det_z);
  G4Box *solidDetector2 = new G4Box("solidDetector2", det_x , det_y , det_z);
  G4Box *solidDetector3 = new G4Box("solidDetector3", det_x , det_y , det_z);
  //Wrapping-solid
  G4Box *solidWrappingUp1 = new G4Box("solidWrappingUp1", det_x , wrapUp1 , det_z);
  G4Box *solidWrappingDown1 = new G4Box("solidWrappingDown1", det_x , wrapDown1 , det_z);
  G4Box *solidWrappingSide11 = new G4Box("solidWrappingSide11", det_x , det_y , wrapSide11);
  G4Box *solidWrappingSide12 = new G4Box("solidWrappingSide12", wrapSide12 , det_y ,det_z );
  G4Box *solidWrappingSide13 = new G4Box("solidWrappingSide13", wrapSide13 , det_y ,det_z );


  //Scintillators-logic------------------------------------------------------------------------------------------------------------------------
  G4LogicalVolume *logicDetector1 = new G4LogicalVolume(solidDetector1, scint_material , "logicDetector1");
  G4LogicalVolume *logicDetector2 = new G4LogicalVolume(solidDetector2, scint_material , "logicDetector2");
  G4LogicalVolume *logicDetector3 = new G4LogicalVolume(solidDetector3, scint_material , "logicDetector3");
  //Wrapping-logic
  G4LogicalVolume *logicWrappingUp1 = new G4LogicalVolume(solidWrappingUp1, scint_material , "logicWrappingUp1");
  G4LogicalVolume *logicWrappingDown1 = new G4LogicalVolume(solidWrappingDown1, scint_material , "logicWrappingDown1");
  G4LogicalVolume *logicWrappingSide11 = new G4LogicalVolume(solidWrappingSide11, scint_material , "logicWrappingSide11");
  G4LogicalVolume *logicWrappingSide12 = new G4LogicalVolume(solidWrappingSide12, scint_material , "logicWrappingSide12");
  G4LogicalVolume *logicWrappingSide13 = new G4LogicalVolume(solidWrappingSide13, scint_material , "logicWrappingSide13");
  

  //Scintillators-position------------------------------------------------------------------------------------------------------------------------
  G4ThreeVector det1_pos(0.*cm, 10.*cm ,0.*cm);
  G4ThreeVector det2_pos(0.*cm, 20.*cm ,0.*cm);
  G4ThreeVector det3_pos(0.*cm, 30.*cm ,0.*cm);
  //Wrapping-position
  G4ThreeVector wrpUp_pos(0.*cm, 10.6*cm ,0.*cm);
  G4ThreeVector wrpDown_pos(0.*cm, 9.4*cm ,0.*cm);
  G4ThreeVector wrpSide11_pos(0.*cm, 10.*cm ,-24.1*cm);
  G4ThreeVector wrpSide12_pos(20.1*cm, 10.*cm ,0.*cm);
  G4ThreeVector wrpSide13_pos(-20.1*cm, 10.*cm ,0.*cm);


  //Scintillators-physics------------------------------------------------------------------------------------------------------------------------
  G4VPhysicalVolume *physDetector1 = new G4PVPlacement(0, det1_pos, logicDetector1, "physDetector1", logicWorld, false, 0, true);
  G4VPhysicalVolume *physDetector2 = new G4PVPlacement(0, det2_pos, logicDetector2, "physDetector2", logicWorld, false, 0, true);
  G4VPhysicalVolume *physDetector3 = new G4PVPlacement(0, det3_pos, logicDetector3, "physDetector3", logicWorld, false, 0, true);
  //Wrapping-physics
  G4VPhysicalVolume *physWrappingUp1 = new G4PVPlacement(0, wrpUp_pos, logicWrappingUp1, "physWrappingUp1", logicWorld, false, 0, true);
  G4VPhysicalVolume *physWrappingDown1 = new G4PVPlacement(0, wrpDown_pos, logicWrappingDown1, "physWrappingDown1", logicWorld, false, 0, true);
  G4VPhysicalVolume *physWrappingSide11 = new G4PVPlacement(0, wrpSide11_pos, logicWrappingSide11, "physWrappingSide11", logicWorld, false, 0, true);
  G4VPhysicalVolume *physWrappingSide12 = new G4PVPlacement(0, wrpSide12_pos, logicWrappingSide12, "physWrappingSide12", logicWorld, false, 0, true);
  G4VPhysicalVolume *physWrappingSide13 = new G4PVPlacement(0, wrpSide13_pos, logicWrappingSide13, "physWrappingSide13", logicWorld, false, 0, true);

  
  // Build the wave guides------------------------------------------------------------------------------------------------------------------------
  G4double d_x1 = 20.*cm;
  G4double d_x2 = 0.5*cm;
  G4double d_y1 = det_y;
  G4double d_y2 = det_y;
  G4double d_z = 10*cm;
  
  G4Trd *solidWaveGuide1 = new G4Trd("solidWaveLine1", d_x1, d_x2 , d_y1, d_y2 , d_z);
  G4Trd *solidWaveGuide2 = new G4Trd("solidWaveLine2", d_x1, d_x2 , d_y1, d_y2 , d_z);
  G4Trd *solidWaveGuide3 = new G4Trd("solidWaveLine3", d_x1, d_x2 , d_y1, d_y2 , d_z);

  G4LogicalVolume *logicWaveGuide1 = new G4LogicalVolume(solidWaveGuide1, scint_material , "logicWaveGuide1");
  G4LogicalVolume *logicWaveGuide2 = new G4LogicalVolume(solidWaveGuide2, scint_material , "logicWaveGuide2");
  G4LogicalVolume *logicWaveGuide3 = new G4LogicalVolume(solidWaveGuide3, scint_material , "logicWaveGuide3");

  G4ThreeVector wg1_pos(0.*cm, 10.*cm ,(det_z+d_z));
  G4ThreeVector wg2_pos(0.*cm, 20.*cm ,(det_z+d_z));
  G4ThreeVector wg3_pos(0.*cm, 30.*cm ,(det_z+d_z));

  G4VPhysicalVolume *physWaveGuide1 = new G4PVPlacement(0, wg1_pos, logicWaveGuide1, "physWaveGuide1", logicWorld, false, 0, true);
  G4VPhysicalVolume *physWaveGuide2 = new G4PVPlacement(0, wg2_pos, logicWaveGuide2, "physWaveGuide2", logicWorld, false, 0, true);
  G4VPhysicalVolume *physWaveGuide3 = new G4PVPlacement(0, wg3_pos, logicWaveGuide3, "physWaveGuide3", logicWorld, false, 0, true);
  

  // Define the optical surface between scint and waveguide------------------------------------------------------------------------------------------------------------------------
  G4OpticalSurface* opticalSurface = new G4OpticalSurface("opticalSurface");
  opticalSurface->SetType(dielectric_dielectric);  // Superficie dielettrica-dielettrica
  opticalSurface->SetFinish(polished);             // Superficie levigata
  opticalSurface->SetModel(unified); 
 
  G4double reflectivity[2] = {0.02, 0.2};
  G4double absorption[2] = {0.02, 0.02};
  G4double efficiency[2] = {1.0, 1.0};

  G4MaterialPropertiesTable* mpt = new G4MaterialPropertiesTable();
  mpt->AddProperty("REFLECTIVITY", energy, reflectivity, 2);
  mpt->AddProperty("EFFICIENCY", energy, efficiency, 2);
  opticalSurface->SetMaterialPropertiesTable(mpt);
  
  G4LogicalBorderSurface *borderSurface = new G4LogicalBorderSurface("borderSurface", physDetector1, physWaveGuide1, opticalSurface);  


  // Build the "PMTs"------------------------------------------------------------------------------------------------------------------------
  G4double pmt_x = d_x2;
  G4double pmt_y = d_y2;
  G4double pmt_z = 1.*cm;

  G4Box *solidPMT = new G4Box("solidPMT", pmt_x , pmt_y , pmt_z);

  logicDetector = new G4LogicalVolume(solidPMT,worldMat,"logicDetector");

  for(G4int i=1; i<4;i++)
    {
      G4VPhysicalVolume *physPMT = new G4PVPlacement(0,G4ThreeVector(-0*cm,i*10.*cm,(det_z+2*d_z+pmt_z)),logicDetector,"physPMT",logicWorld,false,i,true);
    }
  
  return physWorld;

}


void MyDetectorConstruction::ConstructSDandField()
{
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDet");
  if(logicDetector != NULL)
        logicDetector->SetSensitiveDetector(sensDet);
}

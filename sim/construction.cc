#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction(){

}

MyDetectorConstruction::~MyDetectorConstruction(){

}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
  //This is something idk
  G4NistManager *nist = G4NistManager::Instance();

  // Define the material for the scintillator
  // ...
  G4Material *scint_material = nist->FindOrBuildMaterial("G4_POLYSTYRENE");



  // Define the world material
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  // Build the "worlds"
  G4Box *solidWorld = new G4Box("solidWorld", 1.*m, 1.*m, 1.*m); //(name, halfx, halfy, halfz)
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //(rotation, center, logic volume, name,mother/son volume, check for overlaps)

  // Build the "detectors"
  G4double det_x = 20.;
  G4double det_y = 0.5;
  G4double det_z = 24;

  G4Box *solidDetector1 = new G4Box("solidDetector1", det_x*cm , det_y*cm , det_z*cm);
  G4Box *solidDetector2 = new G4Box("solidDetector2", det_x*cm , det_y*cm , det_z*cm);
  G4Box *solidDetector3 = new G4Box("solidDetector3", det_x*cm , det_y*cm , det_z*cm);

  G4LogicalVolume *logicDetector1 = new G4LogicalVolume(solidDetector1, scint_material , "logicDetector1");
  G4LogicalVolume *logicDetector2 = new G4LogicalVolume(solidDetector2, scint_material , "logicDetector2");
  G4LogicalVolume *logicDetector3 = new G4LogicalVolume(solidDetector3, scint_material , "logicDetector3");

  G4ThreeVector det1_pos(0.*cm, 10.*cm ,0.*cm);
  G4ThreeVector det2_pos(0.*cm, 20.*cm ,0.*cm);
  G4ThreeVector det3_pos(0.*cm, 30.*cm ,0.*cm);

  G4VPhysicalVolume *physDetector1 = new G4PVPlacement(0, det1_pos, logicDetector1, "physDetector1", logicWorld, false, 0, true);
  G4VPhysicalVolume *physDetector2 = new G4PVPlacement(0, det2_pos, logicDetector2, "physDetector2", logicWorld, false, 0, true);
  G4VPhysicalVolume *physDetector3 = new G4PVPlacement(0, det3_pos, logicDetector3, "physDetector3", logicWorld, false, 0, true);

  // Build the wave guides
  G4double d_x1 = 20.;
  G4double d_x2 = 0.5;
  G4double d_y1 = det_y;
  G4double d_y2 = det_y;
  G4double d_z = 10;

  G4Trd *solidWaveGuide1 = new G4Trd("solidWaveLine1", d_x1*cm, d_x2*cm , d_y1*cm, d_y2*cm , d_z*cm);
  G4Trd *solidWaveGuide2 = new G4Trd("solidWaveLine2", d_x1*cm, d_x2*cm , d_y1*cm, d_y2*cm , d_z*cm);
  G4Trd *solidWaveGuide3 = new G4Trd("solidWaveLine3", d_x1*cm, d_x2*cm , d_y1*cm, d_y2*cm , d_z*cm);


  G4LogicalVolume *logicWaveGuide1 = new G4LogicalVolume(solidWaveGuide1, scint_material , "logicWaveGuide1");
  G4LogicalVolume *logicWaveGuide2 = new G4LogicalVolume(solidWaveGuide2, scint_material , "logicWaveGuide2");
  G4LogicalVolume *logicWaveGuide3 = new G4LogicalVolume(solidWaveGuide3, scint_material , "logicWaveGuide3");

  G4ThreeVector wg1_pos(0.*cm, 10.*cm ,(det_z+d_z)*cm);
  G4ThreeVector wg2_pos(0.*cm, 20.*cm ,(det_z+d_z)*cm);
  G4ThreeVector wg3_pos(0.*cm, 30.*cm ,(det_z+d_z)*cm);

  G4VPhysicalVolume *physWaveGuide1 = new G4PVPlacement(0, wg1_pos, logicWaveGuide1, "physWaveGuide1", logicWorld, false, 0, true);
  G4VPhysicalVolume *physWaveGuide2 = new G4PVPlacement(0, wg2_pos, logicWaveGuide2, "physWaveGuide2", logicWorld, false, 0, true);
  G4VPhysicalVolume *physWaveGuide3 = new G4PVPlacement(0, wg3_pos, logicWaveGuide3, "physWaveGuide3", logicWorld, false, 0, true);
  
  // Build the "PMTs"
  G4double pmt_x = d_x2;
  G4double pmt_y = d_y2;
  G4double pmt_z = 1.;

  G4Box *solidPMT = new G4Box("solidPMT", pmt_x*cm , pmt_y*cm , pmt_z*cm);
  // G4Box *solidPMT2 = new G4Box("solidPMT2", pmt_x*cm , pmt_y*cm , pmt_z*cm);
  // G4Box *solidPMT3 = new G4Box("solidPMT3", pmt_x*cm , pmt_y*cm , pmt_z*cm);

  // G4LogicalVolume *logicPMT1 = new G4LogicalVolume(solidPMT1, scint_material , "logicPMT1");
  // G4LogicalVolume *logicPMT2 = new G4LogicalVolume(solidPMT2, scint_material , "logicPMT2");
  // G4LogicalVolume *logicPMT3 = new G4LogicalVolume(solidPMT3, scint_material , "logicPMT3");

  // G4ThreeVector pmt1_pos(0.*cm, 10.*cm ,(det_z+2*d_z)*cm);
  // G4ThreeVector pmt2_pos(0.*cm, 20.*cm ,(det_z+2*d_z)*cm);
  // G4ThreeVector pmt3_pos(0.*cm, 30.*cm ,(det_z+2*d_z)*cm);

  // G4VPhysicalVolume *physPMT1 = new G4PVPlacement(0, pmt1_pos, logicPMT1, "physPMT1", logicWorld, false, 0, true);
  // G4VPhysicalVolume *physPMT2 = new G4PVPlacement(0, pmt2_pos, logicPMT2, "physPMT2", logicWorld, false, 0, true);
  // G4VPhysicalVolume *physPMT3 = new G4PVPlacement(0, pmt3_pos, logicPMT3, "physPMT3", logicWorld, false, 0, true);

  logicDetector = new G4LogicalVolume(solidPMT,worldMat,"logicDetector");

  for(G4int i=1; i<4;i++)
    {
      G4VPhysicalVolume *physPMT = new G4PVPlacement(0,G4ThreeVector(-0*cm,i*10.*cm,(det_z+2*d_z)*cm),logicDetector,"physPMT",logicWorld,false,i,true);
    }
  
  
  return physWorld;

}


void MyDetectorConstruction::ConstructSDandField()
{
  MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDet");
  if(logicDetector != NULL)
        logicDetector->SetSensitiveDetector(sensDet);
}

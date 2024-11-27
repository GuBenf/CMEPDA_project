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
  G4Material *scint_material = nist->FindOrBuildMaterial("G4_Pb");



  // Define the world material
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  // Build the "worlds"
  G4Box *solidWorld = new G4Box("solidWorld", 1.*m, 1.*m, 1.*m); //(name, halfx, halfy, halfz)
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //(rotation, center, logic volume, name,mother/son volume, check for overlaps)

  // Build the "detectors"
  double det_x = 20.;
  double det_y = 0.5;
  double det_z = 24;

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

  return physWorld;

}

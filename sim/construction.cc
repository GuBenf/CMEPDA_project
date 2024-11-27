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


  // Define the world material
  G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

  // Build the "worlds"
  G4Box *solidWorld = new G4Box("solidWorld", .1*m, .1*m, .1*m); //(name, halfx, halfy, halfz)
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
  G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //(rotation, center, logic volume, name,mother/son volume, check for overlaps)

  // Build the "detectors"
  G4Box *solidDetector1 = new G4Box("solidDetector", ... , ... , ...);
  G4Box *solidDetector2 = new G4Box("solidDetector", ... , ... , ...);
  G4Box *solidDetector3 = new G4Box("solidDetector", ... , ... , ...);

  G4LogicalVolume *logicDetector1 = new G4LogicalVolume(solidDetector1, material , "logicDetector");
  G4LogicalVolume *logicDetector2 = new G4LogicalVolume(solidDetector2, material , "logicDetector");
  G4LogicalVolume *logicDetector3 = new G4LogicalVolume(solidDetector3, material , "logicDetector");

  G4VPhysicalVolume *physDetector1 = new G4PVPlacement(0, G4ThreeVector(x1,y1,z1), logicDetector1, "physDetector1", logicWorld1, false, 0, true);
  G4VPhysicalVolume *physDetector2 = new G4PVPlacement(0, G4ThreeVector(x2,y2,z2), logicDetector2, "physDetector2", logicWorld2, false, 0, true);
  G4VPhysicalVolume *physDetector3 = new G4PVPlacement(0, G4ThreeVector(x3,y3,z3), logicDetector3, "physDetector3", logicWorld3, false, 0, true);

  return physWorld;

}

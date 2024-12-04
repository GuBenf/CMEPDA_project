#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4SystemOfUnits.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Trd.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4UserLimits.hh"
#include "G4OpBoundaryProcess.hh"
#include "G4LogicalBorderSurface.hh"

#include "detector.hh"



class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  MyDetectorConstruction();
  ~MyDetectorConstruction();

  virtual G4VPhysicalVolume *Construct();
  virtual std::tuple<G4VPhysicalVolume *, G4VPhysicalVolume *> DetectorLayer(G4double posX, G4double posY, G4double posZ, G4LogicalVolume *logicWorld, G4int index);

private:
  G4LogicalVolume *logicDetector;
  virtual void ConstructSDandField();
  
  G4NistManager *nist = G4NistManager::Instance();
  G4Material *scint_material = nist->FindOrBuildMaterial("G4_POLYSTYRENE");

  G4double energy[2] = {1.95*eV, 1.95*eV};

  //Scintillators dimensions
  G4double det_x = 20.*cm;
  G4double det_y = 0.5*cm;
  G4double det_z = 24*cm;

  //Waveguides dimensions
  G4double d_x1 = 20.*cm;
  G4double d_x2 = 2*cm;
  G4double d_y1 = det_y;
  G4double d_y2 = det_y;
  G4double d_z = 10*cm;

  //PMTs dimensions
  G4double pmt_x = d_x2; //needed to couple with waveguide
  G4double pmt_y = d_y2; //needed to couple with waveguide
  G4double pmt_z = 1.*cm;

  G4int nDetectors = 6;
};

#endif
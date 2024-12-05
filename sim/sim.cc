#include <iostream>

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"

#define G4DEBUG_MEMORY

int main(int argc, char** argv)
{
  // Choose the Random engine
  //
  G4Random::setTheEngine(new CLHEP::RanecuEngine);
  G4long seed = time(NULL);
  G4Random::setTheSeed(seed);
  
  //To run geant4
  G4RunManager *runManager = new G4RunManager();
  runManager->SetUserInitialization(new MyDetectorConstruction());
  runManager->SetUserInitialization(new MyPhysicsList());
  runManager->SetUserInitialization(new MyActionInitialization());

  runManager->Initialize();
  //To manage the user interface
  G4UIExecutive *ui = new G4UIExecutive(argc, argv);
  //To visualize
  G4VisManager *visManager = new G4VisExecutive();
  visManager->Initialize();
  //Ui runManager
  G4UImanager *UImanager = G4UImanager::GetUIpointer();

  UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1. 1. 1.");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate 1");
  UImanager->ApplyCommand("/run/verbose 0");
  UImanager->ApplyCommand("/tracking/verbose 0");
  UImanager->ApplyCommand("/optics/verbose 0");
  UImanager->ApplyCommand("/geometry/test/run");


  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->SetFileName("../output.root");
  //man->SetVerboseLevel(1);
  man->OpenFile("../output.root");
  for(int i = 0; i< 1000; i++){
    UImanager->ApplyCommand("/run/beamOn 1");
  }
  man->CloseFile();


  ui->SessionStart();


  return 0;
}


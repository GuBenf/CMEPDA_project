/**
 * @file sim.cc
 * @brief Main file of the Geant4 project.
 * 
 * This program uses the Geant4 framework to run a particle simulation, visualize the results, and log data to an output file. 
 * The simulation is configured to be run via a user interface (UI) with a 3D graphical view of the results. 
 * Additionally, simulation data is collected and written to a .root file.
 * 
 * @author Benfratello G., Niccolai A.
 * @date 2024-12-05
 * @version 1.0
 */

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


/**
 * @brief Main entry point for the Geant4 simulation.
 * 
 * This function initializes the Geant4 framework, sets up the user interface, and begins the simulation. 
 * It configures random number generation, initializes the simulation environment, and sets up visualization commands.
 * It also opens the output file for data logging and runs the simulation for 100,000 events.
 * 
 * @param argc Argument count from the command line.
 * @param argv Argument values from the command line.
 * @return Integer exit status.
 */
int main(int argc, char** argv)
{
  // Initialize random engine
  G4Random::setTheEngine(new CLHEP::RanecuEngine);
  G4long seed = time(NULL);
  G4Random::setTheSeed(seed);
  
  // Initialize Geant4 framework
  G4RunManager *runManager = new G4RunManager();
  runManager->SetUserInitialization(new MyDetectorConstruction());
  runManager->SetUserInitialization(new MyPhysicsList());
  runManager->SetUserInitialization(new MyActionInitialization());
  runManager->Initialize();

  // Initialize user interface and visualization
  G4UIExecutive *ui = new G4UIExecutive(argc, argv);
  G4VisManager *visManager = new G4VisExecutive();
  visManager->Initialize();
  G4UImanager *UImanager = G4UImanager::GetUIpointer();

  // Set visualization commands
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

  // Configure analysis manager
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->SetFileName("../output.root");
  man->OpenFile("../output.root");

  // Run simulation for "runs" events
  int runs = 1000;
  if (argc>1){
    runs = std::stoi(argv[1]);
  }
  G4cout<< runs << G4endl;
  for(int i = 0; i< runs; i++){
    UImanager->ApplyCommand("/run/beamOn 1");
  }
  man->CloseFile();
  ui->SessionStart();


  return 0;
}


/**
 * @file run.hh
 * @brief Declaration of the `MyRunAction` class for managing actions at the start and end of Geant4 runs.
 *
 * This header file defines the `MyRunAction` class, derived from `G4UserRunAction`, 
 * to handle operations performed at the beginning and end of simulation runs. 
 * It integrates functionality for data analysis and run management.
 */

#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

/**
 * @class MyRunAction
 * @brief Handles run-level actions in a Geant4 simulation.
 *
 * This class is responsible for initializing and finalizing the analysis framework, 
 * managing run-level tasks, and ensuring proper data handling during the simulation.
 * It overrides the `BeginOfRunAction` and `EndOfRunAction` methods to implement
 * custom behavior at the start and end of each simulation run.
 */
class MyRunAction : public G4UserRunAction
{
public:
  MyRunAction();
  ~MyRunAction();

  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);
};

#endif

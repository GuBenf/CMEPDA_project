/**
 * The MyRunAction class extends the base class G4UserRunAction from Geant4 and allows defining custom actions to be performed at the beginning and end of a simulation run. The class is responsible for handling the operations necessary for initializing and finalizing the analysis or other processes related to the run.
 */

#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

class MyRunAction : public G4UserRunAction
{
public:
  MyRunAction();
  ~MyRunAction();
  virtual void BeginOfRunAction(const G4Run*);
  virtual void EndOfRunAction(const G4Run*);
};

#endif

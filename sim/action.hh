/**
 * @file action.hh
 * @brief Declaration of the MyActionInitialization class methods.
 * 
 * This file contains the declaration of the `MyActionInitialization` class,
 * which sets up user-defined actions for the Geant4 simulation. Specifically,
 * it initializes the primary particle generator and run action.
 */

#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"

#include "run.hh"
#include "generator.hh"

/**
 * @class MyActionInitialization
 * @brief Manages the initialization of primary generator and run action.
 * 
 * This class inherits from `G4VUserActionInitialization` and defines the 
 * user-defined actions needed for the Geant4 simulation, including the 
 * primary generator and run action.
 */

class MyActionInitialization : public G4VUserActionInitialization
{
public:
  MyActionInitialization();
  ~MyActionInitialization();

  /**
   * @brief Builds the user-defined actions for the simulation.
   */
  virtual void Build() const;
};

#endif

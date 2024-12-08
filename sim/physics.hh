/**
 * @file physics.hh
 * @brief Declaration of the `MyPhysicsList` class for configuring the physics processes in a Geant4 simulation.
 *
 * This header defines the `MyPhysicsList` class, derived from `G4VModularPhysicsList`, to manage 
 * and configure the physical processes used in a Geant4 simulation. It includes support for standard 
 * electromagnetic physics, optical processes, scintillation, and decay processes.
 */

#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"
#include "G4Scintillation.hh"
#include "G4DecayPhysics.hh"

/**
 * @class MyPhysicsList
 * @brief Custom physics list class for defining physics processes in a Geant4 simulation.
 * 
 * The `MyPhysicsList` class is responsible for registering and managing the physical processes 
 * to be used in the simulation. It extends the modular physics list provided by Geant4 
 * (`G4VModularPhysicsList`) and allows the inclusion of:
 * - **Electromagnetic Standard Physics** (`G4EmStandardPhysics`)
 * - **Optical Processes** (`G4OpticalPhysics`)
 * - **Scintillation** (`G4Scintillation`)
 * - **Decay Processes** (`G4DecayPhysics`)
 */
class MyPhysicsList : public G4VModularPhysicsList
{
public:
/**
   * @brief Constructor for the `MyPhysicsList` class.
   *
   * Initializes the custom physics list and sets up default physics modules.
   */
  MyPhysicsList();

  /**
   * @brief Destructor for the `MyPhysicsList` class.
   * 
   * Cleans up resources associated with the physics list.
   */
  ~MyPhysicsList();
};



#endif

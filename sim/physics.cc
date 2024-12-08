/**
 * @file physics.cc
 * @brief Implementation of the `MyPhysicsList` class for configuring physics processes in a Geant4 simulation.
 *
 * This file contains the implementation of the `MyPhysicsList` class methods, 
 * which register and manage the physics processes used in a Geant4 simulation.
 */
#include "physics.hh"

/**
 * @brief Constructor for the `MyPhysicsList` class.
 * 
 * Initializes the physics list by registering the following physics modules:
 * - **Electromagnetic Standard Physics** (`G4EmStandardPhysics`): Handles standard electromagnetic interactions.
 * - **Optical Physics** (`G4OpticalPhysics`): Manages optical photon processes, including reflection, refraction, and scintillation.
 * - **Decay Physics** (`G4DecayPhysics`): Handles particle decay processes.
 */
MyPhysicsList::MyPhysicsList()
{
  RegisterPhysics (new G4EmStandardPhysics());
  RegisterPhysics (new G4OpticalPhysics());
  RegisterPhysics (new G4DecayPhysics());
}

/**
 * @brief Destructor for the `MyPhysicsList` class.
 * 
 * Cleans up resources associated with the physics list. No additional actions are required in this implementation.
 */
MyPhysicsList::~MyPhysicsList()
{

}

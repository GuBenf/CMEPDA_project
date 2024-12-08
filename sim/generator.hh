/**
 * @file generator.hh
 * @brief Header file for the MyPrimaryGenerator class.
 * 
 * Defines the `MyPrimaryGenerator` class, which is responsible for generating primary particles 
 * in a Geant4 simulation. This class inherits from `G4VUserPrimaryGeneratorAction` and provides 
 * the implementation for particle generation using either a particle gun or a general particle source.
 */
#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "globals.hh"
#include "G4RandomTools.hh"

/**
 * @class MyPrimaryGenerator
 * @brief Custom implementation of the primary generator action in Geant4.
 * 
 * The `MyPrimaryGenerator` class defines how primary particles are generated in the simulation.
 * It provides the use of a particle gun for defining particle properties such as energy,
 * momentum, position, and type.
 */
class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
  /**
   * @brief Constructor for the `MyPrimaryGenerator` class.
   * 
   * Initializes the particle gun and/or general particle source used for generating primaries.
   */
  MyPrimaryGenerator();

  /**
   * @brief Destructor for the `MyPrimaryGenerator` class.
   * 
   * Cleans up resources allocated for particle generation tools.
   */
  ~MyPrimaryGenerator();

  /**
   * @brief Generates primary particles for an event.
   * 
   * This method is called by Geant4 at the beginning of each event to define the primary particles.
   * A particle gun is used.
   * 
   * @param event Pointer to the Geant4 event object for the current event.
   */
  virtual void GeneratePrimaries(G4Event*);

private:
  G4ParticleGun *fParticleGun; /**< Pointer to the particle gun object for simple particle generation. */
};

#endif

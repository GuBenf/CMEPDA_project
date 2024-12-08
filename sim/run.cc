/**
 * @file run.cc
 * @brief Implementation of the `MyRunAction` class for managing run-level actions in a Geant4 simulation.
 *
 * This file contains the implementation of the methods defined in the `MyRunAction` class, 
 * responsible for initializing and finalizing the analysis framework, and performing tasks 
 * at the start and end of each simulation run.
 */
#include "run.hh"

/**
 * @brief Constructor for the `MyRunAction` class.
 *
 * This constructor initializes the analysis manager and sets up ntuples for storing 
 * simulation data, such as hits and particle properties, during a Geant4 run.
 */
MyRunAction::MyRunAction()
{
 G4AnalysisManager *man = G4AnalysisManager::Instance();

  // Creating the "Hits" ntuple
  man->CreateNtuple("Hits","Hits");
  man->CreateNtupleIColumn("fEvent");  ///< Event identifier
  man->CreateNtupleIColumn("PMT1");    ///< Hits "value" (0 or 1) by PMT1
  man->CreateNtupleIColumn("PMT2");    ///< Hits "value" (0 or 1) by PMT2
  man->CreateNtupleIColumn("PMT3");    ///< Hits "value" (0 or 1) by PMT3
  man->CreateNtupleIColumn("PMT4");    ///< Hits "value" (0 or 1) by PMT4
  man->CreateNtupleIColumn("PMT5");    ///< Hits "value" (0 or 1) by PMT5
  man->CreateNtupleIColumn("PMT6");    ///< Hits "value" (0 or 1) by PMT6

  man->CreateNtupleDColumn("T_1");     ///< Hits time by PMT1
  man->CreateNtupleDColumn("T_2");     ///< Hits time by PMT2
  man->CreateNtupleDColumn("T_3");     ///< Hits time by PMT3
  man->CreateNtupleDColumn("T_4");     ///< Hits time by PMT4
  man->CreateNtupleDColumn("T_5");     ///< Hits time by PMT5
  man->CreateNtupleDColumn("T_6");     ///< Hits time by PMT6
  man->CreateNtupleDColumn("Times");   ///< Hits time for each event

  man->FinishNtuple(0);   ///< Finalize the "Hits" ntuple configuration

  // Creating the "Simulation" ntuple
  man->CreateNtuple("Simulation", "Simulation");
  man->CreateNtupleDColumn("Momentum");  ///< Particle momentum
  man->CreateNtupleDColumn("CosTheta");  ///< Cosine of the particle angle
  man->FinishNtuple(1);  ///< Finalize the "Simulation" ntuple configuration
}

/**
 * @brief Destructor for the `MyRunAction` class.
 *
 * This destructor performs any necessary cleanup after the simulation run. 
 * Currently, no specific cleanup is implemented.
 */
MyRunAction::~MyRunAction()
{}

/**
 * @brief Actions performed at the beginning of a simulation run.
 *
 * This method is called automatically at the start of each simulation run.
 * Currently, it does not perform any specific actions but can be customized
 * as needed.
 *
 * @param run Pointer to the current `G4Run` object.
 */
void MyRunAction::BeginOfRunAction(const G4Run*)
{}

/**
 * @brief Actions performed at the end of a simulation run.
 *
 * This method is called automatically at the end of each simulation run.
 * Currently, it does not perform any specific actions but can be customized
 * as needed.
 *
 * @param run Pointer to the current `G4Run` object.
 */
void MyRunAction::EndOfRunAction(const G4Run*)
{}

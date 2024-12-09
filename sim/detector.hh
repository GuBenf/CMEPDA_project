/**
 * @file detector.hh
 * @brief Declaration of the MySensitiveDetector class for detector setup in Geant4.
 * 
 * This file defines the `MySensitiveDetector` class, which inherits from 
 * `G4VSensitiveDetector`. It processes hits within a sensitive detector and 
 * manages data like detector hits and timing information.
 */

#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4SystemOfUnits.hh"
#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"

/**
 * @class MySensitiveDetector
 * @brief A sensitive detector class for handling hits and timing in the Geant4 simulation.
 * 
 * This class processes hits detected in the sensitive volumes of the simulation.
 * It includes methods to set and retrieve information about the detectors and
 * their associated timings. The main processing logic is implemented in the
 * `ProcessHits` method.
 */
class MySensitiveDetector : public G4VSensitiveDetector
{
public:
  MySensitiveDetector(G4String name);
  ~MySensitiveDetector();


private:
  virtual G4bool ProcessHits(G4Step *step,G4TouchableHistory *history);
};

#endif

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
/**
   * @brief Constructor for the `MySensitiveDetector` class.
   * 
   * Initializes the sensitive detector with the given name.
   * 
   * @param name The name of the sensitive detector.
   */
  MySensitiveDetector(G4String name);

  /**
   * @brief Destructor for the `MySensitiveDetector` class.
   */
  ~MySensitiveDetector();


private:
  /**
   * @brief Processes hits in the sensitive detector.
   * 
   * This method is called when a hit is registered in the sensitive detector.
   * It processes the `G4Step` and records relevant information.
   * 
   * @param step A pointer to the step that triggered the hit.
   * @param history A pointer to the touchable history of the hit.
   * 
   * @return `true` if the hit was successfully processed.
   */
  virtual G4bool ProcessHits(G4Step *step,G4TouchableHistory *history);
};

#endif

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

  /**
   * @brief Setters for detector hit counts.
   * 
   * These methods set the number of hits for specific detectors (det_1 to det_6).
   * 
   * @param i i = 1 if detector has been hitted, else i = 0.
   */
  void set_det_1(G4int i){det_1 = i;}
  void set_det_2(G4int i){det_2 = i;}
  void set_det_3(G4int i){det_3 = i;}
  void set_det_4(G4int i){det_4 = i;}
  void set_det_5(G4int i){det_5 = i;}
  void set_det_6(G4int i){det_6 = i;}

  /**
   * @brief Setters for detector timing values.
   * 
   * These methods set the timing information for specific detectors (t_1 to t_6).
   * 
   * @param i The timing value to set, in microseconds.
   */
  void set_t_1(G4double i){t_1 = i;}
  void set_t_2(G4double i){t_2 = i;}
  void set_t_3(G4double i){t_3 = i;}
  void set_t_4(G4double i){t_4 = i;}
  void set_t_5(G4double i){t_5 = i;}
  void set_t_6(G4double i){t_6 = i;}

  /**
   * @brief Getters for detector hit counts.
   * 
   * These methods the info about the detector hits (det_1 to det_6).
   * 
   * @return 1 if detector has been hitted, else 0.
   */
  G4int get_det_1(){return det_1;}
  G4int get_det_2(){return det_2;}
  G4int get_det_3(){return det_3;}
  G4int get_det_4(){return det_4;}
  G4int get_det_5(){return det_5;}
  G4int get_det_6(){return det_6;}

  /**
   * @brief Getters for detector timing values.
   * 
   * These methods retrieve the timing information for specific detectors (t_1 to t_6).
   * 
   * @return The timing value recorded by the detector, in seconds.
   */
  G4int get_t_1(){return t_1;}
  G4int get_t_2(){return t_2;}
  G4int get_t_3(){return t_3;}
  G4int get_t_4(){return t_4;}
  G4int get_t_5(){return t_5;}
  G4int get_t_6(){return t_6;}

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

  /**
   * @brief Detector hit value [0,1].
   * 
   * The det_i value is set to 1 if there has been a hit during an event.
   */
  G4int det_1 = 0;
  G4int det_2 = 0;
  G4int det_3 = 0;
  G4int det_4 = 0;
  G4int det_5 = 0;
  G4int det_6 = 0;

  /**
   * @brief Detector time value.
   * 
   * The t_i value is set each time a detector has been hitted 
   * with an absolute value wrt to the beginning of the event.
   */
  G4double t_1;
  G4double t_2;
  G4double t_3;
  G4double t_4;
  G4double t_5;
  G4double t_6;
};

#endif

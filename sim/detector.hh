#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4SystemOfUnits.hh"
#include "G4VSensitiveDetector.hh"
#include "G4RunManager.hh"
#include "G4AnalysisManager.hh"
//#include "g4root.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
  MySensitiveDetector(G4String);
  ~MySensitiveDetector();
  //setters
  void set_det_1(G4int i){det_1 = i;}
  void set_det_2(G4int i){det_2 = i;}
  void set_det_3(G4int i){det_3 = i;}
  void set_det_4(G4int i){det_4 = i;}
  void set_det_5(G4int i){det_5 = i;}
  void set_det_6(G4int i){det_6 = i;}
  void set_t_1(G4double i){t_1 = i;}
  void set_t_2(G4double i){t_2 = i;}
  void set_t_3(G4double i){t_3 = i;}
  void set_t_4(G4double i){t_4 = i;}
  void set_t_5(G4double i){t_5 = i;}
  void set_t_6(G4double i){t_6 = i;}
  //getters
  G4int get_det_1(){return det_1;}
  G4int get_det_2(){return det_2;}
  G4int get_det_3(){return det_3;}
  G4int get_det_4(){return det_4;}
  G4int get_det_5(){return det_5;}
  G4int get_det_6(){return det_6;}
  G4int get_t_1(){return t_1;}
  G4int get_t_2(){return t_2;}
  G4int get_t_3(){return t_3;}
  G4int get_t_4(){return t_4;}
  G4int get_t_5(){return t_5;}
  G4int get_t_6(){return t_6;}

private:
  virtual G4bool ProcessHits(G4Step *,G4TouchableHistory *);
  G4int det_1 = 0;
  G4int det_2 = 0;
  G4int det_3 = 0;
  G4int det_4 = 0;
  G4int det_5 = 0;
  G4int det_6 = 0;
  G4double t_1;
  G4double t_2;
  G4double t_3;
  G4double t_4;
  G4double t_5;
  G4double t_6;  
};

#endif

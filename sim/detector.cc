#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
  G4Track *track = aStep->GetTrack();
  track->SetTrackStatus(fStopAndKill);
  
  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

  G4ThreeVector posPhoton = preStepPoint->GetPosition();

  //G4cout << "Photon position: " << posPhoton << G4endl;
  const G4VTouchable *touchable =aStep->GetPreStepPoint()->GetTouchable();

  G4int copyNo = touchable->GetCopyNumber();
  //G4cout << "Copy number: " << copyNo << G4endl;

  G4VPhysicalVolume *physVol = touchable->GetVolume();
  G4ThreeVector posDetector = physVol->GetTranslation();

  G4cout<< "Detector Position: " << posDetector << G4endl;

<<<<<<< HEAD
=======
  G4double hitTime = preStepPoint->GetGlobalTime();

  G4int det_1, det_2, det_3, det_4, det_5, det_6 = 0;
  G4double T_1,T_2,T_3,T_4,T_5,T_6 = 0; 
    
>>>>>>> 0abcb7db0f57de46fb6989bbd475a22c811152ed
  if(posDetector[1] <= 10.+0.5)
  {
    if(posDetector[1] >= 10.-0.5)
	  {
<<<<<<< HEAD
	    set_det_1(1);
	    set_det_2(0);
	    set_det_3(0);
      set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);
=======
	    det_1 = 1;
	    det_2 = 0;
	    det_3 = 0;
	    det_4 = 0;
	    det_5 = 0;
	    det_6 = 0;

	    T_1 = hitTime;
	    T_2 = 0;
	    T_3 = 0;
	    T_4 = 0;
	    T_5 = 0;
	    T_6 = 0;
>>>>>>> 0abcb7db0f57de46fb6989bbd475a22c811152ed
	  }
  }
  else if(posDetector[1] <= 20.+0.5)
  {
    if(posDetector[1] >= 20.-0.5)
	  {
<<<<<<< HEAD
	    set_det_1(0);
	    set_det_2(1);
	    set_det_3(0);
      set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);
=======
	    det_1 = 0;
	    det_2 = 1;
	    det_3 = 0;
	    det_4 = 0;
	    det_5 = 0;
	    det_6 = 0;

	    T_1 = 0;
	    T_2 = hitTime;
	    T_3 = 0;
	    T_4 = 0;
	    T_5 = 0;
	    T_6 = 0;
>>>>>>> 0abcb7db0f57de46fb6989bbd475a22c811152ed
	  }
  }
  else if(posDetector[1] <=  30.+0.5)
  {
    if(posDetector[1] >=30.-0.5)
	  {
<<<<<<< HEAD
      set_det_1(0);
	    set_det_2(0);
	    set_det_3(1);
      set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);
=======
	    det_1 = 0;
	    det_2 = 0;
	    det_3 = 1;
	    det_4 = 0;
	    det_5 = 0;
	    det_6 = 0;

	    T_1 = 0;
	    T_2 = 0;
	    T_3 = hitTime;
	    T_4 = 0;
	    T_5 = 0;
	    T_6 = 0;
>>>>>>> 0abcb7db0f57de46fb6989bbd475a22c811152ed
	  }
  }
  else if(posDetector[1] <=  40.+0.5)
  {
    if(posDetector[1] >=40.-0.5)
	  {
<<<<<<< HEAD
      set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      set_det_4(1);
	    set_det_5(0);
	    set_det_6(0);
=======
	    det_1 = 0;
	    det_2 = 0;
	    det_3 = 0;
	    det_4 = 1;
	    det_5 = 0;
	    det_6 = 0;

	    T_1 = 0;
	    T_2 = 0;
	    T_3 = 0;
	    T_4 = hitTime;
	    T_5 = 0;
	    T_6 = 0;
>>>>>>> 0abcb7db0f57de46fb6989bbd475a22c811152ed
	  }
  }
  else if(posDetector[1] <=  50.+0.5)
  {
    if(posDetector[1] >=50.-0.5)
	  {
<<<<<<< HEAD
      set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      set_det_4(0);
	    set_det_5(1);
	    set_det_6(0);
=======
	    det_1 = 0;
	    det_2 = 0;
	    det_3 = 0;
	    det_4 = 0;
	    det_5 = 1;
	    det_6 = 0;

	    T_1 = 0;
	    T_2 = 0;
	    T_3 = 0;
	    T_4 = 0;
	    T_5 = hitTime;
	    T_6 = 0;
>>>>>>> 0abcb7db0f57de46fb6989bbd475a22c811152ed
	  }
  }
  else if(posDetector[1] <=  60.+0.5)
  {
    if(posDetector[1] >=60.-0.5)
	  {
<<<<<<< HEAD
      set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      set_det_4(0);
	    set_det_5(0);
	    set_det_6(1);
=======
	    det_1 = 0;
	    det_2 = 0;
	    det_3 = 0;
	    det_4 = 0;
	    det_5 = 0;
	    det_6 = 1;

	    T_1 = 0;
	    T_2 = 0;
	    T_3 = 0;
	    T_4 = 0;
	    T_5 = 0;
	    T_6 = hitTime;
>>>>>>> 0abcb7db0f57de46fb6989bbd475a22c811152ed
	  }
  }

  G4cout<< det_1 << " " << det_2 << " " << det_3 << G4endl;
  G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
  
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->FillNtupleIColumn(0,evt);
<<<<<<< HEAD
  man->FillNtupleIColumn(1,get_det_1());
  man->FillNtupleIColumn(2,get_det_2());
  man->FillNtupleIColumn(3,get_det_3());
  man->FillNtupleIColumn(4,get_det_4());
  man->FillNtupleIColumn(5,get_det_5());
  man->FillNtupleIColumn(6,get_det_6());
=======
  man->FillNtupleIColumn(1,det_1);
  man->FillNtupleIColumn(2,det_2);
  man->FillNtupleIColumn(3,det_3);
  man->FillNtupleIColumn(4,det_4);
  man->FillNtupleIColumn(5,det_5);
  man->FillNtupleIColumn(6,det_6);
  man->FillNtupleDColumn(7,T_1);
  man->FillNtupleDColumn(8,T_2);
  man->FillNtupleDColumn(9,T_3);
  man->FillNtupleDColumn(10,T_4);
  man->FillNtupleDColumn(11,T_5);
  man->FillNtupleDColumn(12,T_6);
>>>>>>> 0abcb7db0f57de46fb6989bbd475a22c811152ed
  man->AddNtupleRow(0);
  
}

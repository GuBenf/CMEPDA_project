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

  if(posDetector[1] <= 10.+0.5)
  {
    if(posDetector[1] >= 10.-0.5)
	  {
	    set_det_1(1);
	    set_det_2(0);
	    set_det_3(0);
      set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);
	  }
  }
  else if(posDetector[1] <= 20.+0.5)
  {
    if(posDetector[1] >= 20.-0.5)
	  {
	    set_det_1(0);
	    set_det_2(1);
	    set_det_3(0);
      set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);
	  }
  }
  else if(posDetector[1] <=  30.+0.5)
  {
    if(posDetector[1] >=30.-0.5)
	  {
      set_det_1(0);
	    set_det_2(0);
	    set_det_3(1);
      set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);
	  }
  }
  else if(posDetector[1] <=  40.+0.5)
  {
    if(posDetector[1] >=40.-0.5)
	  {
      set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      set_det_4(1);
	    set_det_5(0);
	    set_det_6(0);
	  }
  }
  else if(posDetector[1] <=  50.+0.5)
  {
    if(posDetector[1] >=50.-0.5)
	  {
      set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      set_det_4(0);
	    set_det_5(1);
	    set_det_6(0);
	  }
  }
  else if(posDetector[1] <=  60.+0.5)
  {
    if(posDetector[1] >=60.-0.5)
	  {
      set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      set_det_4(0);
	    set_det_5(0);
	    set_det_6(1);
	  }
  }

  G4cout<< det_1 << " " << det_2 << " " << det_3 << G4endl;
  G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
  
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->FillNtupleIColumn(0,evt);
  man->FillNtupleIColumn(1,get_det_1());
  man->FillNtupleIColumn(2,get_det_2());
  man->FillNtupleIColumn(3,get_det_3());
  man->FillNtupleIColumn(4,get_det_4());
  man->FillNtupleIColumn(5,get_det_5());
  man->FillNtupleIColumn(6,get_det_6());
  man->AddNtupleRow(0);
  
}

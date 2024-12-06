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

  //G4cout<< "Detector Position: " << posDetector << G4endl;

  G4double hittime = preStepPoint->GetGlobalTime();
  G4double hitTime = hittime*0.001; //convert in us
  //G4int det_1, det_2, det_3, det_4, det_5, det_6 = 0;
  // G4double T_1,T_2,T_3,T_4,T_5,T_6 = 0; 
  //std::cout<< posDetector[1]<<std::endl;
    
  if(posDetector[1] <= (10.+0.5)*10 && posDetector[1] >= (10.-0.5)*10)
  {
	    set_det_1(1);
	    set_det_2(0);
	    set_det_3(0);
      	set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);
	    
	    set_t_1(hitTime);
	    set_t_2(0);
	    set_t_3(0);
	    set_t_4(0);
	    set_t_5(0);
	    set_t_6(0);
  }
  else if(posDetector[1] <= (20.+0.5)*10 && posDetector[1] >= (20.-0.5)*10)
  {
	    set_det_1(0);
	    set_det_2(1);
	    set_det_3(0);
        set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);

	    set_t_1(0);
	    set_t_2(hitTime);
	    set_t_3(0);
	    set_t_4(0);
	    set_t_5(0);
	    set_t_6(0);
  }
  else if(posDetector[1] <= (30.+0.5)*10 && posDetector[1] >= (30.-0.5)*10)
  {
      	set_det_1(0);
	    set_det_2(0);
	    set_det_3(1);
      	set_det_4(0);
	    set_det_5(0);
	    set_det_6(0);
	    
	    set_t_1(0);
	    set_t_2(0);
	    set_t_3(hitTime);
	    set_t_4(0);
	    set_t_5(0);
	    set_t_6(0);
  }
  else if(posDetector[1] <= (40.+0.5)*10 && posDetector[1] >= (40.-0.5)*10)
  {
      	set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      	set_det_4(1);
	    set_det_5(0);
	    set_det_6(0);

	    set_t_1(0);
	    set_t_2(0);
	    set_t_3(0);
	    set_t_4(hitTime);
	    set_t_5(0);
	    set_t_6(0);
  }
  else if(posDetector[1] <= (50.+0.5)*10 && posDetector[1] >= (50.-0.5)*10)
  {
      	set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      	set_det_4(0);
	    set_det_5(1);
	    set_det_6(0);

	    set_t_1(0);
	    set_t_2(0);
	    set_t_3(0);
	    set_t_4(0);
	    set_t_5(hitTime);
	    set_t_6(0);
  }
  else if(posDetector[1] <= (60.+0.5)*10 && posDetector[1] >= (60.-0.5)*10)
  {
      	set_det_1(0);
	    set_det_2(0);
	    set_det_3(0);
      	set_det_4(0);
	    set_det_5(0);
	    set_det_6(1);

	    set_t_1(0);
	    set_t_2(0);
	    set_t_3(0);
	    set_t_4(0);
	    set_t_5(0);
	    set_t_6(hitTime);
  }

  //G4cout << "Detector: "<< det_1 << " " << det_2 << " " << det_3 << " " << det_4 << " " << det_5 << " " << det_6 << G4endl;
  //G4cout << "Hittime: " << t_1 << " " << t_2 << " " << t_3 << " " << t_4 << " " << t_5 << " " << t_6 << G4endl;
  G4int evt = G4RunManager::GetRunManager()->GetCurrentRun()->GetRunID();
  
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->FillNtupleIColumn(0,0,evt);
  
  man->FillNtupleIColumn(0,1,get_det_1());
  man->FillNtupleIColumn(0,2,get_det_2());
  man->FillNtupleIColumn(0,3,get_det_3());
  man->FillNtupleIColumn(0,4,get_det_4());
  man->FillNtupleIColumn(0,5,get_det_5());
  man->FillNtupleIColumn(0,6,get_det_6());
  
  man->FillNtupleDColumn(0,7,get_t_1());
  man->FillNtupleDColumn(0,8,get_t_2());
  man->FillNtupleDColumn(0,9,get_t_3());
  man->FillNtupleDColumn(0,10,get_t_4());
  man->FillNtupleDColumn(0,11,get_t_5());
  man->FillNtupleDColumn(0,12,get_t_6());
  man->FillNtupleDColumn(0,13,hitTime);
  man->AddNtupleRow(0);
}

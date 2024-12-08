/**
 * @file detector.cc
 * @brief Implementation of the MySensitiveDetector class.
 * 
 * This file implements the functionality of the `MySensitiveDetector` class,
 * which processes hits detected in sensitive volumes and records detector-specific
 * data such as hits and timing information.
 */
#include "detector.hh"

/**
 * @brief Constructor for the `MySensitiveDetector` class.
 * 
 * Initializes the sensitive detector with a given name by calling the base class constructor.
 * 
 * @param name The name of the sensitive detector.
 */
MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

/**
 * @brief Destructor for the `MySensitiveDetector` class.
 * 
 * Cleans up any resources allocated by the sensitive detector.
 */
MySensitiveDetector::~MySensitiveDetector()
{}

/**
 * @brief Processes hits detected in the sensitive detector.
 * 
 * This method is called whenever a particle interacts with the sensitive detector.
 * It records relevant data, such as the detector's position, hit time, and particle's
 * position, and assigns the recorded data to appropriate variables for further analysis.
 * 
 * @param aStep A pointer to the current step, containing information about the particle's movement.
 * @param ROhist A pointer to the touchable history of the hit (not used in this implementation).
 * 
 * @return `true` if the hit was successfully processed.
 */
G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
  // Obtain the track associated with the step and terminate it.
  G4Track *track = aStep->GetTrack();
  track->SetTrackStatus(fStopAndKill); 
  
  // Get pre-step and post-step points for positional information.
  G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
  G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
  
  // Access the touchable information to identify the detector.
  const G4VTouchable *touchable =aStep->GetPreStepPoint()->GetTouchable();
  G4int copyNo = touchable->GetCopyNumber();

  // Get the physical volume and its translation (detector position).
  G4VPhysicalVolume *physVol = touchable->GetVolume();
  G4ThreeVector posDetector = physVol->GetTranslation();

  // Retrieve and convert the global time of the hit to microseconds.
  G4double hittime = preStepPoint->GetGlobalTime();
  G4double hitTime = hittime * 0.001; // Convert to microseconds.
  
  // Determine the detector region based on the Y-coordinate of the detector's position.
  // Assign hits and timing values accordingly.  
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

  // Retrieve the current event ID.
  G4int evt = G4RunManager::GetRunManager()->GetCurrentRun()->GetRunID();
  
  // Access the analysis manager to fill the N-tuple with data.
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->FillNtupleIColumn(0,0,evt);
  
  // Record hits for all detectors.
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

  // Save the row in the N-tuple.
  man->AddNtupleRow(0);
}

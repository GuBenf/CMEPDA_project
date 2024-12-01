#include "run.hh"

MyRunAction::MyRunAction()
{
 G4AnalysisManager *man = G4AnalysisManager::Instance();

  man->CreateNtuple("Hits","Hits");
  man->CreateNtupleIColumn("fEvent");
  man->CreateNtupleIColumn("PMT1");
  man->CreateNtupleIColumn("PMT2");
  man->CreateNtupleIColumn("PMT3");
  man->CreateNtupleIColumn("PMT4");
  man->CreateNtupleIColumn("PMT5");
  man->CreateNtupleIColumn("PMT6");
  man->FinishNtuple(0);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();

  //G4int runID = run->GetRunID();

  // std::stringstream strRunID;
  //strRunID << runID;
  
  
  man->OpenFile("../output.root");
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  man->Write();
  man->CloseFile("../output.root");
}

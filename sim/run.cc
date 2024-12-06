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
  // Comment if hit times are not needed
  man->CreateNtupleDColumn("T_1");
  man->CreateNtupleDColumn("T_2");
  man->CreateNtupleDColumn("T_3");
  man->CreateNtupleDColumn("T_4");
  man->CreateNtupleDColumn("T_5");
  man->CreateNtupleDColumn("T_6");  
  man->CreateNtupleDColumn("Times");
  man->FinishNtuple(0);

  man->CreateNtuple("Simulation","Simulation");
  man->CreateNtupleDColumn("Momentum");
  man->CreateNtupleDColumn("CosTheta");
  man->FinishNtuple(1);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
  //G4AnalysisManager *man = G4AnalysisManager::Instance();
  //man->SetFileName("../output.root");
  ////man->SetVerboseLevel(1);
  //man->OpenFile("../output.root");
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
  //G4AnalysisManager *man = G4AnalysisManager::Instance();
  //man->Write();
  ////man->Clear();
  //man->CloseFile("../output.root");
}

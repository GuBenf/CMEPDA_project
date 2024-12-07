/**
 * @file analysis.cpp
 * @brief Code to analyse data simulated with Geant4.
 * 
 * Provide a plot of the time intervals between a detected muon and its detected decay positron with a fitted exponential decay curve.
When calling the function analysis, you must specify the name of the data file and the person performing the analysis ("g" for Guglielmo, "a" for Alberto) so the correct folder path can be selected automatically.
If one of the two known authors is not selected, you can directly provide the folder path as the second argument.
 * 
 * @author Benfratello G., Niccolai A.
 * @date 2024.12.04
 * @version 1.0
 * 
 * 
 */

#include "TString.h"
#include "TTree.h"
#include "TGraph.h"
#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TColor.h"

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void analysis(TString file, TString name){
  TString filepath = "../";
  if (name=="a"){
    filepath = "/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_Project/sim/";

  }
  else if (name == "g"){
    filepath = "/home/guglibenfri/CMEPDA_project/sim/Data/";
  }
  else{
    filepath = name;

  }
  filepath.Append(file);
    TFile *filename = new TFile(filepath, "READ");
    TTree *tree;
    filename->GetObject("Hits", tree);

    int event;
    int d1, d2, d3, d4, d5, d6;
    double t1, t2, t3, t4, t5, t6, time;

    tree->SetBranchAddress("fEvent", &event);

    tree->SetBranchAddress("PMT1", &d1);
    tree->SetBranchAddress("PMT2", &d2);
    tree->SetBranchAddress("PMT3", &d3);
    tree->SetBranchAddress("PMT4", &d4);
    tree->SetBranchAddress("PMT5", &d5);
    tree->SetBranchAddress("PMT6", &d6);

    tree->SetBranchAddress("T_1", &t1);
    tree->SetBranchAddress("T_2", &t2);
    tree->SetBranchAddress("T_3", &t3);
    tree->SetBranchAddress("T_4", &t4);
    tree->SetBranchAddress("T_5", &t5);
    tree->SetBranchAddress("T_6", &t6);
    tree->SetBranchAddress("Times", &time);

    int totalEntries = tree->GetEntries();

    vector<float> timeDeltas;

    // ==============================
    int totalEvents = 0;
    int currentEvent, nextEvent;
    tree->GetEntry(0);
    currentEvent = event;

    for (int i = 1; i < totalEntries; i++) {
        tree->GetEntry(i);
        nextEvent = event;

        // Compare current event with next event
        if (currentEvent == nextEvent) {
            continue;
        } else {totalEvents += 1;};

        // Move to next entry
        currentEvent = nextEvent;
    }

    //=============================================================

    TH1D *hist= new TH1D("Mu-Life simulation", "Mu-Life simulation", 100, 0., 0.);
    hist->GetXaxis()->SetTitle("Time [us]");
    hist->GetYaxis()->SetTitle("Entries");
    hist->SetFillColor(kAzure-4);
    int prevevt = -1;
    double currentTime, nextTime;
    for (int ev = 0; ev < totalEntries; ev++) {
        tree->GetEntry(ev);
        if(time > 0.050){
	  if(event > prevevt){
            hist->Fill(time);
	    prevevt = event;
	  }
        }

    }
    TCanvas *c = new TCanvas("Fit Muon lifetime", "Fit Muon lifetime");
    //hist->Draw();

    TF1 *fitFunction = new TF1("fitFunction", "[1]/[0] * TMath::Exp(-x / [0])", 0. ,20000.);
    fitFunction->SetParameters(2150., 100);
    fitFunction->SetParNames("#tau", "Ampiezza");
    hist->Fit("fitFunction", "LI");
    hist->Draw();
//
    //c->Update();

    


    
}

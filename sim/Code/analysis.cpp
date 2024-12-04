/**
 * @file analysis.cpp
 * @brief Codice per analizzare i dati simulati tramite Geant@4. 
 * 
 * Restituisce un plot degli intervalli di tempo fra muone rivelato e positrone di decadimento rilevato con fit esponenziale decrescente.
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

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void analysis(){
    TFile *filename = new TFile("/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_Project/sim/output.root", "READ");
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
    cout<<totalEntries<<endl;


    // ===============CHECK FOR THE NUMBER OF EVENTS===============
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

    

    //cout<<totalEvents<<endl;
    //=============================================================

    TH1D *hist= new TH1D("hist", "hist", 100, 0., 0.);

    double currentTime, nextTime;
    for (int ev = 0; ev < totalEntries; ev++) {
        tree->GetEntry(ev);
        if(time > 50.){
            hist->Fill(time);
        }

    }
    hist->Draw();


    
}
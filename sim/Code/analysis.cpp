/**
 * @file analysis.cpp
 * @brief Code for analyzing data simulated with Geant4.
 * 
 * This program reads data from a ROOT file generated by Geant4 simulations, specifically focusing 
 * on the detection of muons and their decay products. It plots the time intervals between detected 
 * muons and their decay positrons and fits an exponential decay curve to estimate the muon lifetime.
 * 
 * The function `analysis` takes as arguments the name of the data file and a specifier for the analysis 
 * folder path. If the name is "a" or "g", predefined paths for specific users are used. For any other 
 * input, the user must provide the full folder path manually.
 * 
 * @note The function relies on ROOT libraries for data handling, histogramming, and fitting.
 * 
 * @author Benfratello G.
 * @author Niccolai A.
 * @date 2024-12-04
 * @version 1.0
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

/**
 * @brief Analyze simulated muon lifetime data and generate a histogram with an exponential fit.
 * 
 * This function processes ROOT files containing simulated detector data to analyze the time intervals 
 * between detected muons and their decay positrons. The results are visualized as a histogram with an 
 * exponential decay fit, representing the muon lifetime.
 * 
 * @param file The name of the ROOT file to analyze (e.g., "data.root").
 * @param name A specifier for the analysis folder path. Use:
 *  - "a" for Alberto's folder path,
 *  - "g" for Guglielmo's folder path,
 *  - Any other value must specify the full custom folder path.
 * 
 * @details 
 * The function:
 * - Determines the file path based on the `name` parameter.
 * - Reads the `Hits` tree from the ROOT file.
 * - Extracts event-based PMT hit and timing data.
 * - Populates a histogram of time intervals (in microseconds).
 * - Fits the histogram with an exponential function to calculate the muon lifetime.
 * 
 * The histogram is displayed on a canvas with the fit overlay.
 * 
 * Example usage:
 * @code
 * root [0] .L analysis.cpp 
 * root [1] analysis("output.root", "a");
 * @endcode
 */
void analysis(TString file, TString name){
  // Define the default folder path based on the name argument
  TString filepath = "../";
  if (name=="a"){
    filepath = "/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_Project/sim/";

  }
  else if (name == "g"){
    filepath = "/home/guglibenfri/CMEPDA_project/sim/Data/";
  }
  else{
    filepath = name;   // Custom path provided by the user

  }
  filepath.Append(file);
  
  // Open the ROOT file
  TFile *filename = new TFile(filepath, "READ");
  TTree *tree;
  filename->GetObject("Hits", tree);

  // Declare variables for tree branches
  int event;
  int d1, d2, d3, d4, d5, d6;
  double t1, t2, t3, t4, t5, t6, time;

  // Set branch addresses for event and PMT data
  tree->SetBranchAddress("fEvent", &event);
  tree->SetBranchAddress("PMT1", &d1);
  tree->SetBranchAddress("PMT2", &d2);
  tree->SetBranchAddress("PMT3", &d3);
  tree->SetBranchAddress("PMT4", &d4);
  tree->SetBranchAddress("PMT5", &d5);
  tree->SetBranchAddress("PMT6", &d6);

  // Set branch addresses for timing data
  tree->SetBranchAddress("T_1", &t1);
  tree->SetBranchAddress("T_2", &t2);
  tree->SetBranchAddress("T_3", &t3);
  tree->SetBranchAddress("T_4", &t4);
  tree->SetBranchAddress("T_5", &t5);
  tree->SetBranchAddress("T_6", &t6);
  tree->SetBranchAddress("Times", &time);

  int totalEntries = tree->GetEntries(); // Total number of entries in the tree

  // Count total number of unique events
  int totalEvents = 0;
  int currentEvent, nextEvent;
  tree->GetEntry(0);
  currentEvent = event;

  for (int i = 1; i < totalEntries; i++)
  {
    tree->GetEntry(i);
    nextEvent = event;

    // Compare current event with next event
    if (currentEvent == nextEvent) {
        continue;
    } else {totalEvents += 1;};

    // Move to next entry
    currentEvent = nextEvent;
  }

  // Create a histogram for the time intervals
  TH1D *hist= new TH1D("Mu-Life simulation", "Mu-Life simulation", 100, 0., 0.);
  hist->GetXaxis()->SetTitle("Time [#mu s]");
  hist->GetYaxis()->SetTitle("Entries");
  hist->SetFillColor(kAzure-4);

  // Cycle to take one time value per event, the first one coming from the e+/e- scintillation
  int prevevt = -1;
  for (int ev = 0; ev < totalEntries; ev++) {
    tree->GetEntry(ev);
    if(time > 0.050){  // Filter out invalid or small time intervals
	    if(event > prevevt && (d2 == 1 || d3 == 1 || d4 == 1 )){  // Take only those from target (2,3,4)
        hist->Fill(time);
	      prevevt = event;
	    }
    }
  }

  // Create a canvas and fit the histogram with an exponential decay function
  TCanvas *c = new TCanvas("Fit Muon lifetime", "Fit Muon lifetime");
  TF1 *fitFunction = new TF1("fitFunction", "[1]/[0] * TMath::Exp(-x / [0])", 0. ,20000.);
  fitFunction->SetParameters(2150., 100);
  fitFunction->SetParNames("#tau", "Ampiezza");
  hist->Fit("fitFunction", "LI");
  hist->Draw();

}

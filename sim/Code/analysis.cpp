#include "TString.h"
#include "TTree.h"
#include "TGraph.h"
#include "TFile.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TColor.h"
#include "ROOT/RDataFrame.hxx"
//#include "ROOT/EnableImplicitMT.hxx"

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void analysis(){
    ROOT::EnableImplicitMT(); // Enable ROOT's implicit multi-threading
    const char* filename = "/Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/sim/Data/output_1000_mu_2_12.root";
    ROOT::RDataFrame rdf("Hits", filename);

    int size = rdf.GetColumnNames().size();

    for (int i = 0; i < size; i++){
        cout<<rdf.GetColumnNames()[i].size()<<endl;    
    }
    
    auto h = rdf.Filter("PMT6 == 1 && PMT5 == 1 && (PMT4 == 1 || PMT3 == 1 || PMT2 == 1) || PMT1 == 0", "cut");//.Histo1D("PMT3"); /*  */
    h.Report()->Print();
    auto hist = h.Filter("T_3 != 0").Histo1D({"prova", "prova", 1000, 0., 0.}, "T_3");
    hist->DrawClone();



}

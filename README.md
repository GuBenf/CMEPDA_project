# DOCUMENTATION:
Link to lsat updated version of documentation: [Testo cliccabile](file:///Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/docs/html/dir_4fedf3bc7458de691f44ea68a2cf9143.html)

This repository contains the code and the data of the simulation of a Fundamental Interactions Physics Laboratory experiment, made with Geant4 for the CMEPDA exam at UNIPI.
The experiment is aimed at measuring the mean life of the muon, using plastic scintillators
The experiment is aimed at measuring the mean life of the muon, using plastic scintillators and PMTs.
The simulation is made generating muons with a momentum extracted from a Gaussian distribution with mean $m =80$ MeV/c adn standard deviation $std = 20$ MeV/c, in order to only have "useful" particles.

# HOW TO
- sim executable: In order to launch the simulation you need to make the executable from the build directory and then execute it. You can pass as a parameter the (int) number of muons that you want to simulate.
- analysis: You can run the (simple) ROOT code for the analysis /Code/analysis.cpp. The analysis function takes two arguments (strings): the name of the data file and its path. If you are one of the authors, you can simply pass "a" (for Alberto) or "g" for (Guglielmo) as a second parameter.

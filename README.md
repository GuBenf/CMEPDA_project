## $\mu$-Life Simulation
$\mu$-Life Simulation is a project made for the CMEPDA exam at UNIPI, in which we aim to reconstruct the $\mu$-Life experiment of the Fundamental Interactions Physics Laboratory.
The aim of this experiment is the measurement of the mean life of the $\mu$, using plastic scintillators and PMTs.
The simulation is made generating muons with a momentum extracted from a Gaussian distribution with mean $m =80$ MeV/c adn standard deviation $std = 20$ MeV/c, in order to only have "useful" particles.

### Documentation
Link to lsat updated version of documentation: [Link](file:///Users/Alberto/Desktop/Magistrale/Computing_methods/Progetto/CMEPDA_project/docs/html/dir_4fedf3bc7458de691f44ea68a2cf9143.html)

### Requirements
To use this project you need to have Geant4 v.11 or superior and ROOT v.6.28 or superior installed in your machine, so be sure to check those requirements.
Compatibility with previous releases is not tested and therefore not assured.

### How To
- sim executable: In order to launch the simulation you need to make the executable from the build directory and then execute it. You can pass as a parameter the (int) number of muons that you want to simulate.
- analysis: You can run the (simple) ROOT code for the analysis /Code/analysis.cpp. The analysis function takes two arguments (strings): the name of the data file and its path. If you are one of the authors, you can simply pass "a" (for Alberto) or "g" for (Guglielmo) as a second parameter.

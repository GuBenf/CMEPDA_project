[![Documentation](https://img.shields.io/badge/docs-online-blue?logo=github)](https://GuBenf.github.io/CMEPDA_project/)
/*!

\mainpage Welcome to the documentation page!

# CMEPDA Project

## $\mu$-Life Simulation
$\mu$-Life Simulation is a project made for the CMEPDA exam at UNIPI, in which we aim to reconstruct the $\mu$-Life experiment of the Fundamental Interactions Physics Laboratory.
The aim of this experiment is the measurement of the mean life of the $\mu$, using plastic scintillators and PMTs.
The simulation is made generating muons with a momentum extracted from a Gaussian distribution with mean $m =80$ MeV/c adn standard deviation $std = 20$ MeV/c, in order to only have "useful" particles.

### Documentation
Link to last updated version of documentation: [Link](https://GuBenf.github.io/CMEPDA_project/)

### Requirements
To use this project you need to have Geant4 v.11 or superior and ROOT v.6.28 or superior installed in your machine, so be sure to check those requirements.
Compatibility with previous releases is not tested and therefore not assured.

### Usage
In order to use the project you need to follow some (easy) steps:
- `mkdir` a directory where you will build the program (optional but suggested);
- Run the command `cmake ..` and then, if everything is alright, run `make`, which will create a executable (called _sim_ by default, you can change that from the CMakeLists.txt file);
- Run the sim executable with `./sim <n_runs>`, where `<n_runs>` is the (integer!) number of particles that you will generate (note that if nothing is passed `<n_runs>`=1000 by default);
- At the end of the simulation the Geant4 UI will be opened, showing one of the generated event and the detector structure;
- The data will be saved in a `.root` file in the `/sim` folder, move or rename it before launching another simulation, otherwise the data will be overwritten;
- You can run the (simple) ROOT code for the analysis `/Code/analysis.cpp` by launching ROOT in the `/Code` folder, writing `.L analysis.cpp` and then `analysis("<data_file_name>","<path_to_data_file>")`. The analysis function takes two arguments (strings): the name of the data file and its path. If you are one of the authors, you can simply pass "a" (for Alberto) or "g" for (Guglielmo) as a second parameter.

### Authors
$\mu$-Life Simulation has been done by **[Alberto Niccolai] (https://github.com/AlbertoNiccolai)**  and **[Guglielmo Benfratello] (https://github.com/GuBenf)**.

*/

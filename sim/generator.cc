/**
 * @file generator.cc
 * @brief Implementation of the MyPrimaryGenerator class.
 * 
 * This source file contains the implementation of the `MyPrimaryGenerator` class,
 * responsible for generating primary muons in a Geant4 simulation environment.
 * It utilizes the `G4ParticleGun` to control spatial, angular, and momentum distributions
 * for primary particles. The particles can be configured with a variety of distributions,
 * such as plane-origin distributions, Gaussian momentum distributions, and cosine-like angular orientations.
 */

#include "generator.hh"

/**
 * @brief Constructor for `MyPrimaryGenerator`.
 * 
 * Initializes the particle generator and creates a new `G4ParticleGun` object configured
 * to generate a single particle per event.
 */
MyPrimaryGenerator::MyPrimaryGenerator()
{
  fParticleGun = new G4ParticleGun(1);
}
/**
 * @brief Destructor for `MyPrimaryGenerator`.
 * 
 * Cleans up memory by deleting the `fParticleGun` instance, ensuring proper resource management.
 */
MyPrimaryGenerator::~MyPrimaryGenerator()
{
  delete fParticleGun;
}

/**
 * @brief GeneratePrimaries method to create primary particles for a simulation event.
 * 
 * Generates primary muons in a Geant4 simulation event. The particle distribution can be
 * configured for different spatial, angular, and momentum distributions, including Gaussian and custom distributions.
 *
 * @param anEvent A pointer to the `G4Event` object representing the current simulation event.
 *
 * **Key functionalities include**:
 * - **Particle Origin (Spatial Distribution)**:
 *   - When `rand_plane_dist` is `true`, particles are uniformly distributed on a plane
 *     the size of the scintillator (specified by `planeHalfX` and `planeHalfZ`).
 *   - If `rand_plane_dist` is `false`, particles are generated at the center of the scintillator.
 *
 * - **Angular Distribution**:
 *   - A cosine-like angular distribution is implemented if `true_ang_dist` is `true`.
 *   - Otherwise, particles are oriented downward by default along the z-axis.
 *
 * - **Momentum Distribution**:
 *   - A Gaussian-distributed momentum can be selected with a mean (`mean`) and standard deviation (`sigma`).
 *   - A custom selection algorithm generates a momentum distribution if `gauss_mom_dist` is set to `false`.
 */
void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
  // --- Particle Definition ---
  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName = "muon";
  G4ParticleDefinition *particle = particleTable->FindParticle("mu-");
  fParticleGun->SetParticleDefinition(particle);

  // --- Distribution Booleans ---
  G4bool true_ang_dist = false;   // Default
  G4bool rand_plane_dist = true;  // Default
  G4bool gauss_mom_dist = true;  // Default

  // --- Spatial Distribution ---
  G4ThreeVector pos;

  if (rand_plane_dist){
    // Generate a random position on a plane which has the same size as the scintillator
    G4double randomValue1 = CLHEP::HepRandom::getTheEngine()->flat();
    G4double randomValue2 = CLHEP::HepRandom::getTheEngine()->flat();
    G4double planeHalfX = 20.0;
    G4double planeHalfZ = 24.0;
    G4double x = (2.0 * randomValue1 - 1.0) * planeHalfX; // Uniform random in [-planeHalfX, planeHalfX]
    G4double z = (2.0 * randomValue2 - 1.0) * planeHalfZ; // Uniform random in [-planeHalfZ, planeHalfZ]
    G4double y = 1.0 * m;  // Plane lies at z = 1 m
    
    pos = G4ThreeVector(x, y, z);
  } else{
    pos = G4ThreeVector(0., 1.*m, 0.); // Vertical, upon the center of the scintillator
  }

  fParticleGun->SetParticlePosition(pos);


  // --- Angular Distribution ---
  G4ThreeVector momDir;
  G4double cosTheta = 0.;

  if (true_ang_dist){
    // Generate a cosine-like angular distribution
    cosTheta = -G4UniformRand();
    G4double theta = std::acos(cosTheta);
    G4double phi = 2. * CLHEP::pi * G4UniformRand();
    G4double px = std::sin(theta) * std::cos(phi);
    G4double pz = std::sin(theta) * std::sin(phi);
    G4double py = std::cos(theta);

    momDir = G4ThreeVector (px, py, pz);
  } else{
    momDir = G4ThreeVector(0., -1., 0.); // Perpendicular to the scintillators
  }

  fParticleGun->SetParticleMomentumDirection(momDir);


  // --- Momentum Distribution ---
  G4double mom;

  if (gauss_mom_dist){
  // Generate a Gaussian-distributed random number
  G4double mean = 80.0;    ///< Mean of the Gaussian distribution
  G4double sigma = 20.0;   ///< Standard deviation of the Gaussian distribution
  G4double u_mom = G4RandGauss::shoot(mean, sigma);
  G4double p_mom = u_mom * MeV;
  fParticleGun->SetParticleMomentum(p_mom);
  mom = p_mom;
  }
  else{
  G4bool part = false;
  G4double p_m = 0.;
  G4int ind = 0;
  while (part == false)
    {
      ind = ind +1;
      if (ind <4)
	{
  G4double u_mom = G4UniformRand();
  G4double p_mom = u_mom * 10.*GeV;
  if (p_mom > 1*GeV)
    {
      G4double cas = 1.*GeV/p_mom;
      G4double p_sel = G4UniformRand();
      if (p_sel<=cas)
	{
	  part = true;
	  p_m = p_mom;
	}
    }
  else if (p_mom<=1.*GeV)
    {
      part = true;
      p_m = p_mom;
    }
	}
      else
	{part=true;}
    }
  fParticleGun->SetParticleMomentum(p_m);
  mom = p_m;
  }

  // Generate the particle for the event
  fParticleGun->GeneratePrimaryVertex(anEvent);

  // --- Analysis Logging ---
  G4int evtID = G4RunManager::GetRunManager()->GetCurrentRun()->GetRunID();
  
  G4AnalysisManager *man = G4AnalysisManager::Instance();
  G4cout<<evtID<< " " << mom <<G4endl;
  man->FillNtupleDColumn(1,0,mom);
  man->FillNtupleDColumn(1,1,cosTheta);
  man->AddNtupleRow(1);

}


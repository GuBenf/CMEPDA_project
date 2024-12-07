#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
  fParticleGun = new G4ParticleGun(1);
  //fParticleSource = new G4GeneralParticleSource();
}
MyPrimaryGenerator::~MyPrimaryGenerator()
{
  delete fParticleGun;
  //delete fParticleSource;
}

G4double randomMaker(){
    return CLHEP::HepRandom::getTheEngine()->flat();
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
  G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName = "muon";
  G4ParticleDefinition *particle = particleTable->FindParticle("mu-");
  fParticleGun->SetParticleDefinition(particle);

  // Generate a random position on a plane (e.g., square plane)
  G4double randomValue1 = CLHEP::HepRandom::getTheEngine()->flat();
  G4double randomValue2 = CLHEP::HepRandom::getTheEngine()->flat();
  G4double planeHalfX = 20.0 * cm;  // Half-width of the plane along X
  G4double planeHalfZ = 24.0 * cm;  // Half-height of the plane along Z
  G4double x = (2.0 * randomValue1 - 1.0) * planeHalfX; // Uniform random in [-planeHalfX, planeHalfX]
  G4double z = (2.0 * randomValue2 - 1.0) * planeHalfZ; // Uniform random in [-planeHalfZ, planeHalfZ]
  G4double y = 1.0 * m;  // Plane lies at z = 1 m
  G4ThreeVector pos(x, y, z);

  // Generate a cosine-like angular distribution
  G4double cosTheta = -G4UniformRand();
  G4double theta = std::acos(cosTheta);
  G4double phi = 2. * CLHEP::pi * G4UniformRand();        // Uniform in [0, 2π]
  G4double px = std::sin(theta) * std::cos(phi);
  G4double pz = std::sin(theta) * std::sin(phi);
  G4double py = std::cos(theta);
  G4ThreeVector mom(px, py, pz);

  G4ThreeVector pos1(0., 1.*m, 0.);
  G4ThreeVector mom1(0., -1., 0.);

  // Choose the spatial distribution of the particle origin (set to true if you want all the particles over the center of the detector)
  if (false){
    fParticleGun->SetParticlePosition(pos1);
  }
  else {
    fParticleGun->SetParticlePosition(pos);
  }

  // Choose the angular distribution of the particle direction (set to true if you want a uniform distribution in angle, else the trajectory will always be vertical)
  if (false){
    fParticleGun->SetParticleMomentumDirection(mom);
  }
  else {
    fParticleGun->SetParticleMomentumDirection(mom1);
  }


  // Generate the momenta distribution (set to true if you want a Gaussian distribution, false if you want a "realistic" toy-distribution, feel free to play with it!)
 
  if (true){
  // Generate a Gaussian-distributed random number
  G4double mean = 80.0;    // Mean of the Gaussian distribution
  G4double sigma = 20.0;   // Standard deviation of the Gaussian distribution
  G4double u_mom = G4RandGauss::shoot(mean, sigma);
  G4double p_mom = u_mom * MeV;
  fParticleGun->SetParticleMomentum(p_mom);

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
  }


  fParticleGun->GeneratePrimaryVertex(anEvent);

  G4int evtID = G4RunManager::GetRunManager()->GetCurrentRun()->GetRunID();
  

  G4AnalysisManager *man = G4AnalysisManager::Instance();
  G4cout<<evtID<< " " << p_mom<<G4endl;
  man->FillNtupleDColumn(1,0,p_mom);
  man->FillNtupleDColumn(1,1,cosTheta);
  man->AddNtupleRow(1);

}

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
  G4ParticleDefinition *particle = particleTable->FindParticle("mu+");
  fParticleGun->SetParticleDefinition(particle);

  // Generate a random position on a plane (e.g., square plane)
  G4double randomValue1 = CLHEP::HepRandom::getTheEngine()->flat();
  G4double randomValue2 = CLHEP::HepRandom::getTheEngine()->flat();
  G4double planeHalfX = 100.0 * cm;  // Half-width of the plane along X
  G4double planeHalfZ = 100.0 * cm;  // Half-height of the plane along Z
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

  fParticleGun->SetParticlePosition(pos);
  fParticleGun->SetParticleMomentumDirection(mom);
  fParticleGun->SetParticleMomentum(50.*MeV);
  

  fParticleGun->GeneratePrimaryVertex(anEvent);
}

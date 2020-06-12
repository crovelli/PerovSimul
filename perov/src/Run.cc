#include "Run.hh"

Run::Run()
: G4Run(),
  fEkinePrimary(0.),
  fEtotPrimary(0.),
  numHitParticles(0)
{ }

Run::~Run()
{} 

void Run::Merge(const G4Run* run)
{
  const Run* localRun = static_cast<const Run*>(run);
  fEkinePrimary += localRun->fEkinePrimary;
  fEtotPrimary += localRun->fEtotPrimary;
  numHitParticles += localRun->numHitParticles;

  G4Run::Merge(run); 
} 

void Run::AddPrimaryEneKine(G4double ene)
{
  fEkinePrimary += ene;
}

void Run::AddPrimaryEneTot(G4double ene)
{
  fEtotPrimary += ene;
}

void Run::AddHitParticle(G4int num)
{
  numHitParticles += num;
}

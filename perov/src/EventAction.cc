#include "EventAction.hh"
#include "Run.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

EventAction::EventAction()
  : G4UserEventAction(),
    fEkinePrimary(0.),
    fEtotPrimary(0.),
    numHitParticles(0)
{} 

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event*)
{    
  fEkinePrimary = 0.;
  fEtotPrimary  = 0.;
  numHitParticles = 0;
}

void EventAction::EndOfEventAction(const G4Event*)
{   
  // accumulate statistics in Run                                                   
  Run* run = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  run->AddPrimaryEneKine(fEkinePrimary);
  run->AddPrimaryEneTot(fEtotPrimary);
  run->AddHitParticle(numHitParticles);
}

#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

/// Event action class
class EventAction : public G4UserEventAction
{
public:
  EventAction();
  virtual ~EventAction();
  
  virtual void BeginOfEventAction(const G4Event* event);
  virtual void EndOfEventAction(const G4Event* event);
  
  void AddPrimaryEneKine(G4double ene) { fEkinePrimary += ene; }
  void AddPrimaryEneTot(G4double ene)  { fEtotPrimary += ene;  }
  void AddHitParticle(G4int hit) { numHitParticles +=hit; }
  
private:
  G4double     fEkinePrimary;
  G4double     fEtotPrimary;
  G4int        numHitParticles;
};

#endif

    

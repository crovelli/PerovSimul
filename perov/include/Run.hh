#ifndef Run_h
#define Run_h 1

#include "G4Run.hh"
#include "globals.hh"

class G4Event;

class Run : public G4Run
{
public:
  Run();
  virtual ~Run();
  
  // method from the base class
  virtual void Merge(const G4Run*);
    
  // user methods
  void AddPrimaryEneKine (G4double ene); 
  void AddPrimaryEneTot (G4double ene); 
  void AddHitParticle (G4int num);
  G4double GetPrimaryEneKine() const { return fEkinePrimary;   }
  G4double GetPrimaryEneTot()  const { return fEtotPrimary;    }
  G4int    GetHitParticle()    const { return numHitParticles; }
  
private:
  G4double  fEkinePrimary;
  G4double  fEtotPrimary;
  G4int     numHitParticles;
};

#endif


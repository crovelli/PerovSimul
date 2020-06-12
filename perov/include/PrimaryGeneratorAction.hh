#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

class G4GeneralParticleSource;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
  PrimaryGeneratorAction();    
  virtual ~PrimaryGeneratorAction();
  
  // method from the base class
  virtual void GeneratePrimaries(G4Event*);         
  
private:
  G4GeneralParticleSource*  fParticleGun; // pointer a to G4 gun class
};

#endif

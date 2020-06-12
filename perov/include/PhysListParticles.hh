#ifndef PhysListParticles_h
#define PhysListParticles_h 1

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

class PhysListParticles : public G4VPhysicsConstructor
{
public: 
  PhysListParticles(const G4String& name = "particles");
  virtual ~PhysListParticles();
  
public: 
  // This method will be invoked in the Construct() method. 
  // each particle type will be instantiated
  virtual void ConstructParticle();
  
  // This method is dummy.
  virtual void ConstructProcess() {};
};

#endif









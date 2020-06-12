#ifndef PhysicsListGeantino_h
#define PhysicsListGeantino_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class PhysicsListGeantino: public G4VUserPhysicsList
{
  public:
    PhysicsListGeantino();
   ~PhysicsListGeantino();

  protected:
    // Construct particle and physics
    virtual void ConstructParticle();
    virtual void ConstructProcess(); 
    virtual void SetCuts();   
};

#endif




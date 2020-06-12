#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "EventAction.hh"
#include "G4UserSteppingAction.hh"
#include "globals.hh"

class EventAction;

class G4LogicalVolume;

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(EventAction* eventAction);
  virtual ~SteppingAction();
  
  // method from the base class
  virtual void UserSteppingAction(const G4Step*);
  
private:
  G4LogicalVolume* fScoringVolume;
  EventAction*  fEventAction;
};

#endif

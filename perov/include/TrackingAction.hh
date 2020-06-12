#ifndef TrackingAction_h
#define TrackingAction_h 1

#include "EventAction.hh" 
#include "G4UserTrackingAction.hh"
#include "globals.hh"

class EventAction;

class TrackingAction : public G4UserTrackingAction
{
public:
  TrackingAction(EventAction* eventAction) ;
  ~TrackingAction() { };
  
  virtual void  PreUserTrackingAction(const G4Track*);
  
private:
  EventAction*  fEventAction;
};

#endif

    

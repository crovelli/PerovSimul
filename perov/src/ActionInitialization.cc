#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "TrackingAction.hh"
#include "SteppingAction.hh"

ActionInitialization::ActionInitialization()
 : G4VUserActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::BuildForMaster() const
{
  RunAction* runAction = new RunAction();
  SetUserAction(runAction);
}

void ActionInitialization::Build() const
{
  PrimaryGeneratorAction* primary = new PrimaryGeneratorAction();    
  SetUserAction(primary);
  
  RunAction* runAction = new RunAction();                     
  SetUserAction(runAction);

  EventAction* eventAction = new EventAction();                      
  SetUserAction(eventAction);

  SetUserAction(new TrackingAction(eventAction));

  SetUserAction(new SteppingAction(eventAction));                   
}  

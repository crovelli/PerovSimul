#include "TrackingAction.hh"
#include "AnalysisManager.hh"   

#include "G4Track.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

TrackingAction::TrackingAction(EventAction* eventAction)
  :G4UserTrackingAction(),
   fEventAction(eventAction)
{ }

void TrackingAction::PreUserTrackingAction(const G4Track* track)
{
  AnalysisManager* analysis = AnalysisManager::GetInstance();  

  if (track->GetTrackID()==1) {

    G4double ekin           = track->GetKineticEnergy();
    G4double etot           = track->GetTotalEnergy();
    G4ThreeVector vertex    = track->GetPosition();
    G4ThreeVector direction = track->GetMomentumDirection();

    // fill histograms    
    analysis->FillPrimaryInfo(ekin, etot, vertex, direction);       

    // to integrate the primary particle energy
    fEventAction->AddPrimaryEneKine(ekin);
    fEventAction->AddPrimaryEneTot(etot);
  }
}






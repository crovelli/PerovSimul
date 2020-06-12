#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "AnalysisManager.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"

SteppingAction::SteppingAction(EventAction* eventAction)
  : G4UserSteppingAction(),
    fScoringVolume(0),
    fEventAction(eventAction)
{}

SteppingAction::~SteppingAction()
{}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
  G4Track* fTrack = step->GetTrack();
  G4int StepNo = fTrack->GetCurrentStepNumber();
  if(StepNo >= 10000) fTrack->SetTrackStatus(fStopAndKill);
  
  // energy deposition in active surface
  if (!fScoringVolume) { 
    const DetectorConstruction* detectorConstruction
      = static_cast<const DetectorConstruction*>
      (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();   
  }
  
  // get volume of the current step
  G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

  AnalysisManager* analysis = AnalysisManager::GetInstance();
  G4double edepStep = step->GetTotalEnergyDeposit();
  if (volume == fScoringVolume) analysis->FillHit(edepStep);  

  if (volume == fScoringVolume) fEventAction->AddHitParticle(1);
}




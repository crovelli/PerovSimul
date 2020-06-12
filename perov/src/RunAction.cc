#include "RunAction.hh"
#include "AnalysisManager.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction()
  : G4UserRunAction(), fRun(0)
{}

RunAction::~RunAction()
{}

G4Run* RunAction::GenerateRun()                                                                                             
{
  fRun = new Run();                                                                                     
  return fRun;                                                                                             
}    

void RunAction::BeginOfRunAction(const G4Run* run)
{ 
  AnalysisManager* analysis = AnalysisManager::GetInstance();
  analysis->BeginOfRun();
}

void RunAction::EndOfRunAction(const G4Run* run)
{
  // G4int nofEvents = run->GetNumberOfEvent();
  G4int nofEvents = fRun->GetNumberOfEvent();
  if (nofEvents == 0) return;

  // Get the analysis manager
  AnalysisManager* analysis = AnalysisManager::GetInstance();
  analysis->EndOfRun(run->GetNumberOfEvent());  

  // Total energy of primary particle
  // const Run* myRun = static_cast<const Run*>(run);
  // G4double primaryEneKine = myRun->GetPrimaryEneKine();
  // G4double primaryEneTot  = myRun->GetPrimaryEneTot();
  // G4int    hits = myRun->GetHitParticle();
  G4double primaryEneKine = fRun->GetPrimaryEneKine();
  G4double primaryEneTot  = fRun->GetPrimaryEneTot();
  G4int    hits = fRun->GetHitParticle();

  G4cout << G4endl;
  G4cout << G4endl;
  G4cout << "============================" << G4endl;
  G4cout << "Primary particle, total energy = " << primaryEneTot/keV  << " keV" << ", " << (primaryEneTot/eV)*1.6022/10000000000000000000.  << " Joule" << G4endl;
  G4cout << "Primary particle, kine energy = "  << primaryEneKine/keV << " keV" << ", " << (primaryEneKine/eV)*1.6022/10000000000000000000. << " Joule" << G4endl;
  G4cout << G4endl;
  G4cout << G4endl;
  G4cout << "# events = " << nofEvents  << G4endl;
  G4cout << "# events with primary hitting the active surface = " << hits << G4endl;   
  G4cout << G4endl;
  G4cout << G4endl;
  G4cout << "Joule on the active surface [kine] = " << (primaryEneTot/eV)*(1.6022/10000000000000000000.)*hits/nofEvents <<  G4endl;
  G4cout << "============================" << G4endl;
  G4cout << G4endl;
}


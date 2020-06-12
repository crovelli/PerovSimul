#ifndef AnalysisManager_h
#define AnalysisManager_h 1

#include "PrimaryGeneratorAction.hh" 
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "CLHEP/Units/SystemOfUnits.h"
#include <vector>

class Histo;

class AnalysisManager
{

public:

  // With description
  static AnalysisManager* GetInstance();
  static void Dispose();
  
private:
  
  AnalysisManager();
  ~AnalysisManager();

public: // Without description

  void BookHisto();

  void BeginOfRun();
  void EndOfRun(G4int);

  void BeginOfEvent();
  void EndOfEvent();

  void FillPrimaryInfo(G4double, G4double, G4ThreeVector, G4ThreeVector);
  void FillHit(G4double);

  void SetVerbose(G4int val) {fVerbose = val;};
  G4int GetVerbose() const {return fVerbose;};

private:

  // MEMBERS
  static AnalysisManager* fManager;

  G4int fVerbose;
  //
  Histo*  fHisto;  
};

#endif

#include "AnalysisManager.hh"
#include "G4UnitsTable.hh"
#include "Histo.hh"
#include "G4ProcessTable.hh"
#include "G4RadioactiveDecay.hh"
#include "G4TwoVector.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>

AnalysisManager* AnalysisManager::fManager = 0;

AnalysisManager* AnalysisManager::GetInstance()
{
  if(!fManager) fManager = new AnalysisManager();
  
  return fManager;
}

void AnalysisManager::Dispose()
{
  delete fManager;
  fManager = 0;
}

AnalysisManager::AnalysisManager()
  : fVerbose(0)
{
  fHisto = new Histo();
  fHisto->SetFileName("perov");
  BookHisto();
}

AnalysisManager::~AnalysisManager()     
{
  delete fHisto;
}

void AnalysisManager::BookHisto()         
{
  // Histos on primary particle
  G4int nbins = 100;
  G4double vmin  = 0.;
  G4double vmax  = 10.;
  G4double vminy = 0.;
  G4double vmaxy = 10.;
  fHisto->Add1D("H10", "kinetic energy", nbins, vmin, vmax);
  fHisto->Add1D("H11", "total energy",   nbins, vmin, vmax);
  nbins = 100; vmin = 0.; vmax = 5.;
  fHisto->Add1D("H12", "vertex dist R", nbins, vmin, vmax);
  nbins = 100; vmin = -1.; vmax = 1.;
  fHisto->Add1D("H13", "direction: cos(theta)", nbins, vmin, vmax);
  nbins = 100; vmin = 0.; vmax = 6.28;  
  fHisto->Add1D("H14", "direction: phi", nbins, vmin, vmax);
  nbins = 100; vmin = 0.; vmax = 100.;
  fHisto->Add1D("H15", "deposited energy", nbins, vmin, vmax);     
  nbins = 60; vmin = -3.; vmax = 3.;   
  fHisto->Add2D("H20", "vertex: Y vs X", nbins, vmin, vmax, nbins,vmin,vmax);
  fHisto->Add2D("H21", "vertex: Z vs X", nbins, vmin, vmax, nbins,vmin,vmax);
  fHisto->Add2D("H22", "vertex: Y vs Z", nbins, vmin, vmax, nbins,vmin,vmax);
  nbins = 100; vmin = 0.; vmax = 6.28; vminy = -1.; vmaxy = 1.;     
  fHisto->Add2D("H23", "direction: cos(theta) vs phi", nbins, vmin, vmax, nbins,vminy,vmaxy);
}
 
void AnalysisManager::BeginOfRun()  
{
  fHisto->Book();
}

void AnalysisManager::EndOfRun(G4int nevent)    
{
  // Save all histos
  fHisto->Save();
  G4cout << "AnalysisManager: Histograms have been saved!" << G4endl;
}

void AnalysisManager::BeginOfEvent()    
{}

void AnalysisManager::EndOfEvent()        
{}

void AnalysisManager::FillPrimaryInfo(G4double ekin, G4double etot, G4ThreeVector vertex, G4ThreeVector direction )   
{
  G4double x = vertex.x(), y = vertex.y(), z = vertex.z();
  G4double theta = direction.theta(), phi = direction.phi();
  if (phi < 0.) phi += CLHEP::twopi;
  G4double cost = std::cos(theta);
  
  G4double r = vertex.mag();
  
  fHisto->FillHisto(0,ekin,1);      
  fHisto->FillHisto(1,etot,1);      
  fHisto->FillHisto(2, r, 1);
  fHisto->FillHisto(3,cost,1);        
  fHisto->FillHisto(4,phi,1);        
  //
  fHisto->FillHisto(0,x,y,1);          
  fHisto->FillHisto(1,x,z,1);          
  fHisto->FillHisto(2,z,y,1);          
  fHisto->FillHisto(3,phi,cost,1);          
}

void AnalysisManager::FillHit(G4double edep) {
  fHisto->FillHisto(5,edep,1);
}


#include "TROOT.h"
#include "TApplication.h"
#include "TGClient.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"

#include "Histo.hh"

Histo::Histo()
  :fHistName(""), fHistType("root"),
   fNHisto1D(0), fNHisto2D(0),
   fVerbose(0),
   fDefaultAct(1)
{
  fROOThisto1D.clear();
  fROOThisto2D.clear();

  fActive1D.clear();
  fBins1D.clear();
  fXmin1D.clear();
  fXmax1D.clear();
  fIds1D.clear();
  fTitles1D.clear();
  fActive2D.clear();
  fBins2D.clear();
  fBins22D.clear();
  fXmin2D.clear();
  fXmin22D.clear();
  fXmax2D.clear();
  fXmax22D.clear();
  fIds2D.clear();
  fTitles2D.clear();
}

Histo::~Histo()
{}

void Histo::Book()
{
  G4String fileNameROOT = fHistName + G4String(".root");
  fHfileROOT = new TFile(fileNameROOT.c_str() ,"RECREATE","ROOT file for ");
  G4cout << "Root file for histos: " << fileNameROOT << G4endl;

  for(G4int i=0; i<fNHisto1D; i++) {
    if(fActive1D[i]) {
      G4String id = G4String("h1")+fIds1D[i];
      fROOThisto1D[i] = new TH1D(id, fTitles1D[i], fBins1D[i], fXmin1D[i], fXmax1D[i]);
      G4cout << "ROOT 1D Histo " << fIds1D[i] << " " << fTitles1D[i] << " booked " << G4endl;
    }
  }

  for(G4int i=0; i<fNHisto2D; i++) {
    if(fActive2D[i]) {
      G4String id = G4String("h2")+fIds2D[i];
      fROOThisto2D[i] = new TH2D(id, fTitles2D[i], fBins2D[i], fXmin2D[i], fXmax2D[i], fBins22D[i], fXmin22D[i], fXmax22D[i]);
      G4cout << "ROOT 2D Histo " << fIds2D[i] << " " << fTitles2D[i] << " booked " << G4endl;
    }
  }
} 

void Histo::Save()
{
  G4cout << "ROOT: files writing..." << G4endl;
  fHfileROOT->Write();
  G4cout << "ROOT: files closing..." << G4endl;
  fHfileROOT->Close();
  delete fHfileROOT;
}

void Histo::Add1D(const G4String& id, const G4String& name, G4int nb, G4double x1, G4double x2)
{
  if(fVerbose > 0) {
    G4cout << "New 1dim histogram will be booked: #" << id << "  <" << name 
           << "  " << nb << "  " << x1 << "  " << x2 << G4endl;
  }
  fNHisto1D++;
  fActive1D.push_back(fDefaultAct);
  fBins1D.push_back(nb);
  fXmin1D.push_back(x1);
  fXmax1D.push_back(x2);
  fIds1D.push_back(id);
  fTitles1D.push_back(name);
  fROOThisto1D.push_back(0);
}

void Histo::Add2D(const G4String& id, const G4String& name, G4int nb, G4double x1, G4double x2, G4int nb2, G4double x12, G4double x22)
{
  if(fVerbose > 0) {
    G4cout << "New 2dim histogram will be booked: #" << id << "  <" << name 
           << "  " << nb << "  " << x1 << "  " << x2 << "  " << nb2 << "  " << x12 << "  " << x22 << G4endl;
  }
  fNHisto2D++;
  fActive2D.push_back(fDefaultAct);
  fBins2D.push_back(nb);
  fXmin2D.push_back(x1);
  fXmax2D.push_back(x2);
  fBins22D.push_back(nb2);
  fXmin22D.push_back(x12);
  fXmax22D.push_back(x22);
  fIds2D.push_back(id);
  fTitles2D.push_back(name);
  fROOThisto2D.push_back(0);
}

void Histo::FillHisto(G4int i, G4double x, G4double w)
{
  if(fVerbose > 1) {
    G4cout << "fill 1dim histogram: #" << i << " at x= " << x << "  weight= " << w << G4endl;   
  }
  
  if(i>=0 && i<fNHisto1D) {
    fROOThisto1D[i]->Fill(x,w);
  } else {
    G4cout << "Histo::fill: WARNING! wrong ROOT histogram index "
           << i << G4endl;
  }
}

void Histo::FillHisto(G4int i, G4double x, G4double y, G4double w)
{
  if(fVerbose > 1) {
    G4cout << "fill 2dim histogram: #" << i 
	   << " at x= " << x << " at y= " << y << "  weight= " << w << G4endl;
  }
  
  if(i>=0 && i<fNHisto2D) {
    fROOThisto2D[i]->Fill(x,y,w);
  } else {
    G4cout << "Histo::fill: WARNING! wrong ROOT histogram index "
           << i << G4endl;
  }
}

void Histo::SetFileName(const G4String& nam) 
{
  fHistName = nam;
}

const G4String& Histo::GetFileName() const
{
  return fHistName;
}

void Histo::SetFileType(const G4String& nam) 
{
  fHistType = nam;
}

const G4String& Histo::FileType() const
{
  return fHistType;
}


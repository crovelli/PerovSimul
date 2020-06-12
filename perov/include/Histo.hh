#ifndef Histo_h
#define Histo_h 1

#include "globals.hh"
#include <vector>

// Root classes
class TFile;
class TH1D;
class TH2D;
class TNtuple;

class Histo
{

public:
  Histo();

  ~Histo();

  void Book();
  void Save();

  void Add1D(const G4String&, const G4String&, G4int nb=100, G4double x1=0., G4double x2=1.);
  void Add2D(const G4String&, const G4String&, G4int nb=100, G4double x1=0., G4double x2=1., G4int nb2=100, G4double x12=0., G4double x22=1.);

  void FillHisto(G4int, G4double, G4double);
  void FillHisto(G4int, G4double, G4double, G4double);

  void SetFileName(const G4String&);
  const G4String& GetFileName() const;  

  void SetFileType(const G4String&);
  const G4String& FileType() const;
  
private:
  
  G4String fHistName;
  G4String fHistType;

  G4int    fNHisto1D;
  G4int    fNHisto2D;
  G4int    fVerbose;
  G4int    fDefaultAct;

  TFile* fHfileROOT; 
  std::vector<TH1D*> fROOThisto1D;
  std::vector<TH2D*> fROOThisto2D;
  
  std::vector<G4int>     fActive1D;
  std::vector<G4int>     fBins1D;
  std::vector<G4double>  fXmin1D;
  std::vector<G4double>  fXmax1D;
  std::vector<G4String>  fIds1D;
  std::vector<G4String>  fTitles1D;

  std::vector<G4int>     fActive2D;
  std::vector<G4int>     fBins2D;
  std::vector<G4double>  fXmin2D;
  std::vector<G4double>  fXmax2D;
  std::vector<G4int>     fBins22D;
  std::vector<G4double>  fXmin22D;
  std::vector<G4double>  fXmax22D;
  std::vector<G4String>  fIds2D;
  std::vector<G4String>  fTitles2D;
};

#endif

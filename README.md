# PerovSimul

# Create your area
mkdir Perov

cd Perov

git clone git@github.com:crovelli/PerovSimul.git

cd PerovSimul

# Setup environment on lxpus
/bin/bash

[ 
  export LCGENV_PATH=/cvmfs/sft.cern.ch/lcg/releases

  /cvmfs/sft.cern.ch/lcg/releases/lcgenv/latest/lcgenv -p LCG_96 --ignore Grid x86_64-centos7-gcc8-opt Geant4 > geant4_lxplus.sh
]

source geant4_lxplus.sh

# Compile
mkdir perov_build

cd perov_build

cmake3 -DGeant4_DIR=GEANT4__HOME ../perov

make

# Run w/o visualization
./perov run.in

# Run with visualization
./perov visandrun.mac


# ----------------------------------------------------------
# A few Geant examples:
/cvmfs/geant4.cern.ch/geant4/10.5/x86_64-centos7-gcc8-opt/share/Geant4-10.5.0/examples

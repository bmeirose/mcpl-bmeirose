Instructions to implement the MCPL file in the Geant simulation:

1) Take the content of the files in G4MCPL and add to the code as follows:

- G4MCPLGenerator.cc, G4MCPLWriter.cc and mcpl.c should be copied to /nnbar-calo-sim-master/src
- G4MCPLGenerator.hh, G4MCPLWriter.hh and mcpl.h should be copied to nnbar-calo-sim-master/include

2) Files to change in order to use MCPL external source:

- CMakeLists.txt - check the modified file, search for "# MCPL libraries"

- nnbar-calo-sim.cc: look for "MCPL file", and note the following: 

  a) All the MCPL imports are added:
      #include "G4MCPLGenerator.hh"
      #include "G4MCPLWriter.hh"
      #include  "mcpl.h"

  b) The line "runManager->SetUserAction(new G4MCPLGenerator("myfile.mcpl"));" calls "myfile.mcpl" file, which
     should be copied to /nnbar-calo-sim-master-build

  b) runManager->BeamOn(5700); --> this is the way to make the code run without crashing/aborting at the end. The number
     in parenthesis should be, at most, the maximum number of particles contained in myfile.mcpl
     This is because one cannot request to simulate more particles than available in the MCPL file, see the documentation:
     https://mctools.github.io/mcpl/hooks_geant4/ :
     "if the MCPL file runs out of particles (which it will eventually if Geant4 
     is requested to simulate more events than there are particles in the MCPL file), the G4MCPLGenerator will graciously request the
     G4RunManager to abort the simulation"



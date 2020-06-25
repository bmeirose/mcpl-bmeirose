# Contents of MCPL directory

This directory is a collection of useful MCPL codes for NNBAR. For MCPL see: https://mctools.github.io/mcpl/
For the two executable files (signal2mcpl and pymcpltool) run first:

$ chmod 777 pymcpltool
$ chmod 777 signal2mcpl (or alternatively, compile it locally)

List of files:

1) signal2mcpl: converts the signal file "nbar_C_dat_100k_McStas_converted.dat" to "nbar_C_dat_100k_McStas_converted.mcpl"
2) pymcpltool: this is the MCPL tool with which you can check any MCPL file
3) mcpl.c and mcpl.h: MCPL files take from: https://github.com/mctools/mcpl
4) nbar_C_dat_100k_McStas_converted.mcpl: MCPL signal file generated by signal2mcpl 

Some useful quick MCPL tips (taken from the MCPL documentation):

- ./pymcpltool --stats --> statistical information about the MCPL file
- ./pymcpltool myfile.mcpl --> default check of MCPL files, shows first 10 particles by default
- ./pymcpltoll -l100 myfile.mcpl --> to check 100 particles, change number for more particles
- ./pymcpltool --stats --pdf myfile.mcpl --> MCPL makes plots of all quantities (needs python library matplotlib)
- ./pymcpltool --stats --gui myfile.mcpl --> MCPL makes plots of all quantities and show then in a GUI (needs python library matplotlib)


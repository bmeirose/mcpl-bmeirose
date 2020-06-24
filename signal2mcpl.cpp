// Converts NNBAR signal file to mcpl file
// author: B. Meirose
// Dependencies: mcpl.c, mcpl.h
//Usage: Compile: g++ -o signal2mcpl signal2mcpl.cpp mcpl.c ; 
//Run:./signal2mcpl
#include "mcpl.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
void convert2mcpl()
{
  ifstream in;

  // File data.txt in local directory
  in.open("/home/bmeirose/DATA/nbar_C_dat_100k_McStas_converted.dat", ios::in); // signal file - has 11 columns of float data

  // Variables in file
  float get_eventNumber, get_weight, get_x, get_y, get_z, get_vx, get_vy, get_vz, get_KE, get_time, get_spin_x, get_spin_y, get_spin_z;
  
  //Variables created
  float get_modulus;
  float get_unit;

   // Initilize variables
   float direction[3] = {0,0,0};
   float polarisation[3] = {0,0,0};
   float position[3] = {0,0,0};
   float ekin = 0.;
   float time = 0.;
   float weight = 0.;
   //unsigned long long pdgcode, get_PDG = 0;
   int pdgcode, get_PDG = 0;

    // Start mcpl conversion (see: https://mctools.github.io/mcpl/usage_c/#creating-mcpl-files)
    mcpl_outfile_t f = mcpl_create_outfile("nbar_C_dat_100k_McStas_converted.mcpl");
    mcpl_hdr_set_srcname(f,"nbar_C_dat_100k_McStas_converted.dat");
    mcpl_particle_t * p = mcpl_get_empty_particle(f);
    mcpl_hdr_add_comment(f,"NNBAR signal events (after annihilation)");
    mcpl_enable_polarisation(f);

   while (1)  // infinite loop
   {
      // Read data poinst from file
      in >> get_eventNumber >> get_PDG >> get_weight >> get_x >> get_y >> get_z >> get_vx >> get_vy >> get_vz >> get_KE >> get_time 
      >> get_spin_x >> get_spin_y >> get_spin_z;

      if (!in.good()) break;

      // Positions:
      get_x=get_x*100; // converting to cm
      get_y=get_y*100; // converting to cm
      get_z=get_z*100; // converting to cm

      // Time:
      get_time = get_time*1.0e3; // converting time to milliseconds

      // Neutron Energy in MeV:
      //get_energy = 0.83746*1.0e-27*(pow(get_vx,2)+pow(get_vy,2)+pow(get_vz,2))*6.242*1.0e12;

      // Unit vectors in all directions:
      get_modulus = sqrt(pow(get_vx,2)+pow(get_vy,2)+pow(get_vz,2));
      //if (get_modulus != 0){
      get_vx=get_vx/get_modulus;  
      get_vy=get_vy/get_modulus;
      get_vz=get_vz/get_modulus;
      //}
     
      /*
      Tune file options or add custom comments or
      binary data into the header:

      mcpl_enable_userflags(f);
      mcpl_enable_doubleprec(f);
      mcpl_enable_universal_pdgcode(f,myglobalpdgcode);
      mcpl_enable_universal_weight(f,myglobalweight);
      mcpl_hdr_add_comment(f,"Some comment.");
      mcpl_hdr_add_data(f,"mydatakey",
                       my_datalength, my_databuf)
      **/

      p->direction[0] = get_vx;
      p->direction[1] = get_vy;
      p->direction[2] = get_vz;
      p->position[0]=get_x;
      p->position[1]=get_y;
      p->position[2]=get_z;
      /*
      if(get_PDG > 10000000){   
      cout << fixed << " get_PDG = " << get_PDG << endl;}
      */
      p->ekin=get_KE;
      p->time=get_time;
      p->pdgcode=get_PDG;
      p->weight=get_weight;
      //p->userflags;
      p->polarisation[0]=get_spin_x;
      p->polarisation[1]=get_spin_y;
      p->polarisation[2]=get_spin_z;

    mcpl_add_particle(f,p); 
   } //end of while loop
 mcpl_close_outfile(f);

}// close function

int main() {
  convert2mcpl();
  return 0;
}

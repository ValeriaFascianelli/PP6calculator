#include "PP6Day4Menu.hpp"

#include <iostream>

#include "ReadParticleDataBase.hpp"
#include "SorterVector.hpp"
#include "ParticleDataBase.hpp"
#include "SorterInvMass.hpp"
#include "GetNumber.hpp"

void PP6Day4Menu(){
    
  std::cout << "Enter one choice" << std::endl;
  std::cout << "1. Print on screen the content of particle data base" << std::endl;
  std::cout << "2. Explore particle database through particle name" <<std::endl;
  std::cout << "3. Sorter an array storing random numbers" << std::endl;
  std::cout << "4. Sorter the 10 largest masses from observed_particle.dat file" << std::endl;
  
  int choice;
  choice = GetNumber();
  
  if (choice == 1){ReadParticleDataBase();} // it prints the content of the pdg.dat file on the screen
  
  if(choice == 2){ParticleDataBase();}      // it creates a database through CParticleInfo class
  
  if (choice == 3){SorterVector();}         // it creates a vector storing 10 random numbers and it is sorted at the end

  if (choice == 4) {SorterInvMass();}      // read the observed_particle.dat and it shows the 10 largest invariant masses between mu+ mu-
}

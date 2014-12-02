#include "ParticleDataBase.hpp"

#include <iostream>

#include "CParticleInfo.hpp"
#include "GetNumber.hpp"


void ParticleDataBase(){
  
  std:: cout << "Enter the name of the particle: " << std::endl;
  std:: cout << "1. Particle name" << std::endl;  
  
  std::string name;
  std::cin >> name;
  
  CParticleInfo particle("pdg.dat.txt");

  int PDG = particle.getPDGCode(name);
  
  std::cout << "Enter the information you want to get: " << std::endl;
  std::cout << "1. Mass" << std::endl;
  std::cout << "2. Charge" << std::endl;
  std::cout << "3. PDG Code" << std::endl;
  
  int info;
  info = GetNumber<int>();
  
  if (info == 1){
    double Mass = particle.getMassGeV(PDG);
    std::cout << "The mass of the particle is " << Mass << " GeV" <<std::endl;
  }
  if (info == 2){
    int Charge = particle.getCharge(PDG);
    std::cout << "The charge of the particle is " << Charge << std::endl;
  }
  if (info == 3){
    std::cout << "The PDG code of the particle is " << PDG << std::endl;
  }
  return;
}

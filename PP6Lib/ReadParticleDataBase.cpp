#include "ReadParticleDataBase.hpp"

#include <iostream>
#include <vector>

#include "FileReader.hpp"


void ReadParticleDataBase(){

  FileReader f("pdg.dat.txt");
  
  std::vector<std::string> ParticleName;
  std::vector<int> ParticlePdg;
  std::vector<int> ParticleCharge;
  std::vector<double> ParticleMass;
  
  if (f.isValid()) {
    std::cout << "File open!" << std::endl;
    
    // Loop until out of lines
    while (f.nextLine()) {
      
      std::string particle = f.getField<std::string>(1);
      int pdgCode = f.getField<int>(2);
      int charge = f.getField<int>(3);
      double massGeV = f.getField<double>(4);
      
      ParticleName.push_back(particle);
      ParticlePdg.push_back(pdgCode);
      ParticleCharge.push_back(charge);
      ParticleMass.push_back(massGeV);
      
      // Check that input is o.k.
      if (f.inputFailed()) break;
    }
  }
  
  int nElements = ParticleName.size();
  
  std::vector<std::string>::iterator iterName = ParticleName.begin();
  std::vector<int>::iterator iterPDG = ParticlePdg.begin();
  std::vector<int>::iterator iterCharge = ParticleCharge.begin();
  std::vector<double>::iterator iterMass = ParticleMass.begin();
  
  std:: cout << "Size of DataBase " << nElements << "  particles stored" << std::endl;

  int i = 0;
  while ( i < nElements){
    std:: cout << "Particle Name:  "<< *iterName << " PDG Code:  "<< *iterPDG <<"  Charge:  " << *iterCharge<< " Mass  " << *iterMass<<   std::endl;
    ++iterName;
    ++iterPDG;
    ++iterCharge;
    ++iterMass;
    ++i;
  }
  return;
}

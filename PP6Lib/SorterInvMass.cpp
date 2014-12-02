#include "SorterInvMass.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

#include "CParticle.hpp"
#include "CParticleInfo.hpp"
#include "Math.hpp"

void SorterInvMass(){

  int muP = 0;
  int muM = 0;
  
  //Create an array of CParticle object
  
  CParticle* muPlus = new CParticle[1000];
  CParticle* muMinus = new CParticle[1000];
  
  CParticleInfo particle("pdg.dat.txt");

  int PDGCodeMuPlus = particle.getPDGCode("mu+");
  int PDGCodeMuMinus = particle.getPDGCode("mu-");
  double massMuPlus = particle.getMassGeV(PDGCodeMuPlus);
  double massMuMinus = particle.getMassGeV(PDGCodeMuMinus);
  
  
  // Open data file
  FileReader f("observedparticles.txt");
  
  if (f.isValid()) {
    std::cout << "File open!" << std::endl;

    // Loop until out of lines
    while (f.nextLine()) {
      std::string particle = f.getField<std::string>(2);
      std::string run = f.getField<std::string>(6);
      
      // Read and set particle momentum from data file
      // The T component of the CParticle object stores the event number read from data file
      
      if (particle == "mu+" && run == "run4.dat"){
	muPlus[muP].SetXMomentum(f.getField<double>(3)); // px
	muPlus[muP].SetYMomentum(f.getField<double>(4)); // py
	muPlus[muP].SetZMomentum(f.getField<double>(5)); // pz
	muPlus[muP].SetTMomentum(f.getField<double>(1)); // event
	muP++;
      }
      
      if (particle == "mu-" && run == "run4.dat"){
	muMinus[muM].SetXMomentum(f.getField<double>(3)); // px
	muMinus[muM].SetYMomentum(f.getField<double>(4)); // py
	muMinus[muM].SetZMomentum(f.getField<double>(5)); // pz
	muMinus[muM].SetTMomentum(f.getField<double>(1)); // event
	muM++;
      }
      // Check that input is o.k.
      if (f.inputFailed()) break;
    }
  }
  
  double pMuPlus;
  double pMuMinus;
  std::vector<double> invMass;
  
  for (int i = 0; i < muP; i++){ // loop over mu+
    for(int j = 0; j < muM; j++){  // loop over mu-
      pMuPlus = muPlus[i].GetMagMomentum();
      pMuMinus = muMinus[j].GetMagMomentum();
      invMass.push_back(InvMass(massMuPlus, massMuMinus, pMuPlus, pMuMinus));
    }
  }
  
  std::sort(invMass.begin(), invMass.end());
  std::reverse(invMass.begin(), invMass.end());
  std::copy(invMass.begin(), invMass.end(), std::ostream_iterator<double>(std::cout, "\n"));
  
  for (int i = 0; i < 1000; i++){
    muPlus[i].~CParticle();
    muMinus[i].~CParticle();
  }
  return;
}

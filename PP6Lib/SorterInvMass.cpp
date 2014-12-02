#include "SorterInvMass.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

#include "CParticle.hpp"
#include "CParticleInfo.hpp"
#include "Math.hpp"

void SorterInvMass(){

  // Create a vector of CParticle object

  std::vector<CParticle> muPlus;
  std::vector<CParticle> muMinus;

  CParticleInfo particle ("pdg.dat.txt");

  int PDGCodeMuPlus = particle.getPDGCode("mu+");
  int PDGCodeMuMinus = particle.getPDGCode("mu-");
  double massMuPlus = particle.getMassGeV(PDGCodeMuPlus);
  double massMuMinus = particle.getMassGeV(PDGCodeMuMinus);
  
  CParticle MuPlus;
  CParticle MuMinus;
  
  // Open data file
  FileReader f("observedparticles.txt");
  
  if (f.isValid()) {
    std::cout << "File open!" << std::endl;

    // Loop until out of lines
    while (f.nextLine()) {
      std::string Particle = f.getField<std::string>(2);
      std::string run = f.getField<std::string>(6);
      
      // Read and set particle momentum from data file
      // The T component of the CParticle object stores the event number read from data file
      
      if (Particle == "mu+" && run == "run4.dat"){
	
	MuPlus.SetXMomentum(f.getField<double>(3)); // px
	MuPlus.SetYMomentum(f.getField<double>(4)); // py
	MuPlus.SetZMomentum(f.getField<double>(5)); // pz
	MuPlus.SetTMomentum(f.getField<double>(1)); // event
	
	muPlus.push_back(MuPlus);
	
      }
      
      if (Particle == "mu-" && run == "run4.dat"){

	MuMinus.SetXMomentum(f.getField<double>(3)); // px
	MuMinus.SetYMomentum(f.getField<double>(4)); // py
	MuMinus.SetZMomentum(f.getField<double>(5)); // pz
	MuMinus.SetTMomentum(f.getField<double>(1)); // event
	
	muMinus.push_back(MuMinus);
      }
      // Check that input is o.k.
      if (f.inputFailed()) break;
    }
  }
  
  double pMuPlus;
  double pMuMinus;
  std::vector<double> invMass;
  int muP = muPlus.size();
  int muM = muMinus.size();

  for (int i = 0; i < muP; i++){ // loop over mu+
    for(int j = 0; j < muM; j++){  // loop over mu-
      pMuPlus = muPlus.at(i).GetMagMomentum();
      pMuMinus = muMinus.at(j).GetMagMomentum();
      invMass.push_back(InvMass(massMuPlus, massMuMinus, pMuPlus, pMuMinus));
    }
  }
  
  std::sort(invMass.begin(), invMass.end());
  std::reverse(invMass.begin(), invMass.end());
  std::copy(invMass.begin(), invMass.end(), std::ostream_iterator<double>(std::cout, "\n"));
  
  return;
}

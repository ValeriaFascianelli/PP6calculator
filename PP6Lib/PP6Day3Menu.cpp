#include "PP6Day3Menu.hpp"

#include <iostream>
#include <cmath>

#include "CFourVector.hpp"
#include "CThreeVector.hpp"
#include "CParticle.hpp"
#include "GetChar.hpp"
#include "GetNumber.hpp"
#include "FileReader.hpp"
#include "Math.hpp"

void PP6Day3Menu(){

  while(true){
    std::cout << "Enter a choice: "<<std::endl;
    std::cout << "1. Compute the interval of a 4 vector"<<std::endl;
    std::cout << "2. Compute a Lorentz boost along z axis"<<std::endl;
    std::cout << "3. Sorting the 10 largest masses from Day2Menu"<<std::endl;
    std::cout << "q .Quite"<<std::endl;
    std::cout << "<<";
    
    char choice;
    choice = GetChar();
    if (choice == 'q') break;
    if(choice == '1'|| choice == '2'){
      double a, b, c, d;
      std::cout << "Enter the time component of the 4 vector"<<std::endl;
      a = GetNumber();
      std::cout << "Enter the x component of the 4 vector"<<std::endl;
      b = GetNumber();
      std::cout << "Enter the y component of the 4 vector"<<std::endl;
      c = GetNumber();
      std::cout << "Enter the z component of the 4 vector"<<std::endl;
      d = GetNumber();
      
      CFourVector vector;
      
      vector.SetT(a);
      vector.SetX(b);
      vector.SetY(c);
      vector.SetZ(d);
      
      if(choice == '1'){
	double interval = vector.GetInterval();
	std::cout << "The interval is: " << interval << std::endl; 
      }
      if (choice =='2'){
	double velocity;
	std::cout << "Enter the velocity of the particle:" << std::endl;
	velocity = GetNumber();
	while (velocity >= 1){
	  std::cout << "The velocity must be less then 1, enter again:"<<std::endl;
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  std::cin >> velocity;
	}
	vector.BoostZ(velocity);
	std::cout << "The time component after Lorentz boost is: "<< vector.GetT() <<std::endl;
	std::cout << "The x component after Lorentz boost is: "<< vector.GetX() <<std::endl;
	std::cout << "The y component after Lorentz boost is: "<< vector.GetY() <<std::endl;
	std::cout << "The z component after Lorentz boost is: "<< vector.GetZ() <<std::endl;
      }
    }
    if (choice == '3'){
      
      int muP = 0;
      int muM = 0;

      //Create an array of CParticle object

      CParticle* muPlus = new CParticle[1000];
      CParticle* muMinus = new CParticle[1000];
      
      // Set the mass of muon parrticle
      
      for(int i = 0; i < 1000; i++){
	muPlus[i].SetMassGeV(0.105658); // from PDG
	muMinus[i].SetMassGeV(0.105658); 
      }
      
      // Open data file
      FileReader f("observedparticles.txt");
      
      if (f.isValid()) {
	std::cout << "File open!" << std::endl;
	// Loop until out of lines
	while (f.nextLine()) {
	  std::string particle = f.getFieldAsString(2);
	  std::string run = f.getFieldAsString(6);

	  // Read and set particle momentum from data file
	  // The T component of the CParticle object stores the event number read from data file

	  if (particle == "mu+" && run == "run4.dat"){
	    muPlus[muP].SetXMomentum(f.getFieldAsDouble(3)); // px
	    muPlus[muP].SetYMomentum(f.getFieldAsDouble(4)); // py
	    muPlus[muP].SetZMomentum(f.getFieldAsDouble(5)); // pz
	    muPlus[muP].SetTMomentum(f.getFieldAsDouble(1)); // event
	    muP++;
	  }

	   if (particle == "mu-" && run == "run4.dat"){
	    muMinus[muM].SetXMomentum(f.getFieldAsDouble(3)); // px
	    muMinus[muM].SetYMomentum(f.getFieldAsDouble(4)); // py
	    muMinus[muM].SetZMomentum(f.getFieldAsDouble(5)); // pz
	    muMinus[muM].SetTMomentum(f.getFieldAsDouble(1)); // event
	    muM++;
	  }
	   // Check that input is o.k.
	   if (f.inputFailed()) break;
	}
      }
      //std::cout << muPlus[0].GetTMomentum()<<std::endl;
      // Compute the invariant mass for each pair of mu+/mu- [GeV]
      // Using the InvMass function stored in Math.cppx
      
      int k = 0;
      double pMuPlus;
      double pMuMinus;
      int dim = muP*muM;
      double* invMass = new double[dim]; 
      double** event = new double*[dim];
      int* Index = new int[dim];
      
      for (int i = 0; i < dim; i++){
	event[i] = new double[2];
	Index[i] = 0;
      }

      for (int i = 0; i < muP; i++){ // loop over mu+
	for(int j = 0; j < muM; j++){  // loop over mu-
	  pMuPlus = muPlus[i].GetMagMomentum();
	  pMuMinus = muMinus[j].GetMagMomentum();
	  // std::cout << "ciao"<<std::endl;
	  invMass[k] = sqrt(InvMass(muPlus[i].GetMassGeV(), muMinus[j].GetMassGeV(), pMuPlus, pMuMinus));
	  //std::cout << "ciao"<<std::endl;
	  event[k][0] = muPlus[i].GetTMomentum();
	  //std::cout << "ciao"<<std::endl;
	  event[k][1] = muMinus[j].GetTMomentum();
	  k++;
	}
      }
      //std::cout << "ciao"<<std::endl;
      Sorter(dim,invMass,Index);
      //std::cout << "ciao"<<std::endl;
      std::cout << "The 10 highest invariant masses and their associated mu+/mu- event pairs are:" <<std::endl;
      for (int i = 0; i < 10; i++){
	std::cout <<i<< ". " << "Invariant mass = " << invMass[i] << " from mu+/mu- event pairs: " << event[Index[i]][0] << " mu+ event and " << event[Index[i]][1] << " mu- event"<<std::endl;
      }
      delete[] invMass;
      delete[] event;
      delete[] Index;

      for (int i = 0; i < 1000; i++){
	muPlus[i].~CParticle();
	muMinus[i].~CParticle();
      }
    }
  }
  return;
}

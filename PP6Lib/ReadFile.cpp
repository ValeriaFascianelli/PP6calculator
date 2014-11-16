#include <iostream>
#include <cmath>

#include "FileReader.hpp"
#include "Math.hpp"

// Open the file to be read
void ReadFile(){
 
  int muP = 0;
  int muM = 0;

  double muonMass = 0.105658; // [GeV] form PDG

  double** muPlus = new double*[1000];
  double** muMinus = new double*[1000];
  
  

  for (int y = 0; y < 1000; y++){
    muPlus[y] = new double[4];
  }

  for (int y = 0; y < 1000; y++){
    muMinus[y] = new double[4];
  }
  
 
  FileReader f("observedparticles.txt");
  
  // Only process if the file is open/valid
  
  if (f.isValid()) {
    std::cout << "File open!" << std::endl;
    // Loop until out of lines
    while (f.nextLine()) {
      
      // Fields in each line line are treated as whitespace separated
      // and counted from 1. Fields can be retrieved as one of four main
      // types
      
      // retrieve field 1 of current line as an integer
      //int a = f.getFieldAsInt(1);
      
      // retrieve field 2 as a float
      //float b = f.getFieldAsFloat(2);
      
      // retrieve field 3 as a double
      //double c = f.getFieldAsDouble(3);
      
      // retrieve field 4 as a float
      std::string particle = f.getFieldAsString(2);
      std::string run = f.getFieldAsString(6);
     
      // if (particle == "mu+" && run == "run4.dat"){std::cout << particle << " " << run << std::endl;}
      if (particle == "mu+" && run == "run4.dat"){
	muPlus[muP][0] = f.getFieldAsDouble(3); // p_x
	muPlus[muP][1] = f.getFieldAsDouble(4); //p_y
	muPlus[muP][2] = f.getFieldAsDouble(5); //p_z
	muPlus[muP][3] = f.getFieldAsDouble(1); //event
	muP++;
      }
     
      
      if (particle == "mu-" && run == "run4.dat"){
	muMinus[muM][0] = f.getFieldAsDouble(3);
	muMinus[muM][1] = f.getFieldAsDouble(4);
	muMinus[muM][2] = f.getFieldAsDouble(5);
	muMinus[muM][3] = f.getFieldAsDouble(1);
	muM++;
      } 
      // Check that input is o.k.
      if (f.inputFailed()) break;
    }
  }
 

  // Compute the invariant mass for each pair of mu+/mu- [GeV]
  // Using the InvMass function stored in Math.cpp

  double pMuPlus;
  double pMuMinus;
  int dim = muP*muM;
  int k = 0;
  double* invMass = new double[dim]; 
  double** event = new double*[dim];
  
  int* Index = new int[dim];

  for (int i = 0; i < dim; i++){
    event[i] = new double[2];
    Index[i] = 0;
  }

  for (int i = 0; i < muP; i++){ // loop over mu+
    for(int j = 0; j < muM; j++){  // loop over mu-
     
	pMuPlus = sqrt(muPlus[i][0]*muPlus[i][0]+muPlus[i][1]*muPlus[i][1]+muPlus[i][2]*muPlus[i][2]);
	pMuMinus = sqrt(muMinus[j][0]*muMinus[j][0]+muMinus[j][1]*muMinus[j][1]+muMinus[j][2]*muMinus[j][2]);
	invMass[k] = sqrt(InvMass(muonMass, muonMass, pMuPlus, pMuMinus));
	event[k][0] = 	muPlus[i][3];
	event[k][1] = 	muMinus[j][3];
	//std::cout << k << " Invariant " << invMass[k] << std::endl;
	k++;
	
    }
  }
  
  swapVect(dim,invMass,Index);
  std::cout << "The 10 highest invariant masses and their associated mu+/mu- event pairs are:" <<std::endl;

  
  for (int i = 0; i < 10; i++){
    std::cout <<i<< ". " << "Invariant mass = " << invMass[i] << " from mu+/mu- event pairs: " << event[Index[i]][0] << " mu+ event and " << event[Index[i]][1] << " mu- event"<<std::endl;
  }
  
  return;
}


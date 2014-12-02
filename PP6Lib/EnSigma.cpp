#include <iostream>
#include <cmath>
#include <cstdlib>

#include "Physics.hpp"
#include "Math.hpp"
#include "GetNumber.hpp"

void EnSigma(){
  
  int dim;
  std::cout << "Enter how many mass values you want to generate: "<< std::endl;
  dim = GetNumber<int>();
  double* MassArray = Mass(dim); 
  double* MomentumArray = Momentum(dim);
  double* EnergyArray =  Energy(dim, MassArray, MomentumArray);
  double E = MeanEnergy(dim, EnergyArray); 
  double sigmaE = StanDev(dim, EnergyArray, E);

  std:: cout << "The mean energy is " << E << " and its standard deviation is " << sigmaE<< std::endl;
 
  return ;
}




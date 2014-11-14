#include <iostream>
#include <cmath>
#include <cstdlib>

#include "Physics.hpp"
#include "Math.hpp"

void EnSigma(){
  
  using namespace std;

  int dim = 100;
  double* MassArray;
  MassArray = new double[dim];
  double* MomentumArray;
  MomentumArray = new double[dim];
  double* EnergyArray;
  EnergyArray = new double[dim];
  double E;
  double sigmaE;

  Mass(MassArray);
  Momentum(MomentumArray);
  Energy(MomentumArray, MassArray, EnergyArray);
  E = MeanEnergy(EnergyArray); 
  sigmaE = StanDev(EnergyArray, E);

  cout << "The mean energy is " << E << " and its standard deviation is " << sigmaE<< endl;
 
  return ;
}




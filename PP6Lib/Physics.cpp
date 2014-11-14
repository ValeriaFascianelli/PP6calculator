#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>

#include "Physics.hpp"
#include "Math.hpp"

void Mass (double* MassArray){

  int dim = 100;

  srand (time(NULL));
  
  for (int i = 0; i < dim; i++){
    MassArray[i] = rand()%100;
  }
  
  return;
}

void Momentum (double* MomentumArray){

  int dim = 100;
  int i = 0;
  double px;
  double py;
  double pz;
  double p;

  srand (time(NULL));
  
  while (i<100){
    px = rand()%100;
    py = rand()%100;
    pz = rand()%100;
    p = sqrt(px*px + py*py + pz*pz);
    MomentumArray[i] = p;
    i++;
  }

  return;
}

void Energy (double* MomentumArray, double* MassArray, double* EnergyArray){

  int dim = 100;
  //std::cout << MomentumArray[56]<< std::endl;
  for (int i = 0; i < dim; i ++){
    EnergyArray[i] = sqrt(MomentumArray[i]*MomentumArray[i] + MassArray[i]*MassArray[i]);
  }

  return ;
}

double MeanEnergy(double* EnergyArray){
 
  int dim = 100;
  double E = 0;
 
  for (int i = 0; i < dim; i++){
    E += EnergyArray[i];
  }

  E = E/dim;
  
  return E;
}

double StanDev(double* EnergyArray, double E){

  double a = 0;
  double SD;
  int dim = 100;

  for (int j = 0; j < dim; j++){
    a += (EnergyArray[j]-E)*(EnergyArray[j]-E); 
  }
  
  SD = sqrt(a/dim);

  return SD;
}


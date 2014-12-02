#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <random>

#include "Physics.hpp"
#include "Math.hpp"
#include "GetNumber.hpp"

double* Mass (int dim){ //, double* MassArray){

  // srand (time(NULL));
  std::uniform_real_distribution<double>dist(0,100);
  std::random_device rseed;
  std::mt19937 rgen(rseed()); // mersenne_twister
  double* MassArray = new double[dim];
  //double* MassArray = Mass;
  
  for (int i = 0; i < dim; i++){
    MassArray[i] = dist(rgen);//std::uniform_int_distribution<int>(0,100); // [0,100]
  }
  
  return MassArray;
  delete [] MassArray; 
}

double* Momentum (int dim){
  
  int i = 0;
  double px;
  double py;
  double pz;
  double p;
  double* MomentumArray = new double[dim];
  srand (time(NULL));
  
  while (i<dim){
    px = rand()%dim;
    py = rand()%dim;
    pz = rand()%dim;
    p = sqrt(px*px + py*py + pz*pz);
    MomentumArray[i] = p;
    i++;
  }

  return MomentumArray;
  delete [] MomentumArray;
}

double* Energy (int dim, double* MassArray, double* MomentumArray){

  double* EnergyArray = new double[dim];
  for (int i = 0; i < dim; i ++){
    EnergyArray[i] = sqrt(MomentumArray[i]*MomentumArray[i] + MassArray[i]*MassArray[i]);
  }

  return EnergyArray;
  delete [] EnergyArray;
}

double MeanEnergy(int dim, double* EnergyArray){
    
  double E = 0;
 
  for (int i = 0; i < dim; i++){
    E += EnergyArray[i];
  }

  E = E/dim;
  
  return E;
}

double StanDev(int dim, double* EnergyArray, double E){

  double a = 0;
  double SD;

  for (int j = 0; j < dim; j++){
    a += (EnergyArray[j]-E)*(EnergyArray[j]-E); 
  }
  
  SD = sqrt(a/dim);

  return SD;
}

void boostZ(double* vect, double* boost, double speed){
  
  double beta = speed;
  double gamma = 1./(sqrt(1-(beta*beta)));
  
  boost[0] = gamma*(vect[0]-beta*vect[3]); // vect[0] = t vect[1] = x vect[2] = y vect[3] = z
  boost[1] = vect[1];
  boost[2] = vect[2];
  boost[3] = gamma*(vect[3]-beta*vect[0]);
  
  return;
}

double Interval(double* boost){
  double interval;
  interval = sqrt(boost[0]*boost[0]-boost[1]*boost[1]-boost[2]*boost[2]-boost[3]*boost[3]);
  
  return interval;
}

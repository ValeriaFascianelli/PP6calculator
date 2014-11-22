#ifndef ENSIGMA_PHYSICS_HH
#define ENSIGMA_PHYSICS_HH

//- Physics 

//***************************************************************************************************************************************************************************//
//The Physics functions compute some physics quantity, in detail:
//1. Mass:      it fills an array of dim-dimension with random-mass values;
//              it requires as input the number of the mass to be created and the pointer to the array to be filled.
//2. Momentum:  it fills an array of dim-dimension with random-momentum values;
//              it requires as input the number of the momentum to be created and the pointer to the array to be filled.
//3. Energy:    it calculates the energy of a particle;
//              it requires as input the number of the particle, the pointer to the array that stores the particle momenta and the pointer to the array that stores the particle masses.
//4. MeanEnergy:it calculate the mean of dim-energies;
//              it requires the number of energy values and a pointer to the array that stores the energy values and it returns the mean value.
//5. StanDev:   it calculates the standard deviation of the mean value;
//              it requires the number of energy values, a pointer to the array that stores the energy values and the mean-energy value. It return the standard deviation value//***************************************************************************************************************************************************************************// 





double* Mass(int dim);

double* Momentum(int dim);

double* Energy(int d, double* a, double* b);

double MeanEnergy(int b, double* a);

double StanDev(int c, double* a, double b);

void boostZ(double* a, double* b, double c);

double Interval(double* a);
#endif

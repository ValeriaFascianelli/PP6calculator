// Function declaration 

#ifndef OPERATION_MATH_HH
#define OPERATION_MATH_HH

// - Arithmetic

double Sum ( double a, double b);

double Diff ( double a, double b);

double Prod ( double a, double b);

double Div ( double a, double b);


// - Solvers
double Intercept(double a, double b);

void Equation (double a, double b, double c, double* d);
  
double Length3D (double a, double b, double c);

double Length4D (double a, double b, double c, double d);

double InvMass (double a, double b, double c, double d);

void swap(double* a);

void swapVect(int dim, double* a, int* b);

void print1 (int a, double b);

void print2 (double* a);
#endif





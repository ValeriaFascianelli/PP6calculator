// Function declaration 

#ifndef OPERATION_MATH_HH
#define OPERATION_MATH_HH

// - Arithmetic

//*************************************************************************************************************************************//
// The Arithmetic functions do basic operations, in detail:
//1. Sum :  it requires two real numbers in input and it returns the sum of them.
//2. Diff:  it requires two real numbers in input and it returns the difference between them.
//3. Prod:  it requires two real numbers in input and it returns the product of them.
//4. Div:   it requires two real numbers in input and it returns the division of them, paying attention to not divide a number by zero.
//*************************************************************************************************************************************//
double Sum ( double a, double b);

double Diff ( double a, double b);

double Prod ( double a, double b);

double Div ( double a, double b);


// - Solvers

//********************************************************************************************************************************************************************//
//The Solvers functions do some generic operation:
//1. Intercept: it calculates the intercept of a line with the x-axis;
//              it requires as input the line's slope and the y-intercept and it returns the intercept of the line on the x-axis.
//2. Equation:  it solves a quadratic equation;
//              it requires as input the quadratic coefficient, the linear coefficient and the constant coefficient.
//3. Length3D:  it calculates the length of a 3 vector;
//              it requires as input the x, y and z component of the vector and it returns its lenght.
//4. Length4D:  it calculates the length of a 4 vector;
//              it requires as input the time component,the  x, y and z component of the vector and it returns its lenght (either time-like either space-like).
//5. InvMass:    it calculates the invarian mass of two particles;
//              it requires as input the two masses of the particles, the module of the momenta of the two particles and it return their invariant mass.
//6. Swap:      it swaps two numbers;
//             
//7. Sorter:    it sorts the component of an array and it fill an array whose entries are the indices of the sorted entries in the main array;
//              it requires as input the dimension of the array to sort, the pointer to the array to sort and a pointer to an empty array in which store the indices.    
//8. print      it prints the result of some functions, in particular of these functions:Sum, Diff, Prod, Div, Intercept, Length3D, Length4D, InvMass;  
//              it requires a label to the function for which it has to print the result and the result to print itself.
//********************************************************************************************************************************************************************//
double Intercept(double a, double b);

void Equation (double a, double b, double c, double d[2]);
  
double Length3D (double a, double b, double c);

double Length4D (double a, double b, double c, double d);

double InvMass (double a, double b, double c, double d);

void Swap();

void Sorter(int dim, double* a, int* b);

void print (char a, double b);

#endif





// Standard library

#include <iostream>
#include <cmath>
#include <limits>

// Project function

#include "Math.hpp"
#include "GetNumber.hpp"

double Sum ( double a, double b){
  return a+b; 
}

double Diff ( double a, double b){
  return a-b; 
}

double Prod ( double a, double b){
  return a*b; 
}

double Div ( double a, double b){
  while (b == 0){
    std::cout << "Impossible dividing by zero!/n Give me another number:"<<std::endl;
    std::cin >> b;
    if (b != 0){break;}
    else {
      std::cin.clear(); // clear the flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::std::cin buffer
      continue;
    }
  } 
  return a/b;
}

double Intercept(double a, double b){
  return -(a/b);
}

void Equation (double a, double b, double c, double result[2]){
  while (a == 0 || b*b-4*a*c < 0){
    std::cout << "Not valid coefficients, try again/n" << std::endl;
    std::cin >> a >> b >> c;
    if (a != 0 && b*b-4*a*c > 0){break;}
    else {
      std::cin.clear(); // clear the flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
      continue;
    }
  }
  result[0] = (-b+sqrt(b*b - 4*a*c))/(2*a);
  result[1] = (-b-sqrt(b*b - 4*a*c))/(2*a);
  return;
}

double Length3D (double a, double b, double c){
  return sqrt (a*a+b*b+c*c);
}

double Length4D (double a, double b, double c, double d){
  return sqrt (d*d-a*a-b*b-c*c);
}

double InvMass (double a, double b, double c, double d){
  return sqrt(a*a + b*b + 2*sqrt(a*a + c*c)*sqrt(b*b + d*d) +2*c*d);
}

void Swap(){
  double a;
  double b;
  double temp;

  std::cout << "Enter two numbers: \n" << std::endl;
  
  a = GetNumber();
  b = GetNumber();

  temp = b;
  b = a;
  a = temp;
    
  std::cout << "The numbers swapped are " << a << " " << b << std::endl;
 return;
}

void Sorter (int dim, double* array, int* Index){
  double temp1;
  int check=0;

  double* flag = new double[dim];
 
  for (int j = 0; j < dim; j++){
    flag[j] = array[j]; //flag[j][j] = array[j];
  }
   
  while(check == 0){

    for (int i = 0; i < dim; i++){
      if (i == dim-1 && array[dim-1]<=array[dim-2]) check = 1;
      if(array[i]<array[i+1]){
	check = 0;
	break;
      }
      else{continue;}
    }
    
    for (int h = 0; h < dim; h++){
      if (array[h] < array[h+1]) {
	temp1 = array[h];
	array[h] = array[h+1];
	array[h+1] = temp1;
      }
      else continue;
    }
  }

  for(int j = 0; j < dim; j++){
        for(int h = 0; h < dim; h++){
      if(array[j] == flag[h]) Index[j] = h;
      else continue;
    }
  }
  delete[]flag;
  return;
}

void print (char choice, double result ){
  if (choice == '1') std::cout << "The result of the operation is " << result << std::endl;  
  if (choice == '2') std::cout << "The intercept of the line on the x axis is  " << result << std::endl;
  if (choice == '4') std::cout << "The length of the 3D vector is " << result << std::endl;
  if (choice == '5') std::cout << "The length of the 4D vector is " << result << std::endl;  
  if (choice == '6') std::cout << "The invariant mass is " << result << std::endl;
  return;
}



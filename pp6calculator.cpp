#include <iostream>
#include <cmath>
#include <limits>

// this project
#include "Math.hpp"
#include "operation.hpp"
#include "Physics.hpp"
#include "EnSigma.hpp"
#include "ReadFile.hpp"

int main(){

  int day;
  int a;
  double* result = new double[2];
  result[0] = 0;
  result[1] = 0;
  
  while(true){
    
    std::cout << "Hi, which exercise do you want to perform?" << std::endl; 
    std::cout << "1. Lecture 1" << std::endl;
    std::cout << "2. Lecture 2" << std::endl;
    std::cout << "0 to quite" << std::endl;
    
    std::cin >> day;
    
    if (day == 0){break;}
    if (day == 1){operation(result);}
    if (day == 2){
      while(true){
	std::cout << "What would you like to do:"<< std::endl;
	std::cout << "1. Evaluate the main energy with its standard daviation from random numbers"<<std::endl;
	std::cout << "2. Read a data file" << std::endl;
	std::cout<< "0 to quite" << std::endl;
	std::cin >> a;
	if(a == 0){break;}
	if(a == 1){EnSigma();}
	if(a == 2){ReadFile();}
      }
    }
  }
  
  std::cout << "Thank you using pp6calculator!" << std::endl;
  return 0;
 
}

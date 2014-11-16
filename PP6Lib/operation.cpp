#include <iostream>
#include <string>
#include <climits>
#include <cmath>

#include "Math.hpp"

void operation (double* result){
  
  double a;
  double b;
  double c;
  double d;
  double* x;
  
  int choice;
 
  std::string op;
  std::string sum;
  std::string diff;
  std::string prod;
  std::string div;

  int loopControl = 0;

  while(true){

    std::cout << "Choose one of the following operation, choose one number:\n"; 
    std::cout << "1. Basic Operation\n"; 
    std::cout << "2. Calculate the intercept of a line\n";
    std::cout << "3. Solve a quadratic equation\n";
    std::cout << "4. Calculate the length of 3D vectors\n";
    std::cout << "5. Calculate length of 4D vectors\n";
    std::cout << "6. Calculate the invariant mass of two particles\n";
    std::cout << "7. Swap two numbers \n";
    std::cout << "8. Swap an array of numbers \n";
    std::cout << "0 to quite \n";
    
    std::cin >> choice;
    
    while(!std::cin){
      std::cout << "Not valid choice, please try again!"<<std::endl;
      std::cin.clear(); // clear the flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::cin buffer
      continue;
    }

    if (choice == 0) break;
    if (choice == 1 || choice == 2){
      
      if (choice == 1) {std::cout << "Give me two numbers\n";}
      if (choice == 2) {std::cout << "Give me the slope and the intercept on the y-axis";} 
      
      while (loopControl == 0){
	
	std::cin >> a >> b;
	
	if (!std::cin){
	  std::cout << "Numbers not valid!"<< std::endl;
	  std::cin.clear(); // clear the flag
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::cin buffer
	  continue;
	}
	else {
	  loopControl = 1;
	}
      }
      
      if (choice == 1){ 
	while (loopControl == 1){
	  std::cout << "What operation do you want to perform: sum diff prod div?"<<std::endl;
	  std::cin >> op;
	  
	  if ((op!= "sum") && (op!= "diff") && (op!="prod") && (op!="div")){
	    std::cout << "Operation not valid!"<< std::endl;
	    std::cin.clear(); // clear the flag
	    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::cin buffer
	    continue;
	  }
	  else {
	    loopControl = 2;
	  }
	  
	  if (op == "sum"){result[0] = Sum(a,b);} 
	  if (op == "diff"){result[0] = Diff(a,b);}
	  if (op == "prod"){result[0] = Prod(a,b);}
	  if (op == "div"){
	    while (b == 0){
	      std::cout << "Impossible dividing by zero!/n Give me another slope:"<<std::endl;
	      std::cin >> b;
	      if (b != 0){break;}
	      else {
		std::cin.clear(); // clear the flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::std::cin buffer
		continue;
	      }
	    } 
	    result[0] = Div(a,b);
	  }
	}
      }
      
      if (choice == 2){result[0] = Intercept (a,b);}
    }
    
    if (choice == 3) {
      std::cout << "Give me the three coefficients of your equation\n The first coefficient must be the quadratic one, the second coefficien must be linear one and the last one must be the known term\n";
      std::cin >> a >> b >> c;
      while (a == 0 || b*b-4*a*c < 0){
	
	std::cout << "Not valid coefficients, try again/n" << std::endl;
	std::cin >> a >> b >> c;
	if (a != 0 && b*b-4*a*c > 0){break;}
	else {
	  std::cin.clear(); // clear the flag
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::std::cin buffer
	  continue;
	}
      }
      Equation (a, b, c, result); 
    }
    
    if (choice == 4) {
      std::cout << "Give me the components of your 3D vector";
      
      while (loopControl == 0){
	
	std::cin >> a >> b >> c;
	
	if (!std::cin){
	  std::cout << "Numbers not valid!"<< std::endl;
	  std::cin.clear(); // clear the flag
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::cin buffer
	  continue;
	}
	else {break;}
      }
      result[0] = Length3D (a,b,c);
    }
    
    if (choice == 5 || choice == 6){
      
      if (choice == 5) {std::cout << "Give me the four component of the 4D vector\n";}
      if (choice == 6) {std::cout << "Give me the masses and the momenta of the particles";} 
      
      while (loopControl == 0){
	
	std::cin >> a >> b >> c >> d;
	
	if (!std::cin){
	  std::cout << "Numbers not valid!"<< std::endl;
	  std::cin.clear(); // clear the flag
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::cin buffer
	  continue;
	}
	else {break;}
      }
      
      if (choice == 5){result[0] = Length4D (a,b,c,d);}
      if (choice == 6){result[0] = InvMass (a,b,c,d);}
      
    }
    
    if (choice == 7){swap(result);}
    if (choice == 8){
      
      int dim;
      
      std::cout << "Give me the number of the array's components" << std::endl;
      std::cin >> dim;
      
      double *array = new double[dim];
      int *Index = new int[dim];
      
      for (int k = 0; k < dim; k ++){
	std::cout << "Give me the components " << k << " of the array" << std::endl; 
	std::cin >> array[k];
      }
      
      swapVect (dim,array,Index);
      
      std::cout << "Array value:" << std::endl;
      for (int j = 0; j < dim; j++){
	std::cout << array[j] << std::endl;
      }
      std::cout << "Array index:" << std::endl;
      for (int j = 0; j < dim; j++){
	std::cout << Index[j] << std::endl;
      }
      
    }
    
    if ((choice != 3) && (choice!= 7) && (choice!=8)) print1 (choice, result[0]);
    if (choice == 3) print2 (result);
  }
  return;
  
}



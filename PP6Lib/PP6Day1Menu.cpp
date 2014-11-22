#include "PP6Day1Menu.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

#include "Math.hpp"
#include "GetNumber.hpp"
#include "GetChar.hpp"

void PP6Day1Menu(){
  
  double a;
  double b;
  double c;
  double d;
  double result[2];
 
  char choice('\0');
 
  // Choice one operation from Day1 
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
    std::cout << "q. Quite \n";
    std::cout << "<<" ;
    
    std::cin >> choice;
   
    if (choice == 'q') break;
    
    while((!std::cin)&&(choice!=1)&&(choice!=2)&&(choice!=3)&&(choice!=4)&&(choice!=5)&&(choice!=6)&&(choice!=7)&&(choice!=8)){
      std::cout << "Not valid choice, please try again!"<<std::endl;
      std::cin.clear(); // clear the flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
      continue;
    }

    //Choice 1: Basic operation

    if (choice == '1') {
      char op;
      while(true){
	std::cout << "Enter two numbers " << std::endl;
	a = GetNumber();
	b = GetNumber();
	std::cout << "What operation do you want to perform :"<<std::endl;
	std::cout << "1. Addition" <<std::endl;
	std::cout << "2. Subtraction" <<std::endl;
	std::cout << "3. Multiplication" <<std::endl;
	std::cout << "4. Division" <<std::endl;
	std::cout << "q. Quite"<<std::endl;
	std::cin >> op;
	if (op == 'q') break;
	while ((op!='1')&&(op!='2')&&(op!='3')&&(op!='4')){
	  std::cout<<"Not valid operation"<<std::endl;
	  std::cout<<"Please re-enter"<<std::endl;
	  std::cin.clear();
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  std::cin >> op;
	}
	if (op == '1'){
	  result[0] = Sum(a,b);
	  print(choice, result[0]);
	} 
	if (op == '2'){
	  result[0] = Diff(a,b);
	  print(choice, result[0]);
	}
	if (op == '3'){
	  result[0] = Prod(a,b);
	  print(choice, result[0]);
	}
	if (op == '4'){
	  while (b == 0){
	    std::cout << "Impossible dividing by zero!/n Enter another slope:"<<std::endl;
	    std::cin >> b;
	    if (b != 0){break;}
	    else {
	      std::cin.clear(); // clear the flag
	      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear std::std::cin buffer
	      continue;
	    }
	  }
	  result[0] = Div(a,b);
	  print (choice, result[0]);
	}
      }
    }
    // Choice 2: Evaluate the intercept of a line
    
    if (choice == '2') {
      std::cout << "Enter the slope: " <<std::endl;
      a = GetNumber();
      std::cout << "Enter the y intercept: " <<std::endl;
      b = GetNumber();
      result[0] = Intercept (a,b);
      print(choice, result[0]);
    } 

    // Choice 3: Solve a quadratic equation
    
    if (choice == '3') {
      std::cout << "Enter the quadratic coefficient: "<<std::endl;
      a = GetNumber();
      std::cout << "Enter the linear coefficient: "<<std::endl;
      b = GetNumber();
      std::cout << "Enter the constant coefficient: "<<std::endl;
      c = GetNumber();
      Equation (a, b, c, result); 
      std::cout << "The solutions of the equation are " << result[0] << " and " << result[1] <<std::endl;
    }
    
    // Choice 4: Calculate the length of a 3Dvector
    
    if (choice == '4') {
      std::cout << "Enter the first component: " <<std::endl;
      a = GetNumber();
      std::cout << "Enter the second component: " <<std::endl;
      b = GetNumber();
      std::cout << "Give me the third component: " <<std::endl;
      c = GetNumber();
      result[0] = Length3D (a,b,c);
      print(choice, result[0]);
    }
    
    // Choice 5: Calculate the length of a 4Dvector

    if (choice == '5') {
      
      std::cout << "Give me the x component: "<<std::endl;
      a = GetNumber();
      std::cout << "Give me the y component: "<<std::endl;
      b = GetNumber();
      std::cout << "Give me the z component: "<<std::endl;
      c = GetNumber();
      std::cout << "Give me the t component: "<<std::endl;
      d = GetNumber();
      result[0] = Length4D(a,b,c,d);
      print(choice, result[0]);
      
    }
    
    // Choice 6: calculate the invariant mass of 2 particles

    if (choice == '6') {
      std::cout << "Give me the mass of the first particle"<<std::endl;
      a = GetNumber();
      std::cout << "Give me the mass of the second particle"<<std::endl;
      b = GetNumber();
      std::cout << "Give me the module of the momentum of the first particle"<<std::endl;
      c = GetNumber();
      std::cout << "Give me the module of the momentum of the second particle"<<std::endl;
      d = GetNumber();
      result[0] = InvMass(a,b,c,d);
      print(choice, result[0]);
    } 
    
    //Choice 8: swap two number

    if (choice == '7'){Swap();}
    
    // Choice 9: Sort an array of number
    
    if (choice == '8'){
      
      int dim;
      
      std::cout << "Give me the number of the array's components" << std::endl;
      dim = GetNumber();
      
      double *array = new double[dim];
      int *Index = new int[dim];
      
      for (int k = 0; k < dim; k ++){
	std::cout << "Give me the components " << k << " of the array" << std::endl; 
	array[k] = GetNumber();
      }
      
      Sorter(dim,array,Index);
      
      std::cout << "Array value:" << std::endl;
      for (int j = 0; j < dim; j++){
	std::cout << array[j] << std::endl;
      }
      std::cout << "Array index:" << std::endl;
      for (int j = 0; j < dim; j++){
	std::cout << Index[j] << std::endl;
      }
    }
  }

  return;
  
}



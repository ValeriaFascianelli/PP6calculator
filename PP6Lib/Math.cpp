// Standard library

#include <iostream>
#include <cmath>
#include <limits>

// project function

#include "Math.hpp"

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
  using namespace std;

  while (b == 0){

    cout << "Impossible dividing by zero!/n Give me another number:"<<endl;
    cin >> b;
    if (b != 0){break;}
    else {
      cin.clear(); // clear the flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
      continue;
    }
  } 
  return a/b;
}

double Intercept(double a, double b){
  using namespace std;
  
  while (b == 0){
    
    cout << "Impossible dividing by zero!/n Give me another slope:"<<endl;
    cin >> b;
    if (b != 0){break;}
    else {
      cin.clear(); // clear the flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
      continue;
    }
  } 
  return -(a/b);
}

void Equation (double a, double b, double c, double* result){
 using namespace std;
 
 
 while (a == 0 || b*b-4*a*c < 0){
    
    cout << "Not valid coefficients, try again/n" << endl;
    cin >> a >> b >> c;
    if (a != 0 && b*b-4*a*c < 0){break;}
    else {
      cin.clear(); // clear the flag
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
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

 using namespace std;
 
 while (d*d-a*a-b*b-c*c < 0){
   
   cout << "Negative value under sqrt, try again/n" << endl;
   cin >> a >> b >> c >> d;
   if (d*d-a*a-b*b-c*c < 0){break;}
   else {
     cin.clear(); // clear the flag
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
     continue;
   }
 } 
 
  return sqrt (d*d-a*a-b*b-c*c);
  
}

double InvMass (double a, double b, double c, double d){
  using namespace std;
  double theta;
  
  using namespace std;
  cout << "choose the angle between two momenta" << endl;
  cin >> theta;
  
  return a*a + b*b + 2*((sqrt(a*a + c*c))*sqrt(b*b + d*d) - c*d*cos(theta)) ;
  
}

void swap(double* result){

  using namespace std;
  int a;
  int b;
  int temp;

  cout << "Give me two numbers to swap: \n" << endl;
  
  cin >> a;
  cin >> b;

  temp = b;
  b = a;
  a = temp;

  result[0] = a;
  result[1] = b;
  cout << "The numbers swapped are " << a << " " << b << endl;
 return;
}

void swapVect (int* array, int* Index){

  int dim = 5;
  int temp1;
  int pos;
  int** flag = new int*[dim];
  
  for (int j = 0; j < dim; j++){
    flag[j] = new int;
  }

  // second value is the array content
  for (int j = 0; j < dim; j++){
    flag[j][j] = array[j];
  }

  //std::cout << flag[0][0] << " "<< flag[1][1] << " "<< flag[2][2] << " "<< flag[3][3] <<std::endl;
  
   while (array[0] < array[1] || array[1] < array[2] || array[2] < array[3] || array[3] < array[4]){
    for (int h = 0; h < dim; h ++){
      if (array[h] < array[h+1]) {
	temp1 = array[h];
	//pos = h;
	array[h] = array[h+1];
	//Index[h] = h+1;
	array[h+1] = temp1;
	//Index[h+1] = pos; 
      }
      else continue;      
    }
  }
   for(int j = 0; j < dim; j++){
     for(int h = 0; h < dim; h++){
       if(array[j] == flag[h][h]) Index[j] = h;
       else continue;
     }
   }
  return;
}





void print1 (int choice, double result ){
  using namespace std;
  if (choice == 1) cout << "The result of the operation is " << result << endl;  
  if (choice == 2) cout << "The intercept of the line on the x axis is  " << result << endl;
  if (choice == 4) cout << "The length of the 3D vector is " << result << endl;
  if (choice == 5) cout << "The length of the 4D vector is " << result << endl;  
  if (choice == 6) cout << "The invariant mass is " << result << endl;
  return;
}

void print2(double* result){
  std::cout << "The solutions of the equation are " << result[0] << " and " << result[1] <<std:: endl;
  return;
}

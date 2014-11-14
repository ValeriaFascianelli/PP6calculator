#include <iostream>
#include <cmath>
#include <limits>

// this project
#include "Math.hpp"
#include "operation.hpp"
#include "Physics.hpp"
#include "EnSigma.hpp"

int main(){

  using namespace std;
  int day;
  double* result = new double[2];
  result[0] = 0;
  result[1] = 0;

  cout << "Hi, which exercise do you want to perform?" << endl; 
  cout << "1. Lecture 1" << endl;
  cout << "2. Lecture 2" << endl;
  cout << "q to quite" << endl;

  cin >> day;
  
  if (!day){return;}
  if (day == 1){operation(result);}
  if (day == 2){EnSigma();}
  
  cout << "Thank you using pp6calculator!" << endl;
  return 0;

}

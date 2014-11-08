#include <iostream>
#include <string>

int main(){

  using namespace std;
  
  double a;
  double b;
  double c;

  string operation;

  cout << "Give me two numbers\n";
  cin >> a >> b;
  cout << "what operation do you want to perform: addition subtraction product fraction ? \n"; 
  cin >> operation;
  
  if (operation != "addition" && operation != "subtraction" && operation != "product" && operation != "fraction") {
    cout << "Operation not valid, try again!\n";
    return 0;
  } 
  
  if (operation == "addition"){
    c = a+b;
  }
  
  if (operation == "subtraction"){
    c = a-b;
  }
  
  if (operation == "fraction"){
    if (b == 0) {
      cout << "Impossible dividing by zero!"<<endl;
      return 0;
    }
    c = a/b;
  }
  
  if (operation == "product"){
    c = a*b;
  }

  cout << "The result is  " << c << "\n";
  
  return 0;
}

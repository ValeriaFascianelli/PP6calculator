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
  cout << "what operation do you want to perform: sum sub prod div ? \n"; 
  cin >> operation;
  
  if (operation != "sum" && operation != "sub" && operation != "prod" && operation != "div") {
    cout << "Operation not valid, try again!\n";
    return 0;
  } 
  
  if (operation == "sum"){
    c = a+b;
  }
  
  if (operation == "sub"){
    c = a-b;
  }
  
  if (operation == "div"){
    if (b == 0) {
      cout << "Impossible dividing by zero!"<<endl;
      return 0;
    }
    c = a/b;
  }
  
  if (operation == "pro"){
    c = a*b;
  }

  cout << "The result is  " << c << "\n";
  
  return 0;
}

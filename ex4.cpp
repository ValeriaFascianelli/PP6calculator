#include <iostream>
#include <string>
#include <climits>

int main(){

  using namespace std;

  double a;
  double b;
  double c;

  string op;
  string sum;
  string diff;
  string prod;
  string div;

  int loopControl = 0;

  while (loopControl == 0){
    
   cout << "Give me the firts number\n";
   cin >> a;

   if (!cin){
     cout << "First number not valid!"<< endl;
     cin.clear(); // clear the flag
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
     continue;
   }
   else {
     loopControl = 1;
   }
  }

  while (loopControl == 1){
    cout << "What operation do you want to perform: sum diff prod div?\n";    
    cin >> op;
    
    if(op != "sum" && op != "diff" && op != "prod" && op != "div"){
      cout << "Operation not valid, try again!"<<endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
      loopControl == 1;
      continue;
    }
    else{
      loopControl = 2;
    }
  }

 while (loopControl == 2){
    
   cout << "Give me the second number\n";
   cin >> b;

   if (!cin || (op == "div" && b == 0 )){
     cout << "Second number not valid!"<< endl;
     cin.clear(); // clear the flag
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear cin buffer
     continue;
   }  
   else {
     loopControl = 3;
   }
  }

  if (op == "sum"){c = a+b;}
  if (op == "diff"){c = a-b;}
  if (op == "prod"){c = a*b;}
  if (op == "div"){c = a/b;}
  
  
  cout << "The result is  "<< c << endl;
  
}

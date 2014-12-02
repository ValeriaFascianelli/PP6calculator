#include <iostream>
#include <cmath>
#include <limits>

// This project

#include "PP6Day1Menu.hpp"
#include "PP6Day2Menu.hpp"
#include "PP6Day3Menu.hpp"
#include "PP6Day4Menu.hpp"
#include "Physics.hpp"
#include "EnSigma.hpp"
#include "ReadFile.hpp"
#include "CFourVector.hpp"

int main(){

  char day;
  
  while(true){
    
    std::cout << "Enter one number: " << std::endl; 
    std::cout << "1. Day 1" << std::endl;
    std::cout << "2. Day 2" << std::endl;
    std::cout << "3. Day 3" << std::endl;
    std::cout << "4. Day 4" << std::endl;
    std::cout << "q. Quite" << std::endl;
    
    std::cin >> day;
    
    if (day == 'q'){break;}
    if (day == '1'){PP6Day1Menu();}
    if (day == '2'){PP6Day2Menu();}
    if (day == '3'){PP6Day3Menu();}
    if (day == '4'){PP6Day4Menu();}
    std::cout << "Thank you for using pp6calculator!" << std::endl;
  }  
  return 0;
}

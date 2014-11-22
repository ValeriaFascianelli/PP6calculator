#include "PP6Day2Menu.hpp"

#include <iostream>

#include "EnSigma.hpp"
#include "ReadFile.hpp"
#include "GetChar.hpp"

void PP6Day2Menu(){
  
  char a;

  while(true){
    std::cout << "Enter a choice: "<< std::endl;
    std::cout << "1. Evaluate the main energy with its standard daviation from random numbers"<<std::endl;
    std::cout << "2. Read a data file" << std::endl;
    std::cout<< "q. to quite" << std::endl;
    a = GetChar();
    if(a == 'q'){break;}
    if(a == '1'){EnSigma();}
    if(a == '2'){ReadFile();}
  }
  return;
}

#ifndef OPERATION_GETNUMBER_HH
#define OPERATION_GETNUMBER_HH

//*****************************************************************************************
// This function ask to the user to enter a number and it will check if it is valid or not.
// While the input is not valid, the user will be asked to re-enter the value.
//******************************************************************************************

#include <iostream>

template <typename T = double>
T GetNumber(){
  T res(0);

  std::cin >> res;

  while (!std::cin)
  {
    std::cout << "Error in input. Please re-enter." << std::endl;

    // clear the buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // retry
    std::cin >> res;
  }

  return res;
}

#endif

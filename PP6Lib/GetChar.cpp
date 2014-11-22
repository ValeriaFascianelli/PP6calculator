#include <iostream>

char GetChar(){

  char op;
  
  std::cin >> op;
  
  while (!std::cin)
    {
      std::cout << "Error in input. Please re-enter." << std::endl;
      
      // clear the buffer
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      
      // retry
      std::cin >> op;
    }
  return op;
}

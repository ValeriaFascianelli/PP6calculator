#include "SorterVector.hpp"

#include <vector>
#include <random>
#include <iostream>

void SorterVector(){
  
  std::vector<int> Vector;
  int i = 0;
  //srand(time(NULL));
  std::random_device rseed;
  std::mt19937 rgen(rseed()); // mersenne_twister
  std::uniform_int_distribution<int>dist(0,100);
  //std::mt19937 mt(1729);
  //std::uniform_int_distribution<int> dist(0,99);

  while(i < 10){
    Vector.push_back(dist(rgen));
    i++;
  }
  std::cout<< "The random numbers are: " << std::endl;
  std::copy(Vector.begin(), Vector.end(), std::ostream_iterator<int>(std::cout, "\n"));
  std::sort(Vector.begin(), Vector.end());
  std:: cout << "Vector sorted is: " <<std::endl;
  std::copy(Vector.begin(), Vector.end(), std::ostream_iterator<int>(std::cout, "\n"));
  std::cout << "The maximum value is " << *std::max_element(Vector.begin(),Vector.end()) << std::endl;
  std::cout << "The minimum value is " << *std::min_element(Vector.begin(),Vector.end()) << std::endl;
  return;  
}

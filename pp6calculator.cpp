#include <iostream>
#include <cmath>
#include <limits>

// This project

#include "PP6Day1Menu.hpp"
#include "PP6Day2Menu.hpp"
#include "PP6Day3Menu.hpp"
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
    std::cout << "q. Quite" << std::endl;
    
    std::cin >> day;
    
    if (day == 'q'){break;}
    if (day == '1'){PP6Day1Menu();}
    if (day == '2'){PP6Day2Menu();}
    if (day == '3'){PP6Day3Menu();}


    /*if (day == 3){
      while(true){
	std::cout << "Choose the 4 components of the vector and the speed, remember you should put the component in the following order, t x y z:"<<std::endl;
	std::cin >> vect[0] >> vect[1] >> vect[2] >> vect[3] >> speed;
	while(speed > 1){
	  std::cout<<"The speed must be less than 1"<<std::endl;
	  std::cin.clear(); // clear the flag
	  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	  std::cin >> speed;
	}
	boostZ(vect, boost, speed);
	std::cout << "The four components after boosting are:"<<std::endl;
	for (int i = 0; i < 4; i++){
	std::cout << boost[i]<<std::endl;
	}
	interval = Interval(boost);
      }
      }*/

    /* if(day == 3){
           
      FourVector vect; //= new FourVector(3,1,1,1);

      std::cout << "Choose the 4 components of the vector and the speed, remember you should put the component in the following order, t x y z"<<std::endl;
      std::cin >> vect.t>>vect.x>>vect.y>>vect.z; 

      //vect->setvariables();
      //vect->t = 3;
      //vect->x = 1;
      //vect->y = 1;
      //vect->z = 1;
      
      double velocity = 0.1;
      double a = vect.interval();
      vect.boost_z(velocity);
      //std::cout<< a << std::endl;
      std::cout << vect.t<<std::endl;
    }
    }*/
std::cout << "Thank you for using pp6calculator!" << std::endl;
}  
return 0;
 

}

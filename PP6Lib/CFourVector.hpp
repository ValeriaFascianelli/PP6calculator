#ifndef PP6DAY3MENU_CFOURVECTOR_HH
#define PP6DAY3MENU_CFOURVECTOR_HH

#include "CThreeVector.hpp"

class CFourVector: public CThreeVector{
public:
  
  //constructor
  CFourVector();

  //destructor
  ~CFourVector();
  
  //member functions
public:  

  void SetT(double);
  double GetT();
  double GetInterval();
  void BoostZ( double);

  /*
  //Overload + operator to add to FourVector object
  CFourVector operator+(CFourVector& v){
    CFourVector vect;
    vect.CThreeVector::GetX() = this->CThreeVector::GetX() + v.CThreeVector::GetX();
    vect.CThreeVector::GetY() = this->CThreeVector::GetY() + v.CThreeVector::GetY();
    vect.CThreeVector::GetZ() = this->CThreeVector::GetZ() + v.CThreeVector::GetZ();
    return vect;
  }
  
  CFourVector operator-(CFourVector& v){
    CFourVector vect;
    vect.CThreeVector::GetX() = this->CThreeVector::GetX() - v.CThreeVector::GetX();
    vect.CThreeVector::GetY() = this->CThreeVector::GetY() - v.CThreeVector::GetY();
    vect.CThreeVector::GetZ() = this->CThreeVector::GetZ() - v.CThreeVector::GetZ();
    return vect;
  }
  */
  
  //member variables
private:
  double ft;
};

#endif

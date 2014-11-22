#include <cmath>

#include "CFourVector.hpp"
#include "CThreeVector.hpp"

CFourVector::CFourVector()
  :CThreeVector()
{ft = 0;}

CFourVector::~CFourVector()
{}

void CFourVector::SetT(double t){
  ft = t;
  return;
}

double CFourVector::GetT(){
  double t = ft;
  return t;
}

double CFourVector::GetInterval(){
  double x = CThreeVector::GetX();
  double y = CThreeVector::GetY();
  double z = CThreeVector::GetZ();
  double s = sqrt(ft*ft - x*x - y*y - z*z);
  return s;
}

void CFourVector::BoostZ(double velocity){
  double beta = velocity;
  double gamma = 1./(sqrt(1-beta*beta));
  //double x = CThreeVector::GetX();
  //double y = CThreeVector::GetY();
  double z = CThreeVector::GetZ();
  ft =  gamma*(ft-beta*z);
  z = gamma*(z-beta*ft);

  return;
}


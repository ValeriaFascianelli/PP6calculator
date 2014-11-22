#include <cmath>
#include "CThreeVector.hpp"

CThreeVector::CThreeVector()
{fx = 0; fy = 0; fz = 0;}

CThreeVector::~CThreeVector()
{}
void CThreeVector::SetX(double x){
  fx = x;
  return;
}
void CThreeVector::SetY(double y){
  fy = y;
  return;
}
void CThreeVector::SetZ(double z){
  fz = z;
  return;
}
double CThreeVector::GetX(){
  double x = fx;
  return x;
}
double CThreeVector::GetY(){
  double y = fy;
  return y;
}
double CThreeVector::GetZ(){
  double z = fz;
  return z;
}
double CThreeVector::GetLength(){
  double s = sqrt((fx*fx)+(fy*fy)+(fz*fz));
  return s;
}

#include "CFourVector.hpp"
#include "CThreeVector.hpp"
#include "CParticle.hpp"


CParticle::CParticle()
  :CFourVector()
{fmass = 0; fPDGCode = 0;}

CParticle::~CParticle()
{}

void CParticle::SetPDGCode(double pdg){
  fPDGCode = pdg;
  return;
}
void CParticle::SetMassGeV(double mass){
  fmass = mass;
  return;
}
void CParticle::SetXMomentum(double xMomentum){
  CThreeVector::SetX(xMomentum);
  return;
}
void CParticle::SetYMomentum(double yMomentum){
  CThreeVector::SetY(yMomentum);
  return;
}
void CParticle::SetZMomentum(double zMomentum){
  CThreeVector::SetZ(zMomentum);
  return;
}
void CParticle::SetTMomentum(double tMomentum){
  CFourVector::SetT(tMomentum);
  return;
}
double CParticle::GetMassGeV(){
  double mass = fmass;
  return mass;
}
double CParticle::GetXMomentum(){
  double xMomentum = CThreeVector::GetX();
  return xMomentum;
}
double CParticle::GetYMomentum(){
  double yMomentum = CThreeVector::GetY();
  return yMomentum;
}
double CParticle::GetZMomentum(){
  double zMomentum = CThreeVector::GetZ();
  return zMomentum;
}
double CParticle::GetTMomentum(){
  double tMomentum = CFourVector::GetT();
  return tMomentum;
}
double CParticle::GetMagMomentum(){
  double s = CThreeVector::GetLength();
  return s;
}

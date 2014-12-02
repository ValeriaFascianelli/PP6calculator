#ifndef PP6CALCULATOR_CPARTICLE_HH
#define PP6CALCULATOR_CPARTICLE_HH

#include "CFourVector.hpp"

//Class which inherits from CFourVector class
class CParticle: public CFourVector{
 public:

  //constructor
  CParticle();
 
  //destructor
  ~CParticle();

  void SetPDGCode(double);
  void SetMassGeV(double);
  void SetXMomentum(double);
  void SetYMomentum(double);
  void SetZMomentum(double);
  void SetTMomentum(double);
  double GetPDGCode();
  double GetMassGeV();
  double GetXMomentum();
  double GetYMomentum();
  double GetZMomentum();
  double GetTMomentum();
  double GetMagMomentum();

  //Overload + operator to add to particles object
  CParticle operator+(const CParticle& p){
    CParticle particle;
    particle.fmass = this->fmass + p.fmass;
    return particle;
  }
  
  //member variables

 private:
  double fmass;
  int fPDGCode;
  //double fxMomentum;
  //double fyMomentum;
  //double fzMomentum;
  //double ftMomentum;

};

#endif

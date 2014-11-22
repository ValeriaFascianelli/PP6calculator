#ifndef PP6DAY3MENU_CTHREEVECTOR_HH
#define PP6DAY3MENU_CTHREEVECTOR_HH

class CThreeVector{
public:

  //constructor
  CThreeVector();
  
  //destructor
  ~CThreeVector();

  //member function
public:
 
  void SetX(double x);
  void SetY(double y);
  void SetZ(double z);
  double GetX();
  double GetY();
  double GetZ();
  double GetLength();
  
  //Overload + operator to add to ThreeVector object
  CThreeVector operator+(const CThreeVector& v){
    CThreeVector vect;
    vect.fx = this->fx + v.fx;
    vect.fy = this->fy + v.fy;
    vect.fz = this->fz + v.fz;
    return vect;
  }

 CThreeVector operator-(const CThreeVector& v){
   CThreeVector vect;
   vect.fx = this->fx - v.fx;
   vect.fy = this->fy - v.fy;
   vect.fz = this->fz - v.fz;
   return vect;
 }
  
  //member variables
private:

  double fx;
  double fy;
  double fz;

};

#endif

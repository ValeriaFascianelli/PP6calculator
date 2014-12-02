#ifndef PP6DAY4MENU_CPARTICLEINFO_HH
#define PP6DAY4MENU_CPARTICLEINFO_HH

#include <iostream>
#include <vector>
#include <map>
#include "FileReader.hpp"

//*************************************************************************************************************//
// Through this class is possible to retrieve the particle information stored in the pdg.dat.txt
// The constructor reads the file and creats different maps between the information stored
// It will be possible to have access to the information through the name of the particle for which you look for
//**************************************************************************************************************//


class CParticleInfo: public FileReader{
public:
  
  //constructor
  CParticleInfo(std::string filename);
  
  //destructor
  ~CParticleInfo();
  
  //member functions
public:
  
  int getPDGCode(std::string name);
  int getCharge(int pdg);
  std::string getName(int pdg);
  double getMassGeV(int pdg);

private:

  CParticleInfo(const CParticleInfo&);
  CParticleInfo operator=(const CParticleInfo);

  //member variables : Create an istance of map, which is empty,they will be used in the constructor to make_pair and add element
public:
  
  typedef std::map<std::string,int> PartIdCont;
  PartIdCont fPDGCodes;
  typedef std::map<int,int> PartIdChar;
  PartIdChar fCharges;
  typedef std::map<int,double> PartIdMass;
  PartIdMass fMasses;
  typedef std::map<int,std::string> PartIdNames;
  PartIdNames fNames;
  
};

#endif

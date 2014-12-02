#include <cmath>
#include <map>
#include <iostream>

#include "CParticleInfo.hpp"
#include "FileReader.hpp"

// the constructor calls the FileReader class to read the file and it creates the map

CParticleInfo::CParticleInfo(std::string filename)
  :FileReader(filename)
{ 
  FileReader f(filename);

  if(f.isValid()){
    while(f.nextLine()){
     
  // use insert and make_pair to add an element
      fPDGCodes.insert(std::make_pair(f.getField<std::string>(1),f.getField<int>(2))); // particle name -> pdg code
      fCharges.insert(std::make_pair(f.getField<int>(2),f.getField<int>(3)));  // particle name -> charge
      fMasses.insert(std::make_pair(f.getField<int>(2),f.getField<double>(4))); // particle name -> mass
      fNames.insert(std::make_pair(f.getField<int>(2),f.getField<std::string>(1))); // pdg code -> particle name
      if (f.inputFailed()) break;
    }
  }
}

CParticleInfo::~CParticleInfo()
{}

int CParticleInfo::getPDGCode(std::string name){
  PartIdCont::iterator p =  fPDGCodes.find(name);
  int PDGCode = (*p).second;
  return PDGCode;
}

std::string CParticleInfo::getName(int info){
  PartIdNames::iterator p = fNames.find(info);
  std::string Name = (*p).second;
  return Name;
}

int CParticleInfo::getCharge(int pdg){
  PartIdChar::iterator p =  fCharges.find(pdg);
  int Charge = (*p).second;
  return Charge;
  }

double CParticleInfo::getMassGeV(int pdg){
  PartIdMass::iterator p =  fMasses.find(pdg);
  double mass = ((*p).second)/1000;
  return mass;
}

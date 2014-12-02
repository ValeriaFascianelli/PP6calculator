# CMake script for pp6 library

# - Add the PP6Lib library
add_library(pp6lib SHARED Math.cpp Math.hpp PP6Day1Menu.cpp PP6Day1Menu.hpp  PP6Day2Menu.cpp PP6Day2Menu.hpp  PP6Day3Menu.cpp PP6Day3Menu.hpp PP6Day4Menu.cpp PP6Day4Menu.hpp Physics.hpp Physics.cpp EnSigma.hpp EnSigma.cpp GetNumber.hpp GetNumber.cpp GetChar.hpp GetChar.cpp FileReader.hpp FileReader.cpp ReadFile.cpp ReadFile.hpp CThreeVector.cpp CThreeVector.hpp CFourVector.cpp CFourVector.hpp CParticle.cpp CParticle.hpp CParticleInfo.cpp CParticleInfo.hpp ReadParticleDataBase.hpp ReadParticleDataBase.cpp ParticleDataBase.hpp ParticleDataBase.cpp SorterInvMass.hpp SorterInvMass.cpp SorterVector.hpp SorterVector.cpp)

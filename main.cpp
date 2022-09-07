// #define NO_PRINTF
// #define ENUM_TERMINATOR ALWAYS_END
#define VERBOSITY 0
#define PRINT_TYPE -1

#include "header.hpp"
#include "enums.hpp"
#include "math/math.hpp"
#include "printing.hpp"
#include "sorting.hpp"
#include "time.tpp"
#include "types.hpp"
#include "util.hpp"

//gitignore executables, .bin, and main.cpp

//remove all .cpp files
//include only .tpp via common include files like header.hpp


//switch pragma once to include guards
//namespace everything
//make ifdefs for all modifying macros (PRINT_TYPE, NO_PRINTF...)

//timer printing
//add typedefs to classes (value_type...)
//remove convert all args in place of overloading <<;
//have printf2 use what have << defined (maybe just call cout)
//move printing to tpp and add concepts to it
//make printing format modifiable (prob via macros)
//base converter

//update duke of ed
//template arg type for weighted_avg, fibonnaci...

int main(){
  //test the vector methods (set_cartesian, invert...)
  //generalize vector for n dimensions (instead make vector a special case of nx1 matrix)

  // compose an NxM matrix from M Vector<N>'s
  // specify Vector<2>, Vector<3>, Vector<7>
  std::cout << std::setprecision(30);
  OUTPUT(constants::gauss<>);
  OUTPUT(0);


  return 0;
}
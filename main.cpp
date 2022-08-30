// #define NO_PRINTF
// #define ENUM_TERMINATOR ALWAYS_END

#include "header.hpp"
#include "enums.hpp"
#include "math/math.hpp"
#include "printing.hpp"
#include "sorting.hpp"
#include "time.hpp"
#include "timer.hpp"
#include "types.hpp"
#include "util.hpp"

//gitignore executables, .bin, and main.cpp

//look at making the tpp not standalone (no includes) they can only be used in a copy-paste context


//namespace everything
//remove convert all args in place of overloading <<;
//have printf2 use what have << defined (maybe just call cout)
//move printing to tpp and add concepts to it
//make printing format modifiable (prob via macros)
//base converter

//switch pragma once to include guards
//update duke of ed
//template arg type for weighted_avg, fibonnaci...

enum class A{
  a,b,c,d,e,f,g,h,i, ENUM_TERMINATOR
};

int main(){
  prog_begin();
  // std::cout << sum(std::function([](natural a){return 1.0L/(a*a);}), 1, 100000000) << std::endl;
  // std::cout << pow(constants::pi<>, 2)/6;
  // std::cout << 1./std::numeric_limits<natural>::max();

  //test the vector methods (set_cartesian, invert...)
  //generalize vector for n dimensions (instead make vector a special case of nx1 matrix)

  // compose an NxM matrix from M Vector<N>'s
  // specify Vector<2>, Vector<3>, Vector<7>

  Vector<real> v{2., 2.};

  OUTPUT(v);

  // auto x = (v == Vector<double>());

  // std::cout << v.angle(v) << std::endl;

  return 0;
}
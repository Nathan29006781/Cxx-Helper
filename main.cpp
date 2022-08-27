// #define NO_PRINTF

#include "header.hpp"
#include "math/math.hpp"
#include "printing.hpp"
#include "sorting.hpp"
#include "time.hpp"
#include "timer.hpp"
#include "types.hpp"
#include "util.hpp"

//gitignore executables, .bin, and main.cpp

//namespace everything
//remove convert all args in place of overloading <<;
//have printf2 use what have << defined (maybe just call cout)
//move printing to tpp and add concepts to it
//make printing format modifiable (prob via macros)
//base converter
//switch pragma once to include guards
//use promote also
//update duke of ed
//template arg type for weighted_avg, fibonnaci...

int main(){
  prog_begin();
  // std::cout << sum(std::function([](natural a){return 1.0L/(a*a);}), 1, 100000000) << std::endl;
  // std::cout << pow(constants::pi<>, 2)/6;
  // std::cout << 1./std::numeric_limits<natural>::max();

  return 0;
}
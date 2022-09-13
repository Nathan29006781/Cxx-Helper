// #define NO_PRINTF
// #define ENUM_TERMINATOR ALWAYS_END
#define VERBOSITY 0
#define PRINT_TYPE -1

#include "header.hpp"
#include "enums.hpp"
#include "math/math.hpp"
#include "ostream operators.hpp"
#include "printing.hpp"
#include "sorting.hpp"
#include "time.tpp"
#include "types.hpp"
#include "util.hpp"

//gitignore executables, .bin, and main.cpp

//!remove all .cpp files
//include only .tpp via common include files like header.hpp

//switch pragma once to include guards
//namespace everything
//make ifdefs for all modifying macros (PRINT_TYPE, NO_PRINTF...)

//update naming standard from [member name, getter get_name()] to [member _name, getter name()]
//move convert_all_args to respective files where the type comes from
//timer printing
//add typedefs to classes (value_type...)
//change std::string in printing.hpp to string_view
//remove convert all args in place of overloading <<;
//have printf2 use what have << defined (maybe just call cout)]
//make printing format modifiable (prob via macros)

//update duke of ed


int main(){
  //generalize vector for n dimensions (instead make vector a special case of nx1 matrix)
  // compose an NxM matrix from M Vector<N>'s
  // specify Vector<2>, Vector<3>, Vector<7>

  auto angle = 30_deg;
  std::cout << 1_rad - angle << std::endl;

  return 0;
}
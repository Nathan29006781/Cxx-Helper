//deprecated
// #define NO_PRINTF
#define VERBOSITY 0
#define PRINT_TYPE -1

#include <iostream>

//!remove all .cpp files

//update naming standard from [member name, getter get_name()] to [member _name, getter name()]
//move convert_all_args to respective files where the type comes from
//timer printing

//change std::string in printing.hpp to string_view
//remove convert all args in place of overloading <<;
//have printf2 use what have << defined (maybe just call cout)]
//make printing format modifiable (prob via macros)

//update duke of ed

int main(){
  //generalize vector for n dimensions (instead make vector a special case of nx1 matrix)
  // compose an NxM matrix from M Vector<N>'s
  // specify Vector<2>, Vector<3>, Vector<7>
  //Don't compose position from Vector until vector is templated

  return 0;
}
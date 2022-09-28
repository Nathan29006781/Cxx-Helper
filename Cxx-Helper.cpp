//deprecated
// #define NO_PRINTF
#define VERBOSITY 0
#define PRINT_TYPE -1

#include <iostream>
#include "math.hpp"
#include "printing.hpp"
#include "queue.hpp"

//!remove all .cpp files

//!fix angle constructor so conversion only happens in radians()...
//iterator pair type that holds a beginning and end iterator
//Make angle enum represent conversion factor
//move gcf/lcm from geometry
//isprime()
//remove .tpp and make it header only
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
  using namespace NATHAN_M_PROJECT_NAME;


  // queue<int, 5> q("queue"); OUTPUT(q); OUTPUT(q.size());
  // q.push(1); OUTPUT(q); OUTPUT(q.size());
  // q.push(2); OUTPUT(q); OUTPUT(q.size());
  // q.push(3); OUTPUT(q); OUTPUT(q.size());
  // q.push(4); OUTPUT(q); OUTPUT(q.size());
  // q.push(5); OUTPUT(q); OUTPUT(q.size());
  // q.pop();   OUTPUT(q); OUTPUT(q.size());
  // q.pop();   OUTPUT(q); OUTPUT(q.size());
  // q.push(6); OUTPUT(q); OUTPUT(q.size());
  // q.push(7); OUTPUT(q); OUTPUT(q.size());

  return 0;
}
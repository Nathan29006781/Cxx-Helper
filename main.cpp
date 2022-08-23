#include "headers.hpp"
#include "geometry.hpp"
#include "math.hpp"
#include "math_functions.hpp"
#include "printing.hpp"
#include "sorting.hpp"
#include "time.hpp"
#include "timer.hpp"
#include "types.hpp"
#include "util.hpp"

//gitignore executables, .bin, and main.cpp

//use promote also
//update duke of ed
//template arg type for weighted_avg, fibonnaci...

enum class AA{A1, A2, A3, A4, A5, A6, NUM_OF_ELEMENTS};

int main(){
  prog_begin();
  std::string s = "HELLO!";

  int x = 2;
  
  std::cout << std::boolalpha << sgn_to_bool(x) << std::endl;

  // auto now = millis();

  // std::cout << std::pow(constants::pi<real>, 2)/6 << std::endl;

  // std::cout << sum(std::function([](natural a){return 1.0L/(a*a);}), 1, 100) << std::endl;

  // std::cout << 1./std::numeric_limits<natural>::max();

  OUTPUT(s);

  // OUTPUT(constants::apery<>, millis()); //need to fold << into expression for each arg

  bogo_sort(s.begin(), s.end());
  return 0;
}
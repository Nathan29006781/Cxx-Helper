#include "headers.hpp"
#include "geometry.hpp"
#include "math.hpp"
#include "math_functions.hpp"
#include "sorting.hpp"
#include "time.hpp"
#include "timer.hpp"
#include "types.hpp"
#include "util.hpp"

//gitignore executables, .bin, and main.cpp

//update duke of ed
//inline random functions
//random file
//constexpr sorts and random if possible

enum class AA{A1, A2, A3, A4, A5, A6, NUM_OF_ELEMENTS};

int main(){
  prog_begin();
  std::string s = "HELLO!";

  bogo_sort(s.begin(), s.end());
  return 0;
}
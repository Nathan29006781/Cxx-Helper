#include "headers.hpp"
#include "geometry.hpp"
#include "math.hpp"
#include "math_functions.hpp"
#include "sorting.hpp"
#include "time.hpp"
#include "timer.hpp"
#include "util.hpp"

//gitignore executables, .bin, and main.cpp

//inline random functions
//random file
//constexpr sorts and random if possible

int main(){
  prog_begin();
  std::string s = "HELLO!";

  bozo_sort(s.begin(), s.end());
  std::cout << __TIME__ << std::endl;
  return 0;
}
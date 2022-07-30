#include "headers.hpp"
#include "geometry.hpp"
#include "math.hpp"
#include "math_functions.hpp"
#include "time.hpp"
#include "timer.hpp"
#include "util.hpp"


//gitignore executables, .bin, and main.cpp

int main(){
  prog_begin();
  loop(10) std::cout << loop_counter << " " << loop_counter_b << '\n';

  return 0;
}
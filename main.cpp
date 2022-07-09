#include "headers.hpp"
#include "math.hpp"
#include "math_functions.hpp"
#include "geometry.hpp"

//gitignore executables, .bin, and main.cpp

int main(){
  BinArthmOp<double> op (std::multiplies<double>(), 12, 3);

  std::cout << std::boolalpha << hypotenuse(1,2.0/2) << std::endl;
    return 0;
}
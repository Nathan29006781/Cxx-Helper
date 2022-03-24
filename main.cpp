#include <ios>
#include <iostream>
#include "math.hpp"
#include "functions.hpp"
#include <cmath>

//gitignore executables, .bin, and main.cpp

int main(){
  BinArthmOp<int> op (std::multiplies<int>(), 10, 2);

  // std::function<int(int, int)> t = std::plus<int>();
  std::cout << std::boolalpha << op() << std::endl;
  return 0;
}
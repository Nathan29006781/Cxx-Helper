//which function called current function
//value struct
//func scale
//maybe equation support here? if not, then math.hpp

#include <functional>

struct BinArthmOp{
  std::function<long double()> first_arg;
  std::function<long double()> second_arg;
  std::function<long double(long double, long double)> operation;


  //() operator
  //check if value-convertible by looking at operands. convert if convertible
};
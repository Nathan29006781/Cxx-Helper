#include "printing.hpp"
#include "math/geometry/geometry.hpp"
#include <iostream>

CXX_HELPER_BEGIN_NAMESPACE

std::string convert_all_args(std::string const & fmt, std::string const & arg){
  if(fmt.back() == 'p') return convert_all_args(fmt, arg.data());
  return arg;
}

template <std::floating_point R>
std::string convert_all_args(std::string const & fmt, Position<R> const & arg){
  return '(' + convert_all_args(fmt, arg.x) + ", " + convert_all_args(fmt, arg.y) + ", " + convert_all_args(fmt, arg.angle) + ")";
}
CXX_HELPER_END_NAMESPACE
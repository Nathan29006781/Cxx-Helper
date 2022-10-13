#ifndef CXX_HELPER_MATH_OPERATOR_HPP_
#define CXX_HELPER_MATH_OPERATOR_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include "../util.hpp"
#include <functional>

CXX_HELPER_BEGIN_NAMESPACE

template <Integer arg_type, typename result_type>
constexpr result_type sum(std::function<result_type(arg_type)> func, integer start = 1, integer end = std::numeric_limits<arg_type>::max()){
  // case needed if going to infinity

  result_type sum = 0;
  loop_to(start, end+1) {sum += func(loop_counter); printf("idx:%lld, val:%Lf, sum:%Lf\n", loop_counter, func(loop_counter), sum);}

  return sum;
}

template <Integer arg_type, typename result_type>
constexpr result_type prod(std::function<result_type(arg_type)> func, integer start = 1, integer end = std::numeric_limits<arg_type>::max()){
  // case needed if going to infinity

  result_type prod = 1;
  loop_to(start, end+1) prod *= func(loop_counter);

  return prod;
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_OPERATOR_HPP_
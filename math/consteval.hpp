#ifndef CXX_HELPER_MATH_CONSTEVAL_HPP_
#define CXX_HELPER_MATH_CONSTEVAL_HPP_

#include "../header_config.hpp"
#include <cmath>

CXX_HELPER_BEGIN_NAMESPACE

namespace compile_time{

  inline consteval long double sqrt(long double const number)
  {
    long double guess{number/2.0};
    long double prev_guess{number};

    while(guess != prev_guess){
      prev_guess = guess;
      guess = (guess+number/guess)/2;
    }

    return guess;
  }

}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_CONSTEVAL_HPP_
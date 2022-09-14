#ifndef CXX_HELPER_MATH_CONSTEVAL_HPP_
#define CXX_HELPER_MATH_CONSTEVAL_HPP_

#include "../header_config.hpp"

CXX_HELPER_BEGIN_NAMESPACE

inline consteval long double sqrt_const(long double number)
{
  long double guess = number/2.0;
  long double prev_guess = number;

	while(guess != prev_guess){
    prev_guess = guess;
    guess = (guess+number/guess)/2;
  }

  return guess;
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_CONSTEVAL_HPP_
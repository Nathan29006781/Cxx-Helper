#pragma once
#include "../header.hpp"
#include "../types.hpp"
// #include "../util.hpp"
#include "constants.hpp"

//integrals
//derivatives
//limits
//series sum/prod
//algebra
//vectors
//integer exponentiation
//constexpr sqrt
//common math sequences: triangular numbers, perfect squares, fibonnaci, matrices
//Next base-k number (k=2: 101 -> 110) (k=3: 101 -> 102)
//Base converter

/*equations:
Printing: 0a+ -1b +c => -b + c
isolate for a variable
combining equations (elimination/ maybe substitution)
solve an equation
*/

//for calc, see if possible to apply to equations directly

//Good upto 70th number
template <Natural N>
constexpr natural fibonacci(N n){
  return round((pow(constants::phi<>, n) - pow(1-constants::phi<>, n)) / (2*constants::phi<>-1));
}

template <Natural N>
constexpr natural factorial(N n){
  return round(std::tgamma(n+1));
}

template <Natural N>
constexpr natural triangular(N n){
  return (n*(n+1))/2;
}

constexpr long double sqrt_const(long double number)
{
  long double guess = number/2.0;
  long double prev_guess = number;

	while(guess != prev_guess){
    prev_guess = guess;
    guess = (guess+number/guess)/2;
  }

  return guess;
}
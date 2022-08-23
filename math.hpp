#pragma once
#include "headers.hpp"
#include "types.hpp"

//integrals
//derivatives
//limits
//series sum/prod
//algebra
//integer exponentiation
//constexpr sqrt
//common math sequences: triangular numbers, perfect squares, fibonnaci, matrices
//Next base-k number (k=2: 101 -> 110) (k=3: 101 -> 102)
//Base converter

#define SIMPLE_CONSTANT_NAMES

namespace constants{
  template<class T = long double> constexpr T pi = T(3.14159265358979323846264338327950288L);
  template<class T = long double> constexpr T phi = T(1.61803398874989484820458683436563811L);
  template<class T = long double> constexpr T e = T(2.71828182845904523536028747135266250L);
  template<class T = long double> constexpr T euler_mascheroni = T(0.57721566490153286060651209008240243L);
  template<class T = long double> constexpr T apery = T(1.20205690315959428539973816151144999L);
  template<class T = long double> constexpr T plastic = T(1.32471795724474602596090885447809734L);
  template<class T = long double> constexpr T glaisher_kinkelin = T(0);

  #ifdef SIMPLE_CONSTANT_NAMES
    template<class T = long double> constexpr T z3 = apery<T>;
    template<class T = long double> constexpr T A = glaisher_kinkelin<T>;
  #endif
}

/*equations:
Printing: 0a+ -1b +c => -b + c
isolate for a variable
combining equations (elimination/ maybe substitution)
solve an equation
*/

//for calc, see if possible to apply to equations directly

//Good upto 70th number
constexpr natural fibonacci(natural n){
  return round((pow(constants::phi<>, n) - pow(1-constants::phi<>, n)) / (2*constants::phi<>-1));
}

template <typename N, typename = typename std::enable_if_t<std::is_integral_v<N> && !std::is_signed_v<N> && !std::is_floating_point_v<N>, void>>
constexpr natural triangular(natural n){
  return (n*(n+1))/2;
}
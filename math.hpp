#pragma once
#include "headers.hpp"
#include "types.hpp"
#include "util.hpp"
#include "printing.hpp"

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

#define SIMPLE_CONSTANT_NAMES

namespace constants{
  template<std::floating_point T = real> inline constexpr T euler = std::numbers::e_v<T>;
  template<std::floating_point T = real> inline constexpr T golden = std::numbers::phi_v<T>;
  template<std::floating_point T = real> inline constexpr T log2e = std::numbers::log2e_v<T>;
  template<std::floating_point T = real> inline constexpr T log10e = std::numbers::log10e_v<T>;
  template<std::floating_point T = real> inline constexpr T ln2 = std::numbers::ln2_v<T>;
  template<std::floating_point T = real> inline constexpr T ln10 = std::numbers::ln10_v<T>;
  template<std::floating_point T = real> inline constexpr T sqrt2 = std::numbers::sqrt2_v<T>;
  template<std::floating_point T = real> inline constexpr T inv_sqrt2 = 0.70710678118654752440084436210484903;
  template<std::floating_point T = real> inline constexpr T sqrt3 = std::numbers::sqrt3_v<T>;
  template<std::floating_point T = real> inline constexpr T inv_sqrt3 = std::numbers::inv_sqrt3_v<T>;
  template<std::floating_point T = real> inline constexpr T pi = std::numbers::pi_v<T>;
  template<std::floating_point T = real> inline constexpr T inv_pi = std::numbers::inv_pi_v<T>;
  template<std::floating_point T = real> inline constexpr T inv_sqrtpi = std::numbers::inv_sqrtpi_v<T>;
  template<std::floating_point T = real> inline constexpr T egamma = std::numbers::egamma_v<T>;
  template<std::floating_point T = real> inline constexpr T euler_mascheroni = 0.57721566490153286060651209008240243;
  template<std::floating_point T = real> inline constexpr T apery = 1.20205690315959428539973816151144999;
  template<std::floating_point T = real> inline constexpr T plastic = 1.32471795724474602596090885447809734;
  template<std::floating_point T = real> inline constexpr T glaisher_kinkelin = 1.28242712910062263687534256886979172;
  template<std::floating_point T = real> inline constexpr T glaisher = glaisher_kinkelin<T>;
  template<std::floating_point T = real> inline std::complex<T> imaginary = std::complex<T>(0, 1);


  #ifdef SIMPLE_CONSTANT_NAMES
    template<std::floating_point T = real> inline constexpr T phi = golden<T>;
    template<std::floating_point T = real> inline constexpr T e = euler<T>;
    template<std::floating_point T = real> inline constexpr T z3 = apery<T>;
    template<std::floating_point T = real> inline constexpr T A = glaisher_kinkelin<T>;
    template<std::floating_point T = real> inline std::complex<T> i = imaginary<T>;

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
template <Natural N>
constexpr natural fibonacci(N n){
  return round((pow(constants::phi<>, n) - pow(1-constants::phi<>, n)) / (2*constants::phi<>-1));
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
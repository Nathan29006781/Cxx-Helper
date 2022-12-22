#ifndef CXX_HELPER_MATH_GENERIC_HPP_
#define CXX_HELPER_MATH_GENERIC_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include "geometry/angles.hpp"
#include "constexpr.hpp"
#include <concepts>

CXX_HELPER_BEGIN_NAMESPACE

namespace generic{

template <typename B, typename E>
auto pow(B base, E exponent){
  if constexpr (Arithmetic<B> && std::integral<E>) return compile_time::int_pow(base, exponent);
  else if constexpr (Arithmetic<B> && std::floating_point<E>) return compile_time::pow(base, exponent);
  // else if constexpr (instance_of_type<B, std::complex> || instance_of_type<E, std::complex>) return std::pow(base, exponent); //Not really necessary
  else return std::pow(base, exponent);
  //complex defines pow
}

template <typename E>
auto exp(E exponent){
  if constexpr (Arithmetic<E>) return compile_time::exp(exponent);
  else return std::exp(exponent);
  //Angle defines exp
  //std::complex defines std::exp
}

template <typename T>
auto factorial(T arg){
  if constexpr (std::integral<T>) return compile_time::factorial(arg);
  else return std::tgamma(arg+1);
  //floating_point will use tgamma
}

}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_GENERIC_HPP_
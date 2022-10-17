#ifndef CXX_HELPER_MATH_GEOMETRY_HPP_
#define CXX_HELPER_MATH_GEOMETRY_HPP_

#include "../../header_config.hpp"
#include "../../types.hpp"
#include <numeric>

//matrices

CXX_HELPER_BEGIN_NAMESPACE

//Template Recursion Base Cases
  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto lcm(T1 value1, T2 value2) {return std::lcm(value1, value2);}

  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto gcd(T1 value1, T2 value2) {return std::gcd(value1, value2);}


//Template Recursion
  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto lcm(T value, Ts... values) {return lcm(value, lcm(values...));}

  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto gcd(T value, Ts... values) {return gcd(value, gcd(values...));}

//Fold Operations
  template <Arithmetic... Ts>
  inline constexpr auto hypotenuse(Ts... values) {return sqrt(((values*values) + ...));}

  template <Arithmetic... Ts>
  inline constexpr auto add(Ts... values) {return (0 + ... + values);}

  template <Arithmetic... Ts>
  inline constexpr auto multiply(Ts... values) {return (1 * ... * values);}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_GEOMETRY_HPP_
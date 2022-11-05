#ifndef CXX_HELPER_MATH_GEOMETRY_HPP_
#define CXX_HELPER_MATH_GEOMETRY_HPP_

#include "../../header_config.hpp"
#include "../../types.hpp"
#include <algorithm>
#include <numeric>

//matrices

CXX_HELPER_BEGIN_NAMESPACE

//Template Recursion Base Cases
  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto lcm(T1 const& value1, T2 const& value2) {return std::lcm(value1, value2);}

  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto gcd(T1 const& value1, T2 const& value2) {return std::gcd(value1, value2);}

  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto max(T1 const& value1, T2 const& value2) {return std::max(value1, value2);}

  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto min(T1 const& value1, T2 const& value2) {return std::min(value1, value2);}


//Template Recursion
  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto lcm(T const& value, Ts const&... values) {return lcm(value, lcm(values...));}

  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto gcd(T const& value, Ts const&... values) {return gcd(value, gcd(values...));}

  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto max(T const& value, Ts const&... values) {return max(value, max(values...));}

  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto min(T const& value, Ts const&... values) {return min(value, min(values...));}

//Fold Operations
  template <Arithmetic... Ts>
  inline constexpr auto hypotenuse(Ts const&... values) {return sqrt(((values*values) + ...));}

  template <Arithmetic... Ts>
  inline constexpr auto add(Ts const&... values) {return (0 + ... + values);}

  template <Arithmetic... Ts>
  inline constexpr auto multiply(Ts const&... values) {return (1 * ... * values);}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_GEOMETRY_HPP_
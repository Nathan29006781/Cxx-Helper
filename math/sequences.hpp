#ifndef CXX_HELPER_MATH_SEQUENCE_HPP_
#define CXX_HELPER_MATH_SEQUENCE_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include "constants.hpp"

CXX_HELPER_BEGIN_NAMESPACE

template <Natural N>
inline constexpr natural fibonacci(N n) {return std::round((pow(constants::golden<>, n) - pow(1-constants::golden<>, n)) / (2*constants::golden<>-1));}

template <Natural N>
inline constexpr natural factorial(N n) {return std::round(std::tgamma(n+1));}

template <Natural N>
inline constexpr natural triangular(N n) {return (n*(n+1))/2;}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_SEQUENCE_HPP_
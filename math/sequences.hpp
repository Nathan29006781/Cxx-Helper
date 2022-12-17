#ifndef CXX_HELPER_MATH_SEQUENCE_HPP_
#define CXX_HELPER_MATH_SEQUENCE_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include "constants.hpp"
#include <cmath>

CXX_HELPER_BEGIN_NAMESPACE

template <Natural N>
inline constexpr natural fibonacci(N const & n) {return std::round((pow(constants::golden<>, n) - pow(1-constants::golden<>, n)) / (2*constants::golden<>-1));}

template <Natural N>
inline constexpr natural factorial(N const & n) {return std::round(std::tgamma(n+1));}

template <Natural N>
inline constexpr natural triangular(N const & n) {return (n*(n+1))/2;}

template <Natural N>
inline constexpr natural permute(N const & n, N const & r) {return r > n ? 0 : factorial(n)/factorial(n-r);}

template <Natural N>
inline constexpr natural choose(N const & n, N const & r) {return r > n ? 0 : permute(n, r)/factorial(r);}


template <Real R>
inline constexpr real sigmoid(R const & r) {return 1/(1+std::exp(-r));}

// template <Natural N>
// inline constexpr natural zeta(N n) {return std::riemann_zeta(n);}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_SEQUENCE_HPP_
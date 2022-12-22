#ifndef CXX_HELPER_MATH_SEQUENCE_HPP_
#define CXX_HELPER_MATH_SEQUENCE_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include "constants.hpp"
#include "constexpr.hpp"
#include <cmath>

CXX_HELPER_BEGIN_NAMESPACE

inline constexpr natural fibonacci(natural n) {return std::round((pow(constants::φ, n) - pow(1-constants::φ, n)) / constants::sqrt5);}
inline constexpr natural triangular(natural n) {return (n*(n+1))/2;}
inline constexpr natural permute(natural n, natural r) {return r > n ? 0 : compile_time::factorial(n)/compile_time::factorial(n-r);}
inline constexpr natural choose(natural n, natural r) {return r > n ? 0 : permute(n, r)/compile_time::factorial(r);}


template <Real R>
inline constexpr real sigmoid(R const & r) {return 1/(1+std::exp(-r));}

// template <Natural N>
// inline constexpr natural zeta(N n) {return std::riemann_zeta(n);}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_SEQUENCE_HPP_
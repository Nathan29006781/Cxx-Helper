#pragma once
#include "../header.hpp"
#include "../types.hpp"
#include "constants.hpp"

template <Natural N>
inline constexpr natural fibonacci(N n) {return std::round((pow(constants::phi<>, n) - pow(1-constants::phi<>, n)) / (2*constants::phi<>-1));}

template <Natural N>
inline constexpr natural factorial(N n) {return std::round(std::tgamma(n+1));}

template <Natural N>
inline constexpr natural triangular(N n) {return (n*(n+1))/2;}
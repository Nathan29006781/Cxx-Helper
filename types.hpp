#ifndef CXX_HELPER_TYPES_HPP_
#define CXX_HELPER_TYPES_HPP_

#include "header_config.hpp"
#include <concepts>

CXX_HELPER_BEGIN_NAMESPACE

//value struct - create my own function class

//These are probably unlikely

//storing types
//type erasure
//tribool
//custom sized type
//bignum
//special enums

typedef long double real;
typedef real rational;
typedef long long integer;
typedef unsigned long long whole;
typedef whole natural;
typedef char const * string_literal;
typedef double percentage; //replace with custom type only up to 100

template <typename T> concept Real = std::convertible_to<T, real>;
template <typename T> concept Rational = std::convertible_to<T, rational>;
template <typename T> concept Integer = std::convertible_to<T, integer> && std::integral<T>;
template <typename T> concept Whole = std::convertible_to<T, whole> && std::unsigned_integral<T>;
template <typename T> concept Natural = Whole<T>; //No reason to have a type that excludes 0
template <typename T> concept Arithmetic = std::integral<T> || std::floating_point<T>;

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_UTIL_HPP_
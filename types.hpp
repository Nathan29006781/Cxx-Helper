#ifndef CXX_HELPER_TYPES_HPP_
#define CXX_HELPER_TYPES_HPP_

#include "header_config.hpp"
#include <concepts>

// CXX_HELPER_BEGIN_NAMESPACE

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
typedef const char* string_literal;

template <typename T> concept Real = std::convertible_to<T, real>;
template <typename T> concept Rational = std::convertible_to<T, rational>;
template <typename T> concept Integer = std::convertible_to<T, integer> && std::integral<T>;
template <typename T> concept Whole = std::convertible_to<T, whole> && std::signed_integral<T>;
template <typename T> concept Natural = Whole<T>; //No reason to have a type that excludes 0
template <typename T> concept Arithmetic = std::integral<T> || std::floating_point<T>;



#define COMMON_REAL(types...) std::common_type_t<types, X>
#define REAL_TEMPLATE(return_type, class_name, additional_template...) template <std::floating_point R> additional_template constexpr return_type class_name<R>::
#define REAL_TEMPLATE_OTHER(return_type, class_name) REAL_TEMPLATE(return_type, class_name, template <std::floating_point X>)

// CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_UTIL_HPP_
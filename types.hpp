#pragma once
#include "header.hpp"

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

template <typename T> concept Real = std::convertible_to<T, real>;
template <typename T> concept Rational = std::convertible_to<T, rational>;
template <typename T> concept Integer = std::convertible_to<T, integer> && std::integral<T>;
template <typename T> concept Whole = std::convertible_to<T, whole> && std::signed_integral<T>;
template <typename T> concept Natural = Whole<T>; //No reason to have a type that excludes 0
template <typename T> concept Arithmetic = std::integral<T> || std::floating_point<T>;
template <typename E> concept Enum = std::is_enum_v<E> && requires { E::ENUM_TERMINATOR; };
template <typename D> concept Duration = std::chrono::__is_duration<D>::value;



#define COMMON_REAL(types...) std::common_type_t<types, X>
#define REAL_TEMPLATE(return_type, class_name, additional_template...) template <std::floating_point R> additional_template constexpr return_type class_name<R>::
#define REAL_TEMPLATE_OTHER(return_type, class_name) REAL_TEMPLATE(return_type, class_name, template <std::floating_point X>)
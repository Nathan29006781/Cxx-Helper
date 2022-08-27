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
template <typename E> concept Enum = std::is_enum_v<E>;

#define REAL_TEMPLATE(return_type, class_name, ...) template <std::floating_point R> __VA_ARGS__ constexpr return_type class_name<R>::
#define REAL_TEMPLATE_OTHER template <std::floating_point X>
#define COMMON_REAL std::common_type_t<R, X>

//Enum Definitions
  template <Enum E>
  constexpr E next_enum_value(E enum_value){
    int value = static_cast<int>(enum_value);

    if (value < static_cast<int>(E::NUM_OF_ELEMENTS) - 1) value++;
    else value = 0;

    return static_cast<E>(value);
  }
  template <Enum E>
  constexpr E previous_enum_value(E enum_value){
    int value = static_cast<int>(enum_value);
    
    if (value > 0) value--;
    else value = static_cast<int>(E::NUM_OF_ELEMENTS) - 1;

    return static_cast<E>(value);
  }
  template <Enum E>
  constexpr E& operator++ (E& enum_value){
    enum_value = next_enum_value(enum_value);
    return enum_value;
  }
  template <Enum E>
  constexpr E& operator-- (E& enum_value){
    enum_value = previous_enum_value(enum_value);
    return enum_value;
  }
  template <Enum E>
  constexpr E operator++ (E& enum_value, int){
    E old = enum_value;
    ++enum_value;
    return old;
  }
  template <Enum E>
  constexpr E operator-- (E& enum_value, int){
    E old = enum_value;
    --enum_value;
    return old;
  }
#pragma once
#include "headers.hpp"

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

//Enum Definitions
  template <typename E, typename = typename std::enable_if_t<std::is_enum_v<E>, void>>
  constexpr E next_enum_value(E enum_value){
    int value = static_cast<int>(enum_value);

    if (value < static_cast<int>(E::NUM_OF_ELEMENTS) - 1) value++;
    else value = 0;

    return static_cast<E>(value);
  }
  template <typename E, typename = typename std::enable_if_t<std::is_enum_v<E>, void>>
  constexpr E previous_enum_value(E enum_value){
    int value = static_cast<int>(enum_value);
    
    if (value > 0) value--;
    else value = static_cast<int>(E::NUM_OF_ELEMENTS) - 1;

    return static_cast<E>(value);
  }
  template <typename E, typename = typename std::enable_if_t<std::is_enum_v<E>, void>>
  constexpr E& operator++ (E& enum_value){
    enum_value = next_enum_value(enum_value);
    return enum_value;
  }
  template <typename E, typename = typename std::enable_if_t<std::is_enum_v<E>, void>>
  constexpr E& operator-- (E& enum_value){
    enum_value = previous_enum_value(enum_value);
    return enum_value;
  }
  template <typename E, typename = typename std::enable_if_t<std::is_enum_v<E>, void>>
  constexpr E operator++ (E& enum_value, int){
    E old = enum_value;
    ++enum_value;
    return old;
  }
  template <typename E, typename = typename std::enable_if_t<std::is_enum_v<E>, void>>
  constexpr E operator-- (E& enum_value, int){
    E old = enum_value;
    --enum_value;
    return old;
  }
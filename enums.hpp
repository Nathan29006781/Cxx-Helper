#pragma once
#include "header.hpp"
#include "types.hpp"

template <Enum E>
constexpr E next_enum_value(const E& enum_value){
  typedef std::underlying_type_t<E> Int;

  Int value = static_cast<Int>(enum_value);

  if (value < static_cast<Int>(E::ENUM_TERMINATOR) - 1) return static_cast<E>(value+1);
  else return static_cast<E>(0);
}

template <Enum E>
constexpr E previous_enum_value(const E& enum_value){
  typedef std::underlying_type_t<E> Int;

  Int value = static_cast<Int>(enum_value);
  
  if (value > 0) return static_cast<E>(value-1);
  else return static_cast<E>(static_cast<Int>(E::ENUM_TERMINATOR) - 1);
}

//Prefix increment operator
template <Enum E>
constexpr E& operator++ (E& enum_value){
  return enum_value = next_enum_value(enum_value);
}

//Prefix decrement operator
template <Enum E>
constexpr E& operator-- (E& enum_value){
  return enum_value = previous_enum_value(enum_value);
}

//Postfix increment operator
template <Enum E>
constexpr E operator++ (E& enum_value, int){
  E old = enum_value;
  ++enum_value;
  return old;
}

//Postfix decrement operator
template <Enum E>
constexpr E operator-- (E& enum_value, int){
  E old = enum_value;
  --enum_value;
  return old;
}

template<typename charT, typename traits, Enum E>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const E& enum_value){
  return os << static_cast<std::underlying_type_t<E>>(enum_value);
}
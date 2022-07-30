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


//Assumes enum values are consecutive
template <typename T>
T operator++ (T enum_type, int) {
  return static_cast<T>(static_cast<int>(enum_type) + 1);
}

//Assumes enum values are consecutive
template <typename T>
T operator-- (T enum_type, int) {
  return static_cast<T>(static_cast<int>(enum_type) - 1);
}

template <typename T, typename = typename std::enable_if_t<std::is_enum_v<T>, void>>
T next_enum_value(T enum_type) {
  if (static_cast<int>(enum_type) < static_cast<int>(T::NUM_OF_ELEMENTS) - 1) return enum_type++;
  else return static_cast<T>(0);
}

template <typename T, typename = typename std::enable_if_t<std::is_enum_v<T>, void>>
T previous_enum_value(T enum_type) {
  if (static_cast<int>(enum_type) > static_cast<int>(static_cast<T>(0))) return enum_type--;
  else return static_cast<T>(static_cast<int>(T::NUM_OF_ELEMENTS) - 1);
}
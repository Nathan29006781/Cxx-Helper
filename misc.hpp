//copy parameter pack to tuple
//logic operators on multiple operands. a == (b or c)
//text splitter
#pragma once
#include "headers.hpp"


void split(std::string& str, int count){
  auto chunk_size = str.size()/count;

  for(int i=0; i<count; i++){

  }
}


constexpr int bool_to_sgn(bool value){
  return value ? 1 : -1;
}

constexpr bool sgn_to_bool(int value){
  return value > 0 ? 1 : 0;
}

template <typename T, typename = typename std::enable_if_t<std::is_arithmetic_v<T>, void>>
constexpr int sgn(T value){
  return (T(0) < value) - (value < T(0));
}

#define waitUntil(condition) while(!(condition)) delay(10);
#define repeatUntil(condition) while(delay(10),!(condition))

/**
 * @brief checks whether a value is in range
 * 
 * @param value value to be checked
 * @param minimum range minimum value
 * @param maximum range maximum value
 * @return whether value is between minimum and maximum. will work even if maximum < minimum
 */
template <typename T>
inline constexpr bool in_range(T value, T minimum, T maximum){
  return ((minimum <= value && value <= maximum) || (maximum <= value && value <= minimum));
}
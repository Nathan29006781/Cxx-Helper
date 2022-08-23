#pragma once
#include "headers.hpp"

constexpr int bool_to_sgn(bool value){
  return value ? 1 : -1;
}

template <Arithmetic T>
constexpr bool sgn_to_bool(T value){
  return value > 0 ? true : false;
}

template <Arithmetic T>
constexpr int sgn(T value){
  return (value == 0) ? 0 : ((value > 0) ? 1 : -1);
}

#define loop_to(from, to) for(int loop_counter = from, loop_counter_b = to; loop_counter < to; loop_counter++, loop_counter_b--)
#define loop(count) loop_to(0, count)
#define forever() while(true)
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
constexpr bool in_range(T value, T minimum, T maximum){
  return ((minimum <= value && value <= maximum) || (maximum <= value && value <= minimum));
}
#pragma once
#include "header.hpp"

inline constexpr int bool_to_sgn(bool value) {return value ? 1 : -1;}

template <Arithmetic T>
inline constexpr bool sgn_to_bool(T value) {return value > 0 ? true : false;}

template <Arithmetic T>
inline constexpr int sgn(T value) {return (value == 0) ? 0 : ((value > 0) ? 1 : -1);} //use copysign

#define loop_to(from, to) for(auto loop_counter = from, loop_counter_b = to; loop_counter < to; loop_counter++, loop_counter_b--)
#define loop(count) loop_to(static_cast<decltype(count)>(0), count)
#define forever() while(true)
#define waitUntil(condition) while(!(condition)) delay(10);
#define repeatUntil(condition) while(delay(10),!(condition))

template <typename T1, typename T2, typename T3>
inline constexpr bool in_range(T1 value, T2 minimum, T3 maximum){
  return ((minimum < value && value < maximum) || (maximum < value && value < minimum));
}

template <typename T1, typename T2, typename T3>
inline constexpr bool in_range_inclusive(T1 value, T2 minimum, T3 maximum){
  return ((minimum <= value && value <= maximum) || (maximum <= value && value <= minimum));
}
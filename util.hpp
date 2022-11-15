#ifndef CXX_HELPER_UTIL_HPP_
#define CXX_HELPER_UTIL_HPP_

#include "header_config.hpp"
#include "types.hpp"

#define loop_to(from, to) for(auto loop_counter{from}, loop_counter_b{to}; loop_counter < to; loop_counter++, loop_counter_b--)
#define loop(count) loop_to(static_cast<decltype(count)>(0), count)
#define forever() while(true)
#define waitUntil(condition) while(!(condition)) delay(10);
#define repeatUntil(condition) while(delay(10),!(condition))

CXX_HELPER_BEGIN_NAMESPACE

inline constexpr int bool_to_sgn(bool value) {return value ? 1 : -1;}

template <Arithmetic T>
inline constexpr bool sgn_to_bool(T value) {return value > 0;}

template <Arithmetic T>
inline constexpr int sgn(T value) {return __sign(value);}

template <typename T1, typename T2, typename T3>
inline constexpr bool in_range(T1 value, T2 minimum, T3 maximum){
  return (minimum < value && value < maximum) || (maximum < value && value < minimum);
}

template <typename T1, typename T2, typename T3>
inline constexpr bool in_range_inclusive(T1 value, T2 minimum, T3 maximum){
  return (minimum <= value && value <= maximum) || (maximum <= value && value <= minimum);
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_UTIL_HPP_
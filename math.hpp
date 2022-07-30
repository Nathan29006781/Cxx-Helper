#include <type_traits>
//integrals
//derivatives
//limits
//series sum/prod
//algebra
//integer exponentiation
//common math sequences: triangular numbers, perfect squares, fibonnaci, matrices
//Next base-k number (k=2: 101 -> 110) (k=3: 101 -> 102)
//Base converter

namespace constants{
  template<class T> constexpr T pi = T(3.14159265358979323846264338327950288L);
  template<class T> constexpr T phi = T(1.61803398874989484820458683436563811L);
  template<class T> constexpr T e = T(2.71828182845904523536028747135266250L);
  template<class T> constexpr T euler_mascheroni = T(0.57721566490153286060651209008240243L);
  template<class T> constexpr T apery = T(1.20205690315959428539973816151144999L);
  template<class T> constexpr T plastic = T(1.32471795724474602596090885447809734L);
}

/*equations:
Printing: 0a+ -1b +c => -b + c
isolate for a variable
combining equations (elimination/ maybe substitution)
solve an equation
*/

//for calc, see if possible to apply to equations directly

//Good upto 70th number
constexpr long long fibonacci(int n){
  return round((pow(constants::phi<long double>, n) - pow(1-constants::phi<long double>, n)) / (2*constants::phi<long double>-1));
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
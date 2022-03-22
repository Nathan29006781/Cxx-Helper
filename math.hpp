#include <type_traits>
//integrals
//derivatives
//limits
//series sum/prod
//algebra
//integer exponentiation
//sgn
//common math sequences: triangular numbers, perfect squares, fibonnaci, matrices
//Next base-k number (k=2: 101 -> 110) (k=3: 101 -> 102)
//Base converter

/*equations:
Printing: 0a+ -1b +c => -b + c
isolate for a variable
combining equations (elimination/ maybe substitution)
solve an equation
*/

//for calc, see if possible to apply to equations directly

int bool_to_sgn(bool value){
  return value ? 1 : -1;
}

bool sgn_to_bool(int value){
  return value > 0 ? 1 : 0;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, void>::type>
int sgn(T value){
  return (T(0) < value) - (value < T(0));
}

#define waitUntil(condition) while(delay(10),!(condition))

/**
 * @brief checks whether a value is in range
 * 
 * @param value value to be checked
 * @param minimum range minimum value
 * @param maximum range maximum value
 * @return whether value is between minimum and maximum. will work even if maximum < minimum
 */
template <typename T>
inline bool in_range(T value, T minimum, T maximum){
  return (minimum <= value && value <= maximum) || (maximum <= value && value <= minimum);
}

/**
 * @brief Gets the sign of a value (0, 1 or -1)
 * 
 * @param value 
 * @return template <typename T> 
 */
template <typename T>
int sgn(T value){
  return (T(0) < value) - (value < T(0));
}

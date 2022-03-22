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

template <typename T1, typename T2, typename T3>
inline const bool in_range(T1 value, T2 min, T3 max){
  return ((min <= value && value <= max) || (max <= value && value <= min));
}

// gets the sign of a value (0, 1 or -1)
template <typename T>
int sgn(T value){
  return (T(0) < value) - (value < T(0));
}

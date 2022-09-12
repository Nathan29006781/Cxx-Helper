#pragma once
#include "../../header.hpp"
#include "../../types.hpp"

//matrices

// template <Arithmetic T>
// constexpr long double hypotenuse(T value){
//   return std::abs(value);
// }

template <Arithmetic... Ts>
constexpr auto hypotenuse(Ts... values){
  return sqrt(((values*values) + ...));
}



template <std::floating_point R> struct Point;
template <std::floating_point R> struct Position;
template <std::floating_point R> struct Vector;

#include "angles.hpp"
#include "point.hpp"
#include "position.hpp"
#include "../linear_algebra/vector.hpp"

#include "point.tpp"
#include "position.tpp"
#include "../linear_algebra/vector.tpp"
#pragma once
#include "../../header.hpp"
#include "../../types.hpp"

//matrices

template <Arithmetic T>
constexpr long double hypotenuse(T value){
  return std::abs(value);
}

template <Arithmetic T, Arithmetic... Ts>
constexpr long double hypotenuse(T value, Ts... values){
  return std::hypot(value, hypotenuse(values...));
}



template <std::floating_point R> struct Point;
template <std::floating_point R> struct Position;
template <std::floating_point R> struct Vector;

#include "point.hpp"
#include "position.hpp"
#include "vector.hpp"

#include "point.tpp"
#include "position.tpp"
#include "vector.tpp"
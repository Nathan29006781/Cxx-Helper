#pragma once
#include "../../header.hpp"
#include "../../types.hpp"

//matrices

template <Arithmetic... Ts>
constexpr auto hypotenuse(Ts... values){
  return sqrt(((values*values) + ...));
}


template <std::floating_point R> struct Position;
class Vector;

#include "angles.hpp"
#include "position.hpp"
#include "../linear_algebra/vector.hpp"

#include "position.tpp"
#include "../linear_algebra/vector.tpp"
#pragma once
#include "../../header.hpp"
#include "../../types.hpp"

//matrices

template <Arithmetic... Ts>
inline constexpr auto hypotenuse(Ts... values) {return sqrt(((values*values) + ...));}


template <std::floating_point R> struct Position;
class Vector;

#include "angles.hpp"
#include "position.hpp"
#include "vector.hpp"

#include "position.tpp"
#include "vector.tpp"
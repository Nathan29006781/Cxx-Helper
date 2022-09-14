#ifndef CXX_HELPER_MATH_GEOMETRY_HPP_
#define CXX_HELPER_MATH_GEOMETRY_HPP_

#include "../../header_config.hpp"
#include "../../types.hpp"

//matrices

CXX_HELPER_BEGIN_NAMESPACE

template <Arithmetic... Ts>
inline constexpr auto hypotenuse(Ts... values) {return sqrt(((values*values) + ...));}


CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_GEOMETRY_HPP_
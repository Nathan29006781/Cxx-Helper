#ifndef CXX_HELPER_MATH_POSITION_HPP_
#define CXX_HELPER_MATH_POSITION_HPP_

#include "../../header_config.hpp"
#include "../geometry/angles.hpp"
#include "vector.hpp"

CXX_HELPER_BEGIN_NAMESPACE

class Vector;
class Position{
  public:
    typedef real value_type;
    value_type x, y, angle;

  //Constructors
    constexpr Position(): x{0.0}, y{0.0}, angle{0.0} {}
    constexpr explicit Position(Vector vector): x{vector.x()}, y{vector.y()}, angle{0.0} {}
    constexpr Position(value_type x, value_type y): x{x}, y{y}, angle{0.0} {}
    constexpr Position(value_type x, value_type y, value_type angle): x{x}, y{y}, angle{angle} {}

    constexpr Position& invert(){
      value_type x{this->x}, y{this->y};
      this->x = y, this->y = x;
      angle = M_PI_2 - angle;
      return *this;
    }

  //Operators
    friend constexpr Position operator* (Position const& position, value_type scalar) {return {position.x*scalar, position.y*scalar, position.angle*scalar};}
    friend constexpr Position operator* (value_type scalar, Position const& position) {return position*scalar;}
    friend constexpr Position operator/ (Position const& position, value_type scalar) {return position * (1 / scalar);}
    friend constexpr Position operator/ (value_type scalar, Position const& position) {return {position.x / scalar, position.y / scalar, position.angle / scalar};}
    constexpr bool operator== (Position const& p2) const {return (x == p2.x) && (y == p2.y) && (angle == p2.angle);}
    constexpr bool operator!= (Position const& p2) const {return !(*this == p2);}
    constexpr Position operator+ (Position const& p2) const {return {x + p2.x, y + p2.y, angle + p2.angle};}
    constexpr Position operator- (Position const& p2) const {return {x - p2.x, y - p2.y, angle - p2.angle};}
    constexpr Position& operator*= (value_type scalar) {return *this = *this * scalar;}
    constexpr Position& operator/= (value_type scalar) {return *this = *this / scalar;}
};

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_POSITION_HPP_
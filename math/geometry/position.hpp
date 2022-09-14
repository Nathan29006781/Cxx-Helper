#ifndef CXX_HELPER_MATH_POSITION_HPP_
#define CXX_HELPER_MATH_POSITION_HPP_

#include "../../header_config.hpp"
#include "../geometry/angles.hpp"
#include "vector.hpp"

CXX_HELPER_BEGIN_NAMESPACE

class Vector;

template <std::floating_point R>
struct Position{
  double x, y, angle;

  //Constructors
    constexpr Position<R>();
    constexpr explicit Position<R>(Vector vector);
    constexpr Position<R>(double x, double y);
    constexpr Position<R>(double x, double y, double angle);

    constexpr Position<R>& invert();

  //Operators
    friend constexpr Position<R> operator* (const Position<R>&, double);
    friend constexpr Position<R> operator* (double, const Position<R>&);
    friend constexpr Position<R> operator/ (const Position<R>&, double);
    friend constexpr Position<R> operator/ (double, const Position<R>&);
    constexpr bool operator== (const Position<R>& p2) const;
    constexpr bool operator!= (const Position<R>& p2) const;
    constexpr Position<R> operator+ (const Position<R>& p2) const;
    constexpr Position<R> operator- (const Position<R>& p2) const;
    constexpr Position<R>& operator*= (double scalar);
    constexpr Position<R>& operator/= (double scalar);
};

template <std::floating_point R> constexpr Position<R>::Position(): x(0.0), y(0.0), angle(0.0){}
template <std::floating_point R> constexpr Position<R>::Position(Vector vector): x(vector.x()), y(vector.y()), angle(0.0){}
template <std::floating_point R> constexpr Position<R>::Position(double x, double y): x(x), y(y), angle(0.0){}
template <std::floating_point R> constexpr Position<R>::Position(double x, double y, double angle): x(x), y(y), angle(angle){}


template <std::floating_point R> 
constexpr Position<R>& Position<R>::invert(){
  double x = this->x, y = this->y;
  this->x = y, this->y = x;
  angle = M_PI_2 - angle;
  return *this;
}

template <std::floating_point R> 
constexpr Position<R> operator* (const Position<R>& position, double scalar){
  return {position.x*scalar, position.y*scalar, position.angle*scalar};
}
template <std::floating_point R> 
constexpr Position<R> operator* (double scalar, const Position<R>& position){
  return position*scalar;
}
template <std::floating_point R> 
constexpr Position<R> operator/ (const Position<R>& position, double scalar){
  return position * (1 / scalar);
}
template <std::floating_point R> 
constexpr Position<R> operator/ (double scalar, const Position<R>& position){
  return {position.x / scalar, position.y / scalar, position.angle / scalar};
}
template <std::floating_point R> 
constexpr bool Position<R>::operator== (const Position<R>& p2) const{
  return (x == p2.x) && (y == p2.y) && (angle == p2.angle);
}
template <std::floating_point R> 
constexpr bool Position<R>::operator!= (const Position<R>& p2) const{
  return !(*this == p2);
}
template <std::floating_point R> 
constexpr Position<R> Position<R>::operator+ (const Position<R>& p2) const{
  return {x + p2.x, y + p2.y, angle + p2.angle};
}
template <std::floating_point R> 
constexpr Position<R> Position<R>::operator- (const Position<R>& p2) const{
  return {x - p2.x, y - p2.y, angle - p2.angle};
}
template <std::floating_point R> 
constexpr Position<R>& Position<R>::operator*= (double scalar){
  return *this = *this * scalar;
}
template <std::floating_point R> 
constexpr Position<R>& Position<R>::operator/= (double scalar){
  return *this = *this / scalar;
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_POSITION_HPP_
#pragma once
#include "../../header.hpp"

template <std::floating_point R> struct Position;
template <std::floating_point R> struct Vector;

template <std::floating_point R>
struct Point{
  double x, y;
  
  //Constructors
    constexpr Point<R>();
    constexpr explicit Point<R>(Vector<R> vector);
    constexpr Point<R>(Position<R> position);
    constexpr Point<R>(double x, double y);

  //Methods
    constexpr Point<R>& invert();
  
  //Operators
    friend constexpr Point<R> operator* (const Point<R>&, double);
    friend constexpr Point<R> operator* (double, const Point<R>&);
    friend constexpr Point<R> operator/ (const Point<R>&, double);
    friend constexpr Point<R> operator/ (double, const Point<R>&);
    constexpr bool operator== (const Point<R>& p2) const;
    constexpr bool operator!= (const Point<R>& p2) const;
    constexpr Point<R> operator+ (const Point<R>& p2) const;
    constexpr Point<R> operator- (const Point<R>& p2) const;
    constexpr Position<R> operator+ (const Position<R>& p2) const;
    constexpr Position<R> operator- (const Position<R>& p2) const;
    constexpr Point<R>& operator*= (double scalar);
    constexpr Point<R>& operator/= (double scalar);
};

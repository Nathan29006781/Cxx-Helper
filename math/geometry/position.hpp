#pragma once
#include "../../header.hpp"

template <std::floating_point R> struct Point;
template <std::floating_point R> struct Vector;

template <std::floating_point R>
struct Position{
  double x, y, angle;

  //Constructors
    constexpr Position<R>();
    constexpr explicit Position<R>(Vector<R> vector);
    constexpr Position<R>(Point<R> point);
    constexpr Position<R>(Point<R> point, double angle);
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
    constexpr Position<R> operator+ (const Point<R>& p2) const;
    constexpr Position<R> operator- (const Point<R>& p2) const;
    constexpr Position<R>& operator*= (double scalar);
    constexpr Position<R>& operator/= (double scalar);
};

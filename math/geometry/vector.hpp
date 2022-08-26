#pragma once
#include "../../header.hpp"
#include "../../types.hpp"

template <std::floating_point R> struct Point;
template <std::floating_point R> struct Position;

template <std::floating_point R>
struct Vector{
  // private:
    std::complex<R> point;
    constexpr Vector(std::complex<R> point);

  public:
    //Constructors
      constexpr Vector(R x = R(), R y = R());
      constexpr explicit Vector(Point<R> p1);
      constexpr explicit Vector(Point<R> p1, Point<R> p2); //Can't use default argument with previous because that makes it -p1
      REAL_TEMPLATE_OTHER constexpr Vector(Vector<X> other); //For Vectors of different underlying floating type
    //Polar Construction Helper
      static constexpr Vector polar(R magnitude, R angle);

    //Modifying Methods
      constexpr Vector& set_cartesian(R x, R y);
      constexpr Vector& set_cartesian(Point<R> point);
      constexpr Vector& set_cartesian(Point<R> p2, Point<R> p1);
      constexpr Vector& set_polar(R magnitude, R angle);
    
    //Methods
      constexpr Vector& invert();
      constexpr Vector& rotate(R angle);

    //Getters
      constexpr R x() const;
      constexpr R y() const;
      constexpr R magnitude() const;
      constexpr R angle() const;

    //Setters
      constexpr void x(R x);
      constexpr void y(R y);
      constexpr void magnitude(R magnitude);
      constexpr void angle(R angle);

    //Operators w/ Scalars
      constexpr Vector& operator*=(R scalar);
      constexpr Vector& operator/=(R scalar);
      REAL_TEMPLATE_OTHER constexpr Vector operator*(const X& scalar);
      REAL_TEMPLATE_OTHER constexpr Vector operator/(const X& scalar);


      // constexpr bool operator== (const Vector& p2) const;
      // constexpr bool operator!= (const Vector& p2) const;

      //Binary ops are defined outside class for symmetry
};
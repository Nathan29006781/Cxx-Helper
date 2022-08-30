#pragma once
#include "../../header.hpp"
#include "../../types.hpp"

template <std::floating_point R> struct Point;
template <std::floating_point R> struct Position;

template <std::floating_point R>
struct Vector{
  private:
    std::complex<R> point;
    constexpr explicit Vector(std::complex<R> point);

  public:
    //Constructors
      constexpr Vector(R x = R(), R y = R());
      constexpr explicit Vector(Point<R> p1);
      constexpr explicit Vector(Point<R> p1, Point<R> p2); //Can't use default argument with previous because that makes it -p1
      template <std::floating_point X> constexpr Vector(Vector<X> other); //For Vectors of different underlying floating type
      //Polar Construction Helper defined outside class

    //Modifying Methods
      constexpr Vector& set_cartesian(R x, R y);
      constexpr Vector& set_cartesian(Point<R> point);
      constexpr Vector& set_cartesian(Point<R> p2, Point<R> p1);
      constexpr Vector& set_polar(R magnitude, R angle);
      constexpr Vector& invert();
      constexpr Vector& rotate(R angle);
      constexpr Vector& flip_x();
      constexpr Vector& flip_y();
    
    //Methods
      constexpr bool is_zero_vector() const;
      constexpr bool is_unit_vector() const;
      constexpr Vector unit_vector() const;
      template <std::floating_point X> constexpr COMMON_REAL(R) angle(const Vector<X>& vector) const;
      // angle between two vectors


    //Getters
      constexpr R x() const;
      constexpr R y() const;
      constexpr R magnitude() const;
      constexpr R angle() const;
      constexpr R magnitude_square() const;


    //Setters
      constexpr void x(R x);
      constexpr void y(R y);
      constexpr void magnitude(R magnitude);
      constexpr void angle(R angle);

    //Scalar Operators
      constexpr Vector& operator*=(R scalar);
      constexpr Vector& operator/=(R scalar);
      template <Arithmetic X> constexpr Vector operator*(const X& scalar) const;
      template <Arithmetic X> constexpr Vector operator/(const X& scalar) const;
      //scalar * vector (implemented out of class)

    //Vector Operators
      template <std::floating_point X> constexpr Vector& operator+=(const Vector<X>& vector);
      template <std::floating_point X> constexpr Vector& operator-=(const Vector<X>& vector);
      template <std::floating_point X> constexpr Vector operator+(const Vector<X>& vector) const;
      template <std::floating_point X> constexpr Vector operator-(const Vector<X>& vector) const;
      template <std::floating_point X> constexpr COMMON_REAL(R) operator*(const Vector<X>& vector) const; //Dot product

    //Boolean Operators
      template <std::floating_point X> constexpr bool operator==(const Vector<X>& vector) const;
      template <std::floating_point X> constexpr bool operator!= (const Vector<X>& vector) const;

    //ostream operator
      template<typename charT, typename traits, std::floating_point T> friend
      std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Vector<T>& vector);
};
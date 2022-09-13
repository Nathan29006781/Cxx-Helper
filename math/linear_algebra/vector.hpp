#pragma once
#include "../../header.hpp"
#include "../../types.hpp"
#include "../geometry/angles.hpp"
#include "../../printing.hpp"

template <std::floating_point real> struct Position;

class Vector{
  private:
    std::complex<real> point;
    constexpr explicit Vector(std::complex<real> point);

  public:
    //Constructors
      constexpr Vector(real x = 0, real y = 0);
      //Polar Construction Helper defined outside class

    //Modifying Methods
      constexpr Vector& set_cartesian(real x, real y);
      constexpr Vector& set_polar(real magnitude, Angle angle);
      constexpr Vector& invert();
      constexpr Vector& rotate(Angle angle);
      constexpr Vector& flip_x();
      constexpr Vector& flip_y();
    
    //Methods
      constexpr bool is_zero_vector() const;
      constexpr bool is_unit_vector() const;
      constexpr Vector normalize() const;
      constexpr Angle angle(const Vector& other) const;

    //Getters
      constexpr real x() const;
      constexpr real y() const;
      constexpr real magnitude() const;
      constexpr Angle angle() const;
      constexpr real square() const;

    //Setters
      constexpr void x(real x);
      constexpr void y(real y);
      constexpr void magnitude(real magnitude);
      constexpr void angle(Angle angle);

    //Scalar Operators
      constexpr Vector& operator*=(real scalar);
      constexpr Vector& operator/=(real scalar);
      constexpr Vector operator*(real scalar) const;
      constexpr Vector operator/(real scalar) const;
      //scalar * vector (implemented out of class)

    //Vector Operators
      constexpr Vector& operator+=(const Vector& other);
      constexpr Vector& operator-=(const Vector& other);
      constexpr Vector operator+(const Vector& other) const;
      constexpr Vector operator-(const Vector& other) const;
      constexpr real operator*(const Vector& other) const; //Dot product

    //Boolean Operators
      constexpr bool operator==(const Vector& other) const;
      constexpr bool operator!= (const Vector& other) const;

    //Unary Operators
      constexpr Vector operator+() const;
      constexpr Vector operator-() const;

    //ostream operator
      template<typename charT, typename traits> friend
      std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Vector& vector);
};

inline std::string convert_all_args(const std::string& fmt, const Vector& arg){
  std::stringstream ss;
  ss << arg;
  // OUTPUT(ss.str());
  return '(' + convert_all_args(fmt, arg.x()) + ", " + convert_all_args(fmt, arg.y()) + ")";
}

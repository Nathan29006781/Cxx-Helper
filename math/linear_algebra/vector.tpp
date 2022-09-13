#include "../../types.hpp"

//Constructors
  constexpr  Vector::Vector(std::complex<real> point): point(point) {};
  constexpr  Vector::Vector(real x, real y): Vector(std::complex<real>(x, y)) {};

//Polar construction helper
  constexpr Vector polar(real magnitude, Angle angle){
    Vector vector;
    return vector.set_polar(magnitude, angle);
  }

//Modifying Methods
  constexpr Vector& Vector::set_cartesian(real x, real y){
    this->x(x);
    this->y(y);
    return *this;
  }

  constexpr Vector& Vector::set_polar(real magnitude, Angle angle){
    point = std::polar(magnitude, angle.rad());
    return *this;
  }

  constexpr Vector& Vector::invert() {return set_cartesian(y(), x());}
  constexpr Vector& Vector::rotate(Angle angle) {return set_polar(magnitude(), this->angle() + angle);}
  constexpr Vector& Vector::flip_x() {x(-x()); return *this;}
  constexpr Vector& Vector::flip_y() {y(-y()); return *this;}


//Methods
  constexpr bool Vector::is_zero_vector() const {return square() == 0;}
  constexpr bool Vector::is_unit_vector() const {return square() == 1;}
  constexpr Vector Vector::normalize() const {return (*this) / magnitude();}
  constexpr Angle Vector::angle(const Vector& other) const {return Angle::acos((*this * other) / std::sqrt(square() * other.square()));}


//Getters
  constexpr real Vector::x() const {return point.real();}
  constexpr real Vector::y() const {return point.imag();}
  constexpr real Vector::magnitude() const {return std::abs(point);}
  constexpr real Vector::square() const {return std::norm(point);}
  constexpr Angle Vector::angle() const {return Angle::arg(point);}

//Setters
  constexpr void Vector::x(real x) {point.real(x);}
  constexpr void Vector::y(real y) {point.imag(y);}
  constexpr void Vector::magnitude(real magnitude) {set_polar(magnitude, angle());}
  constexpr void Vector::angle(Angle angle) {set_polar(magnitude(), angle);}

//Scalar Operators
  constexpr Vector& Vector::operator*=(real scalar) {point *= scalar; return *this;}
  constexpr Vector& Vector::operator/=(real scalar) {point /= scalar; return *this;}
  constexpr Vector Vector::operator*(real rhs) const {return Vector(point * rhs);}
  constexpr Vector Vector::operator/(real rhs) const {return Vector(point / rhs);}

  //scalar * vector (implemented out of class)
  constexpr Vector operator*(real lhs, const Vector& rhs) {return rhs * lhs;}

//Vector Operators
  constexpr Vector& Vector::operator+=(const Vector& other) {point += other.point; return *this;}
  constexpr Vector& Vector::operator-=(const Vector& other) {point -= other.point; return *this;}
  constexpr Vector Vector::operator+(const Vector& other) const {return Vector(point + std::complex<real>(other.point));}
  constexpr Vector Vector::operator-(const Vector& other) const {return *this + (-other);}
  constexpr real Vector::operator*(const Vector& other) const {return x()*other.x() + y()*other.y();}
  
//Boolean Operators
  constexpr bool Vector::operator==(const Vector& other) const {return point == std::complex<real>(other.point);}
  constexpr bool Vector::operator!=(const Vector& other) const {return point != std::complex<real>(other.point);}


//Unary Operators
  constexpr Vector Vector::operator+() const {return *this;}
  constexpr Vector Vector::operator-() const {return Vector(-point);}

//Printing
  template<typename charT, typename traits>
  std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Vector& vector){
    return os << vector.point;
  }
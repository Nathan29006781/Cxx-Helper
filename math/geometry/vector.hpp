#ifndef CXX_HELPER_MATH_VECTOR_HPP_
#define CXX_HELPER_MATH_VECTOR_HPP_

#include "../../header_config.hpp"
#include "../geometry/angles.hpp"
#include "../../printing.hpp"

CXX_HELPER_BEGIN_NAMESPACE

template <std::floating_point real> struct Position;

class Vector{
  public:
    typedef real value_type;

  private:
    std::complex<value_type> point;
    constexpr explicit Vector(std::complex<value_type> point): point(point) {}

  public:

    //Constructors
      constexpr Vector(value_type x = 0, value_type y = 0): Vector(std::complex<value_type>(x, y)) {}
      constexpr Vector make_polar(value_type magnitude, const Angle& angle) {return Vector(polar(magnitude, angle));}

    //Modifying Methods
      constexpr Vector& set_cartesian(value_type x, value_type y){
        this->x(x);
        this->y(y);
        return *this;
      }

      constexpr Vector& set_polar(value_type magnitude, const Angle& angle){
        point = std::polar(magnitude, angle.rad());
        return *this;
      }

      constexpr Vector& invert() {return set_cartesian(y(), x());}
      constexpr Vector& rotate(const Angle& angle) {return set_polar(magnitude(), this->angle() + angle);}
      constexpr Vector& flip_x() {x(-x()); return *this;}
      constexpr Vector& flip_y() {y(-y()); return *this;}
    
    //Methods
      constexpr bool is_zero_vector() const {return square() == 0;}
      constexpr bool is_unit_vector() const {return square() == 1;}
      constexpr Vector normalize() const {return (*this) / magnitude();}

    //const Angle& functions
      constexpr Angle angle(const Vector& other) const {return Angle::acos((*this * other) / std::sqrt(square() * other.square()));}
      constexpr value_type scalar_project(const Vector& other) const {return vector_project(other).magnitude();}
      constexpr Vector vector_project(const Vector& other) const {return other * (*this * other) / other.square();}
      constexpr value_type scalar_reject(const Vector& other) const {return vector_reject(other).magnitude();}
      constexpr Vector vector_reject(const Vector& other) const {return (*this) - vector_project(other);}


    //Getters
      constexpr value_type x() const {return point.real();}
      constexpr value_type y() const {return point.imag();}
      constexpr value_type magnitude() const {return std::abs(point);}
      constexpr value_type square() const {return std::norm(point);}
      constexpr Angle angle() const {return Angle::arg(point);}

    //Setters
      constexpr void x(value_type x) {point.real(x);}
      constexpr void y(value_type y) {point.imag(y);}
      constexpr void magnitude(value_type magnitude) {set_polar(magnitude, angle());}
      constexpr void angle(const Angle& angle) {set_polar(magnitude(), angle);}

    //Scalar Operators
      constexpr Vector& operator*=(value_type scalar) {point *= scalar; return *this;}
      constexpr Vector& operator/=(value_type scalar) {point /= scalar; return *this;}
      constexpr Vector operator*(value_type scalar) const {return Vector(point * scalar);}
      constexpr Vector operator/(value_type scalar) const {return Vector(point / scalar);}
      //scalar * vector (implemented out of class)

    //Vector Operators
      constexpr Vector& operator+=(const Vector& other) {point += other.point; return *this;}
      constexpr Vector& operator-=(const Vector& other) {point -= other.point; return *this;}
      constexpr Vector operator+(const Vector& other) const {return Vector(point + std::complex<value_type>(other.point));}
      constexpr Vector operator-(const Vector& other) const {return *this + (-other);}
      constexpr value_type operator*(const Vector& other) const {return x()*other.x() + y()*other.y();} //Dot product

    //Boolean Operators
      constexpr bool operator==(const Vector& other) const {return point == std::complex<value_type>(other.point);}
      constexpr bool operator!= (const Vector& other) const {return point != std::complex<value_type>(other.point);}

    //Unary Operators
      constexpr Vector operator+() const {return *this;}
      constexpr Vector operator-() const {return Vector(-point);}

    //ostream operator
      template<typename charT, typename traits> friend
      std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Vector& vector);
};

inline std::string convert_all_args(const std::string& fmt, const Vector& arg){
  std::stringstream ss;
  ss << arg;
  // OUTPUT(ss.str());
  return "(" + convert_all_args(fmt, arg.x()) + ", " + convert_all_args(fmt, arg.y()) + ")";
}

//scalar * vector (implemented out of class)
  constexpr Vector operator*(Vector::value_type lhs, const Vector& rhs) {return rhs * lhs;}
  
//Printing
  template<typename charT, typename traits>
  std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Vector& vector){
    return os << vector.point;
  }


CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_VECTOR_HPP_
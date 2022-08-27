#include "../../types.hpp"

//Constructors
  REAL_TEMPLATE(, Vector) Vector(std::complex<R> point): point(point) {};
  REAL_TEMPLATE(, Vector) Vector(R x, R y): point(std::complex<R>(x, y)) {};
  REAL_TEMPLATE(, Vector) Vector(Point<R> p1) {set_cartesian(p1);}
  REAL_TEMPLATE(, Vector) Vector(Point<R> p1, Point<R> p2) {set_cartesian(p2-p1);}
  REAL_TEMPLATE(, Vector, REAL_TEMPLATE_OTHER) Vector(Vector<X> other) {set_cartesian(static_cast<R>(other.x()), static_cast<R>(other.y()));}

//Polar construction helper
  REAL_TEMPLATE(Vector<R>, Vector) polar(R magnitude, R angle){
    Vector<R> vector;
    return vector.set_polar(magnitude, angle);
  }

//Modifying Methods
  REAL_TEMPLATE(Vector<R>&, Vector) set_cartesian(R x, R y){
    point.real(x);
    point.imag(y);
    return *this;
  }

  REAL_TEMPLATE(Vector<R>&, Vector) set_cartesian(Point<R> point){
    return set_cartesian(point.x, point.y);
  }

  REAL_TEMPLATE(Vector<R>&, Vector) set_cartesian(Point<R> p2, Point<R> p1){
    return set_cartesian(p2-p1);
  }

  REAL_TEMPLATE(Vector<R>&, Vector) set_polar(R magnitude, R angle){
    point = std::polar(magnitude, angle);
    return *this;
  }

//Methods
  REAL_TEMPLATE(Vector<R>&, Vector) invert() {return set_cartesian(y(), x());}
  REAL_TEMPLATE(Vector<R>&, Vector) rotate(R angle) {return set_polar(magnitude(), this->angle() + angle);}
  REAL_TEMPLATE(bool, Vector) is_zero_vector() {return x() == 0 && y() == 0;}

//Getters
  REAL_TEMPLATE(R, Vector) x() const {return point.real();}
  REAL_TEMPLATE(R, Vector) y() const {return point.imag();}
  REAL_TEMPLATE(R, Vector) magnitude() const {return std::abs(point);}
  REAL_TEMPLATE(R, Vector) angle() const {return std::arg(point);}

//Setters
  REAL_TEMPLATE(void, Vector) x(R x) {point.real(x);}
  REAL_TEMPLATE(void, Vector) y(R y) {point.imag(y);}
  REAL_TEMPLATE(void, Vector) magnitude(R magnitude) {set_polar(magnitude, angle());}
  REAL_TEMPLATE(void, Vector) angle(R angle) {set_polar(magnitude(), angle);}

//Scalar Operators
  REAL_TEMPLATE(Vector<R>&, Vector) operator*=(R scalar) {point *= scalar; return *this;}
  REAL_TEMPLATE(Vector<R>&, Vector) operator/=(R scalar) {point /= scalar; return *this;}
  REAL_TEMPLATE(Vector<R>, Vector, template <Arithmetic X>) operator*(const X& rhs) const {return point * static_cast<R>(rhs);}
  REAL_TEMPLATE(Vector<R>, Vector, template <Arithmetic X>) operator/(const X& rhs) const {return point / static_cast<R>(rhs);}

  //scalar * vector (implemented out of class)
  template <Arithmetic X, std::floating_point R> constexpr Vector<R> operator*(const X& lhs, const Vector<R>& rhs) {return rhs * lhs;}

//Vector Operators
  REAL_TEMPLATE(Vector<R>&, Vector, REAL_TEMPLATE_OTHER) operator+=(const Vector<X>& vector) {point += vector.point; return *this;}
  REAL_TEMPLATE(Vector<R>&, Vector, REAL_TEMPLATE_OTHER) operator-=(const Vector<X>& vector) {point -= vector.point; return *this;}
  REAL_TEMPLATE(Vector<R>, Vector, REAL_TEMPLATE_OTHER) operator+(const Vector<X>& vector) const {return point + std::complex<R>(vector.point);}
  REAL_TEMPLATE(Vector<R>, Vector, REAL_TEMPLATE_OTHER) operator-(const Vector<X>& vector) const {return point - std::complex<R>(vector.point);}
  REAL_TEMPLATE(COMMON_REAL, Vector, REAL_TEMPLATE_OTHER) operator*(const Vector<X>& vector) const {return x()*vector.x() + y()*vector.y();}
  
//Boolean Operators
  REAL_TEMPLATE(bool, Vector, REAL_TEMPLATE_OTHER) operator== (const Vector<X>& vector) const {return point == std::complex<R>(vector.point);}
  REAL_TEMPLATE(bool, Vector, REAL_TEMPLATE_OTHER) operator!= (const Vector<X>& vector) const {return point != std::complex<R>(vector.point);}

  template<typename charT, typename traits, std::floating_point R> std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Vector<R>& vector){
    return os << vector.point;
  }
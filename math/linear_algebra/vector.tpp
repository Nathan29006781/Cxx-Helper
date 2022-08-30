#include "../../types.hpp"

//Constructors
  REAL_TEMPLATE(, Vector) Vector(std::complex<R> point): point(point) {};
  REAL_TEMPLATE(, Vector) Vector(R x, R y): point(std::complex<R>(x, y)) {};
  // REAL_TEMPLATE(, Vector) Vector(Point<R> p1) {set_cartesian(p1);}
  // REAL_TEMPLATE(, Vector) Vector(Point<R> p1, Point<R> p2) {set_cartesian(p2-p1);}
  REAL_TEMPLATE_OTHER(, Vector) Vector(Vector<X> other) {set_cartesian(static_cast<R>(other.x()), static_cast<R>(other.y()));}

//Polar construction helper
  template <Arithmetic T, Arithmetic X> constexpr Vector<COMMON_REAL(T)> polar(T magnitude, X angle){
    Vector<COMMON_REAL(T)> vector;
    return vector.set_polar(magnitude, angle);
  }

//Modifying Methods
  REAL_TEMPLATE(Vector<R>&, Vector) set_cartesian(R x, R y){
    this->x(x);
    this->y(y);
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

  REAL_TEMPLATE(Vector<R>&, Vector) invert() {return set_cartesian(y(), x());}
  REAL_TEMPLATE(Vector<R>&, Vector) rotate(R angle) {return set_polar(magnitude(), this->angle() + angle);}
  REAL_TEMPLATE(Vector<R>&, Vector) flip_x() {x(-x()); return *this;}
  REAL_TEMPLATE(Vector<R>&, Vector) flip_y() {y(-y()); return *this;}


//Methods
  REAL_TEMPLATE(bool, Vector) is_zero_vector() const {return magnitude_square() == 0;}
  REAL_TEMPLATE(bool, Vector) is_unit_vector() const {return magnitude_square() == 1;}
  REAL_TEMPLATE(Vector<R>, Vector) unit_vector() const {return (*this) / magnitude();}
  REAL_TEMPLATE(COMMON_REAL(R), Vector, template <std::floating_point X>) angle(const Vector<X>& vector) const {return std::acos(((*this)*vector) / std::sqrt(this->magnitude_square()*vector.magnitude_square()));}


//Getters
  REAL_TEMPLATE(R, Vector) x() const {return point.real();}
  REAL_TEMPLATE(R, Vector) y() const {return point.imag();}
  REAL_TEMPLATE(R, Vector) magnitude() const {return std::abs(point);}
  REAL_TEMPLATE(R, Vector) angle() const {return std::arg(point);}
  REAL_TEMPLATE(R, Vector) magnitude_square() const {return std::norm(point);}

//Setters
  REAL_TEMPLATE(void, Vector) x(R x) {point.real(x);}
  REAL_TEMPLATE(void, Vector) y(R y) {point.imag(y);}
  REAL_TEMPLATE(void, Vector) magnitude(R magnitude) {set_polar(magnitude, angle());}
  REAL_TEMPLATE(void, Vector) angle(R angle) {set_polar(magnitude(), angle);}

//Scalar Operators
  REAL_TEMPLATE(Vector<R>&, Vector) operator*=(R scalar) {point *= scalar; return *this;}
  REAL_TEMPLATE(Vector<R>&, Vector) operator/=(R scalar) {point /= scalar; return *this;}
  REAL_TEMPLATE(Vector<R>, Vector, template <Arithmetic X>) operator*(const X& rhs) const {return Vector<R>(point * static_cast<R>(rhs));}
  REAL_TEMPLATE(Vector<R>, Vector, template <Arithmetic X>) operator/(const X& rhs) const {return Vector<R>(point / static_cast<R>(rhs));}

  //scalar * vector (implemented out of class)
  template <Arithmetic X, std::floating_point R> constexpr Vector<R> operator*(const X& lhs, const Vector<R>& rhs) {return rhs * lhs;}

//Vector Operators
  REAL_TEMPLATE_OTHER(Vector<R>&, Vector) operator+=(const Vector<X>& vector) {point += vector.point; return *this;}
  REAL_TEMPLATE_OTHER(Vector<R>&, Vector) operator-=(const Vector<X>& vector) {point -= vector.point; return *this;}
  REAL_TEMPLATE_OTHER(Vector<R>, Vector) operator+(const Vector<X>& vector) const {return Vector<R>(point + std::complex<R>(vector.point));}
  REAL_TEMPLATE_OTHER(Vector<R>, Vector) operator-(const Vector<X>& vector) const {return Vector<R>(point - std::complex<R>(vector.point));}
  REAL_TEMPLATE(COMMON_REAL(R), Vector, template <std::floating_point X>) operator*(const Vector<X>& vector) const {return x()*vector.x() + y()*vector.y();} //cannot use REAL_TEMPLATE_OTHER because COMMON_REAL expands too early with that many levels of nested macros
  
//Boolean Operators
  REAL_TEMPLATE_OTHER(bool, Vector) operator== (const Vector<X>& vector) const {return point == std::complex<R>(vector.point);}
  REAL_TEMPLATE_OTHER(bool, Vector) operator!= (const Vector<X>& vector) const {return point != std::complex<R>(vector.point);}

  template<typename charT, typename traits, std::floating_point T>
  std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Vector<T>& vector){
    return os << vector.point;
  }
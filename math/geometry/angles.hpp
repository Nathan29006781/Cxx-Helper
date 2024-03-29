#ifndef CXX_HELPER_MATH_ANGLE_HPP_
#define CXX_HELPER_MATH_ANGLE_HPP_

#include "../../header_config.hpp"

#include "../../util.hpp"
#include "../constants.hpp"
#include "../functions.hpp"

#define angle_switch(rad_, deg_, rot_) ((_mode == angle_mode::RADIAN) ? rad_ : ((_mode == angle_mode::DEGREE) ? deg_ : rot_))

CXX_HELPER_BEGIN_NAMESPACE

enum class angle_mode{
  RADIAN,
  DEGREE,
  ROTATION
};

class Angle;

inline constexpr Angle radians(real angle);
inline constexpr Angle degrees(real angle);
inline constexpr Angle rotations(real angle);

class Angle{
  public:
    using value_type = real;

  private:
    value_type _angle;
    angle_mode _mode;

    //_c for conversion
    static constexpr value_type rad_c{1};
    static constexpr value_type deg_c{constants::π/180.0}; //converts degrees to radians
    static constexpr value_type rot_c{constants::τ}; //converts rotations to radians

    constexpr Angle(value_type angle, angle_mode mode): _angle{angle}, _mode{mode} {_angle *= angle_switch(rad_c, deg_c, rot_c);}

  public:

  //Out-of-class constructors
    constexpr friend Angle radians(real angle);
    constexpr friend Angle degrees(real angle);
    constexpr friend Angle rotations(real angle);

  //Angle getters
    constexpr value_type radians() const {return _angle/rad_c;}
    constexpr value_type degrees() const {return _angle/deg_c;}
    constexpr value_type rotations() const {return _angle/rot_c;}
    constexpr value_type rad() const {return radians();}
    constexpr value_type deg() const {return degrees();}
    constexpr value_type rot() const {return rotations();}
 
  //String getters
    std::string rad_str() const {std::stringstream ss; ss << rad(); return ss.str() + "rad";}
    std::string deg_str() const {std::stringstream ss; ss << deg(); return ss.str() + "deg";}
    std::string rot_str() const {std::stringstream ss; ss << rot(); return ss.str() + "rot";}
    std::string str() const {return angle_switch(rad_str(), deg_str(), rot_str());}

  //Angle classifiers
    bool is_acute() const {return in_range(deg(), 0, 90);}
    bool is_obtuse() const {return in_range(deg(), 90, 180);}
    bool is_reflex() const {return in_range(deg(), 180, 360);}
    bool is_right() const {return deg() == 90;}
    bool is_straight() const {return deg() == 180;}
    bool is_full() const {return deg() == 360;}

  //Reference angle functions
    constexpr Angle closest_equivalent(Angle const & reference) const {return *this + NATHAN_M_PROJECT_NAME::radians(closest_multiple((reference - *this).rad(), constants::τ));}
    constexpr Angle complementary() const {return -(*this - NATHAN_M_PROJECT_NAME::degrees(90));} //Do not simplify. This accounts for angle_mode
    constexpr Angle supplementary() const {return -(*this - NATHAN_M_PROJECT_NAME::degrees(180));}
    constexpr Angle explementary() const {return -(*this - NATHAN_M_PROJECT_NAME::degrees(360));}
    constexpr Angle mod(value_type arg = rot_c) const {return Angle{std::fmod(rad(), arg) / angle_switch(rad_c, deg_c, rot_c), _mode};}

  //Inverse trig
    static Angle asin(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::asin(arg));}
    static Angle acos(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::acos(arg));}
    static Angle atan(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::atan(arg));}
    static Angle atan2(value_type y, value_type x) {return NATHAN_M_PROJECT_NAME::radians(std::atan2(y, x));}
    static Angle asinh(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::asinh(arg));}
    static Angle acosh(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::acosh(arg));}
    static Angle atanh(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::atanh(arg));}
    template <std::floating_point R>
    static Angle arg(std::complex<R> complex) {return NATHAN_M_PROJECT_NAME::radians(std::arg(complex));}

  //Math operators
    constexpr Angle operator+() const {return *this;}
    constexpr Angle operator-() const {return angle_switch(NATHAN_M_PROJECT_NAME::radians(-rad()), NATHAN_M_PROJECT_NAME::degrees(-deg()), NATHAN_M_PROJECT_NAME::rotations(-rot()));}
    constexpr Angle operator+(Angle const & other) const {return angle_switch(NATHAN_M_PROJECT_NAME::radians(rad()+other.rad()), NATHAN_M_PROJECT_NAME::degrees(deg()+other.deg()), NATHAN_M_PROJECT_NAME::rotations(rot()+other.rot()));}
    constexpr Angle operator-(Angle const & other) const {return *this + (-other);}
    constexpr Angle& operator+=(Angle const & other) {_angle += other.rad(); return *this;}
    constexpr Angle& operator-=(Angle const & other) {_angle -= other.rad(); return *this;}

  //Increment operators
    constexpr Angle& operator++() {_angle += Angle{1, _mode}.rad(); return *this;}
    constexpr Angle& operator--() {_angle -= Angle{1, _mode}.rad(); return *this;}
    constexpr Angle operator++(int) {Angle old{*this}; this->operator++(); return old;}
    constexpr Angle operator--(int) {Angle old{*this}; this->operator--(); return old;}
  
  //Scalar operators
    template <std::floating_point R>
    constexpr std::complex<R> operator*(std::complex<R> const & complex) const {return rad() * complex;}
    constexpr Angle operator*(value_type scalar) const {Angle a(*this); a._angle *= scalar; return a;}
    template <std::floating_point R>
    constexpr std::complex<R> operator/(std::complex<R> const & complex) const {return rad() / complex;}
    constexpr Angle operator/(value_type scalar) const {Angle a(*this); a._angle /= scalar; return a;}
    //Reverse parameter order outside class

  //Boolean operators
    constexpr bool operator==(Angle const & other) const {return rad() == other.rad();}
    constexpr bool operator!=(Angle const & other) const {return rad() != other.rad();}
};

//Outside class
inline constexpr Angle radians(real angle) {return Angle{angle, angle_mode::RADIAN};}
inline constexpr Angle degrees(real angle) {return Angle{angle, angle_mode::DEGREE};}
inline constexpr Angle rotations(real angle) {return Angle{angle, angle_mode::ROTATION};}


inline constexpr Angle operator ""_rad(real angle)  {return radians(angle);}
inline constexpr Angle operator ""_rad(unsigned long long angle) {return radians(angle);}
inline constexpr Angle operator ""_deg(real angle)  {return degrees(angle);}
inline constexpr Angle operator ""_deg(unsigned long long angle) {return degrees(angle);}
inline constexpr Angle operator ""_rot(real angle)  {return rotations(angle);}
inline constexpr Angle operator ""_rot(unsigned long long angle) {return rotations(angle);}

//Trigonometry/Exp
inline constexpr Angle::value_type sin (Angle const & angle) {return std::sin (angle.rad());}
inline constexpr Angle::value_type cos (Angle const & angle) {return std::cos (angle.rad());}
inline constexpr Angle::value_type tan (Angle const & angle) {return std::tan (angle.rad());}
inline constexpr Angle::value_type sinh(Angle const & angle) {return std::sinh(angle.rad());}
inline constexpr Angle::value_type cosh(Angle const & angle) {return std::cosh(angle.rad());}
inline constexpr Angle::value_type tanh(Angle const & angle) {return std::tanh(angle.rad());}
inline constexpr Angle::value_type exp (Angle const & angle) {return std::exp (angle.rad());}
inline constexpr std::complex<Angle::value_type> polar(Angle::value_type magnitude, Angle const & angle) {return std::polar(magnitude, angle.rad());}
inline constexpr std::complex<Angle::value_type> cis(Angle const & angle) {return polar(1, angle);}

//Scalar operators reverse order
template <std::floating_point R>
inline constexpr std::complex<R> operator*(std::complex<R> const & complex, Angle const & angle) {return angle * complex;}
inline constexpr Angle operator*(Angle::value_type scalar, Angle const & angle) {return angle * scalar;}
template <std::floating_point R>
inline constexpr std::complex<R> operator/(std::complex<R> const & complex, Angle const & angle) {return angle / complex;}
inline constexpr Angle operator/(Angle::value_type scalar, Angle const & angle) {return angle / scalar;}

template<typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, Angle const & angle){
  return os << angle.str();
}


CXX_HELPER_END_NAMESPACE
#undef angle_switch
#endif //CXX_HELPER_MATH_ANGLE_HPP_
#pragma once
#include "../../header.hpp"
#include "../constants.hpp"
#include "../functions.hpp"
#include "../../types.hpp"

#define angle_switch(rad_, deg_, rot_) (_mode == angle_mode::RADIAN) ? rad_ : ((_mode == angle_mode::DEGREE) ? deg_ : rot_);

enum class angle_mode{
  DEGREE,
  RADIAN,
  ROTATION
};

class Angle;

inline constexpr Angle radians(real angle);
inline constexpr Angle degrees(real angle);
inline constexpr Angle rotations(real angle);

class Angle{
  private:
    real _angle;
    angle_mode _mode;

    constexpr explicit Angle(real angle, angle_mode mode): _angle(angle), _mode(mode) {_angle *= angle_switch(1, constants::pi<>/180.0, constants::tau<>)};

  public:
    inline constexpr friend Angle radians(real angle);
    inline constexpr friend Angle degrees(real angle);
    inline constexpr friend Angle rotations(real angle);

  //Angle getters
    inline constexpr real radians() const {return _angle;}
    inline constexpr real degrees() const {return _angle*180.0/constants::pi<>;}
    inline constexpr real rotations() const {return _angle/constants::tau<>;}
    inline constexpr real rad() const {return radians();}
    inline constexpr real deg() const {return degrees();}
    inline constexpr real rot() const {return rotations();}


  //String getters
    inline std::string rad_str() const {return std::to_string(rad()) + "rad";}
    inline std::string deg_str() const {return std::to_string(deg()) + "deg";}
    inline std::string rot_str() const {return std::to_string(rot()) + "rot";}
    inline std::string str() const {return angle_switch(rad_str(), deg_str(), rot_str());}

  //Data checkers
    bool is_acute() const {return in_range(deg(), 0, 90);};
    bool is_obtuse() const {return in_range(deg(), 90, 180);};
    bool is_reflex() const {return in_range(deg(), 180, 360);};
    bool is_right() const {return deg() == 90;};
    bool is_straight() const {return deg() == 180;};
    bool is_full() const {return deg() == 360;};

  //Inverse Trigonometry
    static inline Angle asin(real arg) {return ::radians(std::asin(arg));};
    static inline Angle acos(real arg) {return ::radians(std::acos(arg));};
    static inline Angle atan(real arg) {return ::radians(std::atan(arg));};
    static inline Angle atan2(real y, real x) {return ::radians(std::atan2(y, x));};
    static inline Angle asinh(real arg) {return ::radians(std::asinh(arg));};
    static inline Angle acosh(real arg) {return ::radians(std::acosh(arg));};
    static inline Angle atanh(real arg) {return ::radians(std::atanh(arg));};

  //Reference angle functions
    inline constexpr Angle closest_equivalent(const Angle& reference) const {return *this + ::radians(closest_multiple((reference - *this).rad(), constants::tau<>));}

  //Math operators
    inline constexpr Angle operator+() const {return *this;}
    inline constexpr Angle operator-() const {return angle_switch(::radians(-rad()), ::degrees(-deg()), ::rotations(-rot()));}
    inline constexpr Angle operator+(const Angle& other) const {return angle_switch(::radians(rad()+other.rad()), ::degrees(deg()+other.deg()), ::rotations(rot()+other.rot()));}
    inline constexpr Angle operator-(const Angle& other) const {return *this + (-other);}
    inline constexpr Angle& operator+=(const Angle& other) {_angle += other.rad(); return *this;};
    inline constexpr Angle& operator-=(const Angle& other) {_angle -= other.rad(); return *this;};

  //Increment operators
    inline constexpr Angle& operator++() {_angle += Angle{1, _mode}.rad(); return *this;};
    inline constexpr Angle& operator--() {_angle -= Angle{1, _mode}.rad(); return *this;};
    inline constexpr Angle operator++(int) {Angle old = *this; this->operator++(); return old;};
    inline constexpr Angle operator--(int) {Angle old = *this; this->operator--(); return old;};

  //Boolean operators
    inline constexpr bool operator==(const Angle& other) const {return rad() == other.rad();};
    inline constexpr bool operator!=(const Angle& other) const {return rad() != other.rad();};
};

//Outside class
inline constexpr Angle radians(real angle) {return Angle{angle, angle_mode::RADIAN};}
inline constexpr Angle degrees(real angle) {return Angle{angle, angle_mode::DEGREE};}
inline constexpr Angle rotations(real angle) {return Angle{angle, angle_mode::ROTATION};}


inline constexpr Angle operator ""_rad(real angle)  {return radians(angle);}
inline constexpr Angle operator ""_rad(whole angle) {return radians(angle);}
inline constexpr Angle operator ""_deg(real angle)  {return degrees(angle);}
inline constexpr Angle operator ""_deg(whole angle) {return degrees(angle);}
inline constexpr Angle operator ""_rot(real angle)  {return rotations(angle);}
inline constexpr Angle operator ""_rot(whole angle) {return rotations(angle);}

//Trigonometry
inline constexpr real sin(const Angle& angle) {return std::sin(angle.rad());}
inline constexpr real cos(const Angle& angle) {return std::cos(angle.rad());}
inline constexpr real tan(const Angle& angle) {return std::tan(angle.rad());}
inline constexpr real sinh(const Angle& angle) {return std::sinh(angle.rad());}
inline constexpr real cosh(const Angle& angle) {return std::cosh(angle.rad());}
inline constexpr real tanh(const Angle& angle) {return std::tanh(angle.rad());}



template<typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Angle& angle){
  return os << angle.str();
}
#pragma once
#include "../constants.hpp"
#include "../../types.hpp"

#include <cmath>

class Angle;

inline constexpr Angle radians(real angle);
inline constexpr Angle degrees(real angle);

class Angle{
  private:
    real _angle;
    bool radian_mode;

    constexpr explicit Angle(real angle, bool radian_mode): _angle(angle), radian_mode(radian_mode) {};

  public:
    inline constexpr friend Angle radians(real angle);
    inline constexpr friend Angle degrees(real angle);

  //Angle getters
    inline constexpr real degrees() const {return _angle*180.0/constants::pi<>;}
    inline constexpr real radians() const {return _angle;}
    inline constexpr real deg() const {return degrees();}
    inline constexpr real rad() const {return radians();}

  //String getters
    inline std::string deg_str() const {return std::to_string(deg()) + "deg";}
    inline std::string rad_str() const {return std::to_string(rad()) + "rad";}
    inline std::string str() const {return radian_mode ? rad_str() : deg_str();}

  //Data checkers
    bool acute() const {return false;};
    bool obtuse() const {return false;};
    bool reflex() const {return false;};
    bool right() const {return false;};
    bool straight() const {return false;};
    bool full() const {return false;};

  //Inverse Trigonometry
    static inline Angle asin(real arg) {return ::radians(std::asin(arg));};
    static inline Angle acos(real arg) {return ::radians(std::acos(arg));};
    static inline Angle atan(real arg) {return ::radians(std::atan(arg));};
    static inline Angle atan2(real y, real x) {return ::radians(std::atan2(y, x));};
    static inline Angle asinh(real arg) {return ::radians(std::asinh(arg));};
    static inline Angle acosh(real arg) {return ::radians(std::acosh(arg));};
    static inline Angle atanh(real arg) {return ::radians(std::atanh(arg));};

    //closest angle to angle
    //mod360

  //Math operators
    inline constexpr Angle operator+() const {return *this;}
    inline constexpr Angle operator-() const {return ::radians(-rad());}
    inline constexpr Angle operator+(const Angle& other) const {return radian_mode ? ::radians(rad()+other.rad()) : ::degrees(deg()+other.deg());}
    inline constexpr Angle operator-(const Angle& other) const {return *this + (-other);}
    inline constexpr Angle& operator+=(const Angle& other) {_angle += other.rad(); return *this;};
    inline constexpr Angle& operator-=(const Angle& other) {_angle -= other.rad(); return *this;};

  //Boolean operators
    inline constexpr bool operator==(const Angle& other) const {return rad() == other.rad();};
    inline constexpr bool operator!=(const Angle& other) const {return rad() != other.rad();};
};


inline constexpr Angle radians(real angle) {return Angle{angle, true};}
inline constexpr Angle degrees(real angle) {return Angle{angle*constants::pi<>/180.0, false};}

inline constexpr Angle operator ""_rad(real angle)  {return radians(angle);}
inline constexpr Angle operator ""_rad(whole angle) {return radians(angle);}
inline constexpr Angle operator ""_r(real angle)    {return radians(angle);}
inline constexpr Angle operator ""_r(whole angle)   {return radians(angle);}

inline constexpr Angle operator ""_deg(real angle)  {return degrees(angle);}
inline constexpr Angle operator ""_deg(whole angle) {return degrees(angle);}
inline constexpr Angle operator ""_d(real angle)    {return degrees(angle);}
inline constexpr Angle operator ""_d(whole angle)   {return degrees(angle);}

//Trigonometry
inline constexpr real sin(Angle angle) {return std::sin(angle.rad());}
inline constexpr real cos(Angle angle) {return std::cos(angle.rad());}
inline constexpr real tan(Angle angle) {return std::tan(angle.rad());}
inline constexpr real sinh(Angle angle) {return std::sinh(angle.rad());}
inline constexpr real cosh(Angle angle) {return std::cosh(angle.rad());}
inline constexpr real tanh(Angle angle) {return std::tanh(angle.rad());}



template<typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Angle& angle){
  return os << angle.str();
}
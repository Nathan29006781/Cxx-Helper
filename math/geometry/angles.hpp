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
    typedef real value_type;

  public:
    value_type _angle;
    angle_mode _mode;

    //_c for conversion
    static inline constexpr value_type rad_c = 1;
    static inline constexpr value_type deg_c = constants::pi<value_type>/180.0; //converts degrees to radians
    static inline constexpr value_type rot_c = constants::tau<value_type>; //converts rotations to radians

    constexpr Angle(value_type angle, angle_mode mode): _angle(angle), _mode(mode) {_angle *= angle_switch(rad_c, deg_c, rot_c);};

  public:

  //Out-of-class constructors
    inline constexpr friend Angle radians(real angle);
    inline constexpr friend Angle degrees(real angle);
    inline constexpr friend Angle rotations(real angle);

  //Angle getters
    inline constexpr value_type radians() const {return _angle/rad_c;}
    inline constexpr value_type degrees() const {return _angle/deg_c;}
    inline constexpr value_type rotations() const {return _angle/rot_c;}
    inline constexpr value_type rad() const {return radians();}
    inline constexpr value_type deg() const {return degrees();}
    inline constexpr value_type rot() const {return rotations();}
 
  //String getters
    inline std::string rad_str() const {std::stringstream ss; ss << rad(); return ss.str() + "rad";}
    inline std::string deg_str() const {std::stringstream ss; ss << deg(); return ss.str() + "deg";}
    inline std::string rot_str() const {std::stringstream ss; ss << rot(); return ss.str() + "rot";}
    inline std::string str() const {return angle_switch(rad_str(), deg_str(), rot_str());}

  //Angle classifiers
    bool is_acute() const {return in_range(deg(), 0, 90);};
    bool is_obtuse() const {return in_range(deg(), 90, 180);};
    bool is_reflex() const {return in_range(deg(), 180, 360);};
    bool is_right() const {return deg() == 90;};
    bool is_straight() const {return deg() == 180;};
    bool is_full() const {return deg() == 360;};

  //Reference angle functions
    inline constexpr Angle closest_equivalent(const Angle& reference) const {return *this + NATHAN_M_PROJECT_NAME::radians(closest_multiple((reference - *this).rad(), constants::tau<>));}
    inline constexpr Angle complementary() const {return -(*this - NATHAN_M_PROJECT_NAME::degrees(90));} //Do not simplify. This accounts for angle_mode
    inline constexpr Angle supplementary() const {return -(*this - NATHAN_M_PROJECT_NAME::degrees(180));}
    inline constexpr Angle explementary() const {return -(*this - NATHAN_M_PROJECT_NAME::degrees(360));}
    inline constexpr Angle mod(value_type arg = rot_c) const {return Angle{std::fmod(rad(), arg) / angle_switch(rad_c, deg_c, rot_c), _mode};};

  //Inverse Trigonometry
    static inline Angle asin(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::asin(arg));};
    static inline Angle acos(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::acos(arg));};
    static inline Angle atan(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::atan(arg));};
    static inline Angle atan2(value_type y, value_type x) {return NATHAN_M_PROJECT_NAME::radians(std::atan2(y, x));};
    static inline Angle asinh(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::asinh(arg));};
    static inline Angle acosh(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::acosh(arg));};
    static inline Angle atanh(value_type arg) {return NATHAN_M_PROJECT_NAME::radians(std::atanh(arg));};
    template <std::floating_point R>
    static inline Angle arg(std::complex<R> complex) {return NATHAN_M_PROJECT_NAME::radians(std::arg(complex));};

  //Math operators
    inline constexpr Angle operator+() const {return *this;}
    inline constexpr Angle operator-() const {return angle_switch(NATHAN_M_PROJECT_NAME::radians(-rad()), NATHAN_M_PROJECT_NAME::degrees(-deg()), NATHAN_M_PROJECT_NAME::rotations(-rot()));}
    inline constexpr Angle operator+(const Angle& other) const {return angle_switch(NATHAN_M_PROJECT_NAME::radians(rad()+other.rad()), NATHAN_M_PROJECT_NAME::degrees(deg()+other.deg()), NATHAN_M_PROJECT_NAME::rotations(rot()+other.rot()));}
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
inline constexpr Angle::value_type sin(const Angle& angle) {return std::sin(angle.rad());}
inline constexpr Angle::value_type cos(const Angle& angle) {return std::cos(angle.rad());}
inline constexpr Angle::value_type tan(const Angle& angle) {return std::tan(angle.rad());}
inline constexpr Angle::value_type sinh(const Angle& angle) {return std::sinh(angle.rad());}
inline constexpr Angle::value_type cosh(const Angle& angle) {return std::cosh(angle.rad());}
inline constexpr Angle::value_type tanh(const Angle& angle) {return std::tanh(angle.rad());}

template<typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const Angle& angle){
  return os << angle.str();
}


CXX_HELPER_END_NAMESPACE
#undef angle_switch
#endif //CXX_HELPER_MATH_ANGLE_HPP_
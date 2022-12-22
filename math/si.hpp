#ifndef CXX_HELPER_SI_HPP_
#define CXX_HELPER_SI_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include <cmath>
#include <ratio>
#include <sstream>

CXX_HELPER_BEGIN_NAMESPACE

template <int m, int s, int kg, int A, int K, int mol, int cd> struct Dimension;
using base = std::ratio<1>;
template <instance_of_non_type<Dimension> D, instance_of_non_type<std::ratio> R> class Unit;

//The __VA_ARGS__ are because ratio_multiply has commas
#define scale_unit_helper(name, letter, dimension, ...)\
using name##s = Unit<dimension, __VA_ARGS__>;\
namespace si_literals{\
  name##s operator ""_##letter(real val) {return val;}\
  name##s operator ""_##letter(unsigned long long val) {return val;}\
}\

#define scale_unit(name, letter, dimension, ...)\
scale_unit_helper(milli##name, m##letter, dimension, std::ratio_multiply<__VA_ARGS__, std::milli>);\
scale_unit_helper(       name,    letter, dimension, std::ratio_multiply<__VA_ARGS__,       base>);\
scale_unit_helper(kilo ##name, k##letter, dimension, std::ratio_multiply<__VA_ARGS__, std::kilo >);\



template <int m = 0, int s = 0, int kg = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
struct Dimension{
  template <instance_of_non_type<Dimension> D, instance_of_non_type<std::ratio> R> friend class Unit;
  private:
    real value;

    constexpr real& get_value() {return value;}
  public:
    constexpr Dimension(real value = 0): value{value} {}

    constexpr real get_value() const {return value;}

    constexpr Dimension operator+=(Dimension const & rhs) {get_value() += rhs.get_value(); return get_value();}

    template <int m2, int s2, int kg2, int A2, int K2, int mol2, int cd2>
    constexpr Dimension<m+m2, s+s2, kg+kg2, A+A2, K+K2, mol+mol2, cd+cd2> operator*(Dimension<m2, s2, kg2, A2, K2, mol2, cd2> const & rhs) const {return get_value()*rhs.get_value();}

    template <int m2, int s2, int kg2, int A2, int K2, int mol2, int cd2>
    constexpr Dimension<m-m2, s-s2, kg-kg2, A-A2, K-K2, mol-mol2, cd-cd2> operator/(Dimension<m2, s2, kg2, A2, K2, mol2, cd2> const & rhs) const {return get_value()/rhs.get_value();}
};

using Unitless                   = Dimension<>;
using Length                     = Dimension<1>;
using Time                       = Dimension<0, 1>;
using Mass                       = Dimension<0, 0, 1>;
using Current                    = Dimension<0, 0, 0, 1>;
using Temperature                = Dimension<0, 0, 0, 0, 1>;
using Amount                     = Dimension<0, 0, 0, 0, 0, 1>;
using Luminous_Intensity         = Dimension<0, 0, 0, 0, 0, 0, 1>;
using Area                       = decltype(Length{}*Length{});
using Volume                     = decltype(Area{}*Length{});
using Velocity                   = decltype(Length{}/Time{});
using Acceleration               = decltype(Velocity{}/Time{});
using Momentum                   = decltype(Mass{}*Velocity{});
using Force                      = decltype(Mass{}*Acceleration{});
using Density                    = decltype(Mass{}/Volume{});
using Energy                     = decltype(Force{}*Length{});
using Charge                     = decltype(Current{}*Time{});
using Power                      = decltype(Energy{}/Time{});
using Pressure                   = decltype(Energy{}/Area{});
using Voltage                    = decltype(Energy{}/Charge{});
using Resistance                 = decltype(Voltage{}/Current{});
using Capacitance                = decltype(Charge{}/Voltage{});
using Electric_Field_Strength    = decltype(Force{}/Charge{});
using Magnetic_Flux              = decltype(Voltage{}*Time{});
using Magnetic_Flux_Density      = decltype(Magnetic_Flux{}/Area{});
using Inductance                 = decltype(Resistance{}*Time{});
using Conductance                = decltype(Unitless{}/Resistance{});
using Permitivitty               = decltype(Capacitance{}/Length{});
using Permeability               = decltype(Inductance{}/Length{});
using Heat_Capacity              = decltype(Energy{}/Temperature{});
using Specific_Heat_Capacity     = decltype(Heat_Capacity{}/Mass{});
using Radiation_Dose             = decltype(Energy{}/Mass{});
using Molar_Mass                 = decltype(Mass{}/Amount{});
using Catalytic_Activity         = decltype(Amount{}/Time{});
using Illuminance                = decltype(Luminous_Intensity{}/Area{});
using Gravitational_Coupling     = decltype(Acceleration{}*Area{}/Mass{});
using Wavenumber                 = decltype(Unitless{}/Length{});
using Frequency                  = decltype(Unitless{}/Time{});
using Inverse_Mass               = decltype(Unitless{}/Mass{});
using Meter_Rating               = decltype(Unitless{}/Current{});
using Inverse_Amount             = decltype(Unitless{}/Amount{});
using Inverse_Luminous_Intensity = decltype(Unitless{}/Luminous_Intensity{});


template <instance_of_non_type<Dimension> D, instance_of_non_type<std::ratio> R = base>
class Unit{
  private:
  public:
    D dimension;
    std::ratio<R::num, R::den> multiplier;

    constexpr D& get_dimension() {return dimension;}
    constexpr real& get_value() {return get_dimension().get_value();}

  public:
    constexpr Unit(real value = 0): dimension{value} {}
    constexpr Unit(D dimension): dimension{dimension} {}

    template <instance_of_non_type<std::ratio> R2>
    constexpr Unit(Unit<D, R2> const & rhs): dimension{rhs.get_value()*std::ratio_divide<R2, R>::num/std::ratio_divide<R2, R>::den} {}

    constexpr D const & get_dimension () const {return dimension;}
    constexpr D const & get_cdimension() const {return get_dimension();}
    constexpr real get_value () const {return get_dimension().get_value();}
    constexpr real get_cvalue() const {return get_value();}
    std::string string() const {std::stringstream ss; ss << get_value(); return ss.str();}

    template <instance_of_non_type<std::ratio> R2> constexpr Unit& operator+=(Unit<D, R2> const & rhs)       {get_dimension() += Unit{rhs}.get_dimension(); return *this;} //Assignment Plus
    template <instance_of_non_type<std::ratio> R2> constexpr Unit  operator+ (Unit<D, R2> const & rhs) const {auto temp{*this}; return temp += rhs;} //Binary Plus
    template <instance_of_non_type<std::ratio> R2> constexpr Unit& operator-=(Unit<D, R2> const & rhs)       {return *this += -rhs;} //Assignment Minus
    template <instance_of_non_type<std::ratio> R2> constexpr Unit  operator- (Unit<D, R2> const & rhs) const {return *this +  -rhs;} //Binary Minus
    constexpr Unit operator+() const {return *this *=  1;} //Unary Plus
    constexpr Unit operator-() const {return *this *= -1;} //Unary Minus
    constexpr Unit& operator*=(real scalar)       {get_value() *= scalar; return *this;} //Scalar Assignment Multiplication
    constexpr Unit  operator* (real scalar) const {auto temp{*this}; return temp *= scalar;} //Scalar Multiplication
    constexpr Unit  operator/=(real scalar)       {return *this *= (1/scalar);} //Scalar Assignment Division
    constexpr Unit  operator/ (real scalar) const {return *this *  (1/scalar);} //Scalar Division
    friend constexpr auto operator*(real scalar, Unit const & rhs) {return rhs * scalar;} //Reverse-order multiplication
    friend constexpr auto operator/(real scalar, Unit const & rhs) {return Unit<Unitless>{1}/rhs * scalar;} //Reverse-order division
    template <instance_of_non_type<Dimension> D2, instance_of_non_type<std::ratio> R2> constexpr auto operator/(Unit<D2, R2> const & rhs) const {return Unit<decltype(D{} / D2{})>{Unit<D>{*this}.get_cdimension() / Unit<D2>{rhs}.get_cdimension()};} //Unit Division
    template <instance_of_non_type<Dimension> D2, instance_of_non_type<std::ratio> R2> constexpr auto operator*(Unit<D2, R2> const & rhs) const {return Unit<decltype(D{} * D2{})>{Unit<D>{*this}.get_cdimension() * Unit<D2>{rhs}.get_cdimension()};} //Unit Multiplication
};

template <typename charT, typename traits, instance_of_non_type<std::ratio> R, instance_of_non_type<Dimension> D>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, Unit<D, R> const & unit){
  return os << unit.string();
}

using unitless = Unit<Unitless, base>;
scale_unit(meter, m, Length, base);
scale_unit(newton , N  ,  Force, base);
scale_unit(pascal , Pa ,  Pressure, base);
scale_unit(joule  , J  ,  Energy, base);
scale_unit(watt   , W  ,  Power, base);
scale_unit(coulomb, C  ,  Charge, base);
scale_unit(volt   , V  ,  Voltage, base);
scale_unit(weber  , Wb ,  Magnetic_Flux, base);
scale_unit(ohm    , Ω  ,  Resistance, base);
scale_unit(siemen , S  ,  Conductance, base);
scale_unit(farad  , F  ,  Capacitance, base);
scale_unit(tesla  , T  ,  Magnetic_Flux_Density, base);
scale_unit(henry  , H  ,  Inductance, base);
scale_unit(lumen  , lm ,  Illuminance, base);
scale_unit(sievert, Sv ,  Radiation_Dose, base);
scale_unit(katal  , kat,  Catalytic_Activity, base);
scale_unit(litre  , L  ,  Volume, std::milli);

scale_unit(minute , min,  Time, std::ratio<60, 1>);
scale_unit(hour   , hr ,  Time, std::ratio<3600, 1>);
scale_unit(foot   , ft ,  Length, std::ratio<381, 1250>);
// using tonne = megagrams;

#undef scale_unit_helper
#undef scale_unit
CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_SI_HPP_
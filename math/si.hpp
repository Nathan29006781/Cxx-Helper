#ifndef CXX_HELPER_SI_HPP_
#define CXX_HELPER_SI_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include <ratio>
#include <sstream>

CXX_HELPER_BEGIN_NAMESPACE

template <typename R> concept Ratio = requires {{std::ratio<R::num, R::den>{}} -> std::same_as<typename R::type>;};

template <Ratio R>
real ratio_to_real() {return static_cast<real>(R::num)/R::den;};

using base = std::ratio<1>;

template <Ratio R, class D> class Unit;

/**/
//The __VA_ARGS__ are because ratio_multiply has commas
#define scale_unit_helper(name, letter, dimension, ...)\
using name##s = Unit<__VA_ARGS__, dimension>;\
namespace si_literals{\
  name##s operator ""_##letter(real val) {return val;}\
  name##s operator ""_##letter(unsigned long long val) {return val;}\
}\

template <int m = 0, int s = 0, int kg = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
struct Dimension{
  template <Ratio R, class D> friend class Unit;
  private:
    real value;
  public:
    constexpr Dimension(real value = 0): value{value} {}
};

template <Ratio R = base, class D = Dimension<>>
class Unit{
  private:
    D dimension;
    std::ratio<R::num, R::den> multiplier;

    real& get_value() {return dimension.value;}


  public:
    constexpr Unit(real value = 0): dimension{value} {}

    template <Ratio R2>
    constexpr Unit(Unit<R2, D> const & rhs): dimension{rhs.get_value()*ratio_to_real<std::ratio_divide<R2, R>>()} {}

    real get_value() const {return dimension.value;}
    std::string string() const {return std::to_string(get_value());}

    template <Ratio R2> constexpr Unit  operator+ (Unit<R2, D> const & rhs) const {return Unit<base, D>{*this} + Unit<base, D>{rhs};} //Different-type Binary Plus
    template <Ratio R2> constexpr Unit& operator+=(Unit<R2, D> const & rhs)       {get_value() = (*this + rhs).get_value(); return *this;} //Assignment Plus
    template <Ratio R2> constexpr Unit  operator- (Unit<R2, D> const & rhs) const {return *this +  -rhs;} //Different-type Binary Minus
    template <Ratio R2> constexpr Unit& operator-=(Unit<R2, D> const & rhs)       {return *this += -rhs;} //Assignment Plus
    constexpr Unit operator+(Unit const & rhs) const {return get_value() + rhs.get_value();} //Same-type Binary Plus
    constexpr Unit  operator* (real scalar) const {return get_value() * scalar;} //Multiplication
    constexpr Unit& operator*=(real scalar)       {get_value() *= scalar; return *this;} //Assignment Multiplication
    constexpr Unit  operator/ (real scalar) const {return *this *  1/scalar;} //Division
    constexpr Unit  operator/=(real scalar)       {return *this *= 1/scalar;} //Division
    constexpr Unit operator+() const {return  get_value();} //Unary Plus
    constexpr Unit operator-() const {return -get_value();} //Unary Minus

    friend constexpr Unit operator*(real scalar, Unit const & rhs) {return rhs * scalar;} //Reverse-order multiplication
    friend constexpr Unit operator/(real scalar, Unit const & rhs) {return Dimension<>{}/rhs * scalar;} //Reverse-order division
};


using Unitless    = Dimension<>;
using Length      = Dimension<1>;
using Time        = Dimension<0, 1>;
using Mass        = Dimension<0, 0, 1>;
using Current     = Dimension<0, 0, 0, 1>;
using Temperature = Dimension<0, 0, 0, 0, 1>;
using Moles       = Dimension<0, 0, 0, 0, 0, 1>;
using Luminosity  = Dimension<0, 0, 0, 0, 0, 0, 1>;
// using Velocity    = decltype(Length{}/Time{}); 

scale_unit_helper(millimeter, mm, Length, std::milli);
scale_unit_helper(meter, m, Length, base);
scale_unit_helper(kilometer, km, Length, std::kilo);

// using unitless = si_unit<0, 0, 0, 0, 0, 0, 0, base>;
// scale_unit(meter  , m  ,  1,  0,  0,  0,  0,  0,  0, base);
// scale_unit(second , s  ,  0,  1,  0,  0,  0,  0,  0, base);
// scale_unit(gram   , g  ,  0,  0,  1,  0,  0,  0,  0, std::milli);
// scale_unit(ampere , A  ,  0,  0,  0,  1,  0,  0,  0, base);
// scale_unit(kelvin , K  ,  0,  0,  0,  0,  1,  0,  0, base);
// scale_unit(mole   , mol,  0,  0,  0,  0,  0,  1,  0, base);
// scale_unit(candela, cd ,  0,  0,  0,  0,  0,  0,  1, base);
// scale_unit(hertz  , hz ,  0, -1,  0,  0,  0,  0,  0, base);
// scale_unit(newton , N  ,  1, -2,  1,  0,  0,  0,  0, base);
// scale_unit(pascal , Pa , -1, -2,  1,  0,  0,  0,  0, base);
// scale_unit(joule  , J  ,  2, -2,  1,  0,  0,  0,  0, base);
// scale_unit(watt   , W  ,  2, -3,  1,  0,  0,  0,  0, base);
// scale_unit(coulomb, C  ,  0,  1,  0,  1,  0,  0,  0, base);
// scale_unit(volt   , V  ,  2, -3,  1, -1,  0,  0,  0, base);
// scale_unit(weber  , Wb ,  2, -2,  1, -1,  0,  0,  0, base);
// scale_unit(ohm    , Ω  ,  2, -3,  1, -2,  0,  0,  0, base);
// scale_unit(siemen , S  , -2,  3, -1,  2,  0,  0,  0, base);
// scale_unit(farad  , F  , -2,  4, -1,  2,  0,  0,  0, base);
// scale_unit(tesla  , T  ,  0, -2,  1, -1,  0,  0,  0, base);
// scale_unit(henry  , H  ,  2, -2,  1, -2,  0,  0,  0, base);
// scale_unit(lumen  , lm ,  0,  0,  0,  0,  0,  0,  1, base);
// scale_unit(sievert, Sv ,  2, -2,  0,  0,  0,  0,  0, base);
// scale_unit(katal  , kat,  0, -1,  0,  0,  0,  1,  0, base);
// scale_unit(litre  , L  ,  3,  0,  0,  0,  0,  0,  0, std::milli);


// scale_unit(minute , min,  0,  1,  0,  0,  0,  0,  0, std::ratio<60, 1>);
// scale_unit(hour   , hr ,  0,  1,  0,  0,  0,  0,  0, std::ratio<3600, 1>);
// scale_unit(foot   , ft ,  1,  0,  0,  0,  0,  0,  0, std::ratio<381, 1250>);
// using tonne = megagrams;

template <typename charT, typename traits, Ratio R, class D>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, Unit<R, D> const & unit){
  return os << unit.string();
}

#undef scale_unit_helper
#undef scale_unit
CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_SI_HPP_
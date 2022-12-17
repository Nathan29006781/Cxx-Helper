#ifndef CXX_HELPER_SI_HPP_
#define CXX_HELPER_SI_HPP_

#include "header_config.hpp"
#include <ratio>
#include <sstream>

using base = std::ratio<1>;


//The __VA_ARGS__ are because ratio_multiply has commas
#define scale_unit_helper(name, letter, m_, s_, kg_, A_, K_, mol_, cd_, ...)\
using name##s = si_unit<m_, s_, kg_, A_, K_, mol_, cd_, __VA_ARGS__>;\
name##s name{STRINGIFY(letter), STRINGIFY(name##s)};\
namespace si_literals{\
  name##s operator ""_##letter(real val) {return val;}\
  name##s operator ""_##letter(natural val) {return val;}\
}\

//ratio is always from SI unit
#define scale_unit(base_name, base_letter, m_, s_, kg_, A_, K_, mol_, cd_, ...)\
/*scale_unit_helper(atto ##base_name, a ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::atto , __VA_ARGS__>);*/\
scale_unit_helper(femto##base_name, f ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::femto, __VA_ARGS__>);\
scale_unit_helper(pico ##base_name, p ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::pico , __VA_ARGS__>);\
scale_unit_helper(nano ##base_name, n ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::nano , __VA_ARGS__>);\
scale_unit_helper(micro##base_name, µ ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::micro, __VA_ARGS__>);\
scale_unit_helper(milli##base_name, m ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::milli, __VA_ARGS__>);\
scale_unit_helper(centi##base_name, c ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::centi, __VA_ARGS__>);\
scale_unit_helper(deci ##base_name, d ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::deci , __VA_ARGS__>);\
scale_unit_helper(       base_name,     base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<     base , __VA_ARGS__>);\
scale_unit_helper(deca ##base_name, da##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::deca , __VA_ARGS__>);\
scale_unit_helper(hecto##base_name, h ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::hecto, __VA_ARGS__>);\
scale_unit_helper(kilo ##base_name, k ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::kilo , __VA_ARGS__>);\
scale_unit_helper(mega ##base_name, M ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::mega , __VA_ARGS__>);\
scale_unit_helper(giga ##base_name, G ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::giga , __VA_ARGS__>);\
scale_unit_helper(tera ##base_name, T ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::tera , __VA_ARGS__>);\
scale_unit_helper(peta ##base_name, P ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::peta , __VA_ARGS__>);\
/*scale_unit_helper(exa  ##base_name, E ##base_letter, m_, s_, kg_, A_, K_, mol_, cd_, std::ratio_multiply<std::exa  , __VA_ARGS__>);*/\



template <int m = 0, int s = 0, int kg = 0, int A = 0, int K = 0, int mol = 0, int cd = 0>
class unprefixed_unit{
  private:
    real raw_value;
  public:
    constexpr unprefixed_unit(real value = 0): raw_value{value} {}

    real get_raw_value() const {return raw_value;}

    constexpr unprefixed_unit& operator+=(unprefixed_unit const & rhs) {raw_value += rhs.get_raw_value(); return *this;}
    constexpr unprefixed_unit operator+(unprefixed_unit const & rhs) {auto u{*this}; return u += rhs;}
    constexpr unprefixed_unit& operator-=(unprefixed_unit const & rhs) {raw_value -= rhs.get_raw_value(); return *this;}
    constexpr unprefixed_unit operator-(unprefixed_unit const & rhs) {auto u{*this}; return u -= rhs;}
    
    constexpr unprefixed_unit& operator*=(real scalar) {raw_value *= scalar; return *this;}
    constexpr unprefixed_unit operator*(real scalar) const {unprefixed_unit u{*this}; u *= scalar; return u;}
    constexpr unprefixed_unit& operator/=(real scalar) {raw_value /= scalar; return *this;}
    constexpr unprefixed_unit operator/(real scalar) const {unprefixed_unit u{*this}; u /= scalar; return u;}
};


template <int m, int s, int kg, int A, int K, int mol, int cd, class multiplier>
class si_unit{
  private:
    using unit = unprefixed_unit<m, s, kg, A, K, mol, cd>;
    template <typename other_multiplier> using other_unit = si_unit<m, s, kg, A, K, mol, cd, other_multiplier>;

    unit value;
    inline static std::string unit_str, full_unit_str;

    static void set_strings(std::string unit, std::string full_unit) {unit_str = unit; full_unit_str = full_unit;}

  public:
    si_unit(std::string unit, std::string full_unit): value{1} {set_strings(unit, full_unit);}
    constexpr si_unit(real value): value{value} {}

    template <typename other_multiplier>
    constexpr si_unit(other_unit<other_multiplier> const & other):
    value{
      static_cast<real>(std::ratio_divide<multiplier, other_multiplier>::den) /
      std::ratio_divide<multiplier, other_multiplier>::num *
      other.get_value().get_raw_value()
    } {}

    static auto get_num() {return multiplier::num;}
    static auto get_den() {return multiplier::den;}
    static auto get_suffix() {return unit_str;}
    static auto get_full_suffix() {return full_unit_str;}

    unit const & get_value() const {return value;}
    std::string str() const {std::stringstream ss; ss << get_value().get_raw_value() << get_suffix(); return ss.str();}
    std::string full_str() const {std::stringstream ss; ss << get_value().get_value() << get_full_suffix(); return ss.str();}

    static std::string prefix(){
      if constexpr (std::is_same_v<multiplier, std::atto>) return "a";
      if constexpr (std::is_same_v<multiplier, std::femto>) return "f";
      if constexpr (std::is_same_v<multiplier, std::pico>) return "p";
      if constexpr (std::is_same_v<multiplier, std::nano>) return "n";
      if constexpr (std::is_same_v<multiplier, std::micro>) return "µ";
      if constexpr (std::is_same_v<multiplier, std::milli>) return "m";
      if constexpr (std::is_same_v<multiplier, std::centi>) return "c";
      if constexpr (std::is_same_v<multiplier, std::deci>) return "d";
      if constexpr (std::is_same_v<multiplier, std::deca>) return "da";
      if constexpr (std::is_same_v<multiplier, std::hecto>) return "h";
      if constexpr (std::is_same_v<multiplier, std::kilo>) return "k";
      if constexpr (std::is_same_v<multiplier, std::mega>) return "M";
      if constexpr (std::is_same_v<multiplier, std::giga>) return "G";
      if constexpr (std::is_same_v<multiplier, std::tera>) return "T";
      if constexpr (std::is_same_v<multiplier, std::peta>) return "P";
      if constexpr (std::is_same_v<multiplier, std::exa>) return "E";

      return "";
    }

    static std::string full_prefix(){
      if constexpr (std::is_same_v<multiplier, std::atto>) return "atto";
      if constexpr (std::is_same_v<multiplier, std::femto>) return "femto";
      if constexpr (std::is_same_v<multiplier, std::pico>) return "pico";
      if constexpr (std::is_same_v<multiplier, std::nano>) return "nano";
      if constexpr (std::is_same_v<multiplier, std::micro>) return "micro";
      if constexpr (std::is_same_v<multiplier, std::milli>) return "milli";
      if constexpr (std::is_same_v<multiplier, std::centi>) return "centi";
      if constexpr (std::is_same_v<multiplier, std::deci>) return "deci";
      if constexpr (std::is_same_v<multiplier, std::deca>) return "deca";
      if constexpr (std::is_same_v<multiplier, std::hecto>) return "hecto";
      if constexpr (std::is_same_v<multiplier, std::kilo>) return "kilo";
      if constexpr (std::is_same_v<multiplier, std::mega>) return "mega";
      if constexpr (std::is_same_v<multiplier, std::giga>) return "giga";
      if constexpr (std::is_same_v<multiplier, std::tera>) return "tera";
      if constexpr (std::is_same_v<multiplier, std::peta>) return "peta";
      if constexpr (std::is_same_v<multiplier, std::exa>) return "exa";

      return "";
    }

    template <typename other_multiplier>
    constexpr si_unit& operator+=(other_unit<other_multiplier> const & rhs) {value += si_unit(rhs).get_value(); return *this;}

    template <typename other_multiplier>
    constexpr si_unit& operator-=(other_unit<other_multiplier> const & rhs) {value -= si_unit(rhs).get_value(); return *this;}

    template <typename other_multiplier>
    constexpr si_unit operator+(other_unit<other_multiplier> const & rhs) {auto u{*this}; return u += rhs;}

    template <typename other_multiplier>
    constexpr si_unit operator-(other_unit<other_multiplier> const & rhs) {auto u{*this}; return u -= rhs;}

    template <int m2, int s2, int kg2, int A2, int K2, int mol2, int cd2, class multiplier2>
    constexpr auto operator*(si_unit<m2, s2, kg2, A2, K2, mol2, cd2, multiplier2> const & rhs){
      using new_unit = si_unit<m+m2, s+s2, kg+kg2, A+A2, K+K2, mol+mol2, cd+cd2, std::ratio_multiply<multiplier, multiplier2>>;

      if(new_unit::get_suffix() == "") new_unit{get_suffix() + '*' + rhs.get_suffix(), get_full_suffix() + '*' + rhs.get_full_suffix()};
      return new_unit{get_value().get_raw_value()*rhs.get_value().get_raw_value()};
    }

    template <int m2, int s2, int kg2, int A2, int K2, int mol2, int cd2, class multiplier2>
    constexpr auto operator/(si_unit<m2, s2, kg2, A2, K2, mol2, cd2, multiplier2> const & arg){
      using new_unit = si_unit<m-m2, s-s2, kg-kg2, A-A2, K-K2, mol-mol2, cd-cd2, std::ratio_divide<multiplier, multiplier2>>;
      si_unit<m , s , kg , A , K , mol , cd , base> lhs{*this};
      si_unit<m2, s2, kg2, A2, K2, mol2, cd2, base> rhs{arg };

      if(new_unit::get_suffix() == "")
        new_unit{
          new_unit::prefix() + lhs.get_suffix() + '/' + rhs.get_suffix(),
          new_unit::full_prefix() + lhs.get_full_suffix() + '/' + rhs.get_full_suffix()
        };
      
      return new_unit{si_unit<m-m2, s-s2, kg-kg2, A-A2, K-K2, mol-mol2, cd-cd2, base>{lhs.get_value().get_raw_value() / rhs.get_value().get_raw_value()}};
    }


    constexpr si_unit& operator*=(real scalar) {value *= scalar; return *this;}
    constexpr si_unit& operator/=(real scalar) {value /= scalar; return *this;}
    constexpr si_unit operator*(real scalar) const {si_unit u{*this}; return u *= scalar;}
    constexpr si_unit operator/(real scalar) const {si_unit u{*this}; return u /= scalar;}
};

using unitless = si_unit<0, 0, 0, 0, 0, 0, 0, base>;
scale_unit(meter  , m  ,  1,  0,  0,  0,  0,  0,  0, base);
scale_unit(second , s  ,  0,  1,  0,  0,  0,  0,  0, base);
scale_unit(gram   , g  ,  0,  0,  1,  0,  0,  0,  0, std::milli);
scale_unit(ampere , A  ,  0,  0,  0,  1,  0,  0,  0, base);
scale_unit(kelvin , K  ,  0,  0,  0,  0,  1,  0,  0, base);
scale_unit(mole   , mol,  0,  0,  0,  0,  0,  1,  0, base);
scale_unit(candela, cd ,  0,  0,  0,  0,  0,  0,  1, base);
scale_unit(hertz  , hz ,  0, -1,  0,  0,  0,  0,  0, base);
scale_unit(newton , N  ,  1, -2,  1,  0,  0,  0,  0, base);
scale_unit(pascal , Pa , -1, -2,  1,  0,  0,  0,  0, base);
scale_unit(joule  , J  ,  2, -2,  1,  0,  0,  0,  0, base);
scale_unit(watt   , W  ,  2, -3,  1,  0,  0,  0,  0, base);
scale_unit(coulomb, C  ,  0,  1,  0,  1,  0,  0,  0, base);
scale_unit(volt   , V  ,  2, -3,  1, -1,  0,  0,  0, base);
scale_unit(weber  , Wb ,  2, -2,  1, -1,  0,  0,  0, base);
scale_unit(ohm    , Ω  ,  2, -3,  1, -2,  0,  0,  0, base);
scale_unit(siemen , S  , -2,  3, -1,  2,  0,  0,  0, base);
scale_unit(farad  , F  , -2,  4, -1,  2,  0,  0,  0, base);
scale_unit(tesla  , T  ,  0, -2,  1, -1,  0,  0,  0, base);
scale_unit(henry  , H  ,  2, -2,  1, -2,  0,  0,  0, base);
scale_unit(lux    , lx , -2,  0,  0,  0,  0,  0,  1, base);
scale_unit(sievert, Sv ,  2, -2,  0,  0,  0,  0,  0, base);
scale_unit(katal  , kat,  0, -1,  0,  0,  0,  1,  0, base);
scale_unit(litre  , L  ,  3,  0,  0,  0,  0,  0,  0, std::milli);


scale_unit(minute , min,  0,  1,  0,  0,  0,  0,  0, std::ratio<60, 1>);
scale_unit(hour   , hr ,  0,  1,  0,  0,  0,  0,  0, std::ratio<3600, 1>);
scale_unit(foot   , ft ,  1,  0,  0,  0,  0,  0,  0, std::ratio<381, 1250>);
using tonne = megagrams;



//Quantities
template <typename D> concept Distance    = std::convertible_to<D, meters  >;
template <typename T> concept Time        = std::convertible_to<T, seconds >;
template <typename M> concept Mass        = std::convertible_to<M, grams   >;
template <typename C> concept Current     = std::convertible_to<C, amperes >;
template <typename T> concept Temperature = std::convertible_to<T, kelvins >;
template <typename M> concept Moles       = std::convertible_to<M, moles   >;
template <typename B> concept Brightness  = std::convertible_to<B, candelas>;
template <typename F> concept Frequency   = std::convertible_to<F, hertzs  >;
template <typename C> concept Charge      = std::convertible_to<C, coulombs>;
template <typename F> concept Force       = std::convertible_to<F, newtons >;


template <int m, int s, int kg, int A, int K, int mol, int cd, class multiplier>
constexpr si_unit<m, s, kg, A, K, mol, cd, multiplier> operator*(real scalar, si_unit<m, s, kg, A, K, mol, cd, multiplier> const & unit) {return unit*scalar;}

template <int m, int s, int kg, int A, int K, int mol, int cd, class multiplier>
constexpr auto operator/(real scalar, si_unit<m, s, kg, A, K, mol, cd, multiplier> const & unit) {return unitless(scalar)/unit;}


template <typename charT, typename traits, int m, int s, int kg, int A, int K, int mol, int cd, class multiplier>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, si_unit<m, s, kg, A, K, mol, cd, multiplier> const & unit){
  return os << unit.str();
}

#undef scale_unit_helper
#undef scale_unit

CXX_HELPER_BEGIN_NAMESPACE
CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_SI_HPP_
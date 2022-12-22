#ifndef CXX_HELPER_OPERATORS_HPP_
#define CXX_HELPER_OPERATORS_HPP_

#include "header_config.hpp"
#include "math/generic.hpp"

#include "types.hpp"
#include <complex>
#include <ratio>


CXX_HELPER_BEGIN_NAMESPACE

//Generic
  constexpr auto operator^(auto b, auto e) {return generic::pow(b, e);} //Bitwise xor operator is automatically used or forbidden and overrides this 

//Ratio
  constexpr auto ratio_to_real(instance_of_non_type<std::ratio> auto const & r) {return static_cast<real>(r.num)/r.den;}
  constexpr auto ratio_to_real(Arithmetic auto r) {return static_cast<real>(r);}
  constexpr auto operator* (instance_of_non_type<std::ratio> auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return std::ratio_multiply<decltype(r1), decltype(r2)>{};}
  constexpr auto operator/ (instance_of_non_type<std::ratio> auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return std::ratio_divide  <decltype(r1), decltype(r2)>{};}
  constexpr auto operator+ (instance_of_non_type<std::ratio> auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return std::ratio_add     <decltype(r1), decltype(r2)>{};}
  constexpr auto operator- (instance_of_non_type<std::ratio> auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return std::ratio_subtract<decltype(r1), decltype(r2)>{};}
  constexpr auto operator* (Arithmetic auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return ratio_to_real(r1)*ratio_to_real(r2);}
  constexpr auto operator* (instance_of_non_type<std::ratio> auto const & r1, Arithmetic auto const & r2) {return ratio_to_real(r1)*ratio_to_real(r2);}
  constexpr auto operator/ (Arithmetic auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return ratio_to_real(r1)/ratio_to_real(r2);}
  constexpr auto operator/ (instance_of_non_type<std::ratio> auto const & r1, Arithmetic auto const & r2) {return ratio_to_real(r1)/ratio_to_real(r2);}
  constexpr auto operator+ (Arithmetic auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return ratio_to_real(r1)+ratio_to_real(r2);}
  constexpr auto operator+ (instance_of_non_type<std::ratio> auto const & r1, Arithmetic auto const & r2) {return ratio_to_real(r1)+ratio_to_real(r2);}
  constexpr auto operator- (Arithmetic auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return ratio_to_real(r1)-ratio_to_real(r2);}
  constexpr auto operator- (instance_of_non_type<std::ratio> auto const & r1, Arithmetic auto const & r2) {return ratio_to_real(r1)-ratio_to_real(r2);}
  constexpr auto operator<=>(instance_of_non_type<std::ratio> auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {
    if (std::ratio_equal<decltype(r1), decltype(r2)>{}) return std::strong_ordering::equal;
    else if (std::ratio_less<decltype(r1), decltype(r2)>{}) return std::strong_ordering::less;
    else return std::strong_ordering::greater;
  }
  constexpr bool operator==(instance_of_non_type<std::ratio> auto const & r1, instance_of_non_type<std::ratio> auto const & r2) {return r1 <=> r2 == 0;}
  template<typename charT, typename traits> std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, instance_of_non_type<std::ratio> auto const & r){return os << r.num << '/' << r.den;}

//Complex
  using complex = std::complex<real>;
  constexpr complex to_complex(instance_of_type<std::complex> auto const & c) {return c;}
  constexpr complex to_complex(Arithmetic auto c) {return static_cast<real>(c);}
  constexpr complex operator* (instance_of_type<std::complex> auto const & c1, instance_of_type<std::complex> auto const & c2) {return complex{c1} * complex{c2};}
  constexpr complex operator/ (instance_of_type<std::complex> auto const & c1, instance_of_type<std::complex> auto const & c2) {return complex{c1} / complex{c2};}
  constexpr complex operator+ (instance_of_type<std::complex> auto const & c1, instance_of_type<std::complex> auto const & c2) {return complex{c1} + complex{c2};}
  constexpr complex operator- (instance_of_type<std::complex> auto const & c1, instance_of_type<std::complex> auto const & c2) {return complex{c1} - complex{c2};}
  constexpr complex operator* (Arithmetic auto const & c1, instance_of_type<std::complex> auto const & c2) {return to_complex(c1) * to_complex(c2);}
  constexpr complex operator* (instance_of_type<std::complex> auto const & c1, Arithmetic auto const & c2) {return to_complex(c1) * to_complex(c2);}
  constexpr complex operator/ (Arithmetic auto const & c1, instance_of_type<std::complex> auto const & c2) {return to_complex(c1) / to_complex(c2);}
  constexpr complex operator/ (instance_of_type<std::complex> auto const & c1, Arithmetic auto const & c2) {return to_complex(c1) / to_complex(c2);}
  constexpr complex operator+ (Arithmetic auto const & c1, instance_of_type<std::complex> auto const & c2) {return to_complex(c1) + to_complex(c2);}
  constexpr complex operator+ (instance_of_type<std::complex> auto const & c1, Arithmetic auto const & c2) {return to_complex(c1) + to_complex(c2);}
  constexpr complex operator- (Arithmetic auto const & c1, instance_of_type<std::complex> auto const & c2) {return to_complex(c1) - to_complex(c2);}
  constexpr complex operator- (instance_of_type<std::complex> auto const & c1, Arithmetic auto const & c2) {return to_complex(c1) - to_complex(c2);}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_OPERATORS_HPP_
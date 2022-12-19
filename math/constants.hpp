#ifndef CXX_HELPER_MATH_CONSTANT_HPP_
#define CXX_HELPER_MATH_CONSTANT_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include "si.hpp"
#include <complex>
#include <numbers>

CXX_HELPER_BEGIN_NAMESPACE

namespace constants{
  constexpr auto e  {2.718281828459045235360287471352662};
  constexpr auto π  {3.141592653589793238462643383279502};
  constexpr auto λ  {0.577215664901532860606512090082402};
  constexpr auto A  {1.28242712910062263687534256886979172};
  constexpr auto ϖ  {2.62205755429211981046483958989111941};
  constexpr auto Ω  {0.56714329040978387299996866221035554};
  constexpr auto K  {2.58498175957925321706589358738317116};
  constexpr auto φ  {1.618033988749894848204586834365638};
  constexpr auto z3 {1.20205690315959428539973816151144999};
  constexpr auto z2 {π*π/6};
  constexpr auto ζ3 {z3};
  constexpr auto ζ2 {z2};
  constexpr auto τ  {2*π};
  constexpr auto i  {std::complex<real>{0, 1}};

  namespace physics{
    constexpr auto c   {si_unit<1, -1>{299792458}};
    constexpr auto me  {si_unit<0, 0, 1>{9.109383701528e-31}};
    constexpr auto ΔvCs{si_unit<0, -1>{9192631770}};
    constexpr auto e   {si_unit<0, 1, 0, 1>{1.602176634e-19}};
    constexpr auto h   {si_unit<2, -1, 1>{6.62607015e-34}};
    constexpr auto G   {si_unit<3, -2, 1>{6.6743015e-11}};
    constexpr auto NA  {si_unit<0, 0, 0, 0, 0, -1>{6.02214076e23}};
    constexpr auto μ0  {si_unit<1, -2, 1, -2>{1.2566370621219e-6}};
    constexpr auto kB  {si_unit<2, -2, 1, 0, -1>{1.380649e-23}};
    constexpr auto kcd {si_unit<-2, 3, -1, 0, 0, 0, 1>{683}};
    constexpr auto F   {NA*e};
    constexpr auto R   {NA*kB};
    constexpr auto ħ   {h/τ};
    constexpr auto Z0  {μ0*c};
    constexpr auto ε0  {1/(Z0*c)};
    constexpr auto ke  {Z0*c/(2*τ)};
    constexpr auto α   {e*e*μ0*c/(2*h)};
  }


  constexpr auto euler            {e};
  constexpr auto pi               {π};
  constexpr auto phi              {φ};
  constexpr auto golden           {φ};
  constexpr auto apery            {z3};
  constexpr auto glaisher_kinkelin{A};
  constexpr auto leminscate       {ϖ};
  constexpr auto sierpinski       {K};
  constexpr auto omega            {Ω};
  constexpr auto tau              {τ};
  constexpr auto egamma           {λ};
  constexpr auto log2e            {std::numbers::log2e_v<real>};
  constexpr auto log10e           {std::numbers::log10e_v<real>};
  constexpr auto ln2              {std::numbers::ln2_v<real>};
  constexpr auto ln10             {std::numbers::ln10_v<real>};
  constexpr auto sqrt3            {std::numbers::sqrt3_v<real>};
  constexpr auto inv_sqrt3        {std::numbers::inv_sqrt3_v<real>};
  constexpr auto sqrt2            {std::numbers::sqrt2_v<real>};
  constexpr auto inv_sqrt2        {0.70710678118654752440084436210484903};
  constexpr auto plastic          {1.32471795724474602596090885447809734};
  constexpr auto catalan          {0.91596559417721901505460351493238411};
  constexpr auto conway           {1.30357726903429639125709911215255189};
  constexpr auto khinchin         {2.68545200106530644530971483548179569};
  constexpr auto champernowne     {0.12345678910111213141516171819202122};
  constexpr auto parabolic        {2.29558714939263807403429804918949038};
  constexpr auto ramanujan_soldner{0.37250741078136663446199186658011913};

  constexpr auto napier{e};
  constexpr auto euler_mascheroni{λ};
  constexpr auto glaisher{A};
  constexpr auto pythagoras{sqrt2};
  constexpr auto theodorus{sqrt3};
  constexpr auto basel{ζ2};
  constexpr auto gauss{ϖ/π};
  template<std::floating_point T = real> constexpr std::complex<real> imaginary{i};
  
  constexpr auto light_speed{physics::c};
  constexpr auto electron_mass{physics::me};
  constexpr auto cesium_transition{physics::ΔvCs};
  constexpr auto elementary_charge{physics::e};
  constexpr auto planck{physics::h};
  constexpr auto gravitational{physics::G};
  constexpr auto avogadro{physics::NA};
  constexpr auto vacuum_permeability{physics::μ0};
  constexpr auto boltzmann{physics::kB};
  constexpr auto faraday{physics::F};
  constexpr auto gas{physics::R};
  constexpr auto reduced_planck{physics::ħ};
  constexpr auto vacuum_impedance{physics::Z0};
  constexpr auto vacuum_permittivity{physics::ε0};
  constexpr auto coulomb{physics::ke};
  constexpr auto fine_structure{physics::α};
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_CONSTANT_HPP_
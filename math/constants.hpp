#ifndef CXX_HELPER_MATH_CONSTANT_HPP_
#define CXX_HELPER_MATH_CONSTANT_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include "si.hpp"
#include <complex>
#include <numbers>

CXX_HELPER_BEGIN_NAMESPACE

namespace constants{
  constexpr real ln2              {0.69314718055994530941723212145817656};
  constexpr real ln10             {2.30258509299404568401799145468436420};
  constexpr real sqrt2            {1.41421356237309504880168872420969807};
  constexpr real sqrt3            {1.73205080756887729352744634150587236};
  constexpr real sqrt5            {2.23606797749978969640917366873127623};
  constexpr real e                {2.71828182845904523536028747135266249};
  constexpr real π                {3.14159265358979323846264338327950288};
  constexpr real λ                {0.57721566490153286060651209008240243};
  constexpr real A                {1.28242712910062263687534256886979172};
  constexpr real ϖ                {2.62205755429211981046483958989111941};
  constexpr real Ω                {0.56714329040978387299996866221035554};
  constexpr real K                {2.58498175957925321706589358738317116};
  constexpr real z3               {1.20205690315959428539973816151144999};
  constexpr real inv_sqrt2        {0.70710678118654752440084436210484903};
  constexpr real plastic          {1.32471795724474602596090885447809734};
  constexpr real catalan          {0.91596559417721901505460351493238411};
  constexpr real conway           {1.30357726903429639125709911215255189};
  constexpr real khinchin         {2.68545200106530644530971483548179569};
  constexpr real champernowne     {0.12345678910111213141516171819202122};
  constexpr real parabolic        {2.29558714939263807403429804918949038};
  constexpr real ramanujan_soldner{0.37250741078136663446199186658011913};
  constexpr auto i                {std::complex<real>{0, 1}};
  constexpr real φ                {(1+sqrt5)/2};
  constexpr auto z2               {π*π/6};
  constexpr auto τ                {2*π};
  constexpr auto gauss            {ϖ/π};
  constexpr auto euler            {e};
  constexpr auto napier           {e};
  constexpr auto imaginary        {i};
  constexpr auto pi               {π};
  constexpr auto phi              {φ};
  constexpr auto golden           {φ};
  constexpr auto tau              {τ};
  constexpr auto pythagoras       {sqrt2};
  constexpr auto theodorus        {sqrt3};
  constexpr auto egamma           {λ};
  constexpr auto euler_mascheroni {λ};
  constexpr auto ζ2               {z2};
  constexpr auto ζ3               {z3};
  constexpr auto basel            {z2};
  constexpr auto apery            {z3};
  constexpr auto glaisher_kinkelin{A};
  constexpr auto glaisher         {A};
  constexpr auto omega            {Ω};
  constexpr auto leminscate       {ϖ};
  constexpr auto sierpinski       {K};

  namespace physics{
    constexpr auto c   {Unit<Velocity>{299792458}};
    constexpr auto me  {Unit<Mass>{9.109383701528e-31}};
    constexpr auto ΔvCs{Unit<Frequency>{9192631770}};
    constexpr auto e   {Unit<Charge>{1.602176634e-19}};
    constexpr auto h   {Unit<decltype(Energy{}*Time{})>{6.62607015e-34}};
    constexpr auto G   {Unit<Gravitational_Coupling>{6.6743015e-11}};
    constexpr auto NA  {Unit<Inverse_Amount>{6.02214076e23}};
    constexpr auto μ0  {Unit<Permeability>{2e-7*τ}};
    constexpr auto kB  {Unit<Heat_Capacity>{1.380649e-23}};
    constexpr auto kcd {Unit<Dimension<-2, 3, -1, 0, 0, 0, 1>>{683}};
    constexpr auto F   {NA*e};
    constexpr auto R   {NA*kB};
    constexpr auto ħ   {h/τ};
    constexpr auto Z0  {μ0*c};
    constexpr auto ε0  {1/(Z0*c)};
    constexpr auto ke  {μ0*c*c/(2*τ)};
    constexpr auto α   {e*e*Z0/(2*h)};
  
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
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_CONSTANT_HPP_
#pragma once
#include "../header.hpp"
#include "../types.hpp"

#define SIMPLE_CONSTANT_NAMES

namespace constants{
  template<std::floating_point T = real> constexpr T euler             = std::numbers::e_v<T>;
  template<std::floating_point T = real> constexpr T golden            = std::numbers::phi_v<T>;
  template<std::floating_point T = real> constexpr T log2e             = std::numbers::log2e_v<T>;
  template<std::floating_point T = real> constexpr T log10e            = std::numbers::log10e_v<T>;
  template<std::floating_point T = real> constexpr T ln2               = std::numbers::ln2_v<T>;
  template<std::floating_point T = real> constexpr T ln10              = std::numbers::ln10_v<T>;
  template<std::floating_point T = real> constexpr T sqrt2             = std::numbers::sqrt2_v<T>;
  template<std::floating_point T = real> constexpr T inv_sqrt2         = 0.70710678118654752440084436210484903;
  template<std::floating_point T = real> constexpr T sqrt3             = std::numbers::sqrt3_v<T>;
  template<std::floating_point T = real> constexpr T inv_sqrt3         = std::numbers::inv_sqrt3_v<T>;
  template<std::floating_point T = real> constexpr T pi                = std::numbers::pi_v<T>;
  template<std::floating_point T = real> constexpr T inv_pi            = std::numbers::inv_pi_v<T>;
  template<std::floating_point T = real> constexpr T sqrtpi            = 1.77245385090551602729816748334114518;
  template<std::floating_point T = real> constexpr T inv_sqrtpi        = std::numbers::inv_sqrtpi_v<T>;
  template<std::floating_point T = real> constexpr T egamma            = std::numbers::egamma_v<T>;
  template<std::floating_point T = real> constexpr T apery             = 1.20205690315959428539973816151144999;
  template<std::floating_point T = real> constexpr T plastic           = 1.32471795724474602596090885447809734;
  template<std::floating_point T = real> constexpr T glaisher_kinkelin = 1.28242712910062263687534256886979172;
  template<std::floating_point T = real> constexpr T catalan           = 0.91596559417721901505460351493238411;
  template<std::floating_point T = real> constexpr T conway            = 1.30357726903429639125709911215255189;
  template<std::floating_point T = real> constexpr T khinchin          = 2.68545200106530644530971483548179569;
  template<std::floating_point T = real> constexpr T champernowne      = 0.12345678910111213141516171819202122;
  template<std::floating_point T = real> constexpr T leminscate        = 2.62205755429211981046483958989111941;
  template<std::floating_point T = real> constexpr T sierpinski        = 2.58498175957925321706589358738317116;
  template<std::floating_point T = real> constexpr T omega             = 0.56714329040978387299996866221035554;
  template<std::floating_point T = real> constexpr T parabolic         = 2.29558714939263807403429804918949038;


  template<std::floating_point T = real> constexpr T napier = euler<T>;
  template<std::floating_point T = real> constexpr T euler_mascheroni  = egamma<T>;
  template<std::floating_point T = real> constexpr T glaisher = glaisher_kinkelin<T>;
  template<std::floating_point T = real> constexpr T pythagoras = sqrt2<T>;
  template<std::floating_point T = real> constexpr T theodorus = sqrt3<T>;
  template<std::floating_point T = real> constexpr T basel = pi<T>*pi<T>/6;
  template<std::floating_point T = real> constexpr T gauss = leminscate<T>/pi<T>;
  template<std::floating_point T = real> std::complex<T> imaginary = std::complex<T>(0, 1);


  #ifdef SIMPLE_CONSTANT_NAMES
    template<std::floating_point T = real> constexpr T phi = golden<T>;
    template<std::floating_point T = real> constexpr T z3 = apery<T>;
    template<std::floating_point T = real> constexpr T z2 = basel<T>;
    template<std::floating_point T = real> std::complex<T> i = imaginary<T>;
    
    template<std::floating_point T = real> constexpr T e = euler<T>;
    template<std::floating_point T = real> constexpr T A = glaisher_kinkelin<T>;
    template<std::floating_point T = real> constexpr T K = sierpinski<T>;
    template<std::floating_point T = real> constexpr T φ = phi<T>;
    template<std::floating_point T = real> constexpr T ζ3 = z3<T>;
    template<std::floating_point T = real> constexpr T ζ2 = z2<T>;
    template<std::floating_point T = real> constexpr T π = pi<T>;
    template<std::floating_point T = real> constexpr T ϖ = leminscate<T>;
    template<std::floating_point T = real> constexpr T Ω = omega<T>;
  #endif
}
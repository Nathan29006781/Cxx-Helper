#pragma once
#include "../header.hpp"
#include "../types.hpp"

#define SIMPLE_CONSTANT_NAMES

namespace constants{
  template<std::floating_point T = real> inline constexpr T euler = std::numbers::e_v<T>;
  template<std::floating_point T = real> inline constexpr T golden = std::numbers::phi_v<T>;
  template<std::floating_point T = real> inline constexpr T log2e = std::numbers::log2e_v<T>;
  template<std::floating_point T = real> inline constexpr T log10e = std::numbers::log10e_v<T>;
  template<std::floating_point T = real> inline constexpr T ln2 = std::numbers::ln2_v<T>;
  template<std::floating_point T = real> inline constexpr T ln10 = std::numbers::ln10_v<T>;
  template<std::floating_point T = real> inline constexpr T sqrt2 = std::numbers::sqrt2_v<T>;
  template<std::floating_point T = real> inline constexpr T inv_sqrt2 = 0.70710678118654752440084436210484903;
  template<std::floating_point T = real> inline constexpr T sqrt3 = std::numbers::sqrt3_v<T>;
  template<std::floating_point T = real> inline constexpr T inv_sqrt3 = std::numbers::inv_sqrt3_v<T>;
  template<std::floating_point T = real> inline constexpr T pi = std::numbers::pi_v<T>;
  template<std::floating_point T = real> inline constexpr T inv_pi = std::numbers::inv_pi_v<T>;
  template<std::floating_point T = real> inline constexpr T inv_sqrtpi = std::numbers::inv_sqrtpi_v<T>;
  template<std::floating_point T = real> inline constexpr T egamma = std::numbers::egamma_v<T>;
  template<std::floating_point T = real> inline constexpr T euler_mascheroni = 0.57721566490153286060651209008240243;
  template<std::floating_point T = real> inline constexpr T apery = 1.20205690315959428539973816151144999;
  template<std::floating_point T = real> inline constexpr T plastic = 1.32471795724474602596090885447809734;
  template<std::floating_point T = real> inline constexpr T glaisher_kinkelin = 1.28242712910062263687534256886979172;
  template<std::floating_point T = real> inline constexpr T glaisher = glaisher_kinkelin<T>;
  template<std::floating_point T = real> inline std::complex<T> imaginary = std::complex<T>(0, 1);


  #ifdef SIMPLE_CONSTANT_NAMES
    template<std::floating_point T = real> inline constexpr T phi = golden<T>;
    template<std::floating_point T = real> inline constexpr T e = euler<T>;
    template<std::floating_point T = real> inline constexpr T z3 = apery<T>;
    template<std::floating_point T = real> inline constexpr T A = glaisher_kinkelin<T>;
    template<std::floating_point T = real> inline std::complex<T> i = imaginary<T>;

  #endif
}
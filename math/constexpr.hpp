#ifndef CXX_HELPER_MATH_CONSTEVAL_HPP_
#define CXX_HELPER_MATH_CONSTEVAL_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include "constants.hpp"
#include <cmath>
#include <limits>
#include <numeric>


CXX_HELPER_BEGIN_NAMESPACE

namespace compile_time{
  constexpr int neg1_pow(whole x){return x % 2 ? -1 : 1;}
  constexpr real abs(real x){return std::__sign(x)*x;}
  constexpr bool real_unequal(real x, real y) {return abs(x - y) >= std::numeric_limits<real>::epsilon();}

  constexpr real sqrt(real x){
    real guess{x/2};
    real prev_guess{x};

    while(real_unequal(guess, prev_guess)){
      prev_guess = guess;
      guess = (guess+x/guess)/2;
    }

    return guess;
  }

  constexpr real int_pow(real b, whole e){
    real result{1};
    do result *= b; while(e-->1);
    return result;
  }

  constexpr real factorial(natural n){
    real result{1};
    do result *= n; while(n-->1);
    return result;
  }

  constexpr real exp(real x){
    real guess{1};
    real prev_guess;
    real n = 1;

    do{
      prev_guess = guess;
      guess += int_pow(x, n)/factorial(n);
      n++;
    } while(real_unequal(guess, prev_guess));

    return guess;
  }

  constexpr real ln_x_helper(real x){ //For 0 < x < 2
    real guess{--x};
    real prev_guess;
    real n = 2;

    do{
      prev_guess = guess;
      guess += -neg1_pow(n)*int_pow(x, n)/n;
      n++;
    } while(real_unequal(guess, prev_guess));

    return guess;
  }

  constexpr real ln(real x){
    real result{0};
    while(x > 1.5){result += ln_x_helper(1.5); x/= 1.5;}
    return result + ln_x_helper(x);
  }

  constexpr real pow(real b, real e){return exp(e*ln(b));}

  constexpr real sinh(real x) {return (exp(x)-exp(-x))/2;}
  constexpr real cosh(real x) {return (exp(x)+exp(-x))/2;}
  constexpr real tanh(real x) {return (exp(2*x)-1)/(exp(2*x)+1);}
  constexpr real csch(real x) {return 1/sinh(x);}
  constexpr real sech(real x) {return 1/cosh(x);}
  constexpr real coth(real x) {return 1/tanh(x);}

  constexpr real arcsinh(real x){return ln(x + sqrt(int_pow(x, 2)+1));}
  constexpr real arccosh(real x){return ln(x + sqrt(int_pow(x, 2)-1));}
  constexpr real arctanh(real x){return ln((1+x)/(1-x))/2;}
  constexpr real arccsch(real x){return arcsinh(1/x);}
  constexpr real arcsech(real x){return arccosh(1/x);}
  constexpr real arccoth(real x){return arctanh(1/x);}
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_CONSTEVAL_HPP_
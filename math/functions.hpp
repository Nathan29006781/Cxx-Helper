#ifndef CXX_HELPER_MATH_FUNCTION_HPP_
#define CXX_HELPER_MATH_FUNCTION_HPP_

#include "../header_config.hpp"
#include "../types.hpp"
#include <functional>
#include <numeric>
#include <string>

//func scale
//maybe equation support here? if not, then math.hpp

CXX_HELPER_BEGIN_NAMESPACE

inline constexpr auto inv_size(Arithmetic auto... values) {return 1.0/sizeof...(values);}



//Template Recursion Base Cases
  inline constexpr auto lcm(Arithmetic auto value1, Arithmetic auto value2) {return std::lcm(value1, value2);}

  inline constexpr auto gcd(Arithmetic auto value1, Arithmetic auto value2) {return std::gcd(value1, value2);}

  inline constexpr auto max(Arithmetic auto value1, Arithmetic auto value2) {return std::max(value1, value2);}

  inline constexpr auto min(Arithmetic auto value1, Arithmetic auto value2) {return std::min(value1, value2);}

//Template Recursion
  inline constexpr auto lcm(Arithmetic auto value, Arithmetic auto... values) {return lcm(value, lcm(values...));}

  inline constexpr auto gcd(Arithmetic auto value, Arithmetic auto... values) {return gcd(value, gcd(values...));}

  inline constexpr auto max(Arithmetic auto value, Arithmetic auto... values) {return max(value, max(values...));}

  inline constexpr auto min(Arithmetic auto value, Arithmetic auto... values) {return min(value, min(values...));}


//Fold Operations
  inline constexpr auto add(Arithmetic auto... values) {return (values + ...);}

  inline constexpr auto multiply(Arithmetic auto... values) {return (values * ...);}

  inline constexpr auto hypotenuse(Arithmetic auto... values) {return std::sqrt(add((values*values)...));}

  namespace mean{
    inline constexpr auto arithmetic(Arithmetic auto... values) {return inv_size(values...)*add(values...);}

    inline constexpr auto geometric(Arithmetic auto... values) {return std::pow(multiply(values...), inv_size(values...));}

    inline constexpr auto harmonic(Arithmetic auto... values) {return 1.0/(arithmetic((1.0/values)...));}

    inline constexpr auto root_square(Arithmetic auto... values) {return std::sqrt(inv_size(values...))*hypotenuse(values...);}

    inline constexpr auto quadratic(Arithmetic auto... values) {return root_square(values...);}
  }


constexpr auto weighted_avg(Arithmetic auto first, Arithmetic auto second, Arithmetic auto first_scale){
  return first*first_scale + second * (1-first_scale);
}

constexpr auto closest_multiple(Arithmetic auto arg, Arithmetic auto multiple){
  return multiple*std::round(arg/multiple);
}

constexpr bool is_prime(Natural auto n){
  if (n == 2 || n == 3) return true;
  if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;

  for (int i{5}; i * i <= n; i += 6){
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }

  return true;
}

//create arithmetic constraint
// template <typename T>
// struct BinArthmOp{
//   // static std::unordered_map<std::string, std> operators {
//   //   "+", "-", "*", "x", "/", "^", "**", "&&", "&", "|", "||", ">", 
  
//   // };

//   std::function<T()> first_arg;
//   std::function<T()> second_arg;
//   std::function<T(T, T)> operation;

//   std::function<T()> result;

//   BinArthmOp(std::string equation){
//     result = std::function([this](){return this->operation(this->first_arg(), this->second_arg());});
//   }

//   BinArthmOp(std::function<T(T, T)> operation, std::function<T()> first_arg, std::function<T()> second_arg):
//   operation(operation), first_arg(first_arg), second_arg(second_arg){
//     result = std::function([this](){return this->operation(this->first_arg(), this->second_arg());});
//   }

//   BinArthmOp(std::function<T(Arithmetic auto, Arithmetic auto)> operation, Arithmetic auto first_arg, Arithmetic auto second_arg):
//   operation(operation), first_arg([&first_arg](){return first_arg;}), second_arg([&second_arg](){return second_arg;}){
//     result = std::function([this](){return this->operation(this->first_arg(), this->second_arg());});
//   }

//   // ctor with string with op and placeholders __1 and __2, provide

//   T operator ()(){return result();}
//   //check if value-convertible by looking at operands. convert if convertible
// };

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_FUNCTION_HPP_
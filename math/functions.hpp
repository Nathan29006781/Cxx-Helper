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

template <typename... T>
inline constexpr auto inv_size(T const&... values) {return 1.0/sizeof...(values);}



//Template Recursion Base Cases
  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto lcm(T1 const& value1, T2 const& value2) {return std::lcm(value1, value2);}

  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto gcd(T1 const& value1, T2 const& value2) {return std::gcd(value1, value2);}

  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto max(T1 const& value1, T2 const& value2) {return std::max(value1, value2);}

  template <Arithmetic T1, Arithmetic T2>
  inline constexpr auto min(T1 const& value1, T2 const& value2) {return std::min(value1, value2);}


//Template Recursion
  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto lcm(T const& value, Ts const&... values) {return lcm(value, lcm(values...));}

  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto gcd(T const& value, Ts const&... values) {return gcd(value, gcd(values...));}

  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto max(T const& value, Ts const&... values) {return max(value, max(values...));}

  template <Arithmetic T, Arithmetic... Ts>
  inline constexpr auto min(T const& value, Ts const&... values) {return min(value, min(values...));}

//Fold Operations
  template <Arithmetic... Ts>
  inline constexpr auto add(Ts const&... values) {return (values + ...);}

  template <Arithmetic... Ts>
  inline constexpr auto multiply(Ts const&... values) {return (values * ...);}

  template <Arithmetic... Ts>
  inline constexpr auto hypotenuse(Ts const&... values) {return std::sqrt(add((values*values)...));}

  template <Arithmetic... Ts>
  inline constexpr auto mean_arithmetic(Ts const&... values) {return inv_size(values...)*add(values...);}

  template <Arithmetic... Ts> //positive arithmetic
  inline constexpr auto mean_geometric(Ts const&... values) {return std::pow(multiply(values...), inv_size(values...));}

  template <Arithmetic... Ts>
  inline constexpr auto mean_harmonic(Ts const&... values) {return 1.0/(mean_arithmetic((1.0/values)...));}



template<Arithmetic T1, Arithmetic T2, Arithmetic T3>
constexpr auto weighted_avg(T1 const& first, T2 const& second, T3 const& first_scale){
  return first*first_scale + second * (1-first_scale);
}

template<Arithmetic T1, Arithmetic T2>
constexpr auto closest_multiple(T1 const& arg, T2 const& multiple){
  return multiple*std::round(arg/multiple);
}

template<Natural N>
constexpr bool is_prime(N const& n){
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

//   BinArthmOp(std::function<T(T const&, T const&)> operation, T const& first_arg, T const& second_arg):
//   operation(operation), first_arg([&first_arg](){return first_arg;}), second_arg([&second_arg](){return second_arg;}){
//     result = std::function([this](){return this->operation(this->first_arg(), this->second_arg());});
//   }

//   // ctor with string with op and placeholders __1 and __2, provide

//   T operator ()(){return result();}
//   //check if value-convertible by looking at operands. convert if convertible
// };

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_FUNCTION_HPP_
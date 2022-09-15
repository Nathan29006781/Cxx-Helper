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

template<Arithmetic T1, Arithmetic T2, Arithmetic T3>
constexpr auto weighted_avg(T1 first, T2 second, T3 first_scale){
  return first*first_scale + second * (1-first_scale);
}

template<Arithmetic T1, Arithmetic T2>
constexpr auto closest_multiple(T1 arg, T2 multiple){
  return multiple*std::round(arg/multiple);
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

//   BinArthmOp(std::function<T(const T&, const T&)> operation, const T& first_arg, const T& second_arg):
//   operation(operation), first_arg([&first_arg](){return first_arg;}), second_arg([&second_arg](){return second_arg;}){
//     result = std::function([this](){return this->operation(this->first_arg(), this->second_arg());});
//   }

//   // ctor with string with op and placeholders __1 and __2, provide

//   T operator ()(){return result();}
//   //check if value-convertible by looking at operands. convert if convertible
// };

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_MATH_FUNCTION_HPP_
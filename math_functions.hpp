#pragma once
#include "headers.hpp"
#include "util.hpp"

//func scale
//maybe equation support here? if not, then math.hpp

constexpr double weighted_avg(double first, double second, double first_scale){
  return first*first_scale + second * (1-first_scale);
}

template <typename arg_type, typename result_type, typename = typename std::enable_if_t<std::is_convertible_v<arg_type, integer>, void>>
constexpr result_type sum(std::function<result_type(arg_type)> func, integer start = 1, integer end = std::numeric_limits<arg_type>::max()){
  // case needed if going to infinity

  result_type sum = 0;
  loop_to(start, end+1) {sum += func(loop_counter); printf("idx:%d, val:%Lf, sum:%Lf\n", loop_counter, func(loop_counter), sum);}

  return sum;
}

template <typename arg_type, typename result_type, typename = typename std::enable_if_t<std::is_convertible_v<arg_type, integer>, void>>
constexpr result_type prod(std::function<result_type(arg_type)> func, integer start = 1, integer end = std::numeric_limits<arg_type>::max()){
  // case needed if going to infinity

  result_type prod = 1;
  loop_to(start, end+1) prod *= func(loop_counter);

  return prod;
}

//create arithmetic constraint
template <typename T>
struct BinArthmOp{
  // static std::unordered_map<std::string, std> operators {
  //   "+", "-", "*", "x", "/", "^", "**", "&&", "&", "|", "||", ">", 
  
  // };

  std::function<T()> first_arg;
  std::function<T()> second_arg;
  std::function<T(T, T)> operation;

  std::function<T()> result;

  BinArthmOp(std::string equation){
    result = std::function([this](){return this->operation(this->first_arg(), this->second_arg());});
  }

  BinArthmOp(std::function<T(T, T)> operation, std::function<T()> first_arg, std::function<T()> second_arg):
  operation(operation), first_arg(first_arg), second_arg(second_arg){
    result = std::function([this](){return this->operation(this->first_arg(), this->second_arg());});
  }

  BinArthmOp(std::function<T(const T&, const T&)> operation, const T& first_arg, const T& second_arg):
  operation(operation), first_arg([&first_arg](){return first_arg;}), second_arg([&second_arg](){return second_arg;}){
    result = std::function([this](){return this->operation(this->first_arg(), this->second_arg());});
  }

  // ctor with string with op and placeholders __1 and __2, provide

  T operator ()(){return result();}
  //check if value-convertible by looking at operands. convert if convertible
};
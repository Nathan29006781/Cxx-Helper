#ifndef CXX_HELPER_RANDOM_HPP_
#define CXX_HELPER_RANDOM_HPP_

#include "header_config.hpp"
#include "types.hpp"
#include <random>

CXX_HELPER_BEGIN_NAMESPACE


inline std::mt19937 random_engine() {
  std::random_device rd;
  return std::mt19937(rd());
}

template <Integer I = integer>
inline I random_int(I min = 0, I max = 1){
  std::uniform_int_distribution<I> distrib(min, max);
  std::mt19937 g = random_engine();
  return distrib(g);
}

template <std::floating_point R = real>
inline R random_real(R min = 0, R max = 1){
  std::uniform_real_distribution<R> distrib(min, max);
  std::mt19937 g = random_engine();
  return distrib(g);
}

template <std::random_access_iterator Iterator>
void random_shuffle(Iterator first, Iterator last){
  std::shuffle(first, last, random_engine());
}

template <std::forward_iterator Iterator, Integer I = typename Iterator::value_type>
void random_populate(Iterator first, Iterator last, I min = 0, I max = 1){
  std::generate(first, last, [=](){return random_int<I>(min, max);});
}

template <std::forward_iterator Iterator, std::floating_point R = typename Iterator::value_type>
void random_populate(Iterator first, Iterator last, R min = 0, R max = 1){
  std::generate(first, last, [=](){return random_real<R>(min, max);});
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_RANDOM_HPP_
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
inline I random_int(I min = 0, I max = std::numeric_limits<I>::max()){
  std::uniform_int_distribution<I> distrib(0, max - min);
  std::mt19937 g = random_engine();
  return distrib(g);
}

template <std::floating_point R = real>
inline R random_real(R min = 0, R max = 1.0){
  std::uniform_real_distribution<R> distrib(0, max - min);
  std::mt19937 g = random_engine();
  return distrib(g);
}

template <std::random_access_iterator Iterator>
void random_shuffle(Iterator first, Iterator last){
  std::shuffle(first, last, random_engine());
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_RANDOM_HPP_
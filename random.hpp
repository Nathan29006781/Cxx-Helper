#pragma once
#include "headers.hpp"

inline std::mt19937 random_engine() {
  std::random_device rd;
  return std::mt19937(rd());
}

template <class IntType = int>
inline IntType random_int(IntType min = 0, IntType max = std::numeric_limits<IntType>::max()){
  std::uniform_int_distribution<IntType> distrib(0, max - min);
  std::mt19937 g = random_engine();
  return distrib(g);
}

template <class RealType = double>
inline RealType random_real(RealType min = 0, RealType max = 1.0){
  std::uniform_real_distribution<RealType> distrib(0, max - min);
  std::mt19937 g = random_engine();
  return distrib(g);
}

template <class Iterator>
void random_shuffle(Iterator first, Iterator last){
  std::shuffle(first, last, random_engine());
}

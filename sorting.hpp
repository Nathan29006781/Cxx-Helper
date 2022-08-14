#pragma once
#include "headers.hpp"
#include <__random/uniform_int_distribution.h>
//Just all sorting algorithms

#define SORT_FUNC_DECLARE(name, algo) template <class Iterator>\
void name##_sort_step(Iterator first, Iterator last){algo}\
\
template <class Iterator>\
void name##_sort(Iterator first, Iterator last){\
  while(!std::is_sorted(first, last)) name##_sort_step(first, last);\
}\

std::mt19937 random_engine() {
  std::random_device rd;
  return std::mt19937(rd());
}

template <class IntType = int>
IntType random_int(IntType min = 0, IntType max = std::numeric_limits<IntType>::max()){
  std::uniform_int_distribution<IntType> distrib(0, max - min);
  std::mt19937 g = random_engine();
  return distrib(g);
}

template <class RealType = double>
RealType random_real(RealType min = 0, RealType max = 1.0){
  std::uniform_real_distribution<RealType> distrib(0, max - min);
  std::mt19937 g = random_engine();
  return distrib(g);
}

template <class Iterator>
void random_shuffle(Iterator first, Iterator last){
  std::shuffle(first, last, random_engine());
}

SORT_FUNC_DECLARE(bogo,
  random_shuffle(first, last);
)

SORT_FUNC_DECLARE(bozo,
  ptrdiff_t d = last - first - 1;
  std::swap(first[random_int<ptrdiff_t>(0, d)], first[random_int<ptrdiff_t>(0, d)]);
)
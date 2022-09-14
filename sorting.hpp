#pragma once
#include "header.hpp"
#include "random.hpp"
//Just all sorting algorithms

#define SORT_FUNC_DECLARE(name, algo)\
template <class Iterator>\
void name##_sort_step(Iterator first, Iterator last){algo}\
\
template <class Iterator>\
void name##_sort(Iterator first, Iterator last){\
  while(!std::is_sorted(first, last)) name##_sort_step(first, last);\
}


SORT_FUNC_DECLARE(bogo,
  random_shuffle(first, last);
)

SORT_FUNC_DECLARE(bozo,
  ptrdiff_t d = last - first - 1;
  std::swap(first[random_int<ptrdiff_t>(0, d)], first[random_int<ptrdiff_t>(0, d)]);
)
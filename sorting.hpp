#ifndef CXX_HELPER_SORTING_HPP_
#define CXX_HELPER_SORTING_HPP_

#include "header_config.hpp"
#include "containers.hpp"
#include "random.hpp"

#define SORT_FUNC_DECLARE(name, algo)\
template <std::input_iterator Iterator>\
void name##_sort_step(Iterator first, Iterator last){algo}\
\
template <std::input_iterator Iterator>\
void name##_sort(Iterator first, Iterator last){\
  while(!std::is_sorted(first, last)) name##_sort_step(first, last);\
}\
\
namespace ranges{\
  template <Range R>\
  void name##_sort(R& container){\
    NATHAN_M_PROJECT_NAME::name##_sort(container.begin(), container.end());\
  }\
}\

CXX_HELPER_BEGIN_NAMESPACE

SORT_FUNC_DECLARE(bogo,
  random_shuffle(first, last);
)

SORT_FUNC_DECLARE(bozo,
  ptrdiff_t d{last - first - 1};
  std::swap(first[random_int<ptrdiff_t>(0, d)], first[random_int<ptrdiff_t>(0, d)]);
)

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_SORTING_HPP_
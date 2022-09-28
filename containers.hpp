#ifndef CXX_HELPER_CONTAINER_HPP_
#define CXX_HELPER_CONTAINER_HPP_

#include "header_config.hpp"
#include <iostream>
#include <algorithm>

//negative indexing
//runtime fixed size array

template <typename C> concept Range = requires (const C& container){
  {std::ranges::begin(container)};
  {std::ranges::end(container)};
};

CXX_HELPER_BEGIN_NAMESPACE

template <std::input_iterator I>
inline constexpr bool contains(I first, I last, int item){
  return std::find(first, last, item) != last;
}

template<std::input_iterator I, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os = std::cout){
  os << '{';
  for (auto second = std::next(first); second != last; first++, second++) os << *first << ", ";
  return os << *first << '}';
}

namespace ranges{

  template <Range R>
  inline constexpr bool contains(const R& container, typename R::value_type item){
    return NATHAN_M_PROJECT_NAME::contains(container.cbegin(), container.cend(), item);
  }

}

CXX_HELPER_END_NAMESPACE

//Outside namespace so globally available
template<Range C, typename charT, typename traits>
inline constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const C& container){
  return NATHAN_M_PROJECT_NAME::iter_print(container.cbegin(), container.cend(), os);
}

#endif //CXX_HELPER_CONTAINER_HPP_
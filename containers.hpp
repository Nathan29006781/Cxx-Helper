#ifndef CXX_HELPER_CONTAINER_HPP_
#define CXX_HELPER_CONTAINER_HPP_

#include "header_config.hpp"
#include <iostream>
#include <algorithm>
#include <map>

//negative indexing
//runtime fixed size array

template <typename C> concept Range = requires (const C& container){
  {std::ranges::begin(container)};
  {std::ranges::end(container)};
};

//Forward declare iter_print
CXX_HELPER_BEGIN_NAMESPACE
template<std::input_iterator I, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os = std::cout);
CXX_HELPER_END_NAMESPACE

//Outside namespace so globally available
//Container printing
template<Range C, typename charT, typename traits>
inline constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const C& container){
  return NATHAN_M_PROJECT_NAME::iter_print(container.cbegin(), container.cend(), os);
}

// //Pair printing
// inline std::ostream& operator<<(std::ostream os, const std::map<int, int>::value_type& pair){
//   return os << '{' << pair.first << ", " << pair.second << '}';
// }


CXX_HELPER_BEGIN_NAMESPACE

template <std::input_iterator I>
inline constexpr bool contains(I first, I last, int item){
  return std::find(first, last, item) != last;
}

template<std::input_iterator I, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os){
  os << '{';
  // printf("HERE\n");
  if(std::next(first) != last){
    // printf("HERE1\n");
    for (auto second = std::next(first); second != last; first++, second++) os << *first << ", ";
  }
  return os << *first << '}';
}

//Variadic Template Printing
template <typename... Ts, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& many_print(std::basic_ostream<charT, traits>& os, Ts... args){
  os << '{';
  (os << ... << args << ... << ", ");
  return os << '}';
}

namespace ranges{

  template <Range R>
  inline constexpr bool contains(const R& container, typename R::value_type item){
    return NATHAN_M_PROJECT_NAME::contains(container.cbegin(), container.cend(), item);
  }

}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_CONTAINER_HPP_
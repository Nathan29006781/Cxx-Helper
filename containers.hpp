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

//Forward declare prints
CXX_HELPER_BEGIN_NAMESPACE
template<std::input_iterator I, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os = std::cout);

template <typename... Ts, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& many_print(std::basic_ostream<charT, traits>& os, Ts... args);
CXX_HELPER_END_NAMESPACE

//Outside namespace so globally available
//Container printing
// template<Range C, typename charT, typename traits>
// inline constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const C& container){
//   return NATHAN_M_PROJECT_NAME::iter_print(container.cbegin(), container.cend(), os);
// }

//Pair printing
template <typename T1, typename T2, typename charT, typename traits>
inline constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const std::pair<T1, T2>& pair){
  return NATHAN_M_PROJECT_NAME::many_print(os, pair.first, pair.second);
}

//Tuple Printing
template <typename... Ts, typename charT, typename traits>
inline constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const std::tuple<Ts...>& tuple){
  return std::apply([&os](auto &&... args) -> std::basic_ostream<charT, traits>&{
    return NATHAN_M_PROJECT_NAME::many_print(os, args...);
  }, tuple);
}

CXX_HELPER_BEGIN_NAMESPACE


//Container printing
template<Range C, typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const C& container){
  return NATHAN_M_PROJECT_NAME::iter_print(container.cbegin(), container.cend(), os);
}


template <std::input_iterator I>
inline constexpr bool contains(I first, I last, int item){
  return std::find(first, last, item) != last;
}

template<std::input_iterator I, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os){
  using namespace std;
  os << '{';
  if(std::next(first) != last){
    for (auto second = std::next(first); second != last; first++, second++) os << *first << ", ";
  }
  return os << *first << '}';
}

//Variadic Template Printing
template <typename... Ts, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& many_print(std::basic_ostream<charT, traits>& os, Ts... args){
  int count = 0;
  os << '{';
  ((os << (count++ ? ", " : "") << args), ...);
  return os << '}';
}

template <typename... Ts>
constexpr std::ostream& many_print(Ts... args){
  return many_print(std::cout, args...);
}

namespace ranges{
  template <Range R>
  inline constexpr bool contains(const R& container, typename R::value_type item){
    return NATHAN_M_PROJECT_NAME::contains(container.cbegin(), container.cend(), item);
  }
}

CXX_HELPER_END_NAMESPACE

using NATHAN_M_PROJECT_NAME::operator<<;

#endif //CXX_HELPER_CONTAINER_HPP_
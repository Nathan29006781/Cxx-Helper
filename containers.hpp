#ifndef CXX_HELPER_CONTAINER_HPP_
#define CXX_HELPER_CONTAINER_HPP_

#include "header_config.hpp"
#include "colours.hpp"
#include <iostream>
#include <algorithm>
#include <map>

//negative indexing
//runtime fixed size array

template <typename C> concept Range = requires (C  const & container){
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

CXX_HELPER_BEGIN_NAMESPACE


//Container printing
template<Range C, typename charT, typename traits>
inline constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, C const & container){
  return NATHAN_M_PROJECT_NAME::iter_print(container.cbegin(), container.cend(), os);
}

//Pair printing
template <typename T1, typename T2, typename charT, typename traits>
inline constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, std::pair<T1, T2> const & pair){
  return many_print(os, pair.first, pair.second);
}

//Tuple Printing
template <typename... Ts, typename charT, typename traits>
inline constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, std::tuple<Ts...> const & tuple){
  return std::apply([&os](auto &&... args) -> std::basic_ostream<charT, traits>&{
    return many_print(os, args...);
  }, tuple);
}

template<std::input_iterator I, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os){
  using namespace std;
  std::string const & col_code{Colour::get_next()};
  os << col_code << '{' << term_colors::none();

  if(std::next(first) != last){
   for (auto second{std::next(first)}; second != last; first++, second++) os << *first << ", ";
  }

  return os << *first << col_code << '}' << term_colors::none();
}

//Variadic Template Printing
template <typename... Ts, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& many_print(std::basic_ostream<charT, traits>& os, Ts... args){
  int count{0};
  std::string const & col_code{Colour::get_next()};
  os << col_code << '{' << term_colors::none();

  ((os << (count++ ? ", " : "") << args), ...);

  return os << col_code << '}' << term_colors::none();
}

template <typename... Ts>
constexpr std::ostream& many_print(Ts... args){
  return many_print(std::cout, args...);
}


template <std::input_iterator I>
inline constexpr bool contains(I first, I last, int item){
  return std::find(first, last, item) != last;
}

namespace ranges{
  template <Range R>
  inline constexpr bool contains(R const & container, typename R::value_type item){
    return NATHAN_M_PROJECT_NAME::contains(container.cbegin(), container.cend(), item);
  }
}

CXX_HELPER_END_NAMESPACE

using NATHAN_M_PROJECT_NAME::operator<<;

#endif //CXX_HELPER_CONTAINER_HPP_
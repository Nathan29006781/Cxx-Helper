#ifndef CXX_HELPER_CONTAINER_HPP_
#define CXX_HELPER_CONTAINER_HPP_

#include "header_config.hpp"
#include "colours.hpp"
#include "iterator_pair.hpp"

//get nth element
//operations to container
//negative indexing
//runtime fixed size array

CXX_HELPER_BEGIN_NAMESPACE

//Forward declare prints
  template<std::random_access_iterator I, typename charT = char, typename traits = std::char_traits<char>>
  constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os = std::cout);

  template<std::input_iterator I, typename charT = char, typename traits = std::char_traits<char>>
  constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os = std::cout);


  template <typename... Ts, typename charT, typename traits>
  constexpr std::basic_ostream<charT, traits>& many_print(std::basic_ostream<charT, traits>& os, Ts... args);

//Container printing
template<Range C, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, C const & container){
  return NATHAN_M_PROJECT_NAME::iter_print(std::cbegin(container), std::cend(container), os);
}

//Pair printing
template <typename T1, typename T2, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, std::pair<T1, T2> const & pair){
  return many_print(os, pair.first, pair.second);
}

//Tuple Printing
template <typename... Ts, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, std::tuple<Ts...> const & tuple){
  return std::apply([&os](auto &&... args) -> std::basic_ostream<charT, traits>&{
    return many_print(os, args...);
  }, tuple);
}

// Iterator printing
template<std::forward_iterator I, typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, I const iterator){
  return os << static_cast<void const*>(&*iterator);
}

// Iterator Pair printing
template<std::input_or_output_iterator I, typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, iterator_pair<I> ip){
  return os << std::make_pair(ip.begin(), ip.end());
}


//Print by iterator
template<std::input_or_output_iterator I, typename charT = char, typename traits = std::char_traits<char>>
constexpr std::basic_ostream<charT, traits>& iter_print(iterator_pair<I> ip, std::basic_ostream<charT, traits>& os = std::cout){
  return iter_print(ip.begin(), ip.end(), os);
}

template<std::input_iterator I, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os){
  std::string const & col_code{term_color::get_next()};
  os << col_code << '{' << term_colors::none();
  if(first == last) return os << col_code << '}' << term_colors::none();


  if(std::next(first) != last){
   for (auto second{std::next(first)}; second != last; first++, second++) os << *first << ", ";
  }

  return os << *first << col_code << '}' << term_colors::none();
}

template<std::random_access_iterator I, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& iter_print(I first, I last, std::basic_ostream<charT, traits>& os){
  std::string const & col_code{term_color::get_next()};
  os << col_code << '{' << term_colors::none();
  if(first == last) return os << col_code << '}' << term_colors::none();
  

  std::advance(last, -1);
  std::copy(first, last, std::ostream_iterator<typename std::iterator_traits<I>::value_type>(os, ", "));
  return os << *last << col_code << '}' << term_colors::none();
}

//Variadic Template Printing
template <typename... Ts, typename charT, typename traits>
constexpr std::basic_ostream<charT, traits>& many_print(std::basic_ostream<charT, traits>& os, Ts... args){
  std::size_t count{0};
  std::string const & col_code{term_color::get_next()};

  os << col_code << '{' << term_colors::none();

  ((os << (count++ ? ", " : "") << args), ...);

  return os << col_code << '}' << term_colors::none();
}

template <typename... Ts>
constexpr std::ostream& many_print(Ts... args) {return many_print(std::cout, args...);}

template<typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, std::partial_ordering order){
  if(order == std::partial_ordering::unordered) return os << "unordered";
  if(order == std::partial_ordering::less) return os << "less";
  if(order == std::partial_ordering::greater) return os << "greater";
  if(order == std::partial_ordering::equivalent) return os << "equivalent";
  else return os << "Error Value";
}

namespace ranges{
  template <Range C>
  constexpr auto contains(C const & container, typename C::value_type const & item){
    return NATHAN_M_PROJECT_NAME::contains(iterator_pair(container), item);
  }

  template <Range C>
  constexpr auto max(C const & container){
    return NATHAN_M_PROJECT_NAME::max(iterator_pair(container));
  }

  template <Range C>
  constexpr auto min(C const & container){
    return NATHAN_M_PROJECT_NAME::min(iterator_pair(container));
  }

  template <Range C1, Range C2>
  constexpr auto copy(C1 const & container1, C2& container2){
    return NATHAN_M_PROJECT_NAME::copy(iterator_pair(container1), iterator_pair(container2));
  }

  template <Range C>
  constexpr auto in_range(C const & container, typename C::const_iterator middle){
    return NATHAN_M_PROJECT_NAME::in_range(iterator_pair(container), middle);
  }

  template <Range C>
  constexpr auto split(C const & container, typename C::const_iterator middle){
    return NATHAN_M_PROJECT_NAME::split(iterator_pair(container), middle);
  }

  template <Range C>
  constexpr auto split(C const & container, typename C::difference_type offset){
    return NATHAN_M_PROJECT_NAME::split(iterator_pair(container), offset);
  }
}

CXX_HELPER_END_NAMESPACE

using NATHAN_M_PROJECT_NAME::operator<<;

#endif //CXX_HELPER_CONTAINER_HPP_
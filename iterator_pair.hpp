#ifndef CXX_HELPER_ITERATOR_PAIR_HPP_
#define CXX_HELPER_ITERATOR_PAIR_HPP_

#include "header_config.hpp"
#include "types.hpp"
#include <algorithm>
#include <concepts>
#include <iterator>

CXX_HELPER_BEGIN_NAMESPACE

template <typename C> concept Range = requires (C  const & container){
  {std::ranges::begin(container)};
  {std::ranges::end(container)};
};

template <typename O, typename I> concept output_iterator = std::input_iterator<I> && std::output_iterator<O, typename std::iterator_traits<I>::value_type>;

template <std::input_or_output_iterator I>
struct iterator_pair{
  I front, back;
  using value_type      = typename std::iterator_traits<I>::value_type;
  using difference_type = typename std::iterator_traits<I>::difference_type;

                        constexpr iterator_pair():                                    front{nullptr}, back{nullptr} {}
                        constexpr iterator_pair(I first, I last):                     front{first}, back{last} {}
                        constexpr iterator_pair(I first, std::size_t size):           iterator_pair(first, first+size) {}
                        constexpr iterator_pair(string_literal& str):                 iterator_pair(str, strlen(str)+1) {}
  template <Range    C> constexpr iterator_pair(C&  container):                       iterator_pair(std::begin(container), std::end(container)) {}
  template <typename T> constexpr iterator_pair(std::initializer_list<T> const &  il): iterator_pair(il.begin(), il.end()) {}

  constexpr I begin()   const {return front;}
  constexpr I end()     const {return back;}
  constexpr difference_type size() const {return std::distance(begin(), end());}
};

//Deduction Guides
                      iterator_pair(string_literal str)                  -> iterator_pair<string_literal>;
template <Range    C> iterator_pair(C&  container)                       -> iterator_pair<decltype(std::begin(container))>;
template <typename T> iterator_pair(std::initializer_list<T> const &  il) -> iterator_pair<decltype(il.begin())>;






//Iterator Functions
template <std::input_iterator I, output_iterator<I> O>
constexpr auto copy(I const first_in, I const last_in, O first_out, O last_out){
  auto amount = std::min(std::distance(first_in, last_in), std::distance(first_out, last_out));
  std::copy_n(first_in, amount, first_out);
  return amount;
}

template <std::input_iterator I>
constexpr bool contains(I first, I last, typename std::iterator_traits<I>::value_type item){
  return std::find(first, last, item) != last;
}

template <std::input_or_output_iterator I>
constexpr bool in_range(I first, I last, I middle){
  return in_range_inclusive(middle, first, last);
}

template <std::input_or_output_iterator I>
constexpr std::pair<iterator_pair<I>, iterator_pair<I>> split(I first, I last, I middle){
  middle = std::clamp(middle, first, last);
  return {iterator_pair(first, middle), iterator_pair(middle, last)};
}

template <std::input_or_output_iterator I>
constexpr std::pair<iterator_pair<I>, iterator_pair<I>> split(I first, I last, typename std::iterator_traits<I>::difference_type offset){
  return split(first, last, std::next(offset < 0 ? last : first, offset));
}








//Iterator Pair Functions
template <std::input_iterator I>
constexpr auto max(iterator_pair<I> const ip){
  return std::max_element(ip.begin(), ip.end());
}

template <std::input_iterator I>
constexpr auto min(iterator_pair<I> const ip){
  return std::min_element(ip.begin(), ip.end());
}

template <std::input_iterator I, output_iterator<I> O>
constexpr auto copy(iterator_pair<I> const in, iterator_pair<O> out){
  return copy(in.begin(), in.end(), out.begin(), out.end());
}

template <std::input_iterator I>
constexpr auto contains(iterator_pair<I> ip, typename iterator_pair<I>::value_type const & item){
  return std::find(ip.begin(), ip.end(), item) != ip.end();
}

template <std::input_or_output_iterator I>
constexpr auto in_range(iterator_pair<I> ip, I middle){
  return in_range(ip.begin(), ip.end(), middle);
}

template <std::input_or_output_iterator I>
constexpr auto split(iterator_pair<I> ip, I middle){
  return split(ip.begin(), ip.end(), middle);
}

template <std::input_or_output_iterator I>
constexpr auto split(iterator_pair<I> ip, typename std::iterator_traits<I>::difference_type offset){
  return split(ip.begin(), ip.end(), offset);
}



CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_ITERATOR_PAIR_HPP_
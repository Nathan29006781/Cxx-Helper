#ifndef CXX_HELPER_HPP_
#define CXX_HELPER_HPP_

#include "header_config.hpp"
#include "types.hpp"
#include <random>

CXX_HELPER_BEGIN_NAMESPACE
namespace random{

  inline std::mt19937 engine() {
    std::random_device rd;
    return std::mt19937(rd());
  }

  template <Integer I = NATHAN_M_PROJECT_NAME::integer>
  inline I integer(I min = 0, I max = 1){
    std::uniform_int_distribution<I> distrib(min, max);
    std::mt19937 g{engine()};
    return distrib(g);
  }

  template <std::floating_point R = NATHAN_M_PROJECT_NAME::real>
  inline R real(R min = 0, R max = 1){
    std::uniform_real_distribution<R> distrib(min, max);
    std::mt19937 g{engine()};
    return distrib(g);
  }

  template <std::random_access_iterator Iterator>
  void shuffle(Iterator first, Iterator last){
    std::shuffle(first, last, engine());
  }

  template <std::forward_iterator Iterator, Integer I = typename Iterator::value_type>
  void populate(Iterator first, Iterator last, I min = 0, I max = 1){
    std::generate(first, last, [=](){return integer<I>(min, max);});
  }

  template <std::forward_iterator Iterator, std::floating_point R = typename Iterator::value_type>
  void populate(Iterator first, Iterator last, R min = 0, R max = 1){
    std::generate(first, last, [=](){return real<R>(min, max);});
  }

}
CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_HPP_
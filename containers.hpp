#ifndef CXX_HELPER_CONTAINER_HPP_
#define CXX_HELPER_CONTAINER_HPP_

#include "header_config.hpp"
#include <algorithm>

//negative indexing
//Random access list (pointers to list stored in vector)
//runtime fixed size array

CXX_HELPER_BEGIN_NAMESPACE

template <typename T>
inline constexpr bool contains(T& container, typename T::value_type item){
  return std::find(container.begin(), container.end(), item) != container.end();
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_CONTAINER_HPP_
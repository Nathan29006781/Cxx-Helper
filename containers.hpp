#pragma once
#include "headers.hpp"

//negative indexing
//Random access list (pointers to list stored in vector)
//runtime fixed size array

template <typename T>
constexpr bool contains(T& container, typename T::value_type item){
  return std::find(container.begin(), container.end(), item) != container.end();
}
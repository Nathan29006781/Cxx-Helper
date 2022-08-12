#include "headers.hpp"
//Just all sorting algorithms

template <class _RandomAccessIterator>
void random_shuffle(_RandomAccessIterator first, _RandomAccessIterator last){
  std::random_device rd;
  std::shuffle(first, last, std::mt19937(rd()));
}

template <class _ForwardIterator>
void bogo_sort(_ForwardIterator first, _ForwardIterator last){
  while(!std::is_sorted(first, last)) random_shuffle(first, last);
}
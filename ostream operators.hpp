// #pragma once
// #include "header.hpp"
// #include "types.hpp"

// //can use loop because copy uses loop internally anyways
// template<Range C, typename charT, typename traits>
// std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const C& container){
//   if constexpr(std::random_access_iterator<typename C::iterator>){
//     os << '{';
//     std::copy(container.cbegin(), container.cend()-1, std::ostream_iterator<typename C::value_type>(os, ", "));
//     os << *(container.cend()-1) << '}';
//   }

//   else{
//     os << "not random access, have to write this manually";
//   }
  
//   return os;
// }
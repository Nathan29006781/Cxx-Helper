#ifndef CXX_HELPER_ITERATOR_HPP_
#define CXX_HELPER_ITERATOR_HPP_

#include "header_config.hpp"
#include <concepts>
#include <cstddef>
#include <iterator>

CXX_HELPER_BEGIN_NAMESPACE

template <
  typename iterator_derived,
  typename iter_category,
  typename value_t,
  typename difference_t = std::ptrdiff_t,
  typename pointer_t = value_t*,
  typename ref = value_t&
>
class iterator_base{
  public:
    using iterator_category = iter_category;
    using value_type = value_t;
    using difference_type = difference_t;
    using pointer = pointer_t;
    using reference = ref;

    //Assignment
    constexpr iterator_derived& operator+=(difference_type n) requires std::derived_from<iter_category, std::random_access_iterator_tag> {internal += n; return derived_ref();}
    constexpr iterator_derived& operator-=(difference_type n) requires std::derived_from<iter_category, std::random_access_iterator_tag> {return derived_ref() += -n;}

    // Arithmetic
    constexpr iterator_derived operator-(difference_type n) const requires std::derived_from<iter_category, std::random_access_iterator_tag> {return std::prev(derived_ref(), n);}
    constexpr iterator_derived operator+(difference_type n) const requires std::derived_from<iter_category, std::random_access_iterator_tag> {return std::next(derived_ref(), n);}
    friend constexpr iterator_derived operator+(difference_type n, iterator_derived const & rhs) requires std::derived_from<iter_category, std::random_access_iterator_tag> {return rhs+n;}
    
    //Increment/Decrement
    constexpr iterator_derived& operator++()                                                                               {std::advance(internal,  1); return derived_ref();}
    constexpr iterator_derived  operator++(int)                                                                            {iterator_derived temp{*this}; ++(*this); return temp;}
    constexpr iterator_derived& operator--()    requires std::derived_from<iter_category, std::bidirectional_iterator_tag> {std::advance(internal, -1); return derived_ref();}
    constexpr iterator_derived  operator--(int) requires std::derived_from<iter_category, std::bidirectional_iterator_tag> {iterator_derived temp{*this}; --(*this); return temp;}
    
    //Element Access
    constexpr reference operator* () const {return *internal;}
    constexpr pointer   operator->() const {return  internal;}
    constexpr reference operator[](difference_type n) const requires std::derived_from<iter_category, std::random_access_iterator_tag> {return *(*this + n);}

    //Comparison (friends for symmetry)
    friend constexpr bool                 operator== (iterator_derived const & lhs, iterator_derived const & rhs) requires std::derived_from<iter_category, std::forward_iterator_tag>       {return lhs.internal ==  rhs.internal;}
    friend constexpr std::strong_ordering operator<=>(iterator_derived const & lhs, iterator_derived const & rhs) requires std::derived_from<iter_category, std::random_access_iterator_tag> {return lhs.internal <=> rhs.internal;};
    friend constexpr difference_type      operator - (iterator_derived const & lhs, iterator_derived const & rhs) requires std::derived_from<iter_category, std::random_access_iterator_tag> {return lhs.internal  -  rhs.internal;}

  private:
    pointer internal;
    constexpr iterator_derived       & derived_ref()       {return static_cast<iterator_derived       &>(*this);}
    constexpr iterator_derived const & derived_ref() const {return static_cast<iterator_derived const &>(*this);}
    iterator_base() = delete;
  
  protected:
    iterator_base(pointer internal): internal{internal} {}
};

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_ITERATOR_HPP_
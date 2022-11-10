#ifndef CXX_HELPER_QUEUE_HPP_
#define CXX_HELPER_QUEUE_HPP_

#include "header_config.hpp"
#include "containers.hpp"
#include <array>
#include <string>

CXX_HELPER_BEGIN_NAMESPACE

template <typename T,  std::size_t N>
class queue{
  public:
    using value_type      = T;
    using size_type       = std::size_t;
    using array           = std::array<T, N>;
    using pointer         = value_type*;
    using const_pointer   = value_type const*;
    using reference       = value_type&;
    using const_reference = value_type const&;


    array arr;

    class iterator{
      public:
        using difference_type   = std::ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = value_type;
        using pointer           = pointer;
        using reference         = reference;

      public:
        pointer internal;
        pointer begin, end;
        int cycle;

        constexpr bool same_container(iterator const& rhs) const {return begin == rhs.begin && end == rhs.end;}

      public:
        constexpr iterator(pointer ptr, pointer begin, pointer end): internal{ptr}, begin{begin}, end{end}, cycle{0} {};
        constexpr iterator() {};

        constexpr iterator& operator+=(difference_type n) {
          cycle += floor(n / static_cast<double>(N));
          n %= static_cast<std::ptrdiff_t>(N);
          if(n < 0) {n += N;}
          if(n >= end-internal) {internal -= N; cycle++;}
          internal += n;
          return *this;
        }
        constexpr iterator& operator-=(difference_type n) {return *this += -n;}
        constexpr iterator operator+(difference_type n) const {iterator temp{*this}; return temp += n;}
        friend constexpr iterator operator+(difference_type n, iterator const& rhs) {return rhs+n;}
        constexpr iterator operator-(difference_type n) const {return *this + -n;}
        constexpr iterator& operator++() {return *this += 1;}
        constexpr iterator& operator--() {return *this += -1;}
        constexpr iterator operator++(int) {iterator temp{*this}; ++(*this); return temp;}
        constexpr iterator operator--(int) {iterator temp{*this}; --(*this); return temp;}
        constexpr reference operator[](difference_type n) const {return *(*this + n);}
        constexpr reference operator*() const {return *internal;}
        constexpr pointer operator->() {return internal;}
        friend constexpr difference_type operator-(iterator const& lhs, iterator const& rhs) {return lhs.same_container(rhs) ? (lhs.internal-rhs.internal+(lhs.cycle-rhs.cycle)*(lhs.end-lhs.begin)) : std::numeric_limits<difference_type>::max();}

        //== checks for equality on the same cycle. <=> only checks pointer equality
        friend constexpr bool operator==(iterator const& lhs, iterator const& rhs) {return lhs <=> rhs == 0 && lhs.cycle == rhs.cycle;}
        constexpr std::partial_ordering operator<=>(iterator const& rhs) const{
          if(!same_container(rhs)) return std::partial_ordering::unordered;
          return internal <=> rhs.internal;
        }
    };

    using const_iterator         = iterator;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using reverse_const_iterator = std::reverse_iterator<const_iterator>;

    //front_iter points to element about to be popped, back_iter points to location where element will be inserted
    iterator front_iter, back_iter;

    queue(): arr{}, front_iter{arr.begin(), arr.begin(), arr.end()}, back_iter{front_iter} {}
    queue(std::initializer_list<value_type> il): queue() {insert(il);}

    //Methods
    constexpr const_iterator begin() const {return front_iter;}
    constexpr const_iterator end() const {return back_iter;}
    constexpr const_iterator cbegin() const {return front_iter;}
    constexpr const_iterator cend() const {return back_iter;}
    size_t size() const {return back_iter-front_iter;}
    constexpr size_type capacity () const {return N;}
    constexpr size_type space_left () const {return capacity()-size();}
    constexpr bool full() const {return size() == capacity();}
    constexpr bool empty() const {return size() == 0;}
    constexpr const_reference front() const {return *front_iter;}
    constexpr const_reference back() const {return *(back_iter-1);}

    //Non-const Methods
    constexpr iterator begin() {return front_iter;}
    constexpr iterator end() {return back_iter;}
    constexpr reference front() {return *front_iter;}
    constexpr reference back() {return *(back_iter-1);}

    //Insert Modifiers
    constexpr void push_back (const_reference value){if(!full()) *back_iter++ = value; else ERROR("Queue full, cannot push");}
    template<std::input_iterator I> constexpr iterator insert (I first, I last) {if(std::distance(first, last) <= space_left()) back_iter = std::copy(first, last, end()); else ERROR("Not enough space to insert into queue"); return end();}
    template<Range C> constexpr iterator insert (C const& container) {return insert(NATHAN_M_PROJECT_NAME::begin(container), NATHAN_M_PROJECT_NAME::end(container));}
    constexpr iterator insert (const_reference value){push_back(value); return end();}
    constexpr iterator insert (size_type count, const_pointer pointer) {return insert(pointer, pointer+count);}

    //Remove Modifiers
    constexpr void pop () {if(!empty()) *front_iter++ = value_type{}; else ERROR("Queue empty, cannot pop");}
    constexpr iterator erase (const_iterator first, const_iterator last) {return back_iter = std::copy(last, end(), first);}
    constexpr iterator erase (const_iterator pos) {return erase(pos, pos+1);}

};

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_QUEUE_HPP_
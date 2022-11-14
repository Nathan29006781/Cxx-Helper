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
        constexpr iterator(std::nullptr_t = nullptr): iterator{nullptr, nullptr, nullptr} {};

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
        friend constexpr difference_type operator-(iterator const& lhs, iterator const& rhs) {return lhs.same_container(rhs) ? lhs.internal-rhs.internal+(lhs.cycle-rhs.cycle)*(lhs.end-lhs.begin) : std::numeric_limits<difference_type>::max();}

        //== checks for equality on the same cycle. <=> only checks pointer equality
        friend constexpr bool operator==(iterator const& lhs, iterator const& rhs) {return lhs.internal == rhs.internal && lhs.cycle == rhs.cycle;}
        constexpr std::partial_ordering operator<=>(iterator const& rhs) const{
          if(same_container(rhs)){
            if (cycle == rhs.cycle) return internal <=> rhs.internal;
            else return cycle <=> rhs.cycle;
          }
          else return std::partial_ordering::unordered;
        }
    };

    using const_iterator         = iterator;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using reverse_const_iterator = std::reverse_iterator<const_iterator>;


    array arr;
    //front_iter points to element about to be popped, back_iter points to location where element will be inserted
    iterator front_iter, back_iter;

    constexpr queue(): arr{} {clear();}
    constexpr queue(std::initializer_list<value_type> il): queue() {insert(il);}

    constexpr std::pair<iterator_pair<pointer>, iterator_pair<pointer>> contiguous_iterator_pair(){ //Wraparound : Whole range
      return
      end().cycle == begin().cycle ?
      std::make_pair(iterator_pair(begin().internal, end().internal), iterator_pair<pointer>()) :
      std::make_pair(iterator_pair(begin().internal, arr.end()), iterator_pair(arr.begin(), end().internal));
    }

    //Methods
    constexpr const_iterator begin() const {return front_iter;}
    constexpr const_iterator end() const {return back_iter;}
    constexpr const_iterator cbegin() const {return front_iter;}
    constexpr const_iterator cend() const {return back_iter;}
    size_t size() const {return back_iter-front_iter;}
    constexpr size_type capacity() const {return N;}
    constexpr size_type space_left() const {return capacity()-size();}
    constexpr bool full() const {return size() == capacity();}
    constexpr bool empty() const {return size() == 0;}
    constexpr const_reference front() const {return *front_iter;}
    constexpr const_reference back() const {return *(back_iter-1);}
    constexpr iterator construct_iterator(pointer pointer) {return {pointer, arr.begin(), arr.end()};}


    //Non-const Methods
    constexpr iterator begin() {return front_iter;}
    constexpr iterator end() {return back_iter;}
    constexpr reference front() {return *front_iter;}
    constexpr reference back() {return *(back_iter-1);}

    //Insert Modifiers
    constexpr void push_back(const_reference value){if(!full()) *back_iter++ = value; else ERROR("Queue full, cannot push");}
    constexpr iterator insert(const_reference value){push_back(value); return end();}
    template <std::input_iterator I> constexpr iterator insert(I first, I last) {
      auto cp = contiguous_iterator_pair();
      auto size = std::distance(first, last);

      if(size < std::distance(cp.first.begin(), cp.first.end())){ // single write to cp.first

      }
      else{ //needs to splice input range and map remaining part into cp.second

      }

      if(std::distance(first, last) <= space_left()){
        back_iter = construct_iterator(NATHAN_M_PROJECT_NAME::copy(first, last, cp.first.begin(), cp.first.end()));
        // back_iter = construct_iterator(NATHAN_M_PROJECT_NAME::copy(first, last, cp.second.begin(), cp.second.end()));
      }
      else ERROR("Not enough space to insert into queue");
      return end();
    }
    template<std::input_iterator I> constexpr iterator insert(iterator_pair<I> iter_pair) {return insert(iter_pair.begin(), iter_pair.end());}
    constexpr iterator insert(const_pointer pointer, size_type count) {return insert(pointer, pointer+count);}
    constexpr iterator insert(string_literal str) requires std::same_as<std::remove_cv_t<T>, char> {return insert(iterator_pair(str));}

    //Remove Modifiers
    constexpr void pop() {if(!empty()) *front_iter++ = value_type{}; else ERROR("Queue empty, cannot pop");}
    constexpr void clear() {front_iter = back_iter = construct_iterator(arr.begin());}
    constexpr iterator erase(const_iterator first, const_iterator last) {return back_iter = std::copy(last, end(), first);}
    constexpr iterator erase(const_iterator pos) {return erase(pos, pos+1);}

};

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_QUEUE_HPP_
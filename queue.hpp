#ifndef CXX_HELPER_QUEUE_HPP_
#define CXX_HELPER_QUEUE_HPP_

#include "header_config.hpp"
#include "containers.hpp"
#include <array>
#include <string>

CXX_HELPER_BEGIN_NAMESPACE

//FIFO
template <typename T,  std::size_t N> requires std::same_as<std::remove_cvref_t<T>, T>
class queue{
  public:
    class iterator;
    using const_iterator = iterator;
    using size_type              = std::size_t;
    using array                  = std::array<T, N>;
    using difference_type        = std::ptrdiff_t;
    using value_type             = T;
    using pointer                = value_type*;
    using reference              = value_type&;
    using const_value_type       = value_type const;
    using const_pointer          = const_value_type*;
    using const_reference        = const_value_type&;
    using reverse_iterator       = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    class iterator{
      friend queue<T, N>;
      public:
        using difference_type   = difference_type;
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
        constexpr reference operator[](difference_type n) const {return *(*this + n);} //? Needed?
        constexpr reference operator*() const {return *internal;}
        constexpr pointer operator->() {return internal;}
        friend constexpr difference_type operator-(iterator const& lhs, iterator const& rhs) {return lhs.same_container(rhs) ? lhs.internal-rhs.internal+(lhs.cycle-rhs.cycle)*(lhs.end-lhs.begin) : std::numeric_limits<difference_type>::max();}

        //== checks for equality on the same cycle. <=> only checks pointer equality
        friend constexpr bool operator==(iterator const& lhs, iterator const& rhs) {return lhs.internal == rhs.internal && lhs.cycle == rhs.cycle;}
        constexpr std::partial_ordering operator<=>(iterator const& rhs) const{
          if(same_container(rhs)) return cycle == rhs.cycle ? internal <=> rhs.internal : cycle <=> rhs.cycle;
          else return std::partial_ordering::unordered;
        }
    };


  // private:
    //front_iter points to element about to be popped, back_iter points to location where element will be inserted
    array arr;
    iterator front_iter, back_iter;

    constexpr std::pair<iterator_pair<pointer>, iterator_pair<pointer>> empty_contiguous_iterators(){ //Returns two ranges corresponding to unfilled part of queue
      if(full()) return {};
      if(begin().internal <= end().internal) return std::make_pair(iterator_pair(end().internal, arr.end()), iterator_pair(arr.begin(), begin().internal)); //Wraparound
      else return std::make_pair(iterator_pair(end().internal, begin().internal), iterator_pair<pointer>()); //Single Range
    }
    constexpr std::pair<iterator_pair<pointer>, iterator_pair<pointer>> full_contiguous_iterators(){ //Returns two ranges corresponding to filled part of queue
      if(empty()) return {};
      if(begin().internal < end().internal) return std::make_pair(iterator_pair(begin().internal, end().internal), iterator_pair<pointer>()); //Single Range
      else return std::make_pair(iterator_pair(begin().internal, arr.end()), iterator_pair(arr.begin(), end().internal)); //Wraparound
    }

    constexpr const_iterator construct_iterator(pointer pointer) const {return {pointer, arr.begin(), arr.end()};}
    constexpr iterator       construct_iterator(pointer pointer)       {return {pointer, arr.begin(), arr.end()};}

  public:

  //Constructors
    constexpr queue(): arr{}, front_iter{construct_iterator(arr.begin())}, back_iter{front_iter} {}
    constexpr queue(std::initializer_list<value_type> il): queue() {insert(iterator_pair(il));}

    //Getters
    constexpr size_type size() const {return end()-begin();}
    constexpr size_type capacity() const {return N;}
    constexpr size_type space_left() const {return std::max(static_cast<size_type>(0), capacity()-size());}
    constexpr bool full() const {return size() == capacity();}
    constexpr bool empty() const {return size() == 0;}

    //Const Methods
    constexpr const_iterator         begin()   const {return front_iter;}
    constexpr const_iterator         end()     const {return back_iter ;}
    constexpr const_iterator         cbegin()  const {return begin();}
    constexpr const_iterator         cend()    const {return end() ;}
    constexpr const_reverse_iterator rbegin()  const {return const_reverse_iterator(begin());}
    constexpr const_reverse_iterator rend()    const {return const_reverse_iterator(end() );}
    constexpr const_reverse_iterator crbegin() const {return const_reverse_iterator(cbegin());}
    constexpr const_reverse_iterator crend()   const {return const_reverse_iterator(cend() );}
    constexpr const_reference        front()   const {return *begin();}
    constexpr const_reference        back()    const {return *(end()-1);}
    constexpr const_pointer          data()    const {return arr.data();}
    constexpr const_reference        at        (difference_type n) const {if(n < size()) return (*this)[n]; else throw std::out_of_range("queue");}
    constexpr const_reference        operator[](difference_type n) const {return *(begin() + n);}

    //Non-Const Methods
    constexpr iterator          begin()  {return front_iter;}
    constexpr iterator          end()    {return back_iter ;}
    constexpr reverse_iterator  rbegin() {return reverse_iterator{begin()};}
    constexpr reverse_iterator  rend()   {return reverse_iterator{end()  };}
    constexpr reference         front()  {return *begin();}
    constexpr reference         back()   {return *(end()-1);}
    constexpr pointer           data()   {return arr.data();}
    constexpr reference         at        (difference_type n) {if(n < size()) return (*this)[n]; else throw std::out_of_range("queue");}
    constexpr reference         operator[](difference_type n) {return *(begin() + n);}
    
    
    //Insert Modifiers
    constexpr void push(const_reference value){if(!full()) *back_iter++ = value;}
    constexpr iterator insert(const_reference value){push(value); return end();}
    template <std::input_iterator I> constexpr iterator insert(iterator_pair<I> ip){
      auto out = empty_contiguous_iterators();
      auto in = split(ip, out.first.size());
      back_iter += copy(in.first,  out.first );
      back_iter += copy(in.second, out.second);
      return end();
    }
    template <std::input_iterator I> constexpr iterator insert(I first, I last) {return insert(iterator_pair(first, last));}
    constexpr iterator insert(const_pointer pointer, size_type count) {return insert(pointer, pointer+count);}
    constexpr iterator insert(string_literal str) requires std::same_as<T, char> {return insert(iterator_pair(str));}
    constexpr void swap(queue<T, N>& other) {auto old_size = size(); arr.swap(other.arr); back_iter = begin() + other.size(); other.back_iter = other.begin() + old_size;}

    //Remove Modifiers
    constexpr void pop() {if(!empty()) front_iter++;}
    constexpr void clear() {front_iter = end();}
    constexpr iterator erase(iterator pos) {return front_iter = pos;}
    template <output_iterator<iterator> O> constexpr O output(iterator_pair<O> ip){
      auto in = full_contiguous_iterators();
      auto out = split(ip, in.first.size());
      copy(in.first,  out.first );
      copy(in.second, out.second);
      clear();
      return out.second.end();
    }
    template <output_iterator<iterator> O> constexpr O output(O first, O last) {return output(iterator_pair(first, last));}
    template <output_iterator<iterator> O> constexpr O output(O out) {
      auto in = full_contiguous_iterators();
      out = std::copy(in.first .begin(), in.first .end(), out);
      out = std::copy(in.second.begin(), in.second.end(), out);
      clear();
      return out;
    }
    constexpr void output(std::ostream& out) requires std::same_as<T, char> {
      auto in = full_contiguous_iterators();
      out.write(in.first .begin(), in.first .size());
      out.write(in.second.begin(), in.second.size());
      clear();
    }
};

template <typename T,  std::size_t N>
constexpr void swap(NATHAN_M_PROJECT_NAME::queue<T, N>& lhs, NATHAN_M_PROJECT_NAME::queue<T, N>& rhs) {lhs.swap(rhs);}

CXX_HELPER_END_NAMESPACE

#endif //CXX_HELPER_QUEUE_HPP_
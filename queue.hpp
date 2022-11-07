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
    using value_type = T;
    using array      = std::array<T, N>;

    array arr;

    class iterator{
      public:
        using difference_type   = std::ptrdiff_t;
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = value_type;
        using pointer           = value_type*;
        using reference         = value_type&;

      public:
        pointer internal;
        pointer begin, end;
        int cycle;

        constexpr difference_type size() const {return end - begin;}
        constexpr bool same_container(iterator const& rhs) const {return begin == rhs.begin && end == rhs.end;}

      public:
        constexpr iterator(pointer ptr, pointer begin, pointer end): internal{ptr}, begin{begin}, end{end}, cycle{0} {};
        constexpr iterator() {};

        constexpr reference operator*() const {return *internal;}
        constexpr pointer operator->() {return internal;}

        //Operators
        constexpr iterator& operator+=(difference_type n) {
          cycle += floor(n / static_cast<double>(size()));
          n %= size();
          if(n < 0) n += size();
          if(n > end-internal) {internal -= size(); cycle++;}
          internal += n;
          return *this;
        }
        constexpr iterator& operator-=(difference_type n) {return *this += -n;}
        constexpr iterator operator+(difference_type n) const {iterator temp{*this}; return temp += n;}
        friend constexpr iterator operator+(difference_type n, iterator const& rhs) {return rhs+n;}
        constexpr iterator operator-(difference_type n) const {iterator temp{*this}; return temp -= n;}
        constexpr iterator& operator++() {return *this += 1;}
        constexpr iterator& operator--() {return *this += -1;}
        constexpr iterator operator++(int) {iterator temp{*this}; ++(*this); return temp;}
        constexpr iterator operator--(int) {iterator temp{*this}; --(*this); return temp;}
        constexpr reference operator[](difference_type n) const {return *(*this + n);}
        friend constexpr difference_type operator-(iterator const& lhs, iterator const& rhs) {return lhs.same_container(rhs) * lhs.internal-rhs.internal+(lhs.cycle-rhs.cycle)*lhs.size();}

        friend constexpr bool operator==(iterator const& lhs, iterator const& rhs) {return lhs.same_container(rhs) && lhs.cycle == rhs.cycle && lhs.internal == rhs.internal;}
        constexpr std::partial_ordering operator<=>(iterator const& rhs) const{
          if(!same_container(rhs)) return std::partial_ordering::unordered;
          else if(cycle <=> rhs.cycle != 0) return cycle <=> rhs.cycle;
          else return internal <=> rhs.internal;
        }
    };

    iterator front, back;
    std::string name;

    queue(std::string name): arr{}, front{arr.begin(), arr.begin(), arr.end()}, back{arr.end(), arr.begin(), arr.end()}, name{name} {}

    constexpr iterator begin() const {return front;}
    constexpr iterator end()   const {return back;}

    constexpr void push_back (T const& value){*(++back) = value;}

    // constexpr bool full() const;
    // constexpr bool empty() const;
    // size_t size() const;
    // template <std::input_iterator I> requires std::convertible_to<typename I::value_type, value_type>
    // constexpr void push(I first, I last);
    // constexpr void push(T const& val);
    // constexpr void pop();
    // constexpr T const& front() const;
    // constexpr T const& back() const;
    // template<typename T_, std::size_t N_, typename charT, typename traits> friend
    // std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, queue<T_, N_> const& queue);
};

template<typename T_, std::size_t N_, typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, queue<T_, N_> const& queue){
  return iter_print(queue.begin(), queue.end(), os); //will need to be modified since it doesn't actually start at arr.begin
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_QUEUE_HPP_
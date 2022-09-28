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
    typedef T value_type;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef typename std::array<T, N> array;

  private:
    class iter{
      public:
        typedef typename array::const_iterator const_iterator;
        typedef typename array::iterator iterator;
        typedef typename array::difference_type difference_type;
        typedef typename array::value_type value_type;


      private:
        iterator internal;
        
      public:
        iter(iterator iterator): internal(iterator) {};

        static void advance(iter iterator, difference_type amount = 1){
          std::advance(iterator.internal, amount); //actual implementations
        }

        static iter next(iter iterator, difference_type amount = 1){
          advance(iterator, amount);
          return iterator;
        }

        void advance(difference_type amount = 1){
          advance(*this, amount);
        }

        iter next (difference_type amount = 1) const {
          return next(*this, amount);
        };

        // constexpr iterator& operator+=(const iterator& other) {return *this += other;}
        inline value_type& operator* () {return *internal;}
        inline iter& operator++ () {return *this = this->next();}
        inline iter operator++ (int){
          iter old = *this;
          ++(*this);
          return old;
        }
    };



    // typedef typename array::const_iterator const_iterator;
    // typedef typename array::iterator iterator;

    array _arr;
    iter _front, _back;
    std::string _name;

    // constexpr void back_increment(difference_type amount = 1);
    // constexpr void front_increment();
    // inline constexpr iterator& front_iter();
    // inline constexpr iterator& back_iter();
    // inline constexpr const_iterator front_iter() const;
    // inline constexpr const_iterator back_iter() const;

  public:
    queue(std::string name): _arr(), _front(_arr.begin()), _back(_arr.end()), _name(name){}

    inline constexpr bool full() const;
    inline constexpr bool empty() const;
    inline size_t size() const;

    template <std::input_iterator I>
      requires std::convertible_to<typename I::value_type, value_type>
    constexpr void push(I first, I last);
    constexpr void push(const T& val);
    constexpr void pop();

    inline constexpr const T& front() const;
    inline constexpr const T& back() const;

    template<typename T_, std::size_t N_, typename charT, typename traits> friend
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const queue<T_, N_>& queue);
};

template<typename T_, std::size_t N_, typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, const queue<T_, N_>& queue){
  return iter_print(queue._arr.cbegin(), queue._arr.cend(), os); //will need to be modified since it doesn't actually start at arr.begin
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_QUEUE_HPP_
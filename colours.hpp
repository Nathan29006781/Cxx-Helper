#ifndef CXX_HELPER_COLOURS_HPP_
#define CXX_HELPER_COLOURS_HPP_

#include "header_config.hpp"
#include "math/geometry/angles.hpp"
#include "math/geometry/geometry.hpp"
#include "types.hpp"
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <string>
#include <vector>


CXX_HELPER_BEGIN_NAMESPACE

class term_color{
  private:
    std::string const id, seq;
    bool const used;
    static std::vector<term_color*> col_list;
    inline static int index{-1};
  public:
    //Constructors
      term_color (term_color const &) = delete;
      term_color(std::string id, std::string seq, bool used = true): id{id}, seq{seq}, used{used} {col_list.push_back(this);}
    
    //Getters
      std::string const & name() const {return id;}
      std::string const & operator()() const {return seq;}
    
    //Static method
      static std::string const get_next(){ //change back to reference
        return "\033[31m";


        do{
          if(index == col_list.size()-1) index = 0;
          else index++;
        } while (!col_list[index]->used);
        return (*col_list[index])();
      }
};

namespace term_colors{
  inline term_color none{"NONE", "\033[0m", false};
  inline term_color error{"ERROR", "\033[31mERROR: ", false};
  inline term_color warning{"WARNING", "\033[33mWARNING: ", false};
  inline term_color notif{"NOTIFICATION", "\033[32mNOTIF: ", false};
  inline term_color black{"BLACK", "\033[30m", false};
  inline term_color red{"RED", "\033[31m"};
  inline term_color green{"GREEN", "\033[32m"};
  inline term_color yellow{"YELLOW", "\033[33m"};
  inline term_color blue{"BLUE", "\033[34m"};
  inline term_color magenta{"MAGENTA", "\033[35m"};
  inline term_color cyan{"CYAN", "\033[36m"};
  inline term_color white{"WHITE", "\033[37m", false};
}

//hsl and cmyk
class Colour{
  public:
    using code_type = std::bitset<24>; //try bitset<6>
    using channel_type = std::bitset<8>; //try bitset<6>

    code_type code;

    code_type white{0xFFFFFF};
    code_type red  {0xFF0000};
    code_type green{0x00FF00};
    code_type blue {0x0000FF};
    code_type channel_mask {0x0000FF};

  //Static Helpers
    static constexpr channel_type to_channel(code_type const & code){return code.to_ulong();}
    static constexpr code_type to_code(channel_type const & code, int position = 0){return code.to_ulong() << 8*position;}
  
  public:
  //Constructors
    constexpr Colour(code_type code): code{code} {}
    constexpr Colour(channel_type r, channel_type g, channel_type b) {this->rgb(r, g, b);}

  //Getters
    constexpr channel_type r() const {return to_channel(code >> 16 & channel_mask);}
    constexpr channel_type g() const {return to_channel(code >> 8  & channel_mask);}
    constexpr channel_type b() const {return to_channel(code       & channel_mask);}
    constexpr std::tuple<channel_type, channel_type, channel_type> rgb() const {return {r(), g(), b()};}

    constexpr Angle h() const {return std::get<0>(hsv());}
    constexpr channel_type s() const {return std::get<1>(hsv());}
    constexpr channel_type v() const {return std::get<2>(hsv());}
    constexpr std::tuple<Angle, percentage, percentage> hsv() const {
      double r{this->r().to_ulong()/255.0};
      double g{this->g().to_ulong()/255.0};
      double b{this->b().to_ulong()/255.0};

      double max{NATHAN_M_PROJECT_NAME::max(r, g, b)};
      double min{NATHAN_M_PROJECT_NAME::min(r, g, b)};
      double diff{max - min};

      Angle h{0_deg};
      if(max == r) h = (60*(degrees(g-b)/diff + 6_deg)).mod();
      else if(max == g) h = (60*(degrees(b-r)/diff + 2_deg)).mod();
      else if(max == b) h = (60*(degrees(r-g)/diff + 4_deg)).mod();

      return {h, percentage{max ? diff/max : 0}, percentage{max}};
    }

  //Setters
    void r(channel_type r) {code = to_code(r, 2) | (code & ~red  );}
    void g(channel_type g) {code = to_code(g, 1) | (code & ~green);}
    void b(channel_type b) {code = to_code(b, 0) | (code & ~blue );}
    void rgb(channel_type r, channel_type g, channel_type b) {this->r(r); this->g(g); this->b(b);}
    void rgb(std::tuple<channel_type, channel_type, channel_type> rgb) {std::apply([this](channel_type const & r, channel_type const & g, channel_type const & b){this->rgb(r, g, b);}, rgb);}

  //Methods
    Colour& invert() {code = ~code & white; return *this;}
    Colour& darken(percentage percent = percentage{100}) {auto mod = (100-percent)/100.0; r(mod*r().to_ulong()); g(mod*g().to_ulong()); b(mod*b().to_ulong()); return *this;}

  //Static Equivalent Methods
    static Colour invert(Colour const & colour) {Colour col(colour); return col.invert();}
    static Colour darken(Colour const & colour, percentage percent = percentage{100}) {Colour col(colour); return col.darken(percent);}

  
    template<typename charT, typename traits> friend
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, Colour const & colour);
};

// inline constexpr Colour hsv(Angle h, percentage s, percentage v) {return 0;}
// inline constexpr Colour hsl(Angle h, percentage s, percentage l) {return 0;}

template<typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, Colour const & colour){
  auto flags = os.flags();
  auto precision = os.precision();
  auto fill = os.fill();

  os << "0x" << std::uppercase << std::setfill('0') << std::hex << std::setw(6) << colour.code.to_ulong();

  os.flags(flags);
  os.precision(precision);
  os.fill(fill);

  return os;
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_COLOURS_HPP_
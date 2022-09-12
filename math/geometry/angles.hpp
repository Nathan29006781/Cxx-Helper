#pragma once
#include "../constants.hpp"
#include "../../types.hpp"

struct Angle{
  public:
    Angle(real radians): _angle(radians) {};

    real degrees();
    real radians();
    real deg();
    real rad();

    template<typename charT, typename traits> friend
    std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, Angle angle);

  private:
    real _angle;
};

Angle radians(real angle);
Angle degrees(real angle);


Angle operator ""_r(real);
Angle operator ""_d(real);
Angle operator ""_rad(real);
Angle operator ""_deg(real);


template<typename charT, typename traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, Angle angle){
  return os << angle._angle;
}
#include "angles.hpp"

real Angle::radians(){
  return _angle;
}

real Angle::degrees(){
  return _angle*constants::pi<>/180.0;
}

real Angle::rad(){
  return radians();
}

real Angle::deg(){
  return degrees();
}


Angle operator ""_rad(real angle){
  return radians(angle);
}
Angle operator ""_deg(real angle){
  return degrees(angle);
}
Angle operator ""_r(real angle){
  return operator ""_rad(angle);
}
Angle operator ""_d(real angle){
  return operator ""_deg(angle);
}

Angle radians(real angle){
  return Angle{angle};
}

Angle degrees(real angle){
  return Angle{angle*constants::pi<>/180.0};
}
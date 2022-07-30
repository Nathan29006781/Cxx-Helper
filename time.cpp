#include "time.hpp"

using namespace std::chrono;
steady_clock::time_point start;

#define TIME_FUNC_DEFINE(unit)\
  long long unit(steady_clock::time_point start){\
    return duration_cast<unit##econds>(steady_clock::now()-start).count();\
  }\
  \
  long long unit(){\
    return unit(start);\
  }\

  TIME_FUNC_DEFINE(millis)
  TIME_FUNC_DEFINE(micros)
  TIME_FUNC_DEFINE(nanos)
#undef TIME_FUNC_DEFINE

void prog_begin(){
  start = steady_clock::now();
}

void delay(double duration){
  steady_clock::time_point start = steady_clock::now();

  while(millis(start) <= duration);
}
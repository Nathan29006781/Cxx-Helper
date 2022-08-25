#pragma once
#include "header.hpp"

#define TIME_FUNC_DECLARE(unit)\
  long long unit();\
  long long unit(std::chrono::steady_clock::time_point start);\

  TIME_FUNC_DECLARE(millis);
  TIME_FUNC_DECLARE(micros);
  TIME_FUNC_DECLARE(nanos);
#undef TIME_FUNC_DECLARE

void delay(double millis);
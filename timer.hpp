#pragma once
#include <string>

enum class timing_units{
  sec = 1000000,
  millis = 1000,
  micros = 1,

  seconds = sec,
  milliseconds = millis,
  microseconds = micros,
};

class Timer_old{
  //'time' is the time counted by the timer until the last call of pause()
  uint64_t time, last_play_time;
  bool paused; //state of timer
  
  const std::string name;
  const timing_units timing_unit;
  uint64_t get_time_in_timing_unit(); //returns time in either millis micros

  static uint64_t convert_time(uint64_t time, timing_units from, timing_units to);

public:
  explicit Timer_old(std::string name, bool play = true, timing_units timing_unit = timing_units::millis);
  void reset(bool play = true);
  uint64_t get_time();
  uint64_t get_time(timing_units timing_unit);
  bool playing();
  void play();
  void pause();
  void print();
  
  /**
   * @brief To print the time as a fancy string
   * 
   * @param str Message to print with the time
   * @param long_names: 
   * 0: ms
   * 1: millis
   * 2: milliseconds
   * @param unit_conversion converts 1500ms to 1s 500ms if true
   */
  void print_fancy(std::string str, int long_names = 0, bool unit_conversion = false);

  /**
   * @brief To get the time as a fancy string
   * 
   * @param time integer with the time to convert
   * @param unit unit from timing_units enum
   * @param long_names:
   * 0: ms
   * 1: millis
   * 2: milliseconds
   * @param unit_conversion converts 1500ms to 1s 500ms if true
   * @return std::string
   */
  static std::string to_string(std::uint64_t time, timing_units unit = timing_units::millis, int long_names = 0, bool unit_conversion = false);
};
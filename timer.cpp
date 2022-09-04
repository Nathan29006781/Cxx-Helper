#include "timer.hpp"
#include "time.hpp"

Timer_old::Timer_old(std::string name, bool play, timing_units timing_unit):
name(name), timing_unit(timing_unit){
  reset(play);
}

void Timer_old::reset(bool play){
  time = 0;
  if(play){
    paused = true;
    this->play();
  }
  else paused = true;
}

uint64_t Timer_old::get_time(timing_units timing_unit){
  return convert_time(get_time(), this->timing_unit, timing_unit);
}

uint64_t Timer_old::get_time(){
  if (paused) return time;
  else return get_time_in_timing_unit() - last_play_time + time;
}

void Timer_old::play(){
  if (paused){
    last_play_time = get_time_in_timing_unit();
    paused = false;
  }
  // else data_obj->print("Timer \"%s\" is already playing.", name);
}

void Timer_old::pause(){
  if (!paused){
    time += get_time_in_timing_unit() - last_play_time;
    paused = true;
  }
  // else data_obj->print("Timer \"%s\" is already paused.", name);
}

void Timer_old::print(){
  // data_obj->print("%s's current time is: %lld", name, get_time());
}

void Timer_old::print_fancy(std::string str, int long_names, bool unit_conversion){
  // data_obj->print("%s's current time is: %s | %s", name, to_string(get_time(), timing_unit, long_names, unit_conversion));
}

uint64_t Timer_old::convert_time(uint64_t time, timing_units from, timing_units to){
  return time * static_cast<uint64_t>(from) / static_cast<uint64_t>(to);
}

uint64_t Timer_old::get_time_in_timing_unit(){
  // return convert_time(micros(), timing_units::micros, timing_unit);
  return 0;
}

bool Timer_old::playing(){
  return !paused;
}

std::string Timer_old::to_string(std::uint64_t time, timing_units unit, int long_names, bool unit_conversion){
  std::string millis;
  std::string micros;
  std::string sec;
  std::string min;
  std::string plural;

  switch(long_names){
    case 0:
      millis = "ms";
      micros = "us";
      sec = "s";
      min = "m";
      plural = "";
      break;
    case 1:
      millis = " millis";
      micros = " micros";
      sec = " sec";
      min = " min";
      plural = "";
      break;
    case 2:
      millis = " millisecond";
      micros = " microsecond";
      sec = " second";
      min = " minute";
      plural = "s";
      break;
    default:
      millis = "";
      micros = "";
      sec = "";
      min = "";
      plural = "";
      break;
  }

  std::string buffer;

  //Prefixes with large unit. (e.g. 200s -> 3m 20s)
  if(unit_conversion){

    if(time >= 1000 && unit == timing_units::micros){
      std::uint64_t milliseconds = time / 1000;
      time -= milliseconds * 1000;

      if(milliseconds >= 1000) buffer += to_string(milliseconds, timing_units::millis, long_names, true) + ' ';
      else buffer += std::to_string(milliseconds) + millis + ' ';
    }

    else if(time >= 1000 && unit == timing_units::millis){
      std::uint64_t seconds = time / 1000;
      time -= seconds * 1000;

      if(seconds >= 60) buffer += to_string(seconds, timing_units::sec, long_names, true) + ' ';
      else buffer += std::to_string(seconds) + sec + ' ';
    }

    else if(time >= 60 && unit == timing_units::sec){
      std::uint64_t minutes = time / 60;
      time -= minutes * 60;

      buffer += std::to_string(minutes) + min + ' ';
    }

  }

  //Writes value
  if(time){
    buffer += std::to_string(time);
    //Writes unit
    switch(unit){
      case timing_units::micros: buffer += micros; break;
      case timing_units::millis: buffer += millis; break;
      case timing_units::sec: buffer += sec; break;
    }
  }

  if(buffer.back() == ' ') buffer.pop_back();
  return buffer;
}
/*
std::string to_string(std::uint64_t time, timing_units unit, int long_names, bool unit_conversion){
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
      std::uint64_t milliseconds{time / 1000};
      time -= milliseconds * 1000;

      if(milliseconds >= 1000) buffer += to_string(milliseconds, timing_units::millis, long_names, true) + ' ';
      else buffer += std::to_string(milliseconds) + millis + ' ';
    }

    else if(time >= 1000 && unit == timing_units::millis){
      std::uint64_t seconds{time / 1000};
      time -= seconds * 1000;

      if(seconds >= 60) buffer += to_string(seconds, timing_units::sec, long_names, true) + ' ';
      else buffer += std::to_string(seconds) + sec + ' ';
    }

    else if(time >= 60 && unit == timing_units::sec){
      std::uint64_t minutes{time / 60};
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
*/
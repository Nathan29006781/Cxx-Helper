#pragma once
#include "time.hpp"

long long millis(){return Timer<std::chrono::milliseconds>::now();};
long long micros(){return Timer<std::chrono::microseconds>::now();};
void delay(long long millis){Timer<>::delay(millis);};

//Constructors
template <Duration D>
Timer<D>::Timer():
Timer(true) {};

template <Duration D>
Timer<D>::Timer(bool play):
Timer("timer") {};

template <Duration D>
Timer<D>::Timer(const char* name):
Timer(std::string(name)) {};

template <Duration D>
Timer<D>::Timer(std::string name, bool play):
name(name), init_time(clock::now()), pause_time(clock::now()) {reset(play);};



//Actions
template <Duration D>
void Timer<D>::play(){
  init_time += clock::now()-pause_time;
  pause_time = timestamp();
}

template <Duration D>
void Timer<D>::pause(){
  pause_time = clock::now();
}

template <Duration D>
void Timer<D>::reset(bool play){
  if(play) this->play();
  else pause();
}


//Const methods
template <Duration D>
bool Timer<D>::is_playing() const{
  return pause_time == timestamp();
}

template <Duration D>
bool Timer<D>::is_paused() const{
  return !is_playing();
}

template <Duration D>
typename Timer<D>::value_type Timer<D>::time() const{
  if(is_playing()) return time_since(init_time);
  else return time_since(init_time)-time_since(pause_time);
}

template <Duration D>
typename std::string Timer<D>::get_name() const{
  return name;
}



//Static methods
template <Duration D>
typename Timer<D>::value_type Timer<D>::time_since(timestamp start){
  return duration_cast<D>(clock::now()-start).count();
}

template <Duration D>
typename Timer<D>::value_type Timer<D>::now(){
  return time_since(prog_start);
}

template <Duration D>
void Timer<D>::delay(value_type delay_time){
  std::this_thread::sleep_for(D(delay_time));
}
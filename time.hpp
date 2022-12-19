#ifndef CXX_HELPER_TIME_HPP_
#define CXX_HELPER_TIME_HPP_

#include "header_config.hpp"
#include "types.hpp"
#include <chrono>
#include <string>
#include <thread>

template <typename D> concept Duration = std::chrono::__is_duration<D>::value;

CXX_HELPER_BEGIN_NAMESPACE

class Timer_base{
  protected:
    using clock = std::chrono::steady_clock;
    using timestamp = clock::time_point;
    static timestamp const prog_start;
};

Timer_base::timestamp const Timer_base::prog_start{std::chrono::steady_clock::now()};



template <Duration D = std::chrono::milliseconds>
class Timer: private Timer_base{
  private:
    using value_type = typename D::rep;

    std::string const name;
    timestamp init_time{clock::now()}, pause_time; //init_time will change so cannot be reliably used for the time of initialization

  public:
    //Constructors
      Timer(): Timer{true} {}
      explicit Timer(bool play): Timer{"timer"} {}
      explicit Timer(string_literal name): Timer{std::string{name}} {}
      explicit Timer(std::string name, bool play = true): name{name}, pause_time{play ? timestamp() : clock::now()} {}
    
    //Actions
      void pause() {pause_time = clock::now();}

      void play(){
        init_time += clock::now()-pause_time;
        pause_time = timestamp();
      }

      void reset(bool play = true){
        init_time = clock::now();
        pause_time = play ? timestamp() : clock::now();
      }

    //Const methods
      bool is_playing() const {return pause_time == timestamp();}
      bool is_paused() const {return !is_playing();}
      std::string get_name() const {return name;}
      value_type time() const {return time_since(init_time) - (is_playing() ? static_cast<value_type>(0) : time_since(pause_time));}

    //Static methods
      static value_type time_since(timestamp start) {return duration_cast<D>(clock::now()-start).count();}
      static value_type now() {return time_since(prog_start);}
      static void delay(value_type delay_time) {std::this_thread::sleep_for(D(delay_time));}
};

//Printing
  template<typename charT, typename traits, Duration D>
  std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, Timer<D> const & timer){
    return os << timer.time();
  }

//Legacy Functions
  inline long long millis(){return Timer<std::chrono::milliseconds>::now();};
  inline long long micros(){return Timer<std::chrono::microseconds>::now();};
  inline void delay(long long millis){Timer<>::delay(millis);};

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_TIME_HPP_
#pragma once
#include "header.hpp"
#include "types.hpp"

long long millis();
long long micros();
void delay(long long millis);


class Timer_base{
  protected:
    typedef std::chrono::steady_clock clock;
    typedef clock::time_point timestamp;
    friend int main();
    static const timestamp prog_start;
};


template <Duration D = std::chrono::milliseconds>
class Timer: private Timer_base{
  private:
    typedef typename D::rep value_type;

    const std::string name;
    timestamp init_time, pause_time; //init_time cannot be reliably used for the time of initialization

  public:
    Timer();
    explicit Timer(bool play);
    explicit Timer(string_literal name);
    explicit Timer(std::string name, bool play = true);
    
    void play();
    void pause();
    void reset(bool play = true);

    bool is_playing() const;
    bool is_paused() const;
    value_type time() const;
    std::string get_name() const;

    static value_type time_since(timestamp start);
    static value_type now();
    static void delay(value_type delay_time);
};

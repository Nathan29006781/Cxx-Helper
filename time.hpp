#ifndef CXX_HELPER_TIME_HPP_
#define CXX_HELPER_TIME_HPP_

#include "header_config.hpp"
#include "types.hpp"
#include <chrono>
#include <string>

template <typename D> concept Duration = std::chrono::__is_duration<D>::value;

CXX_HELPER_BEGIN_NAMESPACE

long long millis();
long long micros();
void delay(long long millis);


class Timer_base{
  protected:
    typedef std::chrono::steady_clock clock;
    typedef clock::time_point timestamp;
    static const timestamp prog_start;
};


template <Duration D = std::chrono::milliseconds>
class Timer: private Timer_base{
  private:
    typedef typename D::rep value_type;

    const std::string name;
    timestamp init_time, pause_time; //init_time will change so cannot be reliably used for the time of initialization

  public:
    typedef std::chrono::nanoseconds nanoseconds;
    typedef std::chrono::microseconds microseconds;
    typedef std::chrono::milliseconds milliseconds;
    typedef std::chrono::seconds seconds;
    typedef std::chrono::minutes minutes;
    typedef std::chrono::hours hours;
    typedef std::chrono::days days;
    typedef std::chrono::weeks weeks;
    typedef std::chrono::years years;
    typedef std::chrono::months months;

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

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_TIME_HPP_
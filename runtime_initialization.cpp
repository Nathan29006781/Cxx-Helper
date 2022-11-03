#include "colours.hpp"
#include "time.hpp"
CXX_HELPER_BEGIN_NAMESPACE

Timer_base::timestamp const Timer_base::prog_start{std::chrono::steady_clock::now()};
int term_color::index{-1};
std::vector<term_color*> term_color::col_list{};

CXX_HELPER_END_NAMESPACE
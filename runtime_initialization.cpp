#include "colours.hpp"
#include "time.hpp"
CXX_HELPER_BEGIN_NAMESPACE

Timer_base::timestamp const Timer_base::prog_start{std::chrono::steady_clock::now()};
int Colour::index{-1};
std::vector<Colour*> Colour::col_list{};

CXX_HELPER_END_NAMESPACE
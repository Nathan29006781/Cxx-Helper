#include "time.hpp"
CXX_HELPER_BEGIN_NAMESPACE

const Timer_base::timestamp Timer_base::prog_start = std::chrono::steady_clock::now();

CXX_HELPER_END_NAMESPACE
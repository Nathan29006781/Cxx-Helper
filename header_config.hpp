#ifndef CXX_HELPER_HEADER_CONFIG_HPP_
#define CXX_HELPER_HEADER_CONFIG_HPP_

#define NATHAN_M_PROJECT_NAME cxx_helper

#ifdef NATHAN_M_PROJECT_NAME
#define CXX_HELPER_BEGIN_NAMESPACE namespace NATHAN_M_PROJECT_NAME{
#define CXX_HELPER_END_NAMESPACE }
#else
#define NATHAN_M_PROJECT_NAME
#define CXX_HELPER_BEGIN_NAMESPACE
#define CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_BEGIN_NAMESPACE

CXX_HELPER_BEGIN_NAMESPACE
CXX_HELPER_END_NAMESPACE

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define DEBUG(...) printf("\033[34mFile:\'%s\' | Function:\'%s\' | Line:\'%d\'" __VA_OPT__(" | \033[32mMessage:\'%s\033[32m\'") "\033[0m\n", __FILENAME__, __PRETTY_FUNCTION__, __LINE__ __VA_OPT__(,) __VA_ARGS__);
#define ERROR(...) printf("\033[31mFile:\'%s\' | Function:\'%s\' | Line:\'%d\'" __VA_OPT__(" | Error:\'%s\033[31m\'") "\033[0m\n", __FILENAME__, __PRETTY_FUNCTION__, __LINE__ __VA_OPT__(,) __VA_ARGS__);
// #define ERROR(...) throw std::logic_error(__VA_ARGS__);


#endif //CXX_HELPER_HEADER_CONFIG_HPP_
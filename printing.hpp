// #ifndef CXX_HELPER_PRINTING_HPP_
// #define CXX_HELPER_PRINTING_HPP_

// #include "header_config.hpp"
// #include "colours.hpp"
// #include "time.hpp"
// #include "timer.hpp"
// #include "math/geometry/position.hpp"
// #include <bitset>
// #include <iostream>

// //allow bitset to be printed as number, hex
// //make convert_all_args for std::byte

#define STRINGIFY(...) #__VA_ARGS__
#define OUTPUT(...)  std::cout __VA_OPT__(<< " \'" << STRINGIFY(__VA_ARGS__) << "\' = \'" << (__VA_ARGS__) << '\'' )<< '\n';
//Use OUTPUT only for outputting one thing at a time (it is variadic to allow commas in input)
#ifdef NO_PRINTF
#define printf(...)
#endif

// CXX_HELPER_BEGIN_NAMESPACE

// template<typename charT, typename traits>
// std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& os, std::byte const& byte){
//   auto flags = os.flags();
//   auto precision = os.precision();
//   auto fill = os.fill();

//   os << "0x" << std::uppercase << std::setfill('0') << std::hex << std::setw(2) << std::to_integer<int32_t>(byte);

//   os.flags(flags);
//   os.precision(precision);
//   os.fill(fill);

//   return os;
// }

// class Vector;

// /**
//  * -1: no timestamp
//  * 0: 1500 ms
//  * 1: 1500 millis
//  * 2: 1500 milliseconds
//  * 3: 1 s 500 ms
//  * 4: 1 sec 500 millis
//  * 5: 1 second 500 milliseconds
//  */

// constexpr int n_printf_max{50};

// /**
//  * @brief prints a new line to the terminal
//  * 
//  * @param count how many lines to print
//  */
// inline void newline(int count = 1){
//   std::cout << std::string (count-1 , '\n') << std::endl; //-1 because endl puts the final one
// }

// //Convert Args
//   /*General case*/ template <typename T> std::string convert_all_args(std::string const& fmt, T const& arg); //Forces double / int overload instead
//   /*For arithmetic types*/ template <Arithmetic T> std::string convert_all_args(std::string const& fmt, T arg); //Not T const& because that duplicates against the non-arithmetic template overload
//   /*Vectors (C++)*/ template <typename _Tp> std::string convert_all_args(std::string const& fmt, std::vector<_Tp> const& arg);
//   /*Arrays (C++)*/ template <typename _Tp, std::size_t _Nm> std::string convert_all_args(std::string const& fmt, std::array<_Tp, _Nm> const& arg);
//   /*Arrays (C)*/ template <typename _Tp, std::size_t _Nm> std::string convert_all_args(std::string const& fmt, const _Tp (&arg) [_Nm]);
//   /*Initializer lists*/ template <typename _Tp> std::string convert_all_args(std::string const& fmt, std::initializer_list<_Tp> const& arg);
//   /*Bitsets*/ template <size_t _Nb> std::string convert_all_args(std::string const& fmt, std::bitset<_Nb> const& arg);
//   /*Tuples*/ template <typename... Args> std::string convert_all_args(std::string const& fmt, std::tuple<Args...> const& arg);
//   /*Strings*/ inline std::string convert_all_args(std::string const& fmt, std::string const& arg);
//   /*Positions*/ inline std::string convert_all_args(std::string const& fmt, Position const& arg);

// // Printing

//   //Template Recursion Base case
//   inline std::string const& sprintf2(std::string const& fmt) {return fmt;}

//   /**
//   * @brief Formats a printf-style function call into an std::string with more safety.
//   * Calls itself recursively to handle all the arguments to the function.
//   * @param fmt Format string
//   * @param arg 1st argument
//   * @param args Rest of the arguments
//   * @return std::string
//   */
//   //No support for %n format
//   template <typename Param, typename... Params>
//   std::string sprintf2(std::string fmt, Param const& arg, Params const&... args);

//   /**
//   * @brief printf that handles strings and automatically newlines. Can print coloured and a timestamp
//   * 
//   * @param colour The colour to print in 
//   * @param fmt printf format string
//   * @param args printf args
//   */
//   template <typename... Params>
//   std::string sprintf2_format(term_color const& colour, int time_type, std::string fmt, Params... args);

//   /**
//   * @brief printf that handles strings and automatically newlines. Can print coloured and a timestamp
//   * 
//   * @param colour The colour to print in 
//   * @param fmt printf format string
//   * @param args printf args
//   */
//   template <typename... Params>
//   std::string sprintf2_no_colour(int time_type, std::string fmt, Params... args);

//   /**
//   * @brief printf that handles all datatypes and automatically newlines. Can print coloured and a timestamp
//   *
//   * @param colour The colour to print in 
//   * @param fmt printf format string
//   * @param args printf args
//   */
//   template <typename... Params>
//   std::string printf2(term_color const& colour, int time_type, string_literal fmt, Params... args);

//   /**
//   * @brief printf that handles all datatypes and automatically newlines. Can print coloured
//   *
//   * @param colour The colour to print in 
//   * @param fmt printf format string
//   * @param args printf args
//   */
//   template <typename... Params>
//   std::string printf2(term_color const& colour, std::string fmt, Params... args);

//   /**
//   * @brief printf that handles all datatypes and automatically newlines.
//   * 
//   * @param fmt printf format string
//   * @param args printf args
//   */
//   template <typename... Params>
//   std::string printf2(string_literal fmt, Params... args);

// //Convert Args Definitions
//   template <typename T>
//   std::string convert_all_args(std::string const& fmt, T const& arg){
//     char buffer[n_printf_max];
//     snprintf(buffer, n_printf_max, fmt.c_str(), arg);
//     return buffer; //returns local buffer by copy to prevent memory leaks or dangling reference
//   }
//   template <Arithmetic T> //T is conceptually restricted to arithmetic types
//   std::string convert_all_args(std::string const& fmt, T arg){ //Not T const& because that duplicates against the non-arithmetic template overload
//     string_literal format{fmt.c_str()};
//     std::string const fmt_safe {"   " + fmt};
//     char buffer[n_printf_max];
//     char const end[3]{static_cast<char>(tolower(*(fmt.end() - 1))), static_cast<char>(*(fmt.end() - 2)), static_cast<char>(*(fmt.end() - 3))};

//     if(end[1] == 'L') snprintf(buffer, n_printf_max, format, static_cast<long double>(arg)); //%large floating
//     else if(end[0] == 'f' || end[0] == 'e' || end[0] == 'g' || end[0] == 'a') snprintf(buffer, n_printf_max, format, static_cast<double>(arg)); //floating
//     else if(end[0] == 'd' || end[0] == 'i'){ //ints
//       if(end[2] == 'h') snprintf(buffer, n_printf_max, format, static_cast<signed char>(arg));
//       else if(end[2] == 'l') snprintf(buffer, n_printf_max, format, static_cast<long long int>(arg));
//       else if(end[1] == 'h') snprintf(buffer, n_printf_max, format, static_cast<short int>(arg));
//       else if(end[1] == 'l') snprintf(buffer, n_printf_max, format, static_cast<long int>(arg));
//       else if(end[1] == 'j') snprintf(buffer, n_printf_max, format, static_cast<intmax_t>(arg));
//       else snprintf(buffer, n_printf_max, format, static_cast<int>(arg));
//     }
//     else if(end[0] == 'u' || end[0] == 'o' || end[0] == 'x'){ //unsigned, octal, hex
//       if(end[2] == 'h') snprintf(buffer, n_printf_max, format, static_cast<unsigned char>(arg));
//       else if(end[2] == 'l') snprintf(buffer, n_printf_max, format, static_cast<unsigned long long int>(arg));
//       else if(end[1] == 'h') snprintf(buffer, n_printf_max, format, static_cast<unsigned short int>(arg));
//       else if(end[1] == 'l') snprintf(buffer, n_printf_max, format, static_cast<unsigned long int>(arg));
//       else if(end[1] == 'j') snprintf(buffer, n_printf_max, format, static_cast<uintmax_t>(arg));
//       else snprintf(buffer, n_printf_max, format, static_cast<unsigned int>(arg));
//     }
//     else if(end[0] == 'c'){ //characters (are treated as ints)
//       if(end[1] == 'l') snprintf(buffer, n_printf_max, format, static_cast<wint_t>(arg));
//       else snprintf(buffer, n_printf_max, format, static_cast<int>(arg));
//     }
//     else if(end[1] == 'z') snprintf(buffer, n_printf_max, format, static_cast<size_t>(arg));
//     else if(end[1] == 't') snprintf(buffer, n_printf_max, format, static_cast<ptrdiff_t>(arg));

//     else snprintf(buffer, n_printf_max, format, arg);
//     return buffer;
//   }
//   template <typename _Tp>
//   std::string convert_all_args(std::string const& fmt, std::vector<_Tp> const& arg){
//     if(fmt.back() == 'p') return convert_all_args(fmt, arg.data());
//     std::string str;
//     str += '{';
//     for (typename std::vector<_Tp>::const_iterator it{arg.begin()}; it != arg.end(); it++){
//       str += convert_all_args(fmt, *it);
//       if (it+1 != arg.end()) str += ", ";
//     }
//     str += '}';
//     return str;
//   }
//   template <typename _Tp, std::size_t _Nm>
//   std::string convert_all_args(std::string const& fmt, std::array<_Tp, _Nm> const& arg){
//     if(fmt.back() == 'p') return convert_all_args(fmt, arg.data());
//     else if(std::is_same<_Tp, char>::value && fmt.back() == 's') return convert_all_args(fmt, arg.data());
//     std::string str;
//     str += '{';
//     for (typename std::array<_Tp, _Nm>::const_iterator it{arg.begin()}; it != arg.end(); it++){
//       str += convert_all_args(fmt, *it);
//       if (it+1 != arg.end()) str += ", ";
//     }
//     str += '}';
//     return str;
//   }
//   template <typename _Tp, std::size_t _Nm>
//   std::string convert_all_args(std::string const& fmt, const _Tp (&arg) [_Nm]){
//     if(fmt.back() == 'p') return convert_all_args(fmt, const_cast<_Tp*>(arg));
//     else if(std::is_same<_Tp, char>::value && fmt.back() == 's') return convert_all_args(fmt, const_cast<_Tp*>(arg));
//     std::string str;
//     str += '{';
//     for (int i{0}; i < _Nm; i++){
//       str += convert_all_args(fmt, arg[i]);
//       if (i+1 != _Nm) str += ", ";
//     }
//     str += '}';
//     return str;
//   }
//   template <typename _Tp>
//   std::string convert_all_args(std::string const& fmt, std::initializer_list<_Tp> const& arg){
//     std::string str;
//     str += '{';
//     for (typename std::initializer_list<_Tp>::const_iterator it{arg.begin()}; it != arg.end(); it++){
//       str += convert_all_args(fmt, *it);
//       if (it+1 != arg.end()) str += ", ";
//     }
//     str += '}';
//     return str;
//   }
//   template <size_t _Nb>
//   std::string convert_all_args(std::string const& fmt, std::bitset<_Nb> const& arg){
//     std::string str;
//     str += '{';
//     if(fmt.back() == 's') str += arg.to_string();
//     else{
//       for(int i{0}; i < arg.size(); i++){
//         str += convert_all_args(fmt, arg[i]);
//         if (i+1 != arg.size()) str += ", ";
//       }
//     }
//     str += '}';
//     return str;
//   }
//   template <typename... Args>
//   std::string convert_all_args(std::string const& fmt, std::tuple<Args...> const& arg){
//     std::string str;
//     str += '{';
//     for(int i{0}; i < std::tuple_size<std::tuple<Args...>>(); i++){
//       str += convert_all_args(fmt, std::get<i>(arg));
//     }
//     str += '}';
//     return str;
//   }
//   std::string convert_all_args(std::string const& fmt, std::string const& arg){
//     if(fmt.back() == 'p') return convert_all_args(fmt, arg.data());
//     return arg;
//   }
//   std::string convert_all_args(std::string const& fmt, Position const& arg){
//     return '(' + convert_all_args(fmt, arg.x) + ", " + convert_all_args(fmt, arg.y) + ", " + convert_all_args(fmt, arg.angle) + ")";
//   }

// //Print Definitions
//   template <typename Param, typename... Params>
//   std::string sprintf2(std::string fmt, Param const& arg, Params const&... args){
//     std::string::const_iterator first = fmt.begin(), second; //? Why is first being initialized? It's modified immediately after

//     first = std::find(first, fmt.cend(), '%');
//     second = fmt.begin() + fmt.find_first_of("diuoxXfFeEgGaAcspn%*", first-fmt.begin()+1) + 1;
    
//     if(second == fmt.begin()) return fmt; //No valid format specifier found

//     std::string start{std::string(fmt.cbegin(), first)};
//     std::string format_specifier{std::string(first, second)};
//     std::string converted;
//     std::string rest{std::string(second, fmt.cend())};

//     if(format_specifier.back() == '%'){
//       converted = "%";
//       rest = sprintf2(rest, arg, args...);
//     }
//     else if(format_specifier.back() == '*'){
//       format_specifier.pop_back();
//       format_specifier += convert_all_args("%d", arg);
//       rest = sprintf2(format_specifier + rest, args...);
//     }
//     else if(format_specifier.back() == 'n'){
//       converted = "";
//       //set_length(arg, start, converted);
//       rest = sprintf2(rest, args...);
//     }
//     else{
//       converted = convert_all_args(format_specifier, arg);
//       rest = sprintf2(rest, args...);
//     }
    
//     return start + converted + rest;
//   }
//   template <typename... Params>
//   std::string sprintf2_format(term_color const& colour, int time_type, std::string fmt, Params... args){
//     std::string str{sprintf2(fmt, args...)};
//     std::string timestamp;

//     size_t white_count{str.find_first_not_of(" \n")};
//     std::string whitespace{std::string(str.begin(), str.begin() + white_count)};
//     str.erase(str.begin(), str.begin() + white_count);

//     if(time_type == -1) timestamp = "";
//     else if(time_type == 0) timestamp = sprintf2("%-9s| ", Timer_old::to_string(millis(), timing_units::millis, 0, 0));
//     else if(time_type == 1) timestamp = sprintf2("%-12s| ", Timer_old::to_string(millis(), timing_units::millis, 1, 0));
//     else if(time_type == 2) timestamp = sprintf2("%-18s| ", Timer_old::to_string(millis(), timing_units::millis, 2, 0));
//     else if(time_type == 3) timestamp = sprintf2("%-15s| ", Timer_old::to_string(millis(), timing_units::millis, 0, 1));
//     else if(time_type == 4) timestamp = sprintf2("%-21s| ", Timer_old::to_string(millis(), timing_units::millis, 1, 1));
//     else if(time_type == 5) timestamp = sprintf2("%-30s| ", Timer_old::to_string(millis(), timing_units::millis, 2, 1));

//     return whitespace + timestamp + colour() + str + term_colors::none();
//   }
//   template <typename... Params>
//   std::string sprintf2_no_colour(int time_type, std::string fmt, Params... args){
//     std::string str{sprintf2(fmt, args...)};
//     std::string timestamp;

//     size_t white_count{str.find_first_not_of(" \n")};
//     std::string whitespace{std::string(str.begin(), str.begin() + white_count)};
//     str.erase(str.begin(), str.begin() + white_count);

//     if(time_type == -1) timestamp = "";
//     else if(time_type == 0) timestamp = sprintf2("%-9s| ", Timer_old::to_string(millis(), timing_units::millis, 0, 0));
//     else if(time_type == 1) timestamp = sprintf2("%-12s| ", Timer_old::to_string(millis(), timing_units::millis, 1, 0));
//     else if(time_type == 2) timestamp = sprintf2("%-18s| ", Timer_old::to_string(millis(), timing_units::millis, 2, 0));
//     else if(time_type == 3) timestamp = sprintf2("%-15s| ", Timer_old::to_string(millis(), timing_units::millis, 0, 1));
//     else if(time_type == 4) timestamp = sprintf2("%-21s| ", Timer_old::to_string(millis(), timing_units::millis, 1, 1));
//     else if(time_type == 5) timestamp = sprintf2("%-30s| ", Timer_old::to_string(millis(), timing_units::millis, 2, 1));

//     return whitespace + timestamp + str;
//   }
//   template <typename... Params>
//   std::string printf2(term_color const& colour, int time_type, string_literal fmt, Params... args){
//     std::string str{sprintf2_format(colour, time_type, fmt, args...)};
//     printf("%s\n", str.c_str());
//     return str;
//   }
//   template <typename... Params>
//   std::string printf2(term_color const& colour, std::string fmt, Params... args){
//     std::string str{sprintf2_format(colour, -1, fmt, args...)};
//     printf("%s\n", str.c_str());
//     return str;
//   }
//   template <typename... Params>
//   std::string printf2(string_literal fmt, Params... args){
//     std::string str{sprintf2(fmt, args...)};
//     printf("%s\n", str.c_str());
//     return str;
//   }

// CXX_HELPER_END_NAMESPACE
// #endif //CXX_HELPER_PRINTING_HPP_
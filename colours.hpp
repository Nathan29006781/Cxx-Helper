#ifndef CXX_HELPER_COLOURS_HPP_
#define CXX_HELPER_COLOURS_HPP_

#include "header_config.hpp"
#include <string>
#include <vector>


CXX_HELPER_BEGIN_NAMESPACE

class Colour{
  private:
    std::string const id, seq;
    bool const used;
    static std::vector<Colour*> col_list;
    static int index;
  public:
    //Constructors
      Colour (Colour const &) = delete;
      Colour(std::string id, std::string seq, bool used = true): id{id}, seq{seq}, used{used} {col_list.push_back(this);}
    
    //Getters
      std::string const & name() const {return id;}
      std::string const & operator()() const {return seq;}
    
    //Static method
      static std::string const & get_next(){
        do{
          if(index == col_list.size()-1) index = 0;
          else index++;
        }
        while (!col_list[index]->used);
        return (*col_list[index])();
      }
};

namespace term_colors{
  inline Colour none{"NONE", "\033[0m", false};
  inline Colour error{"ERROR", "\033[31mERROR: ", false};
  inline Colour warning{"WARNING", "\033[33mWARNING: ", false};
  inline Colour notif{"NOTIFICATION", "\033[32mNOTIF: ", false};
  inline Colour black{"BLACK", "\033[30m", false};
  inline Colour red{"RED", "\033[31m"};
  inline Colour green{"GREEN", "\033[32m"};
  inline Colour yellow{"YELLOW", "\033[33m"};
  inline Colour blue{"BLUE", "\033[34m"};
  inline Colour magenta{"MAGENTA", "\033[35m"};
  inline Colour cyan{"CYAN", "\033[36m"};
  inline Colour white{"WHITE", "\033[37m", false};
}

CXX_HELPER_END_NAMESPACE
#endif //CXX_HELPER_COLOURS_HPP_
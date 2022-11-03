#include <iostream>
#include <string>

void rainbow_for(int size, char c1 = 'R', char c2 = 'Y', char c3 = 'G', char c4 = 'B', char c5 = 'P'){
  char const chars[5] {c1, c2, c3, c4, c5};

  for(int line = 0; line < size+1; line++){
    std::string line_str;

    std::cout << std::string(size-line, ' ');
    for(int i = 0, idx = 0; i <= size+line; i++){
      line_str += chars[idx];

      if(i < line) idx = (idx+1) % 5;
      else if(line == size) line_str.back() = ' ';
    }
    
    std::cout << line_str;
    std::reverse(line_str.begin(), line_str.end());
    std::cout << line_str << std::endl;
  }
}

void rainbow_while(int size, char c1 = 'R', char c2 = 'Y', char c3 = 'G', char c4 = 'B', char c5 = 'P'){
  char const chars[5] {c1, c2, c3, c4, c5};

  int line = 0;
  while(line < size+1){
    std::string line_str;

    std::cout << std::string(size-line, ' ');
    int i = 0, idx = 0;
    while(i <= size+line){
      line_str += chars[idx];

      if(i < line) idx = (idx+1) % 5;
      else if(line == size) line_str.back() = ' ';
      i++;
    }

    line++;
    std::cout << line_str;
    std::reverse(line_str.begin(), line_str.end());
    std::cout << line_str << std::endl;
  }
}

void rainbow_ptr(int* size, char* c1, char* c2, char* c3, char* c4, char* c5){
  char const ** const charps = static_cast<char const **>(malloc(5*sizeof(char*))); //Pointer to char*. Represents an array of the char* func params. charps means multiple char ptrs
  *(charps + 0) = c1; //Initializing charps with the char* params
  *(charps + 1) = c2;
  *(charps + 2) = c3;
  *(charps + 3) = c4;
  *(charps + 4) = c5;

  std::ostream* out_ptr = &std::cout; //Pointer to cout
  std::ostream& (*endl_ptr)(std::ostream&) = std::endl; //Function ptr to endl
  int line = 0; int* line_ptr = &line;

  while(*line_ptr < *size+1){
    int i = 0; int* i_ptr = &i; //i is the loop counting variable
    char* const line_str = static_cast<char*>(calloc(*size * 2 + 1, sizeof(char)));

    while((*i_ptr)++ < *size - *line_ptr) *out_ptr << ' ';

    char const * const * idx = charps; //Points to the current letter. Is a pointer offset from the charps array 
    *i_ptr = -1;

    while((*i_ptr)++ <= *size + *line_ptr){
      *(line_str + *i_ptr) = **idx; //appends the current character to the current str for the line

      if(*i_ptr < *line_ptr) idx = charps+((idx-charps)+1) % 5;
      else if(*line_ptr == *size) *(line_str + *i_ptr) = ' ';
    }

    (*line_ptr)++;

    *out_ptr << line_str;
    *i_ptr = strlen(line_str);
    while((*i_ptr) --> 0) *out_ptr << *(line_str + *i_ptr); //Prints line_str by character in reverse
    *out_ptr << endl_ptr; //endl_ptr uses the ostream function pointer overload

    free(line_str);
  }
  free(charps);
}

double find_sqrt(double n, double tolerance = 0.0)  {double guess = 1.0; while(std::abs(n-guess*guess) > tolerance) guess = (guess+n/guess)/2; return guess;}
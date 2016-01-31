#include "tokenizer.hpp"
#include <unistd.h>

int main(int argc, char** argv){
  (void) argc;
  (void) argv;
  
  int read_bytes = -1;
  while(read_bytes != 0)
    {
      
    }
  
  std::string s ("Hello   world");
  tkr::tokenizer t(s, ' ');

  while(t.has_more_token()){
    std::cout << t.next_token() << std::endl;
  }
  
  std::cout << "Origine:" <<  s << std::endl;

  return 0;
}

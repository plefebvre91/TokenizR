#include "tokenizer.hpp"
#include <unistd.h>

#define BUF_SIZE 512

int main(int argc, char** argv){
  (void) argc;
  (void) argv;

  char buf[BUF_SIZE];
  int read_bytes = 1;

  while(read_bytes > 0)
    {
      read_bytes = read(0, buf, BUF_SIZE);
      tkr::tokenizer t(buf, ' ');
      while(t.has_more_token()){
	std::cout << t.next_token() << std::endl;
      }
    }  
  return 0;
}

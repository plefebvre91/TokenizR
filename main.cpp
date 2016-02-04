#include "tokenizer.hpp"
#include <unistd.h>
#include <cstring>
#include <cstdio>

#define BUF_SIZE 512

int main(int argc, char** argv){
  (void) argc;
  (void) argv;

  char buf[BUF_SIZE];
  memset(buf, 0, sizeof(buf));
  
  int read_bytes = 1;

  while(read_bytes > 0)
    {
      read_bytes = read(STDIN_FILENO, buf, BUF_SIZE);

      if (read_bytes == -1)
	{
	  perror("read() error:");
	  exit(EXIT_FAILURE);
	}
      
      tkr::tokenizer t(buf, ' ');
      while(t.has_more_tokens()){
	std::cout << t.next_token() << std::endl;
      }
      memset(buf, 0, sizeof(buf));
    }  
  
  return EXIT_SUCCESS;
}

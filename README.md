# TokenizR

Tokenization C++ library

## Usage

```c++
#include "tokenizer.hpp"

int main(int argc, char** argv) {
   
  // Tokenizer object creation (separator is blank space by default)
  tkr::tokenizer t("Hello World !");
  
  // Iterates on tokens
  while(t.has_more_tokens()) {
    std::cout << t.next_token() << std::endl;
  }
  
  return 0;
}
```

  
Output :
```
Hello
World
!
```
  
  
  

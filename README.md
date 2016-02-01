# TokenizR

String tokenization C++ library

## Example

### Code

```c++
#include <iostream>
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
### Compilation
```
gcc code.cpp -o my_tkr -lkr
```
  
### Output
```
Hello
World
!
```
  
  
  

#include <iostream>
#include <vector>
#include <sstream>

#include "tokenizer.hpp"

using namespace tkr;

tokenizer::tokenizer()
{
  //...
}

tokenizer::tokenizer(const tokenizer& t)
{
  //...
}

tokenizer::tokenizer(std::string& str, char separator)
{
  _tokenize(str, separator);
}

tokenizer::tokenizer(const char* str, char separator)
{
  std::string s = str;
  _tokenize(s, separator);
}


bool tokenizer::has_more_token() const
{
  return true;
}

std::string& tokenizer::next_tokens() const
{
  
}


void tokenizer::_tokenize(std::string& str, char separator)
{
  std::stringstream ss(str);
  std::string s;
  while(std::getline(ss, s, separator))
    {
      _tokens.push_back(s);
      std::cout << s << std::endl;
    }
}


int main(int argc, char** argv){
  tkr::tokenizer("Hello World", ' ');
  return 0;
}

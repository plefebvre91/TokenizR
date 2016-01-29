#include <iostream>
#include <vector>
#include <sstream>

#include "tokenizer.hpp"

using namespace tkr;

tokenizer::tokenizer(std::string& str, char separator):
  _tokens()
{
  _tokenize(str, separator);
}

tokenizer::tokenizer(const char* str, char separator):
  _tokens()
{
  std::string s = str;
  _tokenize(s, separator);
}


bool tokenizer::has_more_token() const
{
  return (_it != _tokens.end());
}

std::string tokenizer::next_token()
{
  std::vector<std::string>::const_iterator old_it = _it;
  ++_it;
  return *old_it;
}


void tokenizer::_tokenize(std::string& str, char separator)
{
  std::stringstream ss(str);
  std::string s;
  while(std::getline(ss, s, separator))
    {
      _tokens.push_back(s);
      //   std::cout << s << std::endl;
    }
  _it = _tokens.begin();
}


int main(int argc, char** argv){
  tkr::tokenizer t("Hello World", ' ');

  while(t.has_more_token()){
    std::cout << "token : " << std::endl;
    std::cout << t.next_token() << std::endl;
  }
  return 0;
}

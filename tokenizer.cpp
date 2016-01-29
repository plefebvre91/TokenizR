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

  std::string s;
  
  // voir si on veut modifier la chaine ou non
  
  str.erase(std::unique(str.begin(), str.end()), str.end());

  std::stringstream ss(str);

  while(std::getline(ss, s, separator))
    {
      _tokens.push_back(s);
    }

  _it = _tokens.begin();
}

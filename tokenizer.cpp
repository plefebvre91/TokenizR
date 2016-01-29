/*
 * This file is part of TKR Library.
 *
 * TKR Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * TKR Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with TKR Library.  If not, see <http://www.gnu.org/licenses/>.
*/

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
  return _it != _tokens.end();
}


const std::string& tokenizer::next_token()
{
  std::vector<std::string>::const_iterator old_it = _it++;
  return *old_it;
}


void tokenizer::_tokenize(std::string& str, char separator)
{

  std::string token;
  
  // Temporary string for character removing
  std::string tmp(str);
  
  // Remove consecutive 'separator' character (on tmp string)
  tmp.erase(std::unique(tmp.begin(), tmp.end(), [separator](char a, char b){ return a == separator && b == separator;}), tmp.end());
  
  std::stringstream ss(tmp);

  // Add token in vector
  while(std::getline(ss, token, separator))
    {
      _tokens.push_back(token);
    }
  
  _it = _tokens.begin();
}

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


bool tokenizer::has_more_tokens() const
{
  // No more token if iterator is 
  // at the end of tokens vector
  //  if(!_tokens.empty())
  //    {
      return _it != _tokens.end();
  //   }
  // else
  //   {
  //     return false;
  //   }
}


const std::string& tokenizer::next_token()
{
  
  // Update iterator and 
  // save old iterator position
  std::vector<std::string>::const_iterator old_it = _it++;
  
  return *old_it;
}


void tokenizer::_tokenize(std::string& str, char separator)
{
  // Temporary string for character removing
  std::string tmp(str);
  
  // Remove consecutive 'separator' character (on tmp string)
  tmp.erase(std::unique(tmp.begin(), tmp.end(), [separator](char a, char b){ return a == separator && b == separator;}), tmp.end());


  
  //retirer espace debut / fin 
  //  tmp = std::regex_replace(tmp, std::regex("^ +| +$|( ) +"), "$1");
  const auto str_begin = tmp.find_first_not_of(separator);
  if (str_begin == std::string::npos)
    return; // no content

  const auto str_end = tmp.find_last_not_of(separator);
  const auto str_range = str_end - str_begin + 1;

  tmp = tmp.substr(str_begin, str_range);
  
  
  
  //  tmp = std::regex_replace(tmp, std::regex("^ +"), "");
  std::string token;
  std::stringstream ss(tmp);
  
  //Add token in vector
  while(std::getline(ss, token, separator))
    {
      //      if(token.back() == '\n'){
      //	token.back() = (char)'\0';
	_tokens.push_back(token);
      
    }
  //  size_t start = 0;
  //  size_t pos = 0;
  //  size_t ret = 0;
  
  // while((ret = tmp.find_first_of(separator, pos)) != std::string::npos) {
  //   pos += ret;
  //   _tokens.push_back(tmp.substr(start, pos));
  //   start += (ret+1);
  // }

  _it = _tokens.begin();
}

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
  return _it != _tokens.end();
}


const std::string& tokenizer::next_token()
{
  // Update iterator and save old iterator position
  std::vector<std::string>::const_iterator old_it = _it++;
  
  return *old_it;
}


void tokenizer::_tokenize(std::string& str, char separator)
{
  // Temporary string for character removing
  std::string tmp(str);
  
  // Remove consecutive 'separator' character (on tmp string)
  tmp.erase(std::unique(tmp.begin(),
			tmp.end(), 
			[separator](char a, char b){ return a == separator && b == separator;}), 
	    tmp.end());

  // Remove separator at beginning and end of string
  const auto str_begin = tmp.find_first_not_of(separator);

  // No content
  if (str_begin == std::string::npos)
    {
      return;
    }
  
  const auto str_end = tmp.find_last_not_of(separator);
  const auto str_range = str_end - str_begin + 1;

  tmp = tmp.substr(str_begin, str_range);
    
  std::string token;
  std::stringstream ss(tmp);
  
  //Add token in vector
  while(std::getline(ss, token, separator))
    {
      _tokens.push_back(token);
    }
  
  // Set the iterator on the fist token
  _it = _tokens.begin();
}

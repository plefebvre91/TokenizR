#ifndef TOKENIZER_HPP 
#define TOKENIZER_HPP

#include <iostream>
#include <vector>
#include <sstream>

#define TKR_DEFAULT_SEPARATOR ' '

namespace tkr
{
  class tokenizer
  {
  public:
    /**
     * Constructor
     * \param String to tokenize
     * \param Token separator (blank by default)
     */
    tokenizer(std::string&, char separator = TKR_DEFAULT_SEPARATOR);
    
    /**
     * Constructor
     * \param String to tokenize
     * \param Token separator (blank by default)
     */
    tokenizer(const char*, char separator =  TKR_DEFAULT_SEPARATOR);
    
    /**
     * \return false when all tokens have been read
     */
    bool has_more_token() const;

    /**
     * \return the next token found in given string
     */
    std::string next_token();
    
  private:
    void _tokenize(const char* str, char separator = TKR_DEFAULT_SEPARATOR);
    void _tokenize(std::string& str, char separator = TKR_DEFAULT_SEPARATOR);

    // Vector containing all tokens
    std::vector<std::string> _tokens;
    std::vector<std::string>::const_iterator _it;
  };
}

#endif

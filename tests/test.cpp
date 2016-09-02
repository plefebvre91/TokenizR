#include <iostream>
#include "tokenizer.hpp"
#include <assert.h>


#define TEST_WORD                     "tokenizer"
#define TEST_NO_CHARACTER             ""
#define TEST_ONLY_BLANK               "         "
#define TEST_ONLY_SEPARATOR           "----"
#define TEST_ONE_WORD                 TEST_WORD
#define TEST_BLANK_BEFORE_WORD        " " TEST_WORD
#define TEST_BLANKS_BEFORE_WORD       "     " TEST_WORD
#define TEST_BLANK_AFTER_WORD         TEST_WORD " "
#define TEST_BLANKS_AFTER_WORD        TEST_WORD "      "
#define TEST_BLANK_BEFORE_AFTER_WORD  " " TEST_WORD " "
#define TEST_BLANKS_BEFORE_AFTER_WORD "       " TEST_WORD "      "
#define TEST_TWO_WORDS                TEST_WORD " " TEST_WORD

int main(int argc, char** argv)
{
  (void)argc;
  (void)argv;

  tkr::tokenizer test1(TEST_NO_CHARACTER);
  assert (test1.has_more_tokens() == false);

  tkr::tokenizer test2(TEST_ONLY_BLANK);
  assert (test2.has_more_tokens() == false);
  
  tkr::tokenizer test3(TEST_ONLY_SEPARATOR, '-');
  assert (test3.has_more_tokens() == false);
  
  tkr::tokenizer test4(TEST_ONE_WORD);
  assert (test4.has_more_tokens() == true);
  assert (test4.next_token().compare(TEST_WORD) == 0);
  assert (test4.has_more_tokens() == false);

  tkr::tokenizer test5(TEST_BLANK_BEFORE_WORD);
  assert (test5.has_more_tokens() == true);
  assert (test5.next_token().compare(TEST_WORD) == 0);
  assert (test5.has_more_tokens() == false);

  tkr::tokenizer test6(TEST_BLANKS_BEFORE_WORD);
  assert (test6.has_more_tokens() == true);
  assert (test6.next_token().compare(TEST_WORD) == 0);
  assert (test6.has_more_tokens() == false);

  tkr::tokenizer test7(TEST_BLANK_AFTER_WORD);
  assert (test7.has_more_tokens() == true);
  assert (test7.next_token().compare(TEST_WORD) == 0);
  assert (test7.has_more_tokens() == false);

  tkr::tokenizer test8(TEST_BLANKS_AFTER_WORD);
  assert (test8.has_more_tokens() == true);
  assert (test8.next_token().compare(TEST_WORD) == 0);
  assert (test8.has_more_tokens() == false);

  tkr::tokenizer test9(TEST_BLANK_BEFORE_AFTER_WORD);
  assert (test9.has_more_tokens() == true);
  assert (test9.next_token().compare(TEST_WORD) == 0);
  assert (test9.has_more_tokens() == false);

  tkr::tokenizer test10(TEST_BLANKS_BEFORE_AFTER_WORD);
  assert (test10.has_more_tokens() == true);
  assert (test10.next_token().compare(TEST_WORD) == 0);
  assert (test10.has_more_tokens() == false);

  tkr::tokenizer test11(TEST_TWO_WORDS);
  assert (test11.has_more_tokens() == true);
  assert (test11.next_token().compare(TEST_WORD) == 0);
  assert (test11.has_more_tokens() == true);
  assert (test11.next_token().compare(TEST_WORD) == 0);
  assert (test11.has_more_tokens() == false);

  std::cout << "ok" << std::endl;
  
}


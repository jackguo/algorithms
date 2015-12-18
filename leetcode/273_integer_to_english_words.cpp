#include <iostream>

class Solution {
 public:
  std::string numberToWords(int num);
 private:
  std::string hundredsToWords(int hund);

  static std::string vocabulary1[] = 
  {
    "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten",
    "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nighteen"
  };
  static std::string vocabulary2[] = 
  {
    "twenty", "thirty", "fourty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
  };
  
};

std::string Solution::hundredsToWords(int hund) {
  int two_digit_number = hund % 100;
  std::string two_digit_words;

  if (two_digit_number <= 20) {
    two_digit_words.append(vocabulary1[two_digit_number]);
  }
}


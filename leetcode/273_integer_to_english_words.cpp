#include <iostream>
#include <cstdlib>

class Solution {
 public:
  std::string numberToWords(int num);
 private:
  std::string hundredsToWords(int hund);

  static std::string vocabulary1[20];
  static std::string vocabulary2[8];  
};

std::string Solution::vocabulary1[] = 
  {
    "", "One", "Two", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine", "Ten",
    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
    "Sixteen", "Seventeen", "Eighteen", "Nineteen"
  };

std::string Solution::vocabulary2[] =
  {
    "Twenty", "Thirty", "Forty", "Fifty",
    "Sixty", "Seventy", "Eighty", "Ninety"
  };

std::string Solution::hundredsToWords(int hund) {
  int two_digit_number = hund % 100;
  std::string two_digit_words;

  if (two_digit_number < 20) {
    two_digit_words.append(vocabulary1[two_digit_number]);
  } else {
    int last_digit = two_digit_number % 10;
    int second_digit = two_digit_number / 10;
    if (last_digit == 0) {
      two_digit_words.append(vocabulary2[second_digit - 2]);
    } else {
      two_digit_words.append(vocabulary2[second_digit - 2]).append(" ").append(vocabulary1[last_digit]);
    }
  }
  
  int first_digit = hund / 100;
  if (first_digit == 0) {
    return two_digit_words;
  }

  std::string res = vocabulary1[first_digit];
  res.append(" Hundred");
  if (two_digit_words.length() == 0) {
    return res;
  } else {
    return res.append(" ").append(two_digit_words);
  }
}

std::string Solution::numberToWords(int n) {
  if (n == 0) {
    return "Zero";
  }
  
  int leftn = n;
  int hund;
  int c = 0;
  
  std::string res;
  
  do {
    hund = leftn % 1000;
    std::string partial = hundredsToWords(hund);
    
    if (partial.length() > 0) {
    switch (c) {
      case 0: break;
      case 1: res.length() > 0 ? res.insert(0, " ") : ""; res.insert(0, " Thousand"); break;
      case 2: res.length() > 0 ? res.insert(0, " ") : ""; res.insert(0, " Million"); break;
      case 3: res.length() > 0 ? res.insert(0, " ") : ""; res.insert(0, " Billion"); break;
      default: std::exit(1); // max integer is some billion number
    }
    res.insert(0, partial);
    }

    leftn /= 1000;
    c++;
  } while (leftn > 0);
  
  return res;
}

int main(int argc, char* argv[]) {
  Solution solution;
  std::cout << solution.numberToWords(1000) << std::endl;
  std::cout << solution.numberToWords(123) << std::endl;
  std::cout << solution.numberToWords(123456) << std::endl;
  std::cout << solution.numberToWords(123456789) << std::endl;
  std::cout << solution.numberToWords(1234567890) << std::endl;
}

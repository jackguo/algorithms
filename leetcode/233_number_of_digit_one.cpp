/* Given an integer n, count the total number of digit 1 
   appearing in all non-negative integers less than or equal to n.

   For example:
   Given n = 13,
   Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13. 
*/
#include <iostream>

class Solution {
 public:
  int countDigitOne(int n) {
    int currn, leftn, rightn, c, res;
    leftn = n;
    rightn = 0;
    c = 0;

    res = 0;
    
    do {
      c++;
      rightn = n - leftn * pow10(c - 1);
      currn = leftn % 10;
      leftn /= 10;

      if (currn == 0) {
        res += leftn * pow10(c - 1);
      } else if (currn == 1) {
        res += leftn * pow10(c - 1) + rightn + 1;
      } else {
        res += (leftn + 1) * pow10(c - 1);
      }
    } while (leftn > 0);

    return res;
  }

 private:
  int pow10(int n) {
    if (n < 0) {
      return -1;
    }

    int res = 1;
    while (n > 0) {
      res *= 10;
      n--;
    }
    
    return res;
  }
};

int main(int argc, char* argv[]) {
  Solution solution;

  std::cout << 13 << ":   " << solution.countDigitOne(13) << std::endl;
  std::cout << 100 << ":  " << solution.countDigitOne(100) << std::endl;

  return 0;
}

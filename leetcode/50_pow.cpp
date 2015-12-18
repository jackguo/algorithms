#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        
        if (n < 0) {
          return 1 / myPow(x, -(n + 1)) / x; // -2147483648 !!!!
        }
        
        double res = 1;
        
        res *= myPow(x, n / 2);
        res *= res;
        
        if (n % 2) {
            res *= x;
        }
        
        return res;
    }
};

int main(int argc, char* argv[]) {
  Solution solution;
  std::cout << "pow(1.0, -2147483648):  " << solution.myPow(1.0, -2147483648) << std::endl;
}

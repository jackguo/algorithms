/*
Problem 70: 
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can eithre climb 1 or 2 steps. In how many distinct ways 
can you climb to the top ?

Solution by Junsheng
*/

#include <iostream>
#include <vector>

class Solution {
 public:
  int climbStairs(int n) {
    if(n <= 0) {
      return 0;
    }

    if(n == 1) {
      return 1;
    }
    
    int a[] = { 1, 1 };
    
    for (int i = 2; i <= n; i++) {
      int tmp = a[(i - 1) % 2] + a[(i - 2) % 2];
      a[i % 2] = tmp;
    }
    
    return a[n % 2];
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  int test_set[] = { 0, 1, 2, 5, 10, 11, 12, 13, 14, 15, 36, 70, 100, 500, 1000, 2000 };
  std::vector<int> ts(test_set, test_set + sizeof(test_set) / sizeof(int));
  
  for (std::vector<int>::iterator it = ts.begin(); it != ts.end(); it++) {
    std::cout << "n = " << *it << ": " << solution.climbStairs(*it) << std::endl;
  }
}

    
  
        
  


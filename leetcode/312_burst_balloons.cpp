#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
 public:
  int maxCoins(std::vector<int>& nums) {
    std::vector<int> new_nums(nums.size() + 2, 1);
    int index = 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        new_nums[index++] = nums[i];
      }
    }

    std::vector<int> row(index + 1, 0);
    std::vector<std::vector<int>> mcTable(index + 1, row);
    
    int from, to, curr_max;
    for (int len = 1; len < index; ++len) {
      for (from = 0; from + len < index; ++from) {
        to = from + len + 1;
        curr_max = 0;
        for (int i = from + 1; i < to; ++i) {
          curr_max = std::max(curr_max, new_nums[i] * new_nums[from] * new_nums[to] + mcTable[from][i] + mcTable[i][to]);
        }
        mcTable[from][to] = curr_max;
      }
    }
    
    return mcTable[0][index];
    
  }
};

int main(int argc, char* argv[]) {
  std::vector<int> nums({8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2,2,5});
  Solution solution;
  std::cout << solution.maxCoins(nums) << std::endl;

  return 0;
}

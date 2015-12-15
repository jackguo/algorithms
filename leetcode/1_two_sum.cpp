#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
  
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> mymap;
    for (int i = 0; i < nums.size(); i++) {
      mymap[nums[i]] = i;
    }
    int expected;
    std::unordered_map<int, int>::iterator it;
    std::vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      expected = target - nums[i];
      if ((it = mymap.find(expected)) != mymap.end()) {
        if (i == it->second) continue;
        res.push_back(i + 1);
        res.push_back(it->second + 1);
        return res;
      }
    }
  }
};

int main(int argc, char* argv[]) {
  Solution solution;
  int tmp[] = 
      {
        3, 2, 4
      };
  
  std::vector<int> test(tmp, tmp + 3);
  std::vector<int> res = solution.twoSum(test, 6);
  
  for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
    std::cout << *it << std::endl;
  }
  
}

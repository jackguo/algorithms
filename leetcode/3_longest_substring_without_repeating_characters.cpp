#include <iostream>
#include <unordered_map>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.length() <= 1) {
      return s.length();
    }
    
    std::unordered_map<char, int> mymap;
    int left, right;
    left = right = 0;
    int res = 0;
    for (; right < s.length(); right++) {
      std::unordered_map<char, int>::iterator &&it = mymap.find(s[right]);
      if (it != mymap.end()) {
        if (it->second >= left) {
          res = res < right - left? right - left : res;
          left = it->second + 1;
        }
      }
      
      mymap[s[right]] = right;
    }
    
    res = res < right - left? right - left : res;
    return res;
  }
};


int main(int argc, char* argv[]) {
  Solution solution;
  std::string test_strings[] =
      {
        "abcabcbbd", "abcdefghijk", "babababb", "", "a"
      };
  
  int num = 5;
  for (int i = 0; i < num; i++) {
    std::cout << solution.lengthOfLongestSubstring(test_strings[i]) << std::endl;
  }
}

#include <iostream>
#include <multiset>

class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
      return false;
    }

    std::multiset<char> set_s;
    std::multiset<char> set_t;
    
    for (int i = 0; i < s.length(); i++) {
      set_s.insert(s[i]);
    }

    for (int i = 0; i < t.length(); i++) {
      set_t.insert(t[i]);
    }

    if (set_s == set_t) {
      return true;
    } else {
      return false;
    }
  }
};

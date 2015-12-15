#include <iostream>
#include <unordered_map>

class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) {
      return false;
    }

    std::unordered_map<char, int> map_s;
    std::pair<std::unordered_map<char, int>::iterator, bool> p;
    std::pair<char, int> element;
    
    for (int i = 0; i < s.length(); i++) {
      element.first = s[i];
      element.second = 1;
      p = map_s.insert(element);
      if (! p.second) {
        map_s[s[i]] += 1;
      }
    }

    for (int i = 0; i < t.length(); i++) {
      if (map_s[t[i]] <= 0) return false;
      map_s[t[i]]--;
    }
    
    return true;
  }
};

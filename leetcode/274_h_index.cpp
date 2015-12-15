#include <iostream>
#include <vector>

class Solution {
 public:
  int hIndex(std::vector<int>& citations) {
    if (citations.size() == 0) return 0;
    
    int head = 0;
    int tail = citations.size() - 1;
    int i, tmp;
    
    while (head < tail) {
      i = head - 1;
      
      for (int k = head; k <= tail; k++) {
        if (citations[k] >= citations[tail]) {
          i++;
          tmp = citations[k];
          citations[k] = citations[i];
          citations[i] = tmp;
        } 
      }
      
      if (citations[i] < i + 1) {
        tail = i - 1;
      } else {
        head = i;
      }
    }
    
    if (citations[head] == 0) return 0;
    return head + 1;
  }
};

int main(int argc, char* argv[]) {
  int a1[] = 
      {
        2, 2, 2, 2, 2
      };
  int a2[] = 
      {
        0, 0, 0, 0, 0
      };
  
  std::vector<int> v1(a1, a1 + 5);
  std::vector<int> v2(a2, a2 + 5);
  
  Solution solution;
  
  std::cout << solution.hIndex(v1) << std::endl;
  std::cout << solution.hIndex(v2) << std::endl;
}

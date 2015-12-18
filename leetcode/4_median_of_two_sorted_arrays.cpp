#include <iostream>
#include <vector>

// O (m + n) time complexity
class Solution {
public:
  double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() == 0 && nums2.size() == 0) {
            return 0;
        }
        
        std::vector<int> merged_nums((nums1.size() + nums2.size()) / 2 + 1, 0);
        
        int i = 0, j = 0, k = 0;
        while (k != merged_nums.size()) {
            if (j == nums2.size() || (i != nums1.size() && nums1[i] < nums2[j])) {
                merged_nums[k] = nums1[i];
                ++i;
            } else if (i == nums1.size() || (j != nums2.size() && nums1[i] >= nums2[j])){
                merged_nums[k] = nums2[j];
                ++j;
            }
            ++k;
        }

        if ((nums1.size() + nums2.size()) % 2) {
            return merged_nums[k - 1];
        } else {
            return (merged_nums[k - 1] + merged_nums[k - 2]) / 2.0;
        }

    }
};

int main(int argc, char* argv[]) {
  Solution solution;
  std::vector<int> v1;
  std::vector<int> v2(1, 1);
  std::cout << solution.findMedianSortedArrays(v1, v2);
  
  return 0;
  
}

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string getPermutation(int n, int k) {
        if (k <= 0) return "";
        
        std::vector<int> nums(n, 0);
        int max_k = 1;
        for (int i = 1; i != n + 1; ++i) {
            nums[i - 1] = i;
            max_k *= i;
        }
        
        if (k > max_k) return "";
        
        while (k != 1) {
            nextPermutation(nums);
            --k;
        }
        
        std::string res;
        for (int i = 0; i != n; ++i) {
            res.append(std::to_string(nums[i]));
        }
        
        return res;
    }
    
private:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return;
        
        int i = nums.size() - 1;
        int swap;
        
        while (i != 0 && nums[i - 1] >= nums[i]) {
            --i;
        }
        
        int anchor = i - 1;
        
        if (i != 0) {
            while (i != nums.size() && nums[i] > nums[anchor]) {
                ++i;
            }
            
            swap = nums[i - 1];
            nums[i - 1] = nums[anchor];
            nums[anchor] = swap;
        }
        
        for (int k = anchor + 1, j = nums.size() - 1; k < j; ++k, --j) {
            swap = nums[k];
            nums[k] = nums[j];
            nums[j] = swap;
        }
    }
};

int main(int argc, char *argv[]) {
  Solution solution;
  std::cout << solution.getPermutation(8, 8590) << std::endl;
  return 0;
}

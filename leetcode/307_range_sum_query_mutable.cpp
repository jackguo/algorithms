#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        size = nums.size();
        int start_index = 0;
        root = buildST(nums, start_index, size);
    }

    void update(int i, int val) {
        if (i < 0 || i >= size) return;
        
        stack<SegTreeNode*> nptrStack;
        SegTreeNode* nptr = root;
        int curr_size = size, tmp;
        while (nptr->left != NULL || nptr->right != NULL) {
            nptrStack.push(nptr);
            tmp = curr_size / 2 + curr_size % 2;
            if (i < tmp) {
                nptr = nptr->left;
                curr_size = tmp;
            } else {
                nptr = nptr->right;
                curr_size = curr_size / 2;
                i -= tmp;
            }
        }
        
        tmp = val - nptr->val;
        nptr->val = val;
        while (! nptrStack.empty()) {
            nptr = nptrStack.top();
            nptrStack.pop();
            nptr->val += tmp;
        }
    }

    int sumRange(int i, int j) {
        if (root == NULL) return INT_MIN;
        
        i = max(0, i);
        j = min(j, size - 1);
        if (i > j) return INT_MIN;
        
        int res;
        if (i == 0) {
            res = getSumTo(j);
        } else {
            res = getSumTo(j) - getSumTo(i - 1);
        }
        return res;
    }

private:
    struct SegTreeNode {
        int val;
        SegTreeNode * left;
        SegTreeNode *right;
        SegTreeNode(int value) : val(value), left(NULL), right(NULL){};
    };
    
    SegTreeNode* buildST(vector<int>& nums, int &first, int count) {
        if (count < 1) {
            return NULL;
        }
        
        SegTreeNode *left = NULL, *right = NULL, *res = NULL;
        if (count == 1) {
            res = new SegTreeNode(nums[first++]);
        } else if (count == 2) {
            left = new SegTreeNode(nums[first++]);
            right = new SegTreeNode(nums[first++]);
            res = new SegTreeNode(left->val + right->val);
            res->left = left;
            res->right = right;
        } else {
            int countLeft = count / 2 + count % 2;
            int countRight = count / 2;
            left = buildST(nums, first, countLeft);
            right = buildST(nums, first, countRight);
            res = new SegTreeNode(left->val + right->val);
            res->left = left;
            res->right = right;
        }
        
        return res;
    }
    
    int getSumTo(int index) {
        int res = root->val;
        int curr_size = size, tmp;
        
        SegTreeNode* nptr = root;
        while (nptr->left != NULL || nptr->right != NULL) {
            tmp = curr_size / 2 + curr_size % 2;
            if (index < tmp) {
                res -= nptr->right->val;
                nptr = nptr->left;
                curr_size = tmp;
            } else {
                nptr = nptr->right;
                index -= tmp;
                curr_size = curr_size / 2;
            }
        }
        
        return res;
    }
    
    SegTreeNode* root;
    int size;
};

int main(int argc, char* argv[]) {
  vector<int> nums(
      {
        5, 18, 13 
            });
  
  NumArray solution(nums);
  
  cout << solution.sumRange(0, 2) << endl;
  solution.update(1, -1);
  //  solution.update(2, 3);
  
  
  cout << solution.sumRange(0, 2) << endl;
  
}

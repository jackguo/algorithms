#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        TreeNode *ptr = root;
        std::stack<TreeNode*> tnodes;
        
        while (ptr) {
            tnodes.push(ptr);
            ptr = ptr->left;
        }
        
        while (!tnodes.empty()) {
            ptr = tnodes.top();
            if (ptr->right) {
                ptr = ptr->right;
                while (ptr) {
                    tnodes.push(ptr);
                    ptr = ptr->left;
                }
            } else {
                res.push_back(ptr->val);
                tnodes.pop();
            }
        }
        
        return res;
    }
};

int main(int argc, char* argv[]) {
  TreeNode root(1), left(2), right(3);
  root.left = & left;
  root.right = &right;
  Solution solution;
  solution.postorderTraversal(&root);
}

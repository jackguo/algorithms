#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    int carry = 0;
    ListNode *res;
    ListNode **current_bit = &res;
    ListNode *current_l1 = l1;
    ListNode *current_l2 = l2;
    
    while (current_l1 != NULL || current_l2 != NULL) {
      int sum = carry;
      if (current_l1 != NULL) sum += current_l1->val;
      if (current_l2 != NULL) sum += current_l2->val;
      
      *current_bit = new ListNode(0);
      (*current_bit)->val = sum % 10;
      carry = sum / 10;
      current_l1 = current_l1 ? current_l1->next : NULL ;
      current_l2 = current_l2 ? current_l2->next : NULL ;
      current_bit = &((*current_bit)->next);
    }

    return res;
  }
};


int main(int argc, char* argv[]) {
  Solution solution;
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(8);
  ListNode *l2 = new ListNode(0);
  
  ListNode *res = solution.addTwoNumbers(l1, l2);
}

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode *nptr1, *nptr2, *tmp, *previous;
        nptr1 = head;
        nptr2 = nptr1->next;
        ListNode * header = new ListNode(0);
        header->next = head;
        previous = header;
        
        while (nptr1 != NULL && nptr2 != NULL) {
          previous->next = nptr2;
            tmp = nptr2->next;
            nptr2->next = nptr1;
            nptr1->next = tmp;
            previous = nptr1;
            
            if (nptr1 = tmp) {
                nptr2 = nptr1->next;
            }
        }
        
        return header->next;
    }
};

int main(int argc, char* argv[]) {
  Solution solution;
  ListNode n4(4, NULL);
  ListNode n3(3, &n4);
  ListNode n2(2, &n3);
  ListNode n1(1, &n2);
  
  ListNode * res = solution.swapPairs(&n1);
  return 0;
}

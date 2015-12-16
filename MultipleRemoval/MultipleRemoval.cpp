#include <iostream>
#include <vector>
#include "test.h"

class Solution {
 public:
  Node* multipleRemove(Node* head, std::vector<RemovalRequest>& rrs) {
    if (head == NULL) return head;

    Node dummyNode(0);
    dummyNode.next = head;
    Node *prev = &dummyNode, *nptr = head;

    int currentIndex = 0;
    int count;
    bool isRemoved = false;
    while (nptr != NULL) {
      for (int i = 0; i < rrs.size(); ++i) {
        if (currentIndex >= rrs[i].pos && currentIndex < rrs[i].pos + rrs[i].num) {
          count = rrs[i].pos + rrs[i].num - currentIndex;
          while (count > 0 && nptr != NULL) {
            prev->next = nptr->next;
            nptr = nptr->next;
            ++currentIndex;
            --count;
          }
          isRemoved = true;
        }
      }

      if (nptr == NULL) break;
      if (!isRemoved) {
        prev = nptr;
        nptr = nptr->next;
        ++currentIndex;
      }
      else {
        isRemoved = false;
      }
    }

    return dummyNode.next;
  }
};

void printList(Node *head) {
  while (head != NULL) {
    std::cout << head->val << " ";
    head = head->next;
  }
  std::cout << std::endl;
}

int main(int argc, char* argv) {
  /*
  Node node0(0), node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7);
  node0.next = &node1;
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;
  node5.next = &node6;
  node6.next = &node7;
	
  RemovalRequest rrq1(2, 3), rrq2(4, 2);
  std::vector<RemovalRequest> rrs(2, rrq1);
  //	rrs[0] = rrq1;
  rrs[0] = rrq2;

  Solution solution;
  printList(&node0);
  Node *nptr = solution.multipleRemove(&node0, rrs);
  printList(nptr);
  */
  Solution solution;
  
  TestCase tc1(7, 2, 2, 2, 1, false),
      tc2(10, 3, 2, 3, 1, true),
      tc3(10, 2, 0, 5, 0, false),
      tc4(10, 3, 2, 2, 0, false);
  TestCase * tcs[] = 
      {
        &tc1, &tc2, &tc3, &tc4
      };

  for (int i = 0; i < 4; ++i) {
    printList(tcs[i]->head);
    printList(solution.multipleRemove(tcs[i]->head, tcs[i]->rrqs));
    std::cout << std::endl;
  }
  
  return 0;
}

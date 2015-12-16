#include "node.h"
#include <vector>

class TestCase {
public:
  Node* head;
  std::vector<RemovalRequest> rrqs;
  TestCase(int length, int num_req, int start_pos,
           int num_per_req, int step, bool overlap) : head(NULL), rrqs(num_req) {
    this->nodes = new Node[length];
    
    for (int i = 0; i < length; ++i) {
      nodes[i].val = i;
      if (i != length - 1) {
        nodes[i].next = &(nodes[i + 1]);
      }
    }
    head = &(nodes[0]);

    if (overlap) {
      step = -step;
    }

    for (int i = 0; i < num_req; ++i) {
      rrqs[i].pos = start_pos;
      rrqs[i].num = num_per_req;
      start_pos += (num_per_req + step);
    }
  }

  ~TestCase() {
    delete[] nodes;
  }

private:
  Node *nodes;
};

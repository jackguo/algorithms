/* class definiation */

class Node {
 public:
  int val;
  Node* next;
  Node(int v = 0) : val(v), next(NULL) {}
};

class RemovalRequest {
 public:
  int pos;
  int num;
  RemovalRequest(int p = 0, int n = 0) : pos(p), num(n) {}
};

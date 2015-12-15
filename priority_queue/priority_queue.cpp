#include <iostream>
#include <vector>
#include <string>

template <typename T>
class MaxPriorityQueue {
 public:
  MaxPriorityQueue();
  MaxPriorityQueue(int capacity);
  MaxPriorityQueue(const std::vector<T> &hp);
  void insert(T& element);
  T& max();
  T removeMax();
  bool isEmpty();
  int size();
  
 private:
  inline void exch(int i, int j);
  inline bool less(int i, int j);
  void sink(int k);
  void swim(int k);
  std::vector<T> *hp_ptr;
  int curr_size = 0;
};

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue() {
  this->hp_ptr = new std::vector<T>(1);
}

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(int capacity) {
  this->hp_ptr = new std::vector<T>(capacity + 1);
  curr_size = capacity;
}

template <typename T>
MaxPriorityQueue<T>::MaxPriorityQueue(const std::vector<T> &hp) {
  this->hp_ptr = new std::vector<T>(hp.size() + 1);
  curr_size = hp_ptr->size() - 1;
  for (int i = 0; i < hp.size(); ++i) {
    hp_ptr->at(i + 1) = hp[i];
  }
  
  for (int i = curr_size / 2; i > 0; --i) {
    sink(i);
  }
}

template <typename T>
inline void MaxPriorityQueue<T>::exch(int i, int j) {
  T swap;
  swap = (*hp_ptr)[i];
  (*hp_ptr)[i] = (*hp_ptr)[j];
  (*hp_ptr)[j] = swap;
}

template <typename T>
inline bool MaxPriorityQueue<T>::less(int i, int j) {
  return (*hp_ptr)[i] < (*hp_ptr)[j];
}

template <typename T>
void MaxPriorityQueue<T>::sink(int k) {
  int nxt;
  while (2 * k <= curr_size) {
    nxt = 2 * k;
    if (nxt + 1 <= curr_size && less(nxt, nxt + 1)) {
      ++nxt;
    }
    if (less(nxt, k)) {
      break;
    }
    exch(k, nxt);
    k = nxt;
  }
}

template <typename T>
void MaxPriorityQueue<T>::swim(int k) {
  int nxt;
  while (k / 2 > 0) {
    nxt = k / 2;
    if (less(k, nxt)) {
      break;
    }
    exch(k, nxt);
    k = nxt;
  }
}

template <typename T>
void MaxPriorityQueue<T>::insert(T& element) {
  ++curr_size;
  if (curr_size < hp_ptr->size()) {
    hp_ptr->at(curr_size) = element;
  } else {
    hp_ptr->push_back(element);
  }
  
  swim(curr_size);
}

template <typename T>
T& MaxPriorityQueue<T>::max() {
  return hp_ptr->at(1);
}

template <typename T>
T MaxPriorityQueue<T>::removeMax() {
  T res = hp_ptr->at(1);
  hp_ptr->at(1) = hp_ptr->at(curr_size--);
  sink(1);
  return res;
}

template <typename T>
bool MaxPriorityQueue<T>::isEmpty() {
  return (curr_size == 0);
}

template <typename T>
int MaxPriorityQueue<T>::size() {
  return curr_size;
}

int main(int argc, char* argv[]) {
  MaxPriorityQueue<char> maxPQ;
  std::string input("P R I O * R * * I * T * Y * * * Q U E * * * U * E");
  std::string res;
  
  for (int i = 0; i < input.size(); ++i) {
    switch (input[i]) {
      case ' ' : continue;
      case '*' : res.append(1, maxPQ.removeMax()); break;
      default  : maxPQ.insert(input[i]);
    }
  }

  std::cout << res << std::endl;
  
  return 0;
}

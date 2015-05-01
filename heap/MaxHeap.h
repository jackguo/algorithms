//max heap implementation
// index relation: 
// node with index i:
//   left child => 2*i + 1
//   right child => 2*i + 2
//   parent => floor((i - 1)/2)

#ifndef _MAX_HEAP
#define _MAX_HEAP
#include <iostream>

template<class T>
class MaxHeap {
private:
  int capacity;
  int size;
  T* heap;
  void maintain_heap(int root);
  void initialize();
  
public:
  MaxHeap(int cap);
  MaxHeap(int cap, const T* elements, int num);
  ~MaxHeap() {
    delete [] heap;
  }
  MaxHeap<T>& insert(const T& element);
  MaxHeap<T>& multi_insert(const T* elements, int num);
  T delete_max();
  T delete_by_index(int index);
  void delete_by_value(const T& value);
  MaxHeap<T>& increase(int index, const T& increment);
  MaxHeap<T>& decrease(int index, const T& decrement);
  int get_size();
  void print_heap();
};
template<class T>
MaxHeap<T>::MaxHeap(int cap) : capacity{cap} {
  size = 0;
  heap = new T[this->capacity];
}

template<class T>
MaxHeap<T>::MaxHeap(int cap, const T* elements, int num) {
  if (num > cap) {
    std::cerr << "invalid arguments : num(" << num << ") is larger than heap capacity!" << std::endl;
    return;
  }
  size = num;
  capacity = cap;
  
  heap = new T[capacity];
  for (int i = 0; i < size; i++) {
    heap[i] = elements[i];
  }
  
  this->initialize();
}   

template<class T>
void MaxHeap<T>::maintain_heap(int root) {
  if (root < 0 || root >= size) {
    return ;
  }
  
  int current_pos = root;
  int left_p = current_pos * 2 + 1;
  int right_p = current_pos * 2 + 2;
  int max_p = current_pos;
  T tmp;
  
  while (left_p < size) {
    if (heap[max_p] < heap[left_p]) {
      max_p = left_p;
    }
    if (right_p < size && heap[max_p] < heap[right_p]) {
      max_p = right_p;
    }
    
    if (max_p == current_pos) {
      break;
    }
    
    tmp = heap[max_p];
    heap[max_p] = heap[current_pos];
    heap[current_pos] = tmp;
    current_pos = max_p;
    left_p = current_pos * 2 + 1;
    right_p = current_pos * 2 + 2;
  }
}

template<class T>
void MaxHeap<T>::initialize() {
  for (int i = size - 1; i >= 0; i--) {
    this->maintain_heap(i);
  }
}

template<class T>
MaxHeap<T>& MaxHeap<T>::insert(const T& element) {
  if (size == capacity) {
    std::cerr << "the heap is full!" << std::endl;
    return *this;
  }

  int current_pos = size;
  int parent_pos = (current_pos - 1) / 2;

  heap[size++] = element;
  T tmp;
  
  while (current_pos > 0 && heap[parent_pos] < heap[current_pos]) {
    tmp = heap[current_pos];
    heap[current_pos] = heap[parent_pos];
    heap[parent_pos] = tmp;
    
    current_pos = parent_pos;
    parent_pos = (current_pos - 1) / 2;
  }

  return *this;
}

template<class T>
T MaxHeap<T>::delete_max() {
  if (size == 0) {
    std::cerr << "the heap is empty! nothing to delete" << std::endl;
    T nonsense_value;  
    return nonsense_value;
  }
  
  T ret = heap[0];
  heap[0] = heap[--size];
  this->maintain_heap(0);
  
  return ret;
}

template<class T>
T MaxHeap<T>::delete_by_index(int index) {
  if (index < 0 || index >= size) {
    std::cerr << "index is out of range!" << std::endl;
    T nonsense_value;
    return nonsense_value;
  }
  
  T ret = heap[index];
  heap[index] = heap[--size];
  this->maintain_heap(index);
  
  return ret;
}

template<class T>
void MaxHeap<T>::delete_by_value(const T& value) {
  for (int i = 0; i < size; i++) {
    if (heap[i] == value) {
      this->delete_by_index(i);
      i--;
    }
  }
}

template<class T>
MaxHeap<T>& MaxHeap<T>::decrease(int index, const T& decrement) {
  if (index < 0 || index >=size) {
    return *this;
  }
  
  heap[index] -= decrement;
  this->maintain_heap(index);

  return *this;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::increase(int index, const T& increment) {
  if (index < 0 || index >= size) {
    return *this;
  }
  T tmp;
  int curr_p = index;
  int parent_p = (curr_p - 1) / 2;

  heap[curr_p] += increment;
  
  while (curr_p > 0 && heap[parent_p] < heap[curr_p]) {
    tmp = heap[parent_p];
    heap[parent_p] = heap[curr_p];
    heap[curr_p] = tmp;

    curr_p = parent_p;
    parent_p = (curr_p - 1) /2;
  }
  
  return *this;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::multi_insert(const T* elements, int num) {
  if (num + size > capacity) {
    num = capacity - size;
  }
  
  for (int i = 0; i < num; i++) {
    heap[size++] = elements[i];
  }
  
  this->initialize();
  return *this;
}

template<class T>
int MaxHeap<T>::get_size() {
  return this->size;
}

template<class T>
void MaxHeap<T>::print_heap() {
  if (this->size == 0) {
    std::cout << "Empty heap!\n";
  }
  
  int num_this_row = 1;
  int curr_p = 0;
  
  while (curr_p < this->size) {
    for (int i = 0; i < num_this_row; i++) {
      std::cout << heap[curr_p++] << "   ";
    }
    std::cout << std::endl;
    
    num_this_row *= 2;
    if (num_this_row > this->size - curr_p) {
      num_this_row = this->size - curr_p;
    }
    
  }
}

#endif

  

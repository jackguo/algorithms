#include <iostream>
#include "MaxHeap.h"

template<class T>
MaxHeap<T>::MaxHeap(int cap) : capacity{cap} {
  size = 0;
  heap = new T[this->capacity];
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
    }
  }
}

template<class T>
MaxHeap<T>& MaxHeap<T>::decrease(int index, const T& decrement) {}

template<class T>
MaxHeap<T>& MaxHeap<T>::increase(int index, const T& increment) {
  if (index < 0 || index >= size) {
    return *this;
  }
  
}

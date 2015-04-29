//max heap implementation
// index relation: 
// node with index i:
//   left child => 2*i + 1
//   right child => 2*i + 2
//   parent => floor((i - 1)/2)

#ifndef _MAX_HEAP
#define _MAX_HEAP

template<class T>
class MaxHeap {
private:
  int capacity;
  int size;
  T* heap;
  void maintain_heap(int root);
  
public:
  MaxHeap(int cap);
  ~MaxHeap() {
    delete [] heap;
  }
  MaxHeap<T>& insert(const T& element);
  T delete_max();
  T delete_by_index(int index);
  void delete_by_value(const T& value);
  MaxHeap<T>& increase(int index, const T& increment);
  MaxHeap<T>& decrease(int index, const T& decrement);
  int get_size();
  
};

#endif

  

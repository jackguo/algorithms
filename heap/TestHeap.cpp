#include "MaxHeap.h"

int main(int argc, char* argv[]) {
  MaxHeap<int> mp(30);
  int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  mp.multi_insert(data, 10).print_heap();

  mp.insert(333);
  mp.insert(2);
  mp.insert(0);
 
  mp.print_heap();
  

  mp.delete_max();
  mp.print_heap();
  mp.delete_by_value(6);
  mp.print_heap();

  for (int i = 0; i < 11; i++) {
    mp.delete_max();
  }
  
  mp.print_heap();
}

  

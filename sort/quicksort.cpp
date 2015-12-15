#include <iostream>
#include <vector>

class QuickSort {
 public:
  void sort(std::vector<int> &nums);
 private:
  void quicksort(std::vector<int> &nums, int start, int end);
};

void QuickSort::sort(std::vector<int> &nums) {
  quicksort(nums, 0, nums.size() - 1);
}

void QuickSort::quicksort(std::vector<int> &nums, int start, int end) {
  if (start >= end) {
        return;
    }
    
    if (start == end - 1) {
        if (nums[start] > nums[end]) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
        }
        return ;
    }
    
    int partition = start - 1;
    int swap;
    for (int i = start; i <= end; i++) {
        if (nums[i] <= nums[end]) {
            partition++;
            swap = nums[i];
            nums[i] = nums[partition];
            nums[partition] = swap;
        }
            
    }
    
    quicksort(nums, start, partition - 1);
    quicksort(nums, partition + 1, end);
}

int main(int argc, char* argv[]) {
  int v1[] = 
      {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
      };
  
  int v2[] = 
      {
        4, 2, 11, 33, 21, 55, 1, 3, 9
      };
  
  int v4[] = 
      {
        20, 20, 20, 20, 20
      };

  int v5[] = 
      {
        20, 19, 18, 16, 15, 12, 11, 5, 3, 4
      };
  
  std::vector<int> * test_v[5];
  test_v[0] = new std::vector<int>(v1, v1 + 10);
  test_v[1] = new std::vector<int>(v2, v2 + 9);
  test_v[2] = new std::vector<int>();
  test_v[3] = new std::vector<int>(v4, v4 + 5);
  test_v[4] = new std::vector<int>(v5, v5 + 10);

  QuickSort qs;
  for (int i = 0; i < 5; i++) {
    qs.sort(*test_v[i]);
    for (int j = 0; j < test_v[i]->size(); j++) {
      std::cout << test_v[i]->at(j) << "  ";
    }
    std::cout << std::endl;
  }
}

package PriorityQueueExample;

import java.util.Comparator;
import java.util.PriorityQueue;

public class PriorityQueueSort {
  public int[] sort(int[] nums) {
    Comp comp = new Comp();
    if (nums == null || nums.length == 0) {
      return nums;
    }
    
    PriorityQueue<Integer> pq = new PriorityQueue<Integer>(nums.length, comp);
    
    for (int num : nums) {
      pq.offer(num);
    }
    
    int i = 0;
    while (! pq.isEmpty()) {
      nums[i] = pq.poll().intValue();
      ++i;
    }
    
    return nums;
  }
  
  static class Comp implements Comparator<Integer> {
    public int compare(Integer first, Integer second) {
      return second.intValue() - first.intValue();
    }
  }
}
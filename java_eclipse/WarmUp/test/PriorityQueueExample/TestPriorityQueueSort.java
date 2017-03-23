package PriorityQueueExample;

import junit.framework.TestCase;
import java.util.Arrays;

public class TestPriorityQueueSort extends TestCase {
  public void testSort() throws Exception {
    int[] nums1 = {100, 50, 60, 77, 89, 98, 1, 4, 7};
    int[] nums2 = null;
    int[] nums3 = {};
    
    int[] expected1 = {1, 4, 7, 50, 60, 77, 89, 98, 100};
    int[] expected2 = null;
    int[] expected3 = {};
    
    PriorityQueueSort pqs = new PriorityQueueSort();
    assertTrue(Arrays.equals(expected1, pqs.sort(nums1)));
    assertTrue(Arrays.equals(expected2, pqs.sort(nums2)));
    assertTrue(Arrays.equals(expected3, pqs.sort(nums3)));
  }
}
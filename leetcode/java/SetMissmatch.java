
import java.util.Arrays;

/**
 * leetcode problem 645: Set Mismatch
 */

public class SetMissmatch {
  private int[] solution(int[] nums) {
    int[] counters = new int[nums.length + 1];
    int sum = 0, duplicate = 0;

    for (int i = 0; i < nums.length; ++i) {
      sum += nums[i];
      if (++counters[nums[i]] == 2) {
        duplicate = nums[i];
      }
    }

    int[] res = new int[2];
    res[0] = duplicate;
    res[1] = (1 + nums.length) * nums.length / 2 - sum + duplicate;

    return res;
  }

  public static void main(String[] args) {
    int[] case1 = { 1, 2, 2, 4 };
    int[] res1 = { 2, 3 };
    int[] case2 = { 2, 3, 6, 8, 5, 5, 1, 9, 10, 4, 11, 12, 15, 13, 14};
    int[] res2 = { 5, 7 };
    int[] case3 = { 2, 2};
    int[] res3 = { 2, 1 };

    SetMissmatch setMissmatch = new SetMissmatch();
    
    assert Arrays.equals(res1, setMissmatch.solution(case1));
    assert Arrays.equals(res2, setMissmatch.solution(case2));
    assert Arrays.equals(res3, setMissmatch.solution(case3));
    System.out.println("All 3 tests passed!");
    
  }

}

    

    
      
      
    
    
    
    
      

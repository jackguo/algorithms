/**
 * Given an array of n integers where n > 1, nums, 
 * return an array output such that output[i] is 
 * equal to the product of all the elements of nums except nums[i].
 */

public class ProductOfArrayExceptSelf {
  public int[] getResult(int[] nums) {
    int[] result = new int[nums.length];
    int i, prod;

    for (i = 1, result[0] = 1; i < nums.length; ++i) {
      result[i] = result[i - 1] * nums[i - 1];
    }

    for (i = nums.length - 2, prod = nums[nums.length - 1]; i >=0; --i) {
      result[i] *= prod;
      prod *= nums[i];
    }

    return result;
  }

  public static void main(String[] rags) {
    int[][] input = new int[5][];
    int[][] output = new int[5][];
    
    input[0] = new int[]{1, 0};
    input[1] = new int[]{1, 2, 3, 4, 5};
    input[2] = new int[]{11, 2, 0, 3};
    input[3] = new int[]{999, 88, 1234, 897};
    input[4] = new int[]{1000, 25, 900};

    output[0] = new int[]{0, 1};
    output[1] = new int[]{120, 60, 40, 30, 24};
    output[2] = new int[]{0, 0, 66, 0};
    output[3] = new int[]{97407024, 1105791102, 78857064, 108483408};
    output[4] = new int[]{22500, 900000, 25000};

    ProductOfArrayExceptSelf solution = new ProductOfArrayExceptSelf();
    
    for (int i = 0; i < input.length; ++i) {
      int[] result = solution.getResult(input[i]);

      for (int j = 0; j < output[i].length; ++j) {          
        assert result[j] == output[i][j] : "expected: " + output[i][j] + ", found: " + result[j];;
      }
    }

    System.out.println("All testcases passed!");
    
  }
}


package epi;

import junit.framework.TestCase;

public class ScoreCombinationTest extends TestCase {
  public void testNumScoreComb() throws Exception {
    ScoreCombination sc = new ScoreCombination();
    
    int s = 12;
    int[] w = {2, 3, 7};
    assertEquals(4, sc.numScoreComb(s, w));
    
    int s1 = 0;
    int[] w1 = {2, 3, 5};
    assertEquals(1, sc.numScoreComb(s1, w1));
  }
}
package oa;

import junit.framework.TestCase;

public class TestDuplicateDigit extends TestCase {
  
  public void testMaxNum() throws Exception {
    DuplicateDigit dd = new DuplicateDigit();
    
    assertEquals(1234566, dd.maxNum(123456));
    assertEquals(554321, dd.maxNum(54321));
    assertEquals(1234550123, dd.maxNum(123450123));
    assertEquals(-1123456, dd.maxNum(-123456));
    assertEquals(Integer.MAX_VALUE, dd.maxNum(1147483647));
    assertEquals(Integer.MIN_VALUE, dd.maxNum(-1147483600));
  }
  
  public void testOverflow() throws Exception {
    
    String numStr = "2147483647";
    
    assertEquals(Integer.MAX_VALUE, Integer.parseInt(numStr));
    String zeroStr = "000";
    
    assertEquals(0, Integer.parseInt(zeroStr));
  }
}
package oa;

import junit.framework.TestCase;

public class TestPicLength extends TestCase {
  public void testPicLen() throws Exception {
    String fs = "dir\n ddir\n  a.txt\n  b.jpeg\n  c.gif\n ddir2\n dddir\n ddddir\n  a.exe";
    
    LongestPathPic lpp = new LongestPathPic();
    assertEquals(16, lpp.longestPath(fs));
  }
}
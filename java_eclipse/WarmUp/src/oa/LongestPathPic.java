package oa;

import java.util.Deque;
import java.util.ArrayDeque;

public class LongestPathPic {
  public int longestPath(String fs) {
     if (fs == null || fs.length() == 0) {
       return 0;
     }
     
     Deque<Integer> dirStack = new ArrayDeque<Integer>();
     
     int accuLength = 0, indent = -1, imgLength = 0, currLen = 0;
     
     String[] dirs = fs.split("\n");
     
     for (String dir : dirs) {
       int ind = dir.lastIndexOf((int) ' ');
       String currName = dir.trim();
       
       int len = 0;
       if (ind == indent) {
         len = currLen;
       } else if (ind > indent) {
         dirStack.push(currLen);
         indent = ind;
       } else {
         while (indent > ind) {
           accuLength -= dirStack.pop().intValue();
           --indent;
         }
         len = currLen;
       }
       
       currLen = currName.length() + 1;
       accuLength = accuLength - len + currLen;
       if (currName.matches("[^\\.]+\\.(jpeg|png|gif)") && accuLength > imgLength) {
         imgLength = accuLength;
       }
     }
     
     return imgLength;
  }
}
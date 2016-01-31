package oa;

public class DuplicateDigit {
  public int maxNum(int num) {
    String numStr = String.valueOf(num);
    StringBuilder sb = new StringBuilder();
    int dupPos = 0, res;
    
    if (num < 0) {
      numStr = numStr.substring(1);
      for (;dupPos < numStr.length() - 1; ++dupPos) {
        if (numStr.charAt(dupPos) < numStr.charAt(dupPos + 1)) {
          break;
        }
      }
      sb.append('-');
    } else {
      for (;dupPos < numStr.length() - 1; ++dupPos) {
        if (numStr.charAt(dupPos) > numStr.charAt(dupPos + 1)) {
          break;
        }
      }
    }
    
    sb.append(numStr.substring(0, dupPos)).append(numStr.charAt(dupPos)).append(numStr.substring(dupPos));
    
    try {
      res = Integer.parseInt(sb.toString());
    } catch (NumberFormatException e) {
      res = num > 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
    }
    
    return res;
  }
}
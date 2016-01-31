package HashMapExample;

public class CompositeKey {
  public int numKey;
  public String strKey;

  public CompositeKey(int num, String str) {
    numKey = num;
    strKey = str;
  }
  
  @Override
  public int hashCode() {
    String hcStr = strKey + "#" + String.valueOf(numKey);
    return hcStr.hashCode();
  }
  
  @Override
  public boolean equals(Object obj) {
    if (obj != null && obj instanceof CompositeKey 
        && numKey == ((CompositeKey) obj).numKey
        && strKey.equals(((CompositeKey) obj).strKey)) {
          return true;
    } else {
      return false;
    }
    
  }
}
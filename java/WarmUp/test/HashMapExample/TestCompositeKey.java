package HashMapExample;

import junit.framework.TestCase;
import java.util.HashMap;

public class TestCompositeKey extends TestCase {
  public void testCompKey() throws Exception {
    HashMap<CompositeKey, Integer> hmKeyOnTheFly = new HashMap<CompositeKey, Integer>();
    HashMap<CompositeKey, Integer> hmAllocatedKey = new HashMap<CompositeKey, Integer>();
    
    CompositeKey[] keys = new CompositeKey[5];
    String tmpStr = "abcdef";
    for (int i = 0; i < 5; ++i) {
      keys[i] = new CompositeKey(i, tmpStr.substring(0, i + 1));
    }
    
    CompositeKey ck;
    for (int i = 0; i < 5; ++i) {
      ck = new CompositeKey(i, tmpStr.substring(0, i + 1));
      hmKeyOnTheFly.put(ck, i);
      hmAllocatedKey.put(keys[i], i);
    }
    
    assertEquals(true, hmKeyOnTheFly.containsKey(keys[1]));
    assertEquals(5, hmKeyOnTheFly.size());
    assertEquals(true, hmAllocatedKey.containsKey(keys[1]));
    assertEquals(2, hmKeyOnTheFly.get(keys[2]).intValue());
    assertTrue(keys[2].strKey.equals("abc"));
  }
}
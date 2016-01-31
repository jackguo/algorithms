package ListExample;

import junit.framework.TestCase;
import java.util.List;

public class TestAddReference extends TestCase {
  public void testAddReference() throws Exception {
    ListAddReference lar = new ListAddReference();
    ListElement le = new ListElement(10);
    List<ListElement> l = lar.addReference(le);
    ListElement leIt = l.listIterator().next();
    assertEquals(10, leIt.val);
    
    le.val = 100;
    assertEquals(100, leIt.val);
  }
}
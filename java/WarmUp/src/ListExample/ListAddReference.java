package ListExample;

import java.util.List;
import java.util.ArrayList;

public class ListAddReference {
  public List<ListElement> addReference(ListElement le) {
    List<ListElement> res = new ArrayList<ListElement>();
    if (le != null) {
      res.add(le);
    }
    
    return res;
  }
}
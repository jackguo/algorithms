package ListExample;

public class ListElement {
  public int val;
  public ListElement() {
    val = 0;
  }
  
  public ListElement(int v) {
    this.val = v;
  }
  
  @Override
  public boolean equals(Object o) {
    if (o != null && o instanceof ListElement 
        && ((ListElement) o).val == this.val) {
      return true;
    } else {
      return false;
    }
  }
}
package MultipleRemoval;

public class RemovalRequest {
	public int pos;
	public int num;
	
	public RemovalRequest(int p, int n) {
		pos = p;
		num = n;
	}
	
	public RemovalRequest() {
		pos = 0;
		num = 1;
	}
}
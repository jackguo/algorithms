package MultipleRemoval;

public class RemoveNodes {

	public Node Remove(Node firstNode, RemovalRequest[] removalRequests) {
		if (firstNode == null) {
			return firstNode;
		}
		
		int currIndex = 0;
		Node dummyNode = new Node(0);
		dummyNode.next = firstNode;
		Node prev = dummyNode;
		Node curr = firstNode;

		for (int i = 0; curr != null && i < removalRequests.length; ++i) {
			int start = removalRequests[i].pos;
			int end = start + removalRequests[i].num;
			while (curr != null && currIndex < start) {
				prev = prev.next;
				curr = curr.next;
				++currIndex;
			}
			
			while (curr != null && currIndex < end) {
				prev.next = curr.next;
				curr = curr.next;
				++currIndex;
			}
		}
		
		return dummyNode.next;
	}
}
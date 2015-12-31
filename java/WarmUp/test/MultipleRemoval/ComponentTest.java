package MultipleRemoval;

import junit.framework.TestCase;

public class ComponentTest extends TestCase {
	public void testNode() throws Exception {
		Node node = new Node(10);
		assertEquals(10, node.val);
		assertEquals(null, node.next);
		node.next = node;
		assertEquals(node, node.next);
	}
	
	public void testRemovalRequest() throws Exception {
		RemovalRequest rr = new RemovalRequest(10, 100);
		assertEquals(10, rr.pos);
		assertEquals(100, rr.num);
	}
	
	public void testRemove() throws Exception {
		Node n1 = new Node(1);
		Node n2 = new Node(2);
		Node n3 = new Node(3);
		Node n4 = new Node(4);
		Node n5 = new Node(5);
		Node n6 = new Node(6);

		n1.next = n2;
		n2.next = n3;
		n3.next = n4;
		n4.next = n5;
		n5.next = n6;
		
		RemovalRequest rr1 = new RemovalRequest(0, 1);
		RemovalRequest rr2 = new RemovalRequest(3, 2);
		RemovalRequest rr3 = new RemovalRequest(4, 1);
		RemovalRequest[] rrs = new RemovalRequest[3];
		rrs[0] = rr1;
		rrs[1] = rr2;
		rrs[2] = rr3;
		
		int[] expected_a = {2, 3, 6};
		
		RemoveNodes rn = new RemoveNodes();
		Node res = rn.Remove(n1, rrs);
		int i = 0;
		while (res != null && i < expected_a.length) {
			assertEquals(expected_a[i], res.val);
			res = res.next;
			++i;
		}
		
		if (res != null || i < expected_a.length) {
			fail();
		}
	}
}
public class InsertToEnd{
	public static Node insert(Node head, Node toInsert){
		if(head == null){
			return toInsert;
		}
		Node current = head;
		while(current.next != null){
			current = current.next;
		}
		current.next = toInsert;
		return head;
	}
}

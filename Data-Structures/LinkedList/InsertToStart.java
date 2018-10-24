public class InsertToStart{
	public static Node insert(Node head, Node toInsert){
		if(head == null){
			return toInsert;
		}
		toInsert.next = head;
		return toInsert;
	}
}

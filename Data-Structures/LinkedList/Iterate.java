public class Iterate{
	public static void main(String[] args){
		Node n1 = new Node(1);
		Node n2 = new Node(2);
		Node n3 = new Node(4);
		Node n4 = new Node(8);
		Node n5 = new Node(16);
		
		n1.next = n2;
		n2.next = n3;
		n3.next = n4;
		n4.next = n5;
		
		printValues(n1);
	}
	
	public static void printValues(Node head){
		Node current = head;
		
		while(current != null){
			System.out.println(current.data);
			current = current.next;
		}
	}
}

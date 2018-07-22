package 链表;

public class PrintLinkedList {

	public static void main(String[] args) {
		ListNode head = new ListNode(0);
		ListNode pCurrent = head;
		for(int i=1;i<=10;i++) {
			pCurrent.next = new ListNode(i);
			pCurrent = pCurrent.next;
		}
		Print(head);
	}
	
	public static void Print(ListNode head) {
		if(head == null) return;
		ListNode pCurrent = head;
		while(pCurrent!=null) {
			System.out.print(pCurrent.val+" ");
			pCurrent = pCurrent.next;
		}
	}
}

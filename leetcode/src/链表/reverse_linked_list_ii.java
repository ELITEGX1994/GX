package 链表;

public class reverse_linked_list_ii {

	public static void main(String[] args) {
		ListNode head = new ListNode(1);
		ListNode pCurrent = head;
		for(int i=2;i<=10;i++) {
			pCurrent.next = new ListNode(i);
			pCurrent = pCurrent.next;
		}
		Print(reverseBetween(head,2,5));
	}
	//按顺序打印链表
	public static void Print(ListNode head) {
		if(head == null) return;
		ListNode pCurrent = head;
		while(pCurrent!=null) {
			System.out.print(pCurrent.val+" ");
			pCurrent = pCurrent.next;
		}
	}
	//非递归法
	public static ListNode reverse1(ListNode head) {
		if(head == null||head.next==null) return head;
		ListNode pCurrent = head.next;
		head.next = null;
		ListNode tmp = null;
		while(pCurrent!=null) {
			tmp = pCurrent.next;
		    pCurrent.next = head;
		    head = pCurrent;
		    pCurrent = tmp;
		}
		return head;
	}
	//递归法
	public static ListNode reverse(ListNode head) {
		if(head==null) return null;
		if(head.next==null) return head;
		ListNode newHead = reverse(head.next);
		head.next.next = head;
		head.next = null;
		return newHead;
	}
	//反转打印
	public static void PrintReverse(ListNode head) {
		if(head==null) return;
		PrintReverse(head.next);
		System.out.print(head.val+" ");
	}
	/*
	 * 将位置m的链接列表反转到n。 在原地和一次通过。例如：
	给定1-> 2-> 3-> 4-> 5-> NULL，m = 2且n = 4，
	return1->4->3-> 2->5-> NULL。
	注意：给定m，n满足以下条件：1≤m≤n≤列表长度。
	 */
	public static ListNode reverseBetween(ListNode head, int m, int n) {
        if(head==null||head.next==null) return head;
        if(m==n) return head;
        ListNode pCurrent = head;
        ListNode Start = null;
        ListNode pStart = null;
        ListNode tmp = null;
        for(int i=1;i<m;i++) {
        	Start = pCurrent;
        	pCurrent=pCurrent.next;
        }
        ListNode newTail = pCurrent;
        pCurrent = pCurrent.next;
        pStart = newTail;
        //反转[m,n]之间的链表
        for(int i=m;i<n;i++) {
        	tmp = pCurrent.next;
        	pCurrent.next = pStart;
        	pStart = pCurrent;
        	pCurrent = tmp;
        }
        
        Start.next=pStart;
        newTail.next = pCurrent;
        return head;
    }
}

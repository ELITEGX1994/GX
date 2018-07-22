package 单链表;

public class 单链表排序 {

	public static void main(String[] args) {
		Node head=new Node(3);
		head.next=new Node(7);
		head.next.next = new Node(5);
		head = orderlist(head);
		printList(head);
	}
	//对链表进行排序返回排序后的头节点
	public static Node orderlist(Node head){
		if(head==null||head.next==null) return head;
		Node pCur = head;
		while(pCur.next!=null) {
			Node pNext=pCur.next;
			while(pNext!=null) {
				if(pNext.val<pCur.val) {
					swap(pNext.val, pCur.val);
				}
			}
			pCur=pCur.next;
		}
		return head;
	}

	public static void swap(int a,int b){
		int tmp = 0;
		tmp = a;
		a = b;
		b = a;
	}
	
	public static void printList(Node head) {
		Node tmp = head;
		while(tmp!=null) {
			System.out.print(tmp.val+" ");
			tmp=tmp.next;
		}
	}
}

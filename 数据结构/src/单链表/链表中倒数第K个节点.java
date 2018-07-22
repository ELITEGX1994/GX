package 单链表;

public class 链表中倒数第K个节点 {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Node head=new Node(3);
		head.next=new Node(7);
		head.next.next = new Node(5);
		System.out.println(FindKthToTail(head,1).val);
	}

	public static Node FindKthToTail(Node head,int k) {
		if(k<1|| head==null) 
            return null;
		Node fast = head;
		Node slow = head;
		for(int i=0;i<k;i++) {
			if(fast.next!=null)
				fast=fast.next;
			else
				return null;
		}
		while(fast!=null&&slow!=null) {
			fast=fast.next;
			slow=slow.next;
		}
		return slow;
	}
}

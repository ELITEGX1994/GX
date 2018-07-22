package 单链表;

public class 合并两个单调单链表 {

	public static void main(String[] args) {
		Node list1=new Node(1);
		list1.next=new Node(3);
		list1.next.next=new Node(5);
		Node list2=new Node(2);
		list2.next=new Node(4);
		list2.next.next=new Node(6);
		Node head = Merge2(list1, list2);
		printList(head);
	}
	//递归版本
	public static Node Merge(Node list1,Node list2) {
		if(list1==null) return list2;
		if(list2==null) return list1;
		Node head = null;
		if(list1.val<list2.val){list1.next=Merge(list1.next,list2);head=list1;}
		else {list2.next=Merge(list2.next,list1);head=list2;}
		return head;
	}
	//迭代版本
	public static Node Merge2(Node list1,Node list2) {
		if(list1==null) return list2;
		if(list2==null) return list1;
		Node head= null;//头节点
		Node current=null;//相当于针
		//选择头结点
		if(list1.val<list2.val) {head=current=list1;list1=list1.next;}
		else {head=current=list2;list2=list2.next;}
		//开始合并俩个链表
		//两个链表都没遍历完的时候
		while(list1!=null&&list2!=null) {
			if(list1.val<list2.val) {
			current.next=list1;
			current=current.next;
			list1=list1.next;
			}else {
			current.next=list2;
			current=current.next;
			list2=list2.next;
			}
		}
		//list2遍历完时
		if(list1!=null) {current.next=list1;}
		if(list2!=null) {current.next=list2;}
		return head;
	}
	
	public static void printList(Node head) {
		Node tmp = head;
		while(tmp!=null) {
			System.out.print(tmp.val+" ");
			tmp=tmp.next;
		}
	}
}

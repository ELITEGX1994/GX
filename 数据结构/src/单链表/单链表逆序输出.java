package 单链表;

import java.util.ArrayList;

public class 单链表逆序输出 {
	static ArrayList<Integer>result = new ArrayList<Integer>();
	public static void main(String[] args) {
		Node head=new Node(3);
		head.next=new Node(7);
		head.next.next = new Node(5);
		//printList(head);
		printReverseList(head);
	}
	
	public static void ReverseList(Node head) {
		if(head.next!=null) 
			ReverseList(head.next);
		result.add(head.val);
	}
	
	
	public static void printReverseList(Node head) {
		if(head.next!=null) 
			printReverseList(head.next);
		System.out.println(head.val);
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


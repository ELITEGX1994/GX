package 单链表;

import java.security.AlgorithmParameterGeneratorSpi;
import java.security.AlgorithmParameters;
import java.security.InvalidAlgorithmParameterException;
import java.security.SecureRandom;
import java.security.spec.AlgorithmParameterSpec;
import java.util.ArrayList;

import javax.annotation.Generated;
import javax.naming.spi.DirStateFactory.Result;

public class 单链表反转 {
	public static void main(String[] args) {
		Node head=new Node(3);
		head.next=new Node(7);
		head.next.next = new Node(5);
		//printList(head);
		Node newHead = reverseList2(head);
		printList(newHead);
	}
	//递归版本反转
public static Node reverseList(Node head) {
	
		if(head==null||head.next==null) return head;
		//先反转后面的链表，走到链表的末端结点
		Node newHead = reverseList(head.next);
		//反转主体
		head.next.next=head;
		head.next=null;
		//
		return newHead;
	}
//非递归版本反转
public static Node reverseList2(Node head) {
	if(head==null||head.next==null) return head;
	Node newHead = null;
    Node pPre = null;
    Node pNode = head;
    while(pNode!=null) {
    	Node pNext = pNode.next;
    	if(pNext==null) newHead = pNode;
    	pNode.next = pPre;
    	pPre = pNode;
    	pNode = pNext;
    }
	return newHead;
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

package 线性表;

public class LinkList {
	public Node head;//头结点
	public Node current;//当前结点
	
	public void add(int data)
	{
		if(head == null)//如果头结点为空，说明这个链表还没有创建，那就把新的结点赋给头结点
		{
			head = new Node(data);
			current = head;
		}
		else
		{
			current。next = new Node(data);
			current = current.next;
			
		}
	}
	class Node
	{
		int data;
		Node next;
		public Node(int data)
		{
			this.data = data;
		}
	}

}

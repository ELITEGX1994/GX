package ���Ա�;

public class LinkList {
	public Node head;//ͷ���
	public Node current;//��ǰ���
	
	public void add(int data)
	{
		if(head == null)//���ͷ���Ϊ�գ�˵���������û�д������ǾͰ��µĽ�㸳��ͷ���
		{
			head = new Node(data);
			current = head;
		}
		else
		{
			current��next = new Node(data);
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

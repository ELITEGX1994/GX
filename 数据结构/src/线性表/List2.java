package 线性表;

import java.util.List;

import 线性表.LinkList.Node;

public class List2 {
	class Node
	{
		int data;
		Node next;
		public Node(int data)
		{
			this.data = data;
		}
	}
	
	public static void removeEvenVer1(List<Integer>lst)
	{
		int i=0;
		while(i<lst.size())
		{
			if(lst.get(i)%2 == 0)
			{
				lst.remove(i);
			}
			else
			{
				i++;
			}
		}
	}
	
	public static void main(String args[])

}

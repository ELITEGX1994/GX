package Thread;

class Runnable1 implements Runnable
{
	private static int count = 1;
	private int charac = (int)'A';
	private int threadId;
	private Object o;
	
	public Runnable1(Object o,int threadId)
	{
		this.threadId = threadId;
		this.o = o;
	}
	public void run(){
		while(count<54){
		synchronized(o){
			if(count%2 == 1)
				{
					System.out.print((2*count-1));
					System.out.print(2*count);
					this.notifyAll();
					//flag = false;
				}else {
					try {
						this.wait();
					} catch (InterruptedException e) {
		             e.printStackTrace();
		         	}
				}
			}
			count++;	
	}
	}
}

class Runnable2 implements Runnable
{
	private static int count = 1;
	private int charac = (int)'A';
	private int threadId;
	private Object o;
	
	public Runnable2(Object o,int threadId)
	{
		this.threadId = threadId;
		this.o = o;
	}
	public void run() {
		while(count<54){
		synchronized(o){
			if(count%2 == 1)
				{
					System.out.print((char)charac);
					this.notifyAll();
					//flag = false;
				}else {
					try {
						this.wait();
					} catch (InterruptedException e) {
		             e.printStackTrace();
		         	}
				}
			}
			count++;	
	}
	}
}

public class TwoThread {
	public static void main(String[] args)
	{
		Object o = new Object();
		
		//Thread t1 = new Thread(new Runnable1(o,1));
		Thread t2 = new Thread(new Runnable2(o,2));
		Thread t1 = new Thread(new Runnable1(o,1));
		t1.start();
		t2.start();
	}
}

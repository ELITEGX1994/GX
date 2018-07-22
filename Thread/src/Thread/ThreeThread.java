package Thread;

public class ThreeThread {
	public static void main(String[] args)
	{
		//Object o = new Object();
		
		//Thread t1 = new Thread(new Runnable1(o,1));
		Thread t1 = new Thread(new station(1));
		Thread t2 = new Thread(new station(2));
		Thread t3 = new Thread(new station(3));
		t1.start();
		t2.start();
		t3.start();
	}
}

class station extends Thread{
	
	private int threadId;
    // 通过构造方法给线程名字赋值
    public station(int threadId) {
         this.threadId = threadId;// 给线程名字赋值
    }
     
    // 为了保持票数的一致，票数要静态
    static int tick = 20;
    
    
     
    // 创建一个静态钥匙
    static Object o = "aa";//值是任意的
    public void run(){
    	synchronized(o)
    	{
    		while(tick>0)
    		{
    			 if (tick%3==threadId) {
                     System.out.println(threadId + "卖出了第" + tick + "张票");
                     tick--;
                     //notifyAll();
                 } else {
                	 try {
          			   sleep(100);//休息一秒
          			 }catch(InterruptedException e){
          				 e.printStackTrace();
          			 }
                 }
    	          
             }
          
    		}
    	}
    }
    
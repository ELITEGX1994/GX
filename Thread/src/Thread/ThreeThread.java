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
    // ͨ�����췽�����߳����ָ�ֵ
    public station(int threadId) {
         this.threadId = threadId;// ���߳����ָ�ֵ
    }
     
    // Ϊ�˱���Ʊ����һ�£�Ʊ��Ҫ��̬
    static int tick = 20;
    
    
     
    // ����һ����̬Կ��
    static Object o = "aa";//ֵ�������
    public void run(){
    	synchronized(o)
    	{
    		while(tick>0)
    		{
    			 if (tick%3==threadId) {
                     System.out.println(threadId + "�����˵�" + tick + "��Ʊ");
                     tick--;
                     //notifyAll();
                 } else {
                	 try {
          			   sleep(100);//��Ϣһ��
          			 }catch(InterruptedException e){
          				 e.printStackTrace();
          			 }
                 }
    	          
             }
          
    		}
    	}
    }
    
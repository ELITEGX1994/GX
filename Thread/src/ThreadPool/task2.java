package ThreadPool;

public class task2 implements Runnable{
	@Override
	public void run() {
		// TODO �Զ����ɵķ������
		System.out.println(Thread.currentThread().getName()+"hello gx");
	}
}

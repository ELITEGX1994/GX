package ThreadPool;

public class task1 implements Runnable{
	@Override
	public void run() {
		// TODO �Զ����ɵķ������
		System.out.println(Thread.currentThread().getName()+"hello world");
	}
}

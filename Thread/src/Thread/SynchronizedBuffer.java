package Thread;

public class SynchronizedBuffer {
	private int buffer = -1;
	private boolean occupiedBuffer = false;
	
	public synchronized void set(int value)
	{
		String name = Thread.currentThread().getName();
		while(occupiedBuffer)
		{
			try {
				System.out.println(name+);
			}
		}
	}

}

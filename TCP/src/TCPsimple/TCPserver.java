package TCPsimple;

import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class TCPserver {
	public static void main(String[] args) throws IOException{
		ServerSocket ss = new ServerSocket(8888);
		Socket s = ss.accept();
		OutputStream outputStream = s.getOutputStream();
		s.close();
		//ss.close();
	}
	
	
}

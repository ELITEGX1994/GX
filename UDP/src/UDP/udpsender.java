package UDP;

import java.io.IOError;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Inet4Address;

public class udpsender {
	public static void main(String[] args) throws IOException{
		byte[] s= "hello gx!".getBytes();
		DatagramSocket ds = new DatagramSocket();
		DatagramPacket dp = new DatagramPacket(s, s.length,Inet4Address.getByName("127.0.0.1"),12306);
		ds.send(dp);
		ds.close();
	}
}

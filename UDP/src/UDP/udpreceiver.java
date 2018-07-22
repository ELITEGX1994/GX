package UDP;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Inet4Address;
import java.net.InetAddress;

public class udpreceiver {
	public static void main(String[] args) throws IOException{
		DatagramSocket ds = new DatagramSocket(12306);
		byte[] buffer = new byte[1024];
		DatagramPacket dp = new DatagramPacket(buffer, 1024);
		ds.receive(dp);
		InetAddress ipAddress = dp.getAddress();
		byte[] data=dp.getData();
		String s = new String(data);
		System.out.println(ipAddress.toString()+" "+dp.getPort()+" "+s);		
		
		//System.out.println(s);
		ds.close();
	}
}

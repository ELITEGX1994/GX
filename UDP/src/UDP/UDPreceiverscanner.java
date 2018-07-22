package UDP;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPreceiverscanner {
	public static void main(String[] args) throws IOException{
		DatagramSocket ds = new DatagramSocket(6000);
		byte[] buffer = new byte[1024];
		while(true) {
		DatagramPacket dp = new DatagramPacket(buffer, 1024);
		ds.receive(dp);
		InetAddress ipAddress = dp.getAddress();
		byte[] data=dp.getData();
		String s = new String(data,0,dp.getLength());
		System.out.println(ipAddress.toString()+" "+dp.getPort()+" "+s);		
		
		//System.out.println(s);
		//ds.close();
		}
	}
}

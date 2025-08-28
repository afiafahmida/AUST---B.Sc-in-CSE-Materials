
import java.net.*;
import java.io.*;

class MyClient {

    public static void main(String args[]) throws Exception {
        
        Socket clientSocket = new Socket("localhost", 3333);
        
        
        DataInputStream din = new DataInputStream(clientSocket.getInputStream());
        DataOutputStream dout = new DataOutputStream(clientSocket.getOutputStream());
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = "", str2 = "";
        
        while (!str2.equals("stop")) {
            str = din.readUTF();
            System.out.println("Server says: " + str);
            str2 = br.readLine();
            dout.writeUTF(str2);
            dout.flush();
            
        }
        din.close();
        dout.close();
        clientSocket.close();
    }
}

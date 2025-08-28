
import java.net.*;
import java.io.*;

class MyServer {

    public static void main(String args[]) throws Exception {
        
        ServerSocket ServerSocket = new ServerSocket(3333);
        Socket server = ServerSocket.accept();
        
        DataInputStream din = new DataInputStream(server.getInputStream());
        DataOutputStream dout = new DataOutputStream(server.getOutputStream());
      
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = "", str2 = "";
        while (!str.equals("stop")) {
            str = br.readLine();
            dout.writeUTF(str);
            str2 = din.readUTF();
            System.out.println("client says: " + str2);
            dout.flush();
        }
          
        din.close();
        dout.close();
        server.close();
        ServerSocket.close();
    }
}

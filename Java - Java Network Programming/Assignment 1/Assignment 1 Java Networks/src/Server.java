import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.SocketChannel;
import java.nio.file.Path;
import java.nio.file.Paths;


public class Server implements Runnable {

    ServerSocket serversocket;
    BufferedReader br1;
    PrintWriter pr1;
    Socket socket;
    Thread t1, t2;
    String fileName="";

    public Server() {
        try {
            t1 = new Thread(this);
            t2 = new Thread(this);
            //try  here
            serversocket = new ServerSocket(5005);
            System.out.println("Server is waiting. . . . ");
            socket = serversocket.accept();

            System.out.println("Client connected with Ip " + socket.getInetAddress().getHostAddress());
            t1.start();;
            t2.start();

        } catch (Exception e) {
        }
    }

    public void run() {
        while(true){
        try {
            if (Thread.currentThread() == t1) {
                do {
                    br1 = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    pr1 = new PrintWriter(socket.getOutputStream(), true);
                    pr1.println("Select from the following options: file1\t file2\t  big\t quit");
                    fileName = br1.readLine();
                    File file = new File("resources/" + fileName + ".txt");

                    pr1.flush();
                    if (file.exists()) {
                        SocketChannel server = SocketChannel.open();
                        SocketAddress socketAddr = new InetSocketAddress("localhost", 9009);
                        server.connect(socketAddr);

                        Path path = Paths.get("resources/" + fileName + ".txt");
                        FileChannel fileChannel = FileChannel.open(path);
                        ByteBuffer buffer = ByteBuffer.allocate(1024);

                        while (fileChannel.read(buffer) > 0) {
                            buffer.flip();
                            server.write(buffer);
                            buffer.clear();
                        }
                        System.out.println("File Sent");
                        fileChannel.close();
                    } else
                        System.out.println("File does not exist");
                } while (!fileName.equals("quit"));
                pr1.close();
                br1.close();
                socket.close();
            }
        } catch (Exception e) {
        }

    }

    }

    public static void main(String[] args) {
        new Server();
    }
}
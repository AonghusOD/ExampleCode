import java.io.*;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.EnumSet;


public class Client implements Runnable {

    BufferedReader br1, br2;
    PrintWriter pr1;
    Socket socket;
    Thread t1, t2;
    String in = "", out = "";

    public Client() {
        try {
            t1 = new Thread(this);
            t2 = new Thread(this);
            socket = new Socket("localhost", 5005);
            t1.start();;
            t2.start();

        } catch (Exception e) {
        }
    }

    public void run() {

        try {
            if (Thread.currentThread() == t2) {
                do {
                    br1 = new BufferedReader(new InputStreamReader(System.in));

                    pr1 = new PrintWriter(socket.getOutputStream(), true);

                    PrintStream output = new PrintStream("resources/fileOut.txt");
                    while((in = br1.readLine())!=null) {
                        pr1.println(in);
                        output.print(in);
                        pr1.flush();
                    }
                    pr1.flush();
                    br1.close();

                } while (!in.equals("quit"));
            } else {
                do {
                    br2 = new BufferedReader(new   InputStreamReader(socket.getInputStream()));
                    out = br2.readLine();

                    System.out.println(out);

                    ServerSocketChannel serverSocket = null;
                    SocketChannel client = null;
                    serverSocket = ServerSocketChannel.open();
                    serverSocket.socket().bind(new InetSocketAddress(9009));
                    client = serverSocket.accept();

                    Path path = Paths.get("resources/fileOut.txt");


                    FileChannel fileChannel = FileChannel.open(path,
                            EnumSet.of(StandardOpenOption.CREATE,
                                    StandardOpenOption.TRUNCATE_EXISTING,
                                    StandardOpenOption.WRITE));

                    ByteBuffer buffer = ByteBuffer.allocate(1024);
                    while(client.read(buffer) > 0) {
                        buffer.flip();
                        fileChannel.write(buffer);
                        buffer.clear();
                        try {
                            Files.lines(path).forEach(System.out::println);
                        } catch (IOException ex) {
                            ex.printStackTrace();
                        }
                        break;
                    }
                    client.close();
                    System.out.println("File Received");
                    buffer.clear();
                } while (!out.equals("quit"));
                socket.close();
                br2.close();
            }
        } catch (Exception e) {
        }

    }
    public static void main(String[] args) {
        new Client();
    }
}
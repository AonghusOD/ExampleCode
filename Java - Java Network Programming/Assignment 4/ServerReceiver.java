package com.company;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

public class ServerReceiver {
    public static void main(String[] args) throws  IOException {
        SocketChannel server = SocketChannel.open();
        SocketAddress socketAddr = new InetSocketAddress("localhost", 9000);

        server.connect(socketAddr);
        System.out.print("Ready for file.....");
        ByteBuffer buffer = ByteBuffer.allocate(1024);

        while(server.read(buffer) > 0) {
            buffer.flip();
            while (buffer.hasRemaining()) {
                System.out.print((char) buffer.get());
            }
            buffer.clear();
        }

        System.out.println("\n");
        System.out.println("File Received");
        server.close();

    }
}

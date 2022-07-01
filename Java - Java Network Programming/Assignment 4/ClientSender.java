package com.company;

import java.io.*;
import java.net.InetSocketAddress;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.EnumSet;
import java.util.Scanner;

public class ClientSender {
    public static void main(String[] args) throws IOException {

        ServerSocketChannel serverSocket;
        SocketChannel client;
        serverSocket = ServerSocketChannel.open();
        serverSocket.socket().bind(new InetSocketAddress(9000));

        client = serverSocket.accept();

        System.out.println("Connection Set:  " + client.getRemoteAddress());

        Path path = Paths.get("C:\\test\\big.txt");
        FileChannel fileChannel = FileChannel.open(path);
        long fileSize = fileChannel.size();

        ByteBuffer buffer = ByteBuffer.allocate((int) (fileSize +1));
        System.out.println("Bytes:" + fileSize);

        while(fileChannel.read(buffer) > 0){
            buffer.flip();
            client.write(buffer);
            buffer.clear();
        }

        System.out.println("File Sent");
        fileChannel.close();
        client.close();

    }
}
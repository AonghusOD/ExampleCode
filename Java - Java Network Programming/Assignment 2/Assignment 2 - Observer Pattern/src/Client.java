import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.net.UnknownHostException;

public class Client extends JFrame implements ActionListener {
    JPanel panel;
    JTextField textField;
    JTextArea textArea;
    JButton button;
    int port = 5001;
    String iPStr = "230.0.0.1";
    InetAddress mcIPAddress = InetAddress.getByName(iPStr);
    MulticastSocket socket = new MulticastSocket(port);


    public Client() throws UnknownHostException, IOException {
        panel = new JPanel();
        textField = new JTextField();
        textArea = new JTextArea();
        button = new JButton("Send");
        this.setSize(300, 300);
        this.setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        panel.setLayout(null);
        this.add(panel);
        textArea.setBounds(20, 20, 450, 360);
        panel.add(textArea);
        textField.setBounds(20, 400, 340, 30);
        this.setTitle("Observer");
        button.addActionListener(this);


        socket.joinGroup(mcIPAddress);
        DatagramPacket packet = new DatagramPacket(new byte[1024], 1024);
        while (true) {
            try {
                socket.receive(packet);
                String msg = new String(packet.getData(), packet.getOffset(), packet.getLength());
                if (msg.length() > 0)
                    textArea.setText(textArea.getText() + msg + "\n");


            } catch (Exception e1) {
                textArea.setText(textArea.getText() + '\n'
                        + "Message sending fail:Network Error");
                try {
                    Thread.sleep(3000);
                    System.exit(0);
                } catch (InterruptedException e2) {
                    // TODO Auto-generated catch block
                    e2.printStackTrace();
                }
            }
        }

    }

    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub

        try {
            socket.joinGroup(mcIPAddress);
        } catch (IOException ex) {
            ex.printStackTrace();
        }
        while (true) {

            try {
                byte[] b = new byte[200];
                DatagramPacket packet = new DatagramPacket(b, 200);
                socket.receive(packet);
                String s = new String(packet.getData());
                if (s.length() > 0)
                    textArea.setText(textArea.getText() + s + "\n");

            } catch (Exception e1) {
                textArea.setText(textArea.getText() + '\n'
                        + "Message sending fail:Network Error");
                try {
                    Thread.sleep(3000);
                    System.exit(0);
                } catch (InterruptedException e2) {
                    // TODO Auto-generated catch block
                    e2.printStackTrace();
                }
            }
        }
    }
    public static void main(String[] args) throws UnknownHostException,
            IOException {
        new Client();
    }
}

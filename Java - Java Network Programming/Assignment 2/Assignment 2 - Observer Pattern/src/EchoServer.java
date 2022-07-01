import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class EchoServer extends JFrame implements ActionListener {
    JPanel panel;
    JTextField textField;
    JTextArea textArea;
    JButton button;
    String userName = "";
    int port = 5001;
    String iPStr = "230.0.0.1";
    InetAddress inetAdd = InetAddress.getByName(iPStr);
    DatagramSocket udpSocket = new DatagramSocket();

    public EchoServer() throws UnknownHostException, IOException {
        panel = new JPanel();
        textField = new JTextField();
        textArea = new JTextArea();
        button = new JButton("Send");
        this.setSize(500, 150);
        this.setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        panel.setLayout(null);
        this.add(panel);
        textField.setBounds(20, 40, 340, 30);
        panel.add(textField);
        button.setBounds(375, 40, 95, 30);
        panel.add(button);
        this.setTitle("Server");
        button.addActionListener(this);

    }
    public static void main(String[] args) throws UnknownHostException,
            IOException {
        new EchoServer();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if ((e.getSource() == button) && (textField.getText() != "")) {
            try {
                    userName = textField.getText();
                    byte[] msg = userName.getBytes();
                    DatagramPacket packet = new DatagramPacket(msg, msg.length);
                    packet.setAddress(inetAdd);
                    packet.setPort(port);
                    udpSocket.send(packet);
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
            textField.setText("");
        }
    }
}
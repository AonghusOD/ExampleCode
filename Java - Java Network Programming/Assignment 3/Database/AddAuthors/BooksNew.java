/*Aonghus O Domhnaill
* G00293306
* Adding data to MySQL Database
 */

package AddAuthors;

import java.sql.*;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

public class BooksNew extends JFrame {
    // references to prepared statements for inserting entry
    private PreparedStatement sqlInsertAuthor, sqlInsertTitle, sqlInsertPublisher,  sqlInsertISBN;

    public BooksNew() {
        JTextField t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;

        final String[] key = new String[1];

        t1= new JTextField("First Name", 20);
        t2 = new JTextField("Last Name",20);
        t3 = new JTextField("ISBN (Number)",20);
        t4 = new JTextField("Title",20);
        t5 = new JTextField("Edition Number (Number)",20);
        t6 = new JTextField("Copyright (Year)",20);
        t7 = new JTextField("Publisher ID (1 - 2)",20);
        t8 = new JTextField("Image File",20);
        t9 = new JTextField("Price",20);
        t10 = new JTextField("Publisher",20);

        JButton button = new JButton("Add");

        //super("Enter Data Books Database");
        setLayout(new FlowLayout());

        try {
            // load database driver class
            Class.forName("com.mysql.cj.jdbc.Driver");
            // connect to database
            Connection connection = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/books", "root", "root");


            button.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent event) {

                    try {
                        Class.forName("com.mysql.cj.jdbc.Driver");
                        // connect to database
                        Connection connection = DriverManager.getConnection(
                                "jdbc:mysql://localhost:3306/books", "root", "root");
                        // create Statement to query database

                        sqlInsertAuthor = connection.prepareStatement(
                                "INSERT INTO authors (firstName, lastName) VALUES (?,?)", Statement.RETURN_GENERATED_KEYS);
                        sqlInsertTitle = connection.prepareStatement(
                                "INSERT INTO titles (isbn, title, editionNumber, copyright, publisherID, imageFile, price) VALUES (?,?,?,?,?,?,?)");
                        sqlInsertPublisher = connection.prepareStatement(
                                "INSERT INTO publishers ( publisherID, publisherName ) VALUES (?, ?)");
                        sqlInsertISBN = connection.prepareStatement(
                                "INSERT INTO authorisbn ( authorID, isbn ) VALUES (?, ?)");

                        sqlInsertAuthor.setString(1, t1.getText());
                        sqlInsertAuthor.setString(2, t2.getText());
                        sqlInsertAuthor.executeUpdate();

                        ResultSet res = sqlInsertAuthor.getGeneratedKeys();

                        ResultSetMetaData rsmd = res.getMetaData();
                        int columnCount = rsmd.getColumnCount();

                        if (res.next()) {
                            do {
                                for (int i=1; i<=columnCount; i++) {
                                    key[i-1] = res.getString(i);
                                    sqlInsertISBN.setInt(1,  Integer.parseInt(key[i-1]));
                                }
                            } while(res.next());

                        }
                        else {
                            System.out.println("NO KEYS WERE GENERATED.");
                        }

                        sqlInsertTitle.setLong(1, Long.parseLong(t3.getText()));
                        sqlInsertTitle.setString(2, t4.getText());
                        sqlInsertTitle.setInt(3, Integer.parseInt(t5.getText()));
                        sqlInsertTitle.setInt(4, Integer.parseInt(t6.getText()));
                        sqlInsertTitle.execute("SET FOREIGN_KEY_CHECKS=0");
                        sqlInsertTitle.setInt(5, Integer.parseInt(t7.getText()));
                        sqlInsertTitle.setString(6, t8.getText());
                        sqlInsertTitle.setDouble(7, Double.parseDouble(t9.getText()));


                        sqlInsertPublisher.setInt(1, Integer.parseInt(t5.getText()));
                        sqlInsertPublisher.setString(2, t10.getText());

                        //Set authorID and ISBN
                        sqlInsertISBN.setLong(2,  Long.parseLong(t3.getText()));

                        sqlInsertTitle.executeUpdate();
                        sqlInsertISBN.executeUpdate();

                        sqlInsertPublisher.executeUpdate();

                         t1.setText("First Name");
                         t2.setText("Last Name");
                         t3.setText("ISBN (Number)");
                         t4.setText("Title");
                         t5.setText("Edition Number (Number)");
                         t6.setText("Copyright (Year)");
                         t7.setText("Publisher ID (1 - 2)");
                         t8.setText("Image File");
                         t9.setText("Price");
                         t10.setText("Publisher");

                    }catch (SQLException | ClassNotFoundException e) {
                        e.printStackTrace();}
                }
            });
            add(t1);
            add(t2);
            add(t3);
            add(t4);
            add(t5);
            add(t6);
            add(t7);
            add(t8);
            add(t9);
            add(t10);
            add(button);

            setSize(300, 350);
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            setLocationRelativeTo(null);
            setVisible(true);

            connection.close();

        }
        catch (SQLException | ClassNotFoundException sqlException ) {
            JOptionPane.showMessageDialog( null,
                    sqlException.getMessage(), "Database Error",
                    JOptionPane.ERROR_MESSAGE );

            System.exit( 1 );
        }


    }

    private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new BooksNew();
        //Display the window.
        frame.pack();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }

    public static void main (String args[])
    {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                BooksNew window = new BooksNew();
                window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            }
        });
    }
}
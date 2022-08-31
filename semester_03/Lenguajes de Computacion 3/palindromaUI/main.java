import javax.swing.JFrame;

import java.awt.*;
import java.awt.event.*;

public class main {
  public static void main(String[] args) {
    JFrame.setDefaultLookAndFeelDecorated(true);
    JFrame frame = new JFrame("Palindroma");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
    interfacePalindroma interfazPassword = new interfacePalindroma();
    frame.getContentPane().add(interfazPassword, BorderLayout.CENTER);

    frame.setBounds(100, 100, 400, 325);
    frame.setVisible(true);
  }
}

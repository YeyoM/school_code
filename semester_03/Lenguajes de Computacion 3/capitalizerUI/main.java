import javax.swing.JFrame;

import java.awt.*;
import java.awt.event.*;

public class main {
  public static void main(String[] args) {
    JFrame.setDefaultLookAndFeelDecorated(true);
    JFrame frame = new JFrame("Capitilizer");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
    capitalizerInterface interfaz = new capitalizerInterface();
    frame.getContentPane().add(interfaz, BorderLayout.CENTER);

    frame.setBounds(100, 100, 400, 325);
    frame.setVisible(true);
  }
}

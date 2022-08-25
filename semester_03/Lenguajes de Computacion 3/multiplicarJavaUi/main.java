import javax.swing.JFrame;

import java.awt.*;
import java.awt.event.*;

public class main {
  public static void main(String[] args) {
    JFrame.setDefaultLookAndFeelDecorated(true);
    JFrame frame = new JFrame("2 Fields and 1 Button");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
    interfaceMult interfazMult = new interfaceMult();
    frame.getContentPane().add(interfazMult, BorderLayout.CENTER);

    frame.setBounds(100, 100, 400, 325);
    frame.setVisible(true);
  }
}

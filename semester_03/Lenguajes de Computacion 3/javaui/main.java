import javax.swing.JFrame;

import java.awt.*;
import java.awt.event.*;

public class main {
  public static void main(String[] args) {
    JFrame.setDefaultLookAndFeelDecorated(true);
    JFrame frame = new JFrame("2 Fields and 1 Button");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    
    botones boton = new botones();
    frame.getContentPane().add(boton, BorderLayout.CENTER);

    frame.setBounds(100, 100, 400, 325);
    frame.setVisible(true);
  }
}


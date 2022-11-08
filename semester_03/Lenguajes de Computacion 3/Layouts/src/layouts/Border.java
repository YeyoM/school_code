/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package layouts;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.event.ActionEvent;
import javax.swing.JButton;
import javax.swing.JFrame;
import static javax.swing.WindowConstants.EXIT_ON_CLOSE;

/**
 *
 * @author Usuario
 */
public class Border extends JFrame {
    
    Border() {
    
        JButton b1=new JButton("1");  
        b1.addActionListener((ActionEvent e) -> {
            b1.setText("cambiado");
        });
  
        setLayout(new BorderLayout()); 
        
        add(new Button("North"), BorderLayout.NORTH);
        add(new Button("South"), BorderLayout.SOUTH);
        add(new Button("East"), BorderLayout.EAST);
        add(new Button("West"), BorderLayout.WEST);
        add(new Button("Center"), BorderLayout.CENTER);
        
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        setSize(300,300); 
         setTitle("Border");
        setVisible(true); 
    }
    
    public static void main(String[] args) {
      java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Border().setVisible(true);
            }
        });
    }
}

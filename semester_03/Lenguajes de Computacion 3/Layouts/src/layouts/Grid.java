/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package layouts;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;

public class Grid extends JFrame {

    Grid() {
    
    JButton b1=new JButton("1");  
    b1.addActionListener(new ActionListener(){  
    public void actionPerformed(ActionEvent e){  
               b1.setText("cambiado");    }    });  

    JButton b2=new JButton("2");      JButton b3=new JButton("3");  
    JButton b4=new JButton("4");      JButton b5=new JButton("5");  
    JButton b6=new JButton("6");      JButton b7=new JButton("7");  
    JButton b8=new JButton("8");      JButton b9=new JButton("9");  
    
    add(b1);add(b2);add(b3);add(b4);add(b5);  
    add(b6);add(b7);add(b8);add(b9);  
  
    setLayout(new GridLayout(3,3)); 
    setDefaultCloseOperation(EXIT_ON_CLOSE);

     setTitle("Grid");
     setSize(300,300);  
    setVisible(true); 
              }
    public static void main(String[] args) {
      java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Grid().setVisible(true);
            }
        });
    }
 }









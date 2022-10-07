/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package archivosgraficas;

import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

/**
 *
 * @author Usuario
 */
public class ArchivosGraficas extends JFrame implements ActionListener {
    
    JPanel panel1;
    JTextArea text1;
    JButton but1;
    
    ArchivosGraficas() {
    
        panel1 = new JPanel();
        text1=new JTextArea(15,15);
        but1=new JButton("leer");
        but1.addActionListener(this);
        panel1.add(text1);
        panel1.add(but1);
        add(panel1);

        setLayout(new GridLayout(1, 1));  
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(550,350);

    }
    
    @Override
    public void actionPerformed(ActionEvent evt) { 
       
    try {
        JFileChooser open = new JFileChooser();
        int option = open.showOpenDialog(this);
        File f1 = new File(open.getSelectedFile().getPath());
        FileReader fr = new FileReader(f1);
        BufferedReader br = new BufferedReader(fr);
        String s;
        while((s=br.readLine())!=null) {
            text1.append(s + "\n");
        }
        fr.close();
    } catch(Exception ae) {
        System.out.println(ae);
    }    
         
    }


    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ArchivosGraficas().setVisible(true);
            }
        });

    }
    
}

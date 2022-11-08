/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package layouts;
import java.awt.*;    
import javax.swing.*;    
    
public class Box extends Frame {    
    Button buttons[];    
    
    public Box () {    
        buttons = new Button [5];    
      
        for (int i = 0;i<5;i++) {    
            buttons[i] = new Button ("Button " + (i + 1));    
            // adding the buttons so that it can be displayed  
            add (buttons[i]);    
        }    
        // the buttons will be placed horizontally  
        setLayout (new BoxLayout (this, BoxLayout.Y_AXIS));    

        setSize(400,400);
        setTitle("Box");
        setVisible(true);    
    }    
    // main method  
    public static void main(String args[]){    
    Box b=new Box();    
    }    
}  

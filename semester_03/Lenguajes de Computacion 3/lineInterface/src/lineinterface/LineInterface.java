/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lineinterface;

import java.applet.Applet; 
import java.awt.*; 
import java.awt.event.*;

/**
 *
 * @author Usuario
 */
public class LineInterface extends Applet implements ActionListener { 
    // Creating a text field.
    TextField name;
    int oportunidades=0;
    //variable tipo Image
    Image img;
   // Creating a text field.
    public LineInterface()
    {
        //creo una direccion de imagen
        String imageFile="D:\\Usuario\\Descargas\\cheems.png";
        // Creating an image object.
        img=Toolkit.getDefaultToolkit().getImage(imageFile);
        //aqui creo el textfield
        name=new TextField(20);
        //aqui agrego el textfield al applet
        name.addActionListener(this);  
        add(name);
    }

    /**
     * The function actionPerformed is called when the user clicks the button
     * 
     * @param ae The ActionEvent object that was generated when the button was clicked.
     */

     //aqui hace jalar el textfield
    public void actionPerformed(ActionEvent ae)
    {
        //contador de oportunidades
        oportunidades++;
        // Calling the `paint()` method.
        //NO QUITAR ESTA LINEA
        repaint();
        //si llega a cinco te saca
        if(oportunidades==5)
        {
            System.exit(0);
        }
    }

/**
 * The function takes a Graphics object as a parameter, and then draws a line, an oval, a string, and
 * an image on the screen
 * 
 * @param g The Graphics object to draw on.
 */
//funcion para dibujar
public void paint(Graphics g) 
{ 
    //aqui tamaño y fuente de la letra
      g.setFont(new Font("Arial",Font.BOLD,12)); 
      //aqui color de las lineas y letras
      g.setColor(Color.pink);
      //aqui dibujo la linea diagonal
      // This is a conditional statement that checks if the variable `oportunidades` is equal to 1. If
      // it is, then the line is drawn.
      if(oportunidades==1)
      {    g.drawLine(100,110,140,150);}
      //aqui dibujo el circulo
     // This is a conditional statement that checks if the variable `oportunidades` is equal to 2. If
     //       it is, then the oval is drawn.
      if(oportunidades==2)
      {    g.drawLine(100,110,140,150);
           g.drawOval(100,110,140,150);}
           //aqui agrego la palabra prueba
        // This is a conditional statement that checks if the variable `oportunidades` is equal to 3.
        // If
        //         it is, then the line, oval, and string are drawn.
        if(oportunidades==3)
        {    g.drawLine(100,110,140,150);
             g.drawOval(100,110,140,150);
             g.drawString("prueba",50,50);}
             //aqui agrego la imagen
        // This is a conditional statement that checks if the variable `oportunidades` is equal to 4.
        // If
        //         it is, then the line, oval, and string are drawn.
        if(oportunidades==4)
        {    g.drawLine(100,110,140,150);
             g.drawOval(100,110,140,150);
             g.drawString("prueba",50,50);
             g.drawImage(img,100,100,this);}
} 

/**
 * The main function creates a frame, sets its size, adds the applet to the frame, and makes the frame
 * visible
 */
public static void main(String[] args) 
{ 
    // Creating a frame.
    //ttulo del frame
    Frame drawLineApplet = new Frame("Dibujar lineas"); 
    // Creating an instance of the applet.
    //tamaño del frame
    drawLineApplet.setSize(500, 450); 
    //llamos a nuestra funcion
   // Creating an instance of the applet.
    Applet DrawLine = new LineInterface(); 
    // Adding the applet to the frame.
    //la funcion que se llama DrawLine se agrega al frame
    drawLineApplet.add(DrawLine); 
    //que se vea el drawnlineapplet sea visible
    drawLineApplet.setVisible(true); 

    // This is a listener that is listening for a window event. When the window is closed, the program
    // will exit.
    //hace que cierre cuando le piques a la x
    drawLineApplet.addWindowListener(new WindowAdapter() { 
    public void windowClosing(WindowEvent e) {System.exit(0); } 
                                                                               }); 
} 
}

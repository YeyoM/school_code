//import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JFrame;

public class Lineas2 extends JFrame{
    public void paint(Graphics g){
        super.paint(g);
        int x1 = 0, y1 = 0, x2 = 0, y2 = 400;
        int x3 = 0, y3 = 0, x4 = 0, y4 = 500;
        //Mover para abajo toda la figura
        //Esquina superior izquierda
        while(x3 < 500){
          g.drawLine(x3,y3,x4,y4); // 0 0 0 400
          x3 += 10;
          y4 -= 10;
        }
        //Esquina superior derecha
        x3 = x3 - 200;
        while(y3 < 500){
            g.drawLine(x3,y3,x4,y4); 
            x4 += 10;
            y3 += 10;
        }
        // //Esquina inferior izquierda
        // while(y1 < 400){
        //     g.drawLine(x1,y1,x2,y2); // 0 0 0 400
        //     y1 += 10;
        //     x2 += 10;
        // }
        // //Esquina inferior derecha
        // while(x1 < 400){
        //     g.drawLine(x1,y1,x2,y2); // 0 0 0 400
        //     x1 += 10;
        //     y2 -= 10;
        // }
    }

    public static void main (String[] args){
        Lineas2 obj = new Lineas2();

        obj.setSize(400,500);
        obj.setVisible(true);
        obj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
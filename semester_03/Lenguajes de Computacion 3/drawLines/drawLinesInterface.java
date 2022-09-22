import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.StringTokenizer;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class drawLinesInterface extends JPanel implements drawLinesInterface {
  JTextField name;
  int oportunidades = 0;
  Image img;

  public drawLinesInterface() {
    String imageFile = "";
    img = Toolkit.getDefaultToolkit().getImage(imageFile);
    setLayout(new FlowLayout());
    name = new JTextField(20);
    name.addActionListener(this);
    add(name);
  }

  public void actionPerformed(ActionEvent ae) {
    oportunidades++;
    repaint();
    if (oportunidades == 5) {
      System.exit(0);
    }

    public void paintComponent(Graphics g) {
      super.paintComponent(g);
      g.drawImage(img, 0, 0, this);
      g.setColor(Color.red);
      g.drawLine(0, 0, 100, 100);
    }

  }

}

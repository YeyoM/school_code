import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class interfaceMult extends JPanel implements ActionListener {
  JButton multiplicar;
  JTextField text1, text2;

  /**
   * 
   */
  public interfaceMult() {
    text1 = new JTextField(10);
    text2 = new JTextField(10);
    multiplicar = new JButton("multiplicar");
    multiplicar.addActionListener(this);
    setLayout(new FlowLayout());
    add(text1);
    add(text2);
    add(multiplicar);
  }

  public void actionPerformed(ActionEvent ae) {
    if (ae.getSource() == multiplicar) {
      int num1 = Integer.parseInt(text1.getText());
      int num2 = Integer.parseInt(text2.getText());
      int multiplicacion = num1 * num2;
      text2.setText(Integer.toString(multiplicacion));
    }
  }

}
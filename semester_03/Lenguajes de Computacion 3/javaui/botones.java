import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class botones extends JPanel implements ActionListener {
  JButton sumar;
  JTextField text1, text2;

  /**
   * 
   */
  public botones() {
    text1 = new JTextField(10);
    text2 = new JTextField(10);
    sumar = new JButton("sumar");
    sumar.addActionListener(this);
    setLayout(new FlowLayout());
    add(text1);
    add(text2);
    add(sumar);
  }

  public void actionPerformed(ActionEvent ae) {
    if (ae.getSource() == sumar) {
      int num1 = Integer.parseInt(text1.getText());
      int num2 = Integer.parseInt(text2.getText());
      int suma = num1 + num2;
      text2.setText(Integer.toString(suma));
    }
  }

}

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class interfacePalindroma extends JPanel implements ActionListener {
  JLabel notification;
  JButton checkPalabra;
  JTextField palabraInput;

  public interfacePalindroma() {
    palabraInput = new JTextField(10);
    notification = new JLabel("Notification: ");
    checkPalabra = new JButton("Revisar si es palindroma");
    checkPalabra.addActionListener(this);
    setLayout(new FlowLayout());
    add(palabraInput);
    add(checkPalabra);
    add(notification);
  }

  public void actionPerformed(ActionEvent e) {
    StringBuffer palabra = new StringBuffer(palabraInput.getText().toString());

    if (palabra.toString().toLowerCase().replaceAll("\\s+","").equals(palabra.reverse().toString().toLowerCase().replaceAll("\\s+",""))) {
      notification.setText("Es palindroma");
    } else {
      notification.setText("No es palindroma");
    }
  }

}

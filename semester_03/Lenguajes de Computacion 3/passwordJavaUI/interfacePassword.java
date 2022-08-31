import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class interfacePassword extends JPanel implements ActionListener {
  JLabel notification;
  JButton checkPassword;
  JPasswordField passwordInput;
  JTextField nameInput;

  public interfacePassword() {
    passwordInput = new JPasswordField(10);
    nameInput = new JTextField(10);
    notification = new JLabel("Notification: ");
    checkPassword = new JButton("Check password");
    checkPassword.addActionListener(this);
    setLayout(new FlowLayout());
    add(nameInput);
    add(passwordInput);
    add(checkPassword);
    add(notification);
  }

  /* (non-Javadoc)
   * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
   */
  public void actionPerformed(ActionEvent e) {
    String[] users = {"Juan", "Maria", "Luisa", "Gerardo"};
    String[] passwords = {"password", "password", "password", "password"};
    String user = nameInput.getText();
    String password = String.valueOf(passwordInput.getPassword());
    String passwordValue = new String();
    // if (name.equals("admin") && password.equals("admin")) {
    //   notification.setText("Welcome admin");
    // } else {
    //   notification.setText("Wrong password");
    // }
    for (int i = 0; i < users.length; i++) {
      if (user.equals(users[i])){  
        passwordValue = passwords[i];
      }
    }

    if (password.equals(passwordValue) && !passwordValue.equals("")) {
      notification.setText("ingreso");
    } else {
      notification.setText("no ingreso");
    }


  }

}

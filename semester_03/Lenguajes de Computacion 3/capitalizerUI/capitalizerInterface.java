import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class capitalizerInterface extends JPanel implements ActionListener {
  JTextField wordInput;
  JLabel capitilizedWord;
  JButton capitilizeWord;

  public capitalizerInterface() {
    wordInput = new JTextField(10);
    capitilizedWord = new JLabel(" ");
    capitilizeWord = new JButton("Capitilize my Word");
    capitilizeWord.addActionListener(this);
    setLayout(new FlowLayout());
    add(wordInput);
    add(capitilizedWord);
    add(capitilizeWord);
  }

  public void actionPerformed(ActionEvent e) {
    String word = wordInput.getText().toString();
    String capitilizedWord = word.substring(0, 1).toUpperCase() + word.substring(1).toLowerCase();
    this.capitilizedWord.setText(capitilizedWord);
  }

}

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.StringTokenizer;

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
    StringBuffer stringbuff = new StringBuffer();
    String a;
        
    StringTokenizer st = new StringTokenizer(wordInput.getText().toString()," ");
    while (st.hasMoreTokens()){
        a = st.nextToken();
        stringbuff.append(a.toUpperCase().charAt(0)+a.substring(1)+" ");
    }
    capitilizedWord.setText(stringbuff.toString());
  }

}

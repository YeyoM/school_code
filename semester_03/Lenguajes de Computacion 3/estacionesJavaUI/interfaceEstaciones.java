import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class interfaceEstaciones extends JPanel implements ActionListener {
  JLabel mes, estacion;
  JButton mostrarEstacion;
  JTextField mesInput;

  public interfaceEstaciones() {
    mesInput = new JTextField(10);
    mes = new JLabel("Mes: ");
    estacion = new JLabel("Estacion: ");
    mostrarEstacion = new JButton("Mostrar estacion");
    mostrarEstacion.addActionListener(this);
    setLayout(new FlowLayout());
    add(mes);
    add(mesInput);
    add(mostrarEstacion);
    add(estacion);
  }

  public void actionPerformed(ActionEvent e) {

    // generate an array of 4 seasons
    String[] estaciones = new String[4];
    estaciones[0] = "Invierno";
    estaciones[1] = "Primavera";
    estaciones[2] = "Verano";
    estaciones[3] = "Otono";

    // get the month number from the input
    int mes = Integer.parseInt(mesInput.getText());
    if (mes < 1 || mes > 12) {
      estacion.setText("Mes invalido");
    } else {
      // get the season number
      int estacion = (mes - 1) / 3;
      // show the season
      this.estacion.setText(estaciones[estacion]);
    }
  }

}

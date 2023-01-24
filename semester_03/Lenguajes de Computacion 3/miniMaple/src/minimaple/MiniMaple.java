/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package minimaple;
import java.util.ArrayList;
import java.util.StringTokenizer;
import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.math.Fraction;

/**
 *
 * @author Usuario
 */
public class MiniMaple {

    /**
     * @param args the command line arguments
     */
    public static boolean isNumeric(String strNum) {
        if (strNum == null) {
            return false;
        } 
        try {
            double d = Double.parseDouble(strNum);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }
    
    public static void main(String[] args) {
        
        MiniMapleUI ui = new MiniMapleUI();
        ui.setVisible(true);
        
        String literalsInput = "1*a + 1/2*b - 3/2*c";
        
        Fraction multiplicar = Fraction.getFraction(1, 2);
        
        ArrayList<Fraction> coeficientesParciales = new ArrayList<>();
        ArrayList<Fraction> resultadosCoeficientes = new ArrayList<>();
        
       
        // System.out.println(numeroTerminos);
        StringTokenizer st = new StringTokenizer(literalsInput, " ");
        while(st.hasMoreTokens()) {
            String actual = st.nextToken();
            if (!"+".equals(actual) && !"-".equals(actual)) {
                
                // obtener el coeficiente
                int indice1 = actual.indexOf("*");
                int inicio = 0;
                int termino = actual.length();
                
                String coeficiente = actual.substring(inicio, indice1);
                String literal = actual.substring(indice1 + 1, termino);
                
                System.out.println("Coeficiente -> " + coeficiente);
                System.out.println("Literal -> " + literal);
                
                if (coeficiente.contains("/")) {
                   int indice2 = coeficiente.indexOf("/");
                    int inicio2 = 0;
                    int termino2 = coeficiente.length();
                
                    int numerador = Integer.parseInt(coeficiente.substring(inicio2, indice2));
                    int denominador = Integer.parseInt(coeficiente.substring(indice2 + 1, termino2));
                        
                    // System.out.println("Fraccion -> " + actual);
                    // System.out.println("Numerador -> " + numerador);
                    // System.out.println("Denominador -> " + denominador);
                
                    Fraction.getFraction(numerador, denominador);
                    coeficientesParciales.add(Fraction.getFraction(numerador, denominador)); 
                } else {
                    // System.out.println("Entero -> " + actual);
                    int numerador = Integer.parseInt(coeficiente);
                    int denominador = 1;
                
                    coeficientesParciales.add(Fraction.getFraction(numerador, denominador)); 
                }
                
            }
        }
        
        System.out.println(coeficientesParciales.toString());
        
        // multiplicamos
        for (int i = 0; i < coeficientesParciales.size(); i++) {
            Fraction fraccion = coeficientesParciales.get(i);
            Fraction result = fraccion.multiplyBy(multiplicar);
            resultadosCoeficientes.add(result);
        }
        
        System.out.println(resultadosCoeficientes.toString());
        
    }
    
}

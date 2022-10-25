/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package introduccionbasesdedatos;

import org.mariadb.jdbc.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


/**
 *
 * @author Usuario
 */
public class IntroduccionBasesDeDatos {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try {
            Connection conn = (Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/prueba01", "root", "");
            if (conn != null) {
                System.out.println("Conectado a la base de datos prueba01");
                System.out.println("> Datos de la tabla prueba");                
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    String query = "SELECT * FROM prueba;";
                    // ejecuta la consulta y obtiene el resultado
                    ResultSet rs = st.executeQuery(query);                    
                    while (rs.next()) {
                        int id = rs.getInt("id");
                        String nombre = rs.getString("nom");
                        // imprime el resultado
                        System.out.format("%s | %s\n", id, nombre);
                    }
                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                }
            }            
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
        System.out.println("fin programa.");
    }
    
}

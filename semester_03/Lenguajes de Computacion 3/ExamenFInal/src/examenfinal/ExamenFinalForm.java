package examenfinal;

import com.formdev.flatlaf.FlatDarkLaf;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */

/**
 *
 * @author Usuario
 */
public class ExamenFinalForm extends javax.swing.JFrame {
    
    ArrayList<String> carritoIds = new ArrayList<>();
    ArrayList<String> carritoCantidades = new ArrayList<>();
    ArrayList<String> inventarioActual = new ArrayList<>();
    ArrayList<String> nuevoInventario = new ArrayList<>();
    
    Integer total = 0;
    
    /**
     * Creates new form ExamenFinalForm
     */
    public ExamenFinalForm() {
        try {
            UIManager.setLookAndFeel( new FlatDarkLaf() );
        } catch( UnsupportedLookAndFeelException ex ) {
            System.err.println( "Failed to initialize LaF" );
        }
        initComponents();
    }


    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jTabbedPane1 = new javax.swing.JTabbedPane();
        productosPane = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        nombreInput = new javax.swing.JTextField();
        idInput = new javax.swing.JTextField();
        buscarNombreBtn = new javax.swing.JButton();
        buscarIdBtn = new javax.swing.JButton();
        jLabel4 = new javax.swing.JLabel();
        buscarTodosBtn = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        displayProducts = new javax.swing.JTextArea();
        carritoPane = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        idInputCarrito = new javax.swing.JTextField();
        cantidadInputCarrito = new javax.swing.JTextField();
        agragarAlCarrito = new javax.swing.JButton();
        pagarBtn = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        carritoArea = new javax.swing.JTextArea();
        totalLabel = new javax.swing.JLabel();
        notificaciones = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Buscar por nombre:");

        jLabel3.setText("Buscar por ID:");

        buscarNombreBtn.setText("Buscar");
        buscarNombreBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarNombreBtnActionPerformed(evt);
            }
        });

        buscarIdBtn.setText("Buscar");
        buscarIdBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarIdBtnActionPerformed(evt);
            }
        });

        jLabel4.setText("Buscar todos los productos");

        buscarTodosBtn.setText("Buscar");
        buscarTodosBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarTodosBtnActionPerformed(evt);
            }
        });

        displayProducts.setColumns(20);
        displayProducts.setRows(5);
        jScrollPane1.setViewportView(displayProducts);

        javax.swing.GroupLayout productosPaneLayout = new javax.swing.GroupLayout(productosPane);
        productosPane.setLayout(productosPaneLayout);
        productosPaneLayout.setHorizontalGroup(
            productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(productosPaneLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1)
                    .addGroup(productosPaneLayout.createSequentialGroup()
                        .addGroup(productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                .addGroup(productosPaneLayout.createSequentialGroup()
                                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 148, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(nombreInput))
                                .addGroup(productosPaneLayout.createSequentialGroup()
                                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 148, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(idInput, javax.swing.GroupLayout.PREFERRED_SIZE, 131, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 148, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(buscarNombreBtn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(buscarIdBtn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(buscarTodosBtn, javax.swing.GroupLayout.DEFAULT_SIZE, 97, Short.MAX_VALUE))))
                .addContainerGap())
        );
        productosPaneLayout.setVerticalGroup(
            productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(productosPaneLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(nombreInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(buscarNombreBtn))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(idInput)
                        .addComponent(buscarIdBtn))
                    .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(productosPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(buscarTodosBtn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jLabel4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 171, Short.MAX_VALUE)
                .addContainerGap())
        );

        jTabbedPane1.addTab("Productos", productosPane);

        jLabel2.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel2.setText("Tu carrito");

        jLabel5.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel5.setText("Agregar Productos");

        jLabel6.setText("ID");

        jLabel7.setText("Cantidad");

        agragarAlCarrito.setText("Agregar Producto al Carrito");
        agragarAlCarrito.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                agragarAlCarritoActionPerformed(evt);
            }
        });

        pagarBtn.setText("Pagar");
        pagarBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                pagarBtnActionPerformed(evt);
            }
        });

        carritoArea.setColumns(20);
        carritoArea.setRows(5);
        jScrollPane2.setViewportView(carritoArea);

        totalLabel.setText("Total: ");

        notificaciones.setText(" ");

        javax.swing.GroupLayout carritoPaneLayout = new javax.swing.GroupLayout(carritoPane);
        carritoPane.setLayout(carritoPaneLayout);
        carritoPaneLayout.setHorizontalGroup(
            carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(carritoPaneLayout.createSequentialGroup()
                .addGroup(carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(carritoPaneLayout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 252, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(pagarBtn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(totalLabel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(notificaciones, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                    .addGroup(carritoPaneLayout.createSequentialGroup()
                        .addGroup(carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(carritoPaneLayout.createSequentialGroup()
                                .addContainerGap()
                                .addGroup(carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 141, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addGroup(carritoPaneLayout.createSequentialGroup()
                                        .addGroup(carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addGroup(carritoPaneLayout.createSequentialGroup()
                                                .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 82, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(idInputCarrito, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE)
                                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                                .addComponent(jLabel7, javax.swing.GroupLayout.PREFERRED_SIZE, 82, javax.swing.GroupLayout.PREFERRED_SIZE))
                                            .addComponent(jLabel5))
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(cantidadInputCarrito, javax.swing.GroupLayout.PREFERRED_SIZE, 96, javax.swing.GroupLayout.PREFERRED_SIZE))))
                            .addGroup(carritoPaneLayout.createSequentialGroup()
                                .addGap(57, 57, 57)
                                .addComponent(agragarAlCarrito, javax.swing.GroupLayout.PREFERRED_SIZE, 271, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(0, 14, Short.MAX_VALUE)))
                .addContainerGap())
        );
        carritoPaneLayout.setVerticalGroup(
            carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(carritoPaneLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel2)
                .addGap(3, 3, 3)
                .addGroup(carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addGroup(carritoPaneLayout.createSequentialGroup()
                        .addComponent(notificaciones)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(totalLabel)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(pagarBtn))
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 112, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel5)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(carritoPaneLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel7, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(cantidadInputCarrito, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addComponent(idInputCarrito, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(agragarAlCarrito)
                .addGap(14, 14, 14))
        );

        jTabbedPane1.addTab("Carrito", carritoPane);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void buscarTodosBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarTodosBtnActionPerformed
        displayProducts.setText("");
        try {
            org.mariadb.jdbc.Connection conn = (org.mariadb.jdbc.Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/examen_final", "root", "");
            if (conn != null) {
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    
                    String query = "SELECT * FROM `inventario` WHERE 1;";
                    System.out.println(query);

                    ResultSet rs = st.executeQuery(query);
                    while(rs.next()) {
                        String nombre = rs.getString("nom");
                        String id = rs.getString("id");
                        Integer precio = rs.getInt("precio");
                        Integer inventario = rs.getInt("inventario");
                        
                        String addToPanel = id + " | " + nombre + " - $" + precio.toString() + " - " + inventario.toString() + " unidades.\n";
                        displayProducts.append(addToPanel);
                    }

                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                }
            }   
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
    }//GEN-LAST:event_buscarTodosBtnActionPerformed

    private void buscarIdBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarIdBtnActionPerformed
        // TODO add your handling code here:
        displayProducts.setText("");
        try {
            org.mariadb.jdbc.Connection conn = (org.mariadb.jdbc.Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/examen_final", "root", "");
            if (conn != null) {
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    
                    String idQ = idInput.getText();
                    
                    String query = "SELECT * FROM `inventario` WHERE id='" + idQ + "';";
                    System.out.println(query);

                    ResultSet rs = st.executeQuery(query);
                    while(rs.next()) {
                        String nombre = rs.getString("nom");
                        String id = rs.getString("id");
                        Integer precio = rs.getInt("precio");
                        Integer inventario = rs.getInt("inventario");
                        
                        String addToPanel = id + " | " + nombre + " - $" + precio.toString() + " - " + inventario.toString() + " unidades.\n";
                        displayProducts.append(addToPanel);
                    }

                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                }
            }   
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
    }//GEN-LAST:event_buscarIdBtnActionPerformed

    private void buscarNombreBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarNombreBtnActionPerformed
        // TODO add your handling code here:
        displayProducts.setText("");
        try {
            org.mariadb.jdbc.Connection conn = (org.mariadb.jdbc.Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/examen_final", "root", "");
            if (conn != null) {
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    
                    String nombreInputQ = nombreInput.getText();
                    
                    String query = "SELECT * FROM `inventario` WHERE nom='" + nombreInputQ + "';";
                    System.out.println(query);

                    ResultSet rs = st.executeQuery(query);
                    while(rs.next()) {
                        String nombre = rs.getString("nom");
                        String id = rs.getString("id");
                        Integer precio = rs.getInt("precio");
                        Integer inventario = rs.getInt("inventario");
                        
                        String addToPanel = id + " | " + nombre + " - $" + precio.toString() + " - " + inventario.toString() + " unidades.\n";
                        displayProducts.append(addToPanel);
                    }

                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                }
            }   
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
    }//GEN-LAST:event_buscarNombreBtnActionPerformed

    private void agragarAlCarritoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_agragarAlCarritoActionPerformed
        // TODO add your handling code here:
        
        String idCarrito = idInputCarrito.getText();
        String cantidadCarrito = cantidadInputCarrito.getText();
        
        if (!" ".equals(idCarrito) && Integer.parseInt(cantidadCarrito) != 0) {
            try {
                org.mariadb.jdbc.Connection conn = (org.mariadb.jdbc.Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/examen_final", "root", "");
                if (conn != null) {
                    //crea la declaracion
                    try (Statement st = conn.createStatement()) {
                    
                        String query = "SELECT * FROM `inventario` WHERE id='" + idCarrito + "';";
                        System.out.println(query);

                        ResultSet rs = st.executeQuery(query);
                        while(rs.next()) {
                            
                            String id;
                            Integer precio;
                            Integer inventario;
                            Integer nuevoInventarioQ;
                            
                            id = rs.getString("id");
                            precio = rs.getInt("precio");
                            inventario = rs.getInt("inventario");
                                                    
                            if (Integer.parseInt(cantidadCarrito) <= inventario) {
                                
                                nuevoInventarioQ = inventario - Integer.parseInt(cantidadCarrito);
                                
                                carritoIds.add(id);
                                carritoCantidades.add(cantidadCarrito);
                                inventarioActual.add(inventario.toString());
                                nuevoInventario.add(nuevoInventarioQ.toString());
                                
                                Integer precioTotal = precio * Integer.parseInt(cantidadCarrito);
                                
                                total += precioTotal;
                                
                                // agregar al textarea del carrito
                                String paraCarrito = id + " | " + cantidadCarrito + "pza: $" + precioTotal + "\n";
                                carritoArea.append(paraCarrito);
                                
                                totalLabel.setText("Total: $" + total);
                                
                                notificaciones.setText("Producto agregado!");
                                
                                idInputCarrito.setText("");
                                cantidadInputCarrito.setText("");
                            } else {
                                // no se puede
                            }
                            
                        }

                    } catch (SQLException ex) {
                        System.err.println(ex.getMessage());
                    }
                }   
            } catch (SQLException ex) {
                System.err.println(ex.getMessage());
            }
        }
    }//GEN-LAST:event_agragarAlCarritoActionPerformed

    private void pagarBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_pagarBtnActionPerformed
           
        // TODO add your handling code here:
         try {
            org.mariadb.jdbc.Connection conn = (org.mariadb.jdbc.Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/examen_final", "root", "");
            if (conn != null) {
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    
                    for (int i = 0; i < carritoIds.size(); i++) {
                                        
                        // actualizar el inventario
                        String query = "UPDATE `inventario` \nSET inventario=" + nuevoInventario.get(i) + "\nWHERE id=" + carritoIds.get(i) + ";" ;
                        st.executeUpdate(query);
                        String content = "Abarrotes La Esquina \n\nGracias Por Su Pago \n\nProductos: \n" + carritoArea.getText() + "\nTotal: $" + total.toString();
                        String path = "D:/ticket.txt";
                        Files.write( Paths.get(path), content.getBytes());
                    }
                    
                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                } catch (IOException ex) {
                    Logger.getLogger(ExamenFinalForm.class.getName()).log(Level.SEVERE, null, ex);
                }
            }   
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
        
        carritoIds.removeAll(carritoIds);
        carritoCantidades.removeAll(carritoCantidades);
        total = 0;
        
        notificaciones.setText("Pago completado!");
        carritoArea.setText("");
        totalLabel.setText("Total: $0");
    }//GEN-LAST:event_pagarBtnActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ExamenFinalForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ExamenFinalForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ExamenFinalForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ExamenFinalForm.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ExamenFinalForm().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton agragarAlCarrito;
    private javax.swing.JButton buscarIdBtn;
    private javax.swing.JButton buscarNombreBtn;
    private javax.swing.JButton buscarTodosBtn;
    private javax.swing.JTextField cantidadInputCarrito;
    private javax.swing.JTextArea carritoArea;
    private javax.swing.JPanel carritoPane;
    private javax.swing.JTextArea displayProducts;
    private javax.swing.JTextField idInput;
    private javax.swing.JTextField idInputCarrito;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JTextField nombreInput;
    private javax.swing.JLabel notificaciones;
    private javax.swing.JButton pagarBtn;
    private javax.swing.JPanel productosPane;
    private javax.swing.JLabel totalLabel;
    // End of variables declaration//GEN-END:variables
}
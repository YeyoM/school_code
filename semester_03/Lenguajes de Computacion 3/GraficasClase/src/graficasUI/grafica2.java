/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package graficasUI;

import java.util.HashSet;
import javax.swing.SwingUtilities;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.category.DefaultCategoryDataset;

/**
 *
 * @author Usuario
 */
public class grafica2 extends javax.swing.JFrame {

    /**
     * Creates new form grafica2
     * @param title
     */
    public grafica2(String title) {
        super(title);
        initComponents();
        // Create dataset  
        DefaultCategoryDataset dataset = createDataset();  
        // Create chart  
        JFreeChart chart = ChartFactory.createLineChart(  
            "Site Traffic", // Chart title  
            "Date", // X-Axis Label  
            "Number of Visitor", // Y-Axis Label  
            dataset  
            );  
      
        ChartPanel panel = new ChartPanel(chart);  
        setContentPane(panel);
    }
    
    private DefaultCategoryDataset createDataset() {  
      
        String series1 = "Visitor";  
        String series2 = "Unique Visitor";  
      
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();  
      
        dataset.addValue(200, series1, "2016-12-19");  
        dataset.addValue(150, series1, "2016-12-20");  
        dataset.addValue(100, series1, "2016-12-21");  
        dataset.addValue(210, series1, "2016-12-22");  
        dataset.addValue(240, series1, "2016-12-23");  
        dataset.addValue(195, series1, "2016-12-24");  
        dataset.addValue(245, series1, "2016-12-25");  
      
        dataset.addValue(150, series2, "2016-12-19");  
        dataset.addValue(130, series2, "2016-12-20");  
        dataset.addValue(95, series2, "2016-12-21");  
        dataset.addValue(195, series2, "2016-12-22");  
        dataset.addValue(200, series2, "2016-12-23");  
        dataset.addValue(180, series2, "2016-12-24");  
        dataset.addValue(230, series2, "2016-12-25");  
      
        return dataset;  
    } 
    
    


    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
    SwingUtilities.invokeLater(() -> {
       grafica2 ejemplo = new grafica2("Ejemplo");
       ejemplo.setAlwaysOnTop(true);
       ejemplo.pack();
       ejemplo.setSize(600, 400);
       ejemplo.setDefaultCloseOperation(EXIT_ON_CLOSE);
       ejemplo.setVisible(true);
    });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package graficasUI;

import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PiePlot3D;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;
import org.jfree.util.Rotation;

/**
 *
 * @author Usuario
 */
public class grafica1 extends javax.swing.JFrame {

    public grafica1(String applicationTitle, String chartTitle) {
        super(applicationTitle);
        initComponents();
        // This will create the dataset
        PieDataset dataset = createDataset();
        // based on the dataset we create the chart
        JFreeChart chart = createChart(dataset, chartTitle);
        // we put the chart into a panel
        ChartPanel chartPanel = new ChartPanel(chart);
        // default size
        chartPanel.setPreferredSize(new java.awt.Dimension(500, 270));
        // add it to our application
        setContentPane(chartPanel);

    }
    
    private  PieDataset createDataset() {
        DefaultPieDataset result = new DefaultPieDataset();
        result.setValue("Aguascalientes", 948990);
        result.setValue("Asientos", 51536);
        result.setValue("Calvillo", 58250);
        result.setValue("Cosío", 17000);
        result.setValue("Jesús María", 129929);
        result.setValue("Pabellón de Arteaga", 47646);
        result.setValue("Rincón de Romos ", 57369);
        result.setValue("San José de Gracia", 9552);
        result.setValue("Tepezalá", 22485);
        result.setValue("El Llano", 20853);
        result.setValue("San Francisco de los Romo", 61997);

        return result;

    }
    
    private JFreeChart createChart(PieDataset dataset, String title) {

        JFreeChart chart = ChartFactory.createPieChart3D(
            title,                  // chart title
            dataset,                // data
            true,                   // include legend
            true,
            false
        );

        PiePlot3D plot = (PiePlot3D) chart.getPlot();
        plot.setStartAngle(290);
        plot.setDirection(Rotation.CLOCKWISE);
        plot.setForegroundAlpha(0.5f);
        return chart;
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
        grafica1 demo = new grafica1("Población por municipio", "Población por municipio");
        demo.pack();
        demo.setVisible(true);
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}
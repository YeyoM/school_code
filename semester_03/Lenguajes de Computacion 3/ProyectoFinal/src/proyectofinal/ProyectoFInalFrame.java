/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package proyectofinal;

import com.formdev.flatlaf.FlatDarkLaf;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.HeadlessException;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.Date;
import java.util.Locale;
import javax.swing.JFileChooser;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import org.mariadb.jdbc.Connection;
import java.sql.Time;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.ArrayList;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.data.category.CategoryDataset;
import org.jfree.data.category.DefaultCategoryDataset;

/**
 *
 * @author Usuario
 */
public class ProyectoFInalFrame extends javax.swing.JFrame {
    
    // CREATING FORM INITILIZING... /////////////////////////////////////////////////////
    
    public ProyectoFInalFrame() {
        try {
            UIManager.setLookAndFeel( new FlatDarkLaf() );
        } catch( UnsupportedLookAndFeelException ex ) {
            System.err.println( "Failed to initialize LaF" );
        }
        initComponents();
        notificationLabel.setText("");
    }
    
    // VARIABLES GLOBALES //////////////////////////////////////////////////////////////
    
    String dateForGraph;
    int newUsersForGraph;
    int activeUserForGraph;
    String peekHourForGraph;
    int avgUsageForGraph;
    String countryForGraph;
    String monthForGraph;
    
    ArrayList<String> many_dateForGraph = new ArrayList<>();
    ArrayList<Integer> many_newUsersForGraph = new ArrayList<>();
    ArrayList<Integer> many_activeUserForGraph = new ArrayList<>();
    ArrayList<String> many_peekHourForGraph = new ArrayList<>();
    ArrayList<Integer> many_avgUsageForGraph = new ArrayList<>();
    ArrayList<String> many_countryForGraph = new ArrayList<>();

    
    // FUNCIONES AUXILIARES ///////////////////////////////////////////////////////////

    public static boolean isValidFormat(String format, String value, Locale locale) {
        LocalDateTime ldt = null;
        DateTimeFormatter fomatter = DateTimeFormatter.ofPattern(format, locale);

        try {
            ldt = LocalDateTime.parse(value, fomatter);
            String result = ldt.format(fomatter);
            return result.equals(value);
        } catch (DateTimeParseException e) {
            try {
                LocalDate ld = LocalDate.parse(value, fomatter);
                String result = ld.format(fomatter);
                return result.equals(value);
            } catch (DateTimeParseException exp) {
                try {
                    LocalTime lt = LocalTime.parse(value, fomatter);
                    String result = lt.format(fomatter);
                    return result.equals(value);
                } catch (DateTimeParseException e2) {
                    // Debugging purposes
                    //e2.printStackTrace();
                }
            }
        }

        return false;
    }
    
    public void deleteInfo() {
        dateForGraph = "";
        newUsersForGraph = 0;
        activeUserForGraph = 0;
        peekHourForGraph = "";
        avgUsageForGraph = 0;
        countryForGraph = "";
        
        many_dateForGraph.removeAll(many_dateForGraph);
        many_newUsersForGraph.removeAll(many_newUsersForGraph);
        many_activeUserForGraph.removeAll(many_activeUserForGraph);
        many_peekHourForGraph.removeAll(many_peekHourForGraph);
        many_avgUsageForGraph.removeAll(many_avgUsageForGraph);
        many_countryForGraph.removeAll(many_countryForGraph);
    }
    
    public void setInfo(Date dateQuery, Time timeQuery, int newUsers, int activeUsers, int avgUserUsage, String countryQuery) {
        dateForGraph = dateQuery.toString();
        newUsersForGraph = newUsers;
        activeUserForGraph = activeUsers;
        peekHourForGraph = timeQuery.toString();
        avgUsageForGraph = avgUserUsage;
        countryForGraph = countryQuery;
    }
    
    public CategoryDataset createDatasetAlone(int newUsers, int activeUsers) {  
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        
        dataset.addValue(newUsers, "New Users", "New Users");
        dataset.addValue(activeUsers, "Active Users", "Active Users");
      
        return dataset;  
    }  
    
    public void CreateBarChartUnique(String dateQuery, String timeQuery, int newUsers, int activeUsers, int avgUserUsage, String countryQuery) {
        chartPanel.removeAll();
        chartPanel.revalidate();
        chartPanel.repaint();
        CategoryDataset dataset = createDatasetAlone(newUsers, activeUsers);  
        JFreeChart chart = ChartFactory.createBarChart(  
            "New and Active Users for " + countryQuery + " at " + dateQuery + " at " + timeQuery + " and avg usage: " + avgUserUsage + "hrs", 
            "", // Category axis  
            "Number of persons", // Value axis  
            dataset,  
            PlotOrientation.VERTICAL,  
            true,true,false  
        );
        ChartPanel chartPanel2 = new ChartPanel(chart);
        chartPanel2.setMouseWheelEnabled(true);
        chartPanel2.setPreferredSize(new Dimension(416, 278));
        chartPanel.setLayout(new BorderLayout());
        chartPanel.add(chartPanel2, BorderLayout.NORTH);
        pack();
        repaint();
    }
    
    public CategoryDataset createDatasetMany(ArrayList<Integer> many_activeUsers, ArrayList<Integer> many_newUsers) {  
        DefaultCategoryDataset dataset = new DefaultCategoryDataset();
        
        double activeUsersMean = calculateAverage(many_activeUsers);
        double newUsersMean = calculateAverage(many_newUsers);

        
        dataset.addValue(newUsersMean, "New Users", "New Users");
        dataset.addValue(activeUsersMean, "Active Users", "Active Users");
      
        return dataset;  
    }  
    
    public void CreateBarChartMonth(String month, ArrayList<Integer> many_newUsers, ArrayList<Integer> many_activeUsers, ArrayList<Integer> many_avgUsage) {
        chartPanel.removeAll();
        chartPanel.revalidate();
        chartPanel.repaint();
        CategoryDataset dataset = createDatasetMany(many_activeUsers, many_newUsers);  
        double avgUsageMean = calculateAverage(many_avgUsage);
        JFreeChart chart = ChartFactory.createBarChart(  
            "New and Active Users for the month: " + month + " and avg usage: " + avgUsageMean + "hrs", 
            "", // Category axis  
            "Number of persons", // Value axis  
            dataset,  
            PlotOrientation.VERTICAL,  
            true,true,false  
        );
        ChartPanel chartPanel2 = new ChartPanel(chart);
        chartPanel2.setMouseWheelEnabled(true);
        chartPanel2.setPreferredSize(new Dimension(416, 278));
        chartPanel.setLayout(new BorderLayout());
        chartPanel.add(chartPanel2, BorderLayout.NORTH);
        pack();
        repaint();
    }
    
    public void CreateBarChartAllTime(ArrayList<Integer> many_newUsers, ArrayList<Integer> many_activeUsers, ArrayList<Integer> many_avgUsage) {
        chartPanel.removeAll();
        chartPanel.revalidate();
        chartPanel.repaint();
        CategoryDataset dataset = createDatasetMany(many_activeUsers, many_newUsers);  
        double avgUsageMean = calculateAverage(many_avgUsage);
        JFreeChart chart = ChartFactory.createBarChart(  
            "New and Active Users all time, avg usage: " + avgUsageMean + "hrs", 
            "", // Category axis  
            "Number of persons", // Value axis  
            dataset,  
            PlotOrientation.VERTICAL,  
            true,true,false  
        );
        ChartPanel chartPanel2 = new ChartPanel(chart);
        chartPanel2.setMouseWheelEnabled(true);
        chartPanel2.setPreferredSize(new Dimension(416, 278));
        chartPanel.setLayout(new BorderLayout());
        chartPanel.add(chartPanel2, BorderLayout.NORTH);
        pack();
        repaint();
    }
    
    public void CreateBarChartImported(ArrayList<Integer> many_newUsers, ArrayList<Integer> many_activeUsers, ArrayList<Integer> many_avgUsage) {
        chartPanel.removeAll();
        chartPanel.revalidate();
        chartPanel.repaint();
        CategoryDataset dataset = createDatasetMany(many_activeUsers, many_newUsers);  
        double avgUsageMean = calculateAverage(many_avgUsage);
        JFreeChart chart = ChartFactory.createBarChart(  
            "New and Active Users information imported, avg usage: " + avgUsageMean + "hrs", 
            "", // Category axis  
            "Number of persons", // Value axis  
            dataset,  
            PlotOrientation.VERTICAL,  
            true,true,false  
        );
        ChartPanel chartPanel2 = new ChartPanel(chart);
        chartPanel2.setMouseWheelEnabled(true);
        chartPanel2.setPreferredSize(new Dimension(416, 278));
        chartPanel.setLayout(new BorderLayout());
        chartPanel.add(chartPanel2, BorderLayout.NORTH);
        pack();
        repaint();
    }
    
    private double calculateAverage(ArrayList <Integer> marks) {
        Integer sum = 0;
        if(!marks.isEmpty()) {
            for (Integer mark : marks) {
                sum += mark;
            }
            return sum.doubleValue() / marks.size();
        }
        return sum;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jMenu1 = new javax.swing.JMenu();
        jLabel1 = new javax.swing.JLabel();
        jFrame1 = new javax.swing.JFrame();
        previewPane = new javax.swing.JTabbedPane();
        jPanel1 = new javax.swing.JPanel();
        jLabel4 = new javax.swing.JLabel();
        notificationLabel = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        dateInput = new javax.swing.JTextField();
        dateQueryBtn = new javax.swing.JButton();
        jLabel6 = new javax.swing.JLabel();
        countryInput = new javax.swing.JTextField();
        countryQueryBtn = new javax.swing.JButton();
        jLabel7 = new javax.swing.JLabel();
        monthInput = new javax.swing.JTextField();
        monthQueryBtn = new javax.swing.JButton();
        jLabel8 = new javax.swing.JLabel();
        queryAllBtn = new javax.swing.JButton();
        jLabel9 = new javax.swing.JLabel();
        importBtn = new javax.swing.JButton();
        uploadFileBtn = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        exportBtn = new javax.swing.JButton();
        chartPanel = new javax.swing.JPanel();
        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu2 = new javax.swing.JMenu();
        jMenuItem4 = new javax.swing.JMenuItem();
        jMenuItem5 = new javax.swing.JMenuItem();
        jMenu3 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();
        jMenuItem3 = new javax.swing.JMenuItem();

        jMenu1.setText("jMenu1");

        jLabel1.setFont(new java.awt.Font("Space Grotesk Medium", 1, 36)); // NOI18N
        jLabel1.setText("User Analytics Explorer");

        javax.swing.GroupLayout jFrame1Layout = new javax.swing.GroupLayout(jFrame1.getContentPane());
        jFrame1.getContentPane().setLayout(jFrame1Layout);
        jFrame1Layout.setHorizontalGroup(
            jFrame1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        jFrame1Layout.setVerticalGroup(
            jFrame1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(56, 56, 56));
        getContentPane().setLayout(new java.awt.GridLayout(1, 0));

        previewPane.setBackground(new java.awt.Color(56, 56, 56));
        previewPane.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 0, 0, 0));
        previewPane.setAlignmentX(0.0F);
        previewPane.setAlignmentY(0.0F);

        jPanel1.setBackground(new java.awt.Color(56, 56, 56));
        jPanel1.setAlignmentX(0.0F);
        jPanel1.setAlignmentY(0.0F);

        jLabel4.setFont(new java.awt.Font("Space Grotesk Medium", 0, 24)); // NOI18N
        jLabel4.setText("User Analytics Manager");

        notificationLabel.setText("NOTIFICATIONS HERE");

        jLabel5.setFont(new java.awt.Font("Space Grotesk Light", 0, 14)); // NOI18N
        jLabel5.setText("Query by specific date");

        dateInput.setText("YYYY-MM-DD");
        dateInput.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dateInputActionPerformed(evt);
            }
        });

        dateQueryBtn.setText("EXECUTE");
        dateQueryBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dateQueryBtnActionPerformed(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Space Grotesk Light", 0, 14)); // NOI18N
        jLabel6.setText("Query by country");

        countryQueryBtn.setText("EXECUTE");
        countryQueryBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                countryQueryBtnActionPerformed(evt);
            }
        });

        jLabel7.setFont(new java.awt.Font("Space Grotesk Light", 0, 14)); // NOI18N
        jLabel7.setText("Query all");

        monthInput.setText("MM");

        monthQueryBtn.setText("EXECUTE");
        monthQueryBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                monthQueryBtnActionPerformed(evt);
            }
        });

        jLabel8.setFont(new java.awt.Font("Space Grotesk Light", 0, 14)); // NOI18N
        jLabel8.setText("Query by month");

        queryAllBtn.setText("EXECUTE");
        queryAllBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                queryAllBtnActionPerformed(evt);
            }
        });

        jLabel9.setFont(new java.awt.Font("Space Grotesk Light", 0, 14)); // NOI18N
        jLabel9.setText("Import From txt");

        importBtn.setText("Select FIle");
        importBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                importBtnActionPerformed(evt);
            }
        });

        uploadFileBtn.setText("Upload to BD");
        uploadFileBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                uploadFileBtnActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(notificationLabel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addComponent(jLabel5)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 28, Short.MAX_VALUE)
                                .addComponent(dateInput, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel6)
                                    .addComponent(jLabel8))
                                .addGap(61, 61, 61)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(countryInput)
                                    .addComponent(monthInput)))
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel7)
                                    .addComponent(jLabel4)
                                    .addComponent(jLabel9))
                                .addGap(0, 0, Short.MAX_VALUE)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(uploadFileBtn, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 104, Short.MAX_VALUE)
                            .addComponent(importBtn, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(queryAllBtn, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(monthQueryBtn, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(countryQueryBtn, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(dateQueryBtn, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel4)
                .addGap(29, 29, 29)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(dateInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(dateQueryBtn))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(countryInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(countryQueryBtn))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(monthInput, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(monthQueryBtn)
                    .addComponent(jLabel8))
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(queryAllBtn))
                .addGap(51, 51, 51)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel9)
                    .addComponent(importBtn))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(uploadFileBtn)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 27, Short.MAX_VALUE)
                .addComponent(notificationLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        previewPane.addTab("Manage Query", jPanel1);

        jPanel2.setBackground(new java.awt.Color(56, 56, 56));

        jLabel3.setFont(new java.awt.Font("Space Grotesk Medium", 0, 24)); // NOI18N
        jLabel3.setText("Graph");

        exportBtn.setFont(new java.awt.Font("Space Grotesk Light", 0, 22)); // NOI18N
        exportBtn.setText("Export graph");

        javax.swing.GroupLayout chartPanelLayout = new javax.swing.GroupLayout(chartPanel);
        chartPanel.setLayout(chartPanelLayout);
        chartPanelLayout.setHorizontalGroup(
            chartPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        chartPanelLayout.setVerticalGroup(
            chartPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 278, Short.MAX_VALUE)
        );

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(chartPanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                        .addGap(0, 213, Short.MAX_VALUE)
                        .addComponent(exportBtn, javax.swing.GroupLayout.PREFERRED_SIZE, 203, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(jLabel3)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(chartPanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(exportBtn)
                .addContainerGap())
        );

        previewPane.addTab("Preview Graph", jPanel2);

        getContentPane().add(previewPane);

        jMenu2.setText("File");

        jMenuItem4.setText("Import txt");
        jMenu2.add(jMenuItem4);

        jMenuItem5.setText("Export Graph");
        jMenu2.add(jMenuItem5);

        jMenuBar1.add(jMenu2);

        jMenu3.setText("Edit");

        jMenuItem1.setText("Clear All query");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu3.add(jMenuItem1);

        jMenuItem2.setText("Clear Graph");
        jMenu3.add(jMenuItem2);

        jMenuItem3.setText("Clear All");
        jMenu3.add(jMenuItem3);

        jMenuBar1.add(jMenu3);

        setJMenuBar(jMenuBar1);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void dateInputActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dateInputActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_dateInputActionPerformed

    private void countryQueryBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_countryQueryBtnActionPerformed
        // TODO add your handling code here:
        deleteInfo();
        try {
            Connection conn = (Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/proyectofinal", "root", "");
            if (conn != null) {
                notificationLabel.setText("Connected to dataBase 'proyectofinal'");
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    
                    String country = countryInput.getText();
                    String query;
                    
                    if (!"".equals(country)) {
                        query = "SELECT * FROM `user_stats` WHERE country_most_users='" + country + "';";
                        System.out.println(query);
                        
                        ResultSet rs = st.executeQuery(query);
                        while(rs.next()) {
                            // OBTENER LOS DATOS QUE QUERRAMOS
                            int newUsers = rs.getInt("new_users");
                            int activeUsers = rs.getInt("active_users");
                            int avgUserUsage = rs.getInt("avg_usage_per_user");
                            Date dateQuery = rs.getDate("date");
                            Time timeQuery = rs.getTime("peek_hour");
                            setInfo(dateQuery, timeQuery, newUsers, activeUsers, avgUserUsage, country);
                        }
                    } else {
                        notificationLabel.setText("Date must have the correct format yyyy-MM-dd");
                    }
                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                }
            }   
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
        CreateBarChartImported(dateForGraph, peekHourForGraph, newUsersForGraph, activeUserForGraph, avgUsageForGraph, countryForGraph);
    }//GEN-LAST:event_countryQueryBtnActionPerformed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    private void importBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_importBtnActionPerformed
        // TODO add your handling code here:
        deleteInfo();
        int contadoraaa = 0;
        try {
            JFileChooser open = new JFileChooser();
            int option = open.showOpenDialog(this);
            File f1 = new File(open.getSelectedFile().getPath());
            // LEER EL ARCHIVO AQUI
            try (FileReader fr = new FileReader(f1)) {
                BufferedReader br = new BufferedReader(fr);
                String s;
                while((s=br.readLine())!=null) {
                    StringTokenizer st = new StringTokenizer(s, "\n");
                    while(st.hasMoreTokens()) {
                        StringTokenizer st2 = new StringTokenizer(st.nextToken(), "|");
                        while(st2.hasMoreTokens()) {
                            String actual = st2.nextToken();
                            System.out.println(contadoraaa +" "+ actual);
                            switch (contadoraaa) {
                                case 0:
                                    many_dateForGraph.add(actual);
                                    break;
                                case 1:
                                    many_newUsersForGraph.add(Integer.parseInt(actual));
                                    break;
                                case 2:
                                    many_activeUserForGraph.add(Integer.parseInt(actual));
                                    break;
                                case 3:
                                    many_peekHourForGraph.add(actual);
                                    break;
                                case 4:
                                    many_avgUsageForGraph.add(Integer.parseInt(actual));
                                    break;
                                case 5:
                                    many_countryForGraph.add(actual);
                                    break;
                                default:
                                    break;
                            }
                            contadoraaa++;
                        }
                        contadoraaa = 0;
                    }
                }
            } catch (FileNotFoundException ex) {
                Logger.getLogger(ProyectoFInalFrame.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(ProyectoFInalFrame.class.getName()).log(Level.SEVERE, null, ex);
            }
        } catch(HeadlessException ae) {
            System.out.println(ae);
        }
        CreateBarChartAllTime(many_newUsersForGraph, many_activeUserForGraph, many_avgUsageForGraph);
    }//GEN-LAST:event_importBtnActionPerformed

    private void dateQueryBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dateQueryBtnActionPerformed
        // TODO add your handling code here:
        deleteInfo();
        try {
            Connection conn = (Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/proyectofinal", "root", "");
            if (conn != null) {
                notificationLabel.setText("Connected to dataBase 'proyectofinal'");
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    
                    String date = dateInput.getText();
                    String query;
                    
                    if (isValidFormat("yyyy-MM-dd", date, Locale.ENGLISH)) {
                        query = "SELECT * FROM `user_stats` WHERE date='" + date + "';";
                        System.out.println(query);
                        
                        ResultSet rs = st.executeQuery(query);
                        while(rs.next()) {
                            // OBTENER LOS DATOS QUE QUERRAMOS
                            int newUsers = rs.getInt("new_users");
                            int activeUsers = rs.getInt("active_users");
                            int avgUserUsage = rs.getInt("avg_usage_per_user");
                            String country = rs.getString("country_most_users");
                            Date dateQuery = rs.getDate("date");
                            Time timeQuery = rs.getTime("peek_hour");
                            setInfo(dateQuery, timeQuery, newUsers, activeUsers, avgUserUsage, country);
                        }
                    } else {
                        notificationLabel.setText("Date must have the correct format yyyy-MM-dd");
                    }
                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                }
            }   
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
        CreateBarChartUnique(dateForGraph, peekHourForGraph, newUsersForGraph, activeUserForGraph, avgUsageForGraph, countryForGraph);
    }//GEN-LAST:event_dateQueryBtnActionPerformed

    private void monthQueryBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_monthQueryBtnActionPerformed
        // TODO add your handling code here:
        deleteInfo();
        try {
            Connection conn = (Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/proyectofinal", "root", "");
            if (conn != null) {
                notificationLabel.setText("Connected to dataBase 'proyectofinal'");
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    
                    String month = monthInput.getText();
                    monthForGraph = month;
                    String query;
                    
                    if (!"".equals(month)) {
                        query = "SELECT * FROM `user_stats` WHERE 1;";
                        System.out.println(query);
                        
                        ResultSet rs = st.executeQuery(query);
                        while(rs.next()) {
                            // OBTENER LOS DATOS QUE QUERRAMOS (que tengan el mes que estamos buscando)
                            Date dateQuery = rs.getDate("date");
                            int monthQuery = dateQuery.getMonth();
                            if (Integer.parseInt(month) == (monthQuery + 1)) {
                                
                                int newUsers = rs.getInt("new_users");
                                int activeUsers = rs.getInt("active_users");
                                int avgUserUsage = rs.getInt("avg_usage_per_user");
                                String country = rs.getString("country_most_users");
                                Time timeQuery = rs.getTime("peek_hour");
                                
                                many_dateForGraph.add(dateQuery.toString());
                                many_newUsersForGraph.add(newUsers);
                                many_activeUserForGraph.add(activeUsers);
                                many_peekHourForGraph.add(timeQuery.toString());
                                many_avgUsageForGraph.add(avgUserUsage);
                                many_countryForGraph.add(country);
                            }
                        }
                    } else {
                        notificationLabel.setText("Date must have the correct format yyyy-MM-dd");
                    }
                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                }
            }   
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
        CreateBarChartMonth(monthForGraph, many_newUsersForGraph, many_activeUserForGraph, many_avgUsageForGraph);
    }//GEN-LAST:event_monthQueryBtnActionPerformed

    private void queryAllBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_queryAllBtnActionPerformed
        // TODO add your handling code here:
        deleteInfo();
        try {
            Connection conn = (Connection) DriverManager.getConnection("jdbc:mariadb://localhost:3306/proyectofinal", "root", "");
            if (conn != null) {
                notificationLabel.setText("Connected to dataBase 'proyectofinal'");
                //crea la declaracion
                try (Statement st = conn.createStatement()) {
                    
                    String month = monthInput.getText();
                    String query;

                    query = "SELECT * FROM `user_stats` WHERE 1;";
                    System.out.println(query);
                    
                    ResultSet rs = st.executeQuery(query);
                    while(rs.next()) {
                        // OBTENER LOS DATOS QUE QUERRAMOS (que tengan el mes que estamos buscando)

                        Date dateQuery = rs.getDate("date");
                        int monthQuery = dateQuery.getMonth();
                        int newUsers = rs.getInt("new_users");
                        int activeUsers = rs.getInt("active_users");
                        int avgUserUsage = rs.getInt("avg_usage_per_user");
                        String country = rs.getString("country_most_users");
                        Time timeQuery = rs.getTime("peek_hour");
                        
                        many_dateForGraph.add(dateQuery.toString());
                        many_newUsersForGraph.add(newUsers);
                        many_activeUserForGraph.add(activeUsers);       
                        many_peekHourForGraph.add(timeQuery.toString());
                        many_avgUsageForGraph.add(avgUserUsage);
                        many_countryForGraph.add(country);
                    }

                } catch (SQLException ex) {
                    System.err.println(ex.getMessage());
                }
            }   
        } catch (SQLException ex) {
            System.err.println(ex.getMessage());
        }
        CreateBarChartAllTime(many_newUsersForGraph, many_activeUserForGraph, many_avgUsageForGraph) ;
    }//GEN-LAST:event_queryAllBtnActionPerformed

    private void uploadFileBtnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_uploadFileBtnActionPerformed
        // TODO add your handling code here:
        for (int i = 0; i < many_dateForGraph.size(); i++) {
            try {
                var con = DriverManager.getConnection("jdbc:mariadb://localhost:3306/proyectofinal", "root", "");
                if (con != null) {
                    String insert = "INSERT INTO user_stats VALUES ('"
                            + many_dateForGraph.get(i) + "', "
                            + many_newUsersForGraph.get(i) + ", "
                            + many_activeUserForGraph.get(i) + ", '"
                            + many_peekHourForGraph.get(i) + "', "
                            + many_avgUsageForGraph.get(i) + ", '"
                            + many_countryForGraph.get(i)   + "'); ";
                    System.out.println(insert);  		//imprimimos el Query
               
                    try (Statement stmt = con.createStatement()) {
                        stmt.executeUpdate(insert);      //Se actualiza el registro con los datos
                        stmt.close();  // Se cierran de los objetos 

                    } catch (SQLException ex) {
                        System.err.println(ex.getMessage());
                    }
                    con.close();
                    System.out.println("Captura OK"); //Mensaje de verificacion
                }
            } catch (SQLException ex) {
                Logger.getLogger(ProyectoFInalFrame.class.getName()).log(Level.SEVERE, null, ex);
            }   
        }
    }//GEN-LAST:event_uploadFileBtnActionPerformed

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
            java.util.logging.Logger.getLogger(ProyectoFInalFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ProyectoFInalFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ProyectoFInalFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ProyectoFInalFrame.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        
        

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ProyectoFInalFrame().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel chartPanel;
    private javax.swing.JTextField countryInput;
    private javax.swing.JButton countryQueryBtn;
    private javax.swing.JTextField dateInput;
    private javax.swing.JButton dateQueryBtn;
    private javax.swing.JButton exportBtn;
    private javax.swing.JButton importBtn;
    private javax.swing.JFrame jFrame1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenu jMenu3;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem3;
    private javax.swing.JMenuItem jMenuItem4;
    private javax.swing.JMenuItem jMenuItem5;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JTextField monthInput;
    private javax.swing.JButton monthQueryBtn;
    private javax.swing.JLabel notificationLabel;
    private javax.swing.JTabbedPane previewPane;
    private javax.swing.JButton queryAllBtn;
    private javax.swing.JButton uploadFileBtn;
    // End of variables declaration//GEN-END:variables
}

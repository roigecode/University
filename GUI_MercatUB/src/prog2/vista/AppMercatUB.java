/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.vista;

import java.io.File;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import prog2.controlador.Controlador;

/**
 *
 * @author allue
 */
public class AppMercatUB extends javax.swing.JFrame {

    /**
     * Creates new form AppMercatUB
     */
    public static Controlador controlador = new Controlador();

    /**
     * Constructor de AppMercatUB
     */
    public AppMercatUB() {
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

        btnArticles = new javax.swing.JButton();
        btnClients = new javax.swing.JButton();
        btnComandes = new javax.swing.JButton();
        btnGuardar = new javax.swing.JButton();
        btnCarregar = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Mercat UB");
        setBackground(new java.awt.Color(204, 255, 255));

        btnArticles.setBackground(new java.awt.Color(0, 0, 0));
        btnArticles.setFont(new java.awt.Font("Calibri", 0, 18)); // NOI18N
        btnArticles.setForeground(new java.awt.Color(255, 255, 255));
        btnArticles.setText("Articles");
        btnArticles.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                btnArticlesStateChanged(evt);
            }
        });
        btnArticles.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnArticlesActionPerformed(evt);
            }
        });

        btnClients.setBackground(new java.awt.Color(0, 0, 0));
        btnClients.setFont(new java.awt.Font("Calibri", 0, 18)); // NOI18N
        btnClients.setForeground(new java.awt.Color(255, 255, 255));
        btnClients.setText("Clients");
        btnClients.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnClientsActionPerformed(evt);
            }
        });

        btnComandes.setBackground(new java.awt.Color(0, 0, 0));
        btnComandes.setFont(new java.awt.Font("Calibri", 0, 18)); // NOI18N
        btnComandes.setForeground(new java.awt.Color(255, 255, 255));
        btnComandes.setText("Comandes");
        btnComandes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnComandesActionPerformed(evt);
            }
        });

        btnGuardar.setBackground(new java.awt.Color(0, 0, 0));
        btnGuardar.setFont(new java.awt.Font("Calibri", 0, 18)); // NOI18N
        btnGuardar.setForeground(new java.awt.Color(0, 255, 255));
        btnGuardar.setText("Guardar");
        btnGuardar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnGuardarActionPerformed(evt);
            }
        });

        btnCarregar.setBackground(new java.awt.Color(0, 0, 0));
        btnCarregar.setFont(new java.awt.Font("Calibri", 0, 18)); // NOI18N
        btnCarregar.setForeground(new java.awt.Color(255, 153, 51));
        btnCarregar.setText("Carregar");
        btnCarregar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCarregarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(200, 200, 200)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.CENTER)
                    .addComponent(btnArticles, javax.swing.GroupLayout.PREFERRED_SIZE, 141, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnClients, javax.swing.GroupLayout.PREFERRED_SIZE, 144, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnComandes, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnGuardar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(btnCarregar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(241, 241, 241))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(32, Short.MAX_VALUE)
                .addComponent(btnArticles)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnClients)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnComandes)
                .addGap(56, 56, 56)
                .addComponent(btnGuardar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(btnCarregar)
                .addGap(40, 40, 40))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * Aquest mètode és l'encarregat de la gestió del botó d'Articles
     * @param evt 
     */
    private void btnArticlesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnArticlesActionPerformed
        // TODO add your handling code here:
        FrmGestioArticles frmGA = new FrmGestioArticles();
        frmGA.setVisible(true);
    }//GEN-LAST:event_btnArticlesActionPerformed

    /**
     * Aquest mètode és l'encarregat de la gestió del botó de Clients
     * @param evt 
     */
    private void btnClientsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnClientsActionPerformed
        // TODO add your handling code here:
        FrmGestioClients frmGC = new FrmGestioClients();
        frmGC.setVisible(true);
    }//GEN-LAST:event_btnClientsActionPerformed

    /**
     * Aquest mètode és l'encarregat de la gestió del botó de Comandes
     * @param evt 
     */
    private void btnComandesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnComandesActionPerformed
        // TODO add your handling code here:
        FrmGestioComandes frmGCom = new FrmGestioComandes();
        frmGCom.setVisible(true);
    }//GEN-LAST:event_btnComandesActionPerformed

    /**
     * Aquest mètode és l'encarregat de la gestió del botó de Guardar
     * @param evt 
     */
    private void btnGuardarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnGuardarActionPerformed
        try {
            String ruta = JOptionPane.showInputDialog("Escriu la ruta del arxiu: ");
            controlador.guardar(ruta);
            JOptionPane.showMessageDialog(null, "Guardat amb èxit a " + ruta+".");
        } catch (MercatException ex) {
            Logger.getLogger(AppMercatUB.class.getName()).log(Level.SEVERE, null, ex);
        }

    }//GEN-LAST:event_btnGuardarActionPerformed

    /**
     * Aquest mètode és l'encarregat de la gestió del botó de Carregar
     * @param evt 
     */
    private void btnCarregarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCarregarActionPerformed

        // TODO add your handling code here:
        JFileChooser file = new JFileChooser();
        File workingDirectory = new File(System.getProperty("user.dir"));
        file.setCurrentDirectory(workingDirectory);
        file.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
        file.setFileHidingEnabled(false);

        if (file.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
            try {
                java.io.File f = file.getSelectedFile();
                controlador.carregar(f.getPath());
                JOptionPane.showMessageDialog(null, "Arxiu carregat amb èxit.");
            } catch (MercatException ex) {
                Logger.getLogger(AppMercatUB.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }//GEN-LAST:event_btnCarregarActionPerformed

    private void btnArticlesStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_btnArticlesStateChanged
        // TODO add your handling code here:
    }//GEN-LAST:event_btnArticlesStateChanged

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
            java.util.logging.Logger.getLogger(AppMercatUB.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(AppMercatUB.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(AppMercatUB.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(AppMercatUB.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new AppMercatUB().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnArticles;
    private javax.swing.JButton btnCarregar;
    private javax.swing.JButton btnClients;
    private javax.swing.JButton btnComandes;
    private javax.swing.JButton btnGuardar;
    // End of variables declaration//GEN-END:variables
}

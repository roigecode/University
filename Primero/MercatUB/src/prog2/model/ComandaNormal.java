/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.model;

import java.util.Date;

/**
 *
 * @author Roige
 */
public class ComandaNormal extends Comanda {
    
    /**
     * Constructor de la classe ComandaNormal
     * @param article
     * @param client
     * @param quantitat 
     */
    public ComandaNormal(Article article, Client client, int quantitat) {
        super(article, client, quantitat);
    }

    /**
     * Getter sobreescrit del tipus de comanda
     * @return "Normal"
     */
    @Override
    public String tipusComanda() {
        return "Normal";
    }

    /**
     * Mètode per saber si la comanda ha estat enviada
     * @return boolean
     */
    @Override
    public boolean comandaEnviada() {
        Date tempsActual = new Date();
        return (tempsActual.getTime() -  this.dataCreacio.getTime() >
                (this.article.getTempsEnviament()) * 60000);
    }

    /**
     * Mètode per saber si la comanda ha estat rebuda
     * @return boolean
     */
    @Override
    public boolean comandaRebuda() {
        Date tempsActual = new Date();
        long tempsEnviament = this.dataCreacio.getTime() + (this.article.getTempsEnviament()) * 60000;
        return (tempsActual.getTime() - tempsEnviament > 2*24*3600*1000);    
    }

    /**
     * Aquest mètode retorna el preu d'enviament d'una comanda normal
     * @return preuEnviament
     */
    @Override
    public float preuEnviament() {
           return 1 - this.client.descompteEnv()/100;
   }
    
}

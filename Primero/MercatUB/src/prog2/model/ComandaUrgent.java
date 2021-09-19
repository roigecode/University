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
public class ComandaUrgent extends Comanda{

    /**
     * Constructor de ComandaUrgent
     * @param article
     * @param client
     * @param quantitat 
     */
    public ComandaUrgent(Article article, Client client, int quantitat) {
        super(article, client, quantitat);
    }

    /**
     * Getter del tipus de comanda
     * @return "Urgent"
     */
    @Override
    public String tipusComanda() {
        return "Urgent";
    }

    /**
     * Mètode per saber si una comanda urgent ha estat enviada
     * @return boolean
     */
    @Override
    public boolean comandaEnviada() {
        Date tempsActual = new Date();
        return (tempsActual.getTime() -  this.dataCreacio.getTime() >
                (this.article.getTempsEnviament() / 2) * 60000);
    }

    /**
     * Mètode per saber si una comanda urgent ha estat rebuda
     * @return boolean
     */
    @Override
    public boolean comandaRebuda() {
        Date tempsActual = new Date();
        long tempsEnviament = this.dataCreacio.getTime() + (this.article.getTempsEnviament() / 2) * 60000;
        return (tempsActual.getTime() - tempsEnviament > 1 *24*3600*1000);    
    }

    /**
     * Mètode que retorna el preu d'enviament per una comanda urgent
     * @return preuEnviament
     */
    @Override
    public float preuEnviament() {
        return 4 * (1 - this.client.descompteEnv()/100);
    }
    
}

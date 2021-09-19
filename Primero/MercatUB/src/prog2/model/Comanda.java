/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.model;

import java.io.Serializable;
import java.util.Date;

/**
 *
 * @author Roige
 */
public abstract class Comanda implements Serializable {

    /**
     * Atributs de la classe comanda
     */
    protected Article article;
    protected Client client;
    protected int quantitatArticles;
    protected Date dataCreacio;

    /**
     * Constructor de la classe Comanda
     *
     * @param article
     * @param client
     * @param quantitat
     */
    public Comanda(Article article, Client client, int quantitat) {
        this.article = article;
        this.client = client;
        this.quantitatArticles = quantitat;
        this.dataCreacio = new Date();
    }

    /**
     * Getter de Data Creacio
     *
     * @return data creacio
     */
    public Date getDataCreacio() {
        return this.dataCreacio;
    }

    public Article getArticle() {
        return this.article;
    }

    /**
     * Aquest mètode calcula el preu a pagar per una comanda en funció del preu de l'article
     * i de quantitat d'aquests
     * @return preuTotal
     */
    public float calcPreu() {
        return article.getPreu() * this.quantitatArticles;
    }

    /**
     * Sobreescriptura del mètode toString
     * @return StringComanda
     */
    @Override
    public String toString() {
        return "Tipus=" + this.tipusComanda() + ", Article=" + article.getNom() + ", Client=" + client.getNomClient()
                + ", Quantitat=" + quantitatArticles + ", Data de creacio=" + dataCreacio.toString()
                + ", Enviat=" + this.comandaEnviada() + ", Rebuda=" + this.comandaRebuda() + ", Preu Articles=" + this.calcPreu()
                + ", Preu Enviament=" + this.preuEnviament();
    }

    public abstract String tipusComanda();

    public abstract boolean comandaEnviada();

    public abstract boolean comandaRebuda();

    public abstract float preuEnviament();
}

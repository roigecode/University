/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.model;

import java.io.Serializable;

/**
 *
 * @author Roige
 */
public class Article implements Serializable {

    /**
     * Atributos de la classe Article
     */
    protected String id;
    protected String nom;
    protected float preu;
    protected int tempsEnviament;
    protected boolean enviamentUrgent;

    /**
     * Constructor de la classe Article
     *
     * @param id
     * @param nom
     * @param preu
     * @param tempsEnviament
     * @param enviamentUrgent
     */
    public Article(String id, String nom, float preu, int tempsEnviament, boolean enviamentUrgent) {
        this.id = id;
        this.nom = nom;
        this.preu = preu;
        this.tempsEnviament = tempsEnviament;
        this.enviamentUrgent = enviamentUrgent;
    }

    /**
     * Getter de ID
     *
     * @return id
     */
    public String getId() {
        return id;
    }

    /**
     * Setter de ID
     *
     * @param id
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * Getter de Nom
     *
     * @return nom
     */
    public String getNom() {
        return nom;
    }

    /**
     * Setter de Nom
     *
     * @param nom
     */
    public void setNom(String nom) {
        this.nom = nom;
    }

    /**
     * Getter de Preu
     *
     * @return preu
     */
    public float getPreu() {
        return preu;
    }

    /**
     * Setter de preu
     *
     * @param preu
     */
    public void setPreu(float preu) {
        this.preu = preu;
    }

    /**
     * Getter de Temps d'Enviament
     *
     * @return tempsEnviament
     */
    public int getTempsEnviament() {
        return tempsEnviament;
    }

    /**
     * Setter de Temps d'Enviament
     *
     * @param tempsEnviament
     */
    public void setTempsEnviament(int tempsEnviament) {
        this.tempsEnviament = tempsEnviament;
    }

    /**
     * Getter de Enviament Urgent
     *
     * @return enviamentUrgent
     */
    public boolean isEnviamentUrgent() {
        return enviamentUrgent;
    }

    /**
     * Setter d'Enviament Urgent
     *
     * @param enviamentUrgent
     */
    public void setEnviamentUrgent(boolean enviamentUrgent) {
        this.enviamentUrgent = enviamentUrgent;
    }
    
    /**
     * Sobreescriptura del mètode toString
     * @return StringArticle
     */
    @Override
    public String toString() {
        return "Id=" + id + ", Nom=" + nom + ", Preu=" + preu
                + ", Temps fins enviament=" + tempsEnviament + ", Enviament Urgent=" + enviamentUrgent;
    }
}

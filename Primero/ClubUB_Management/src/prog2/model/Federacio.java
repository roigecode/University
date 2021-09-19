package prog2.model;
import java.io.*;

public class Federacio implements Serializable{

    // Atrib.
    public String nom;
    public float preu;

    /**
     * Constructor de la classe Federació
     * @param nom String amb el nom del soci
     * @param preu float amb el preu de la federació
     */
    public Federacio(String nom, float preu) {
        this.nom = nom;
        this.preu = preu;
    }

    // Getters
    public String getNom() {
        return this.nom;
    }

    public float getPreu() {
        return this.preu;
    }

    // Methods
    @Override
    public String toString() {
        return "Federació: Nom = " + nom + ", Preu = " + preu;

    }
}

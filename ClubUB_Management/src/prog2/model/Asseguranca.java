package prog2.model;
import java.io.*;

public class Asseguranca implements Serializable {

    // Atrib.
    public String tipus; // Bàsica/Completa
    public float preu;

    /**
     * Constructor de la classe Assegurança
     * @param tipus String amb el tipus
     * @param preu float amb el preu de la assegurança
     */
    public Asseguranca(String tipus, float preu) {
        this.tipus = tipus;
        this.preu = preu;
    }

    public String getTipus() {
        return this.tipus;
    }

    public float getPreu() {
        return this.preu;
    }

    // Setter
    public void setTipus(String tipus) {
        this.tipus = tipus;
    }

    // Methods
    @Override
    public String toString() {
        return "Assegurança: " + tipus + ", Preu = " + preu;

    }

}

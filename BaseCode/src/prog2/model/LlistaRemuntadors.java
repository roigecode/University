package prog2.model;

import java.util.ArrayList;

public class LlistaRemuntadors {

    // Atributs
    private final ArrayList<Remuntador> llista = new ArrayList<>();

    // Getter
    /**
     * Mètode que retorna la llista de remuntadors
     *
     * @return llista Llista de remuntadors
     */
    public ArrayList<Remuntador> getLlista() {
        return this.llista;
    }

    // Methods
    /**
     * Mètode que actualitza l'estat dels remuntadors en funció de la
     * meteorologia
     *
     * @param meteo Objecte de la classe Meteo
     */
    public void actualitzar(Meteo meteo) {
        // Se pueden usar functional operators para la iteración pero dificultarian
        // enormemente la lectura
        for (Remuntador remuntador : this.llista) {
            remuntador.actualitzar(meteo);
        }
    }
    
    /**
     * Mètode per afegir un remuntador a la llista
     * @param rm Objecte de la classe remuntador
     */
    public void afegirRemuntador(Remuntador rm) {
        this.llista.add(rm);
    }

    /**
     * Ens diu mitjançant una variable booleana si tots els remuntadors es
     * troben fora de servei
     *
     * @return boolean trobat que ens diu si tots són fora de servei
     */
    public boolean totsForaDeServei() {
        boolean trobat = true;
        for (Remuntador remuntador : this.llista) {
            // me deja acceder con .estat pq está declarado protected
            // no sé si es buena práctica, igual debería ser con un getter?
            if (remuntador.estat.equals("En Servei")) {
                trobat = false;
            }
        }
        return trobat;
    }

    /**
     * Retorna un String amb la llista de Remuntadors en l'estat demanat.
     *
     * @param estat Estat dels remuntadors que volem que ens siguin retornats
     * @return String text String amb els remuntadors demanats
     */
    public String llistarRemuntadors(String estat) {
        String text = "";

        // caso estat == "Tots" separado para no comprobar cada iteración
        if (estat.equals("Tots")) {
            for (Remuntador remuntador : this.llista) {
                text += remuntador.toString();
                text += "\n"; // salt de línia
            }
        } else {
            for (Remuntador remuntador : this.llista) {
                if (remuntador.estat.equals(estat)) {
                    text += remuntador.toString();
                    text += "\n"; // salt de línia  
                }
            }
        }

        return text;
    }

    /**
     * Mètode similar a un getter que ens retorna mitjançant un String anomenat
     * text els noms dels Remuntadors.
     *
     * @return String text noms dels Remuntadors dins la llista de remuntadors
     */
    public String getNoms() {
        String text = "";
        for (Remuntador remuntador : this.llista) {
            text += (remuntador.nom + " ");
        }
        return text;
    }

}

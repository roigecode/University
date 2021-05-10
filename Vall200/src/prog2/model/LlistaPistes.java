package prog2.model;

import java.util.ArrayList;

public class LlistaPistes {

    // Atributs
    private final ArrayList<Pista> llista = new ArrayList<>();

    // Getter
    /**
     * Mètode que retorna la llista de pistes de l'estació
     *
     * @return llista LLista de pistes de l'estació
     */
    public ArrayList<Pista> getLlista() {
        return this.llista;
    }

    // Methods
    /**
     * Mètode que crida per cada pista al seu propi mètode actualitzar()
     */
    public void actualitzar() {
        for (Pista pista : this.llista) {
            pista.actualitzar();
        }
    }

    /**
     * Afegeix una nova pista al ArrayList de pistes
     *
     * @param p Objecte Pista
     */
    public void afegirPista(Pista p) {
        this.llista.add(p);
    }

    /**
     * Retorna el nom de les pistes en cas d'existir.
     *
     * @param nom String que indica el nom de la pista
     * @return pista
     */
    public Pista getPista(String nom) {
        // suposarem que la pista demanada està en la llista
        for (Pista pista : this.llista) {
            if (pista.getNom().equals(nom)) {
                return pista;
            }
        }
        // si arribem aquí, la pista no esta en la llista
        // retornem null
        return null;
    }

    /**
     * Imprimeix les pistes corresponents a l'estat passat per paràmetre
     *
     * @param estat String que s'usarà per determinar quines pistes imprimir
     * @return text String de text amb les pistes demanades
     */
    public String llistarPistes(String estat) {
        String text = "";
        // caso estat == "Tots" separado para no comprobar cada iteración...
        if (estat.equals("Tots")) {
            for (Pista pista : this.llista) {
                // enunciado ambiguo, no sé si sumar el nombre de la pista o la descripción de la pista
                // por ahora dejo la despripción de la pista como en LlistaRemutnadors
                text += pista.toString();
                text += "\n"; // salt de línia
            }
        } else {
            for (Pista pista : this.llista) {
                // me deja acceder con .estat pq está declarado protected
                // no sé si es buena práctica, igual debería ser con un getter?
                if (pista.getEstatPista().equals(estat)) {
                    // enunciado ambiguo, no sé si sumar el nombre de la pista o la descripción de la pista
                    // por ahora dejo la despripción de la pista como en LlistaRemutnadors
                    text += pista.toString();
                    text += "\n"; // salt de línia  
                }
            }
        }

        return text;
    }

    /**
     * Calcula els km de pistes esquiables i el del conjunt total
     *
     * @param estat String que ens permet decidir amb quines pistes calcular els
     * km
     * @return suma float amb el nombre de kilometres desitjats
     */
    public float calculaKmsPistes(String estat) {
        float suma = 0;
        // caso estat == "Tots" separado para no comprobar cada iteración...
        if (estat.equals("Tots")) {
            for (Pista pista : this.llista) {
                suma += pista.getLongitud();
            }
        } else {
            for (Pista pista : this.llista) {
                if (pista.getEstatPista().equals(estat)) {
                    suma += pista.getLongitud();
                }
            }
        }

        return suma;
    }

}

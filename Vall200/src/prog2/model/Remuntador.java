package prog2.model;

public abstract class Remuntador {

    // Atributs
    protected String nom; //RMn
    protected String sector; // Nord, Sud, Inter-Sector
    protected String estat; // En servei, Fora de servei
    protected int limitVent;
    protected boolean afectaVisibilitat;

    /**
     * Constructor amb paràmetres de la classe Remuntador
     *
     * @param _nom String amb el nom del Remuntador
     * @param _sector Sector al que pertany el remuntador
     * @param _estat String per saber si el remuntador està obert o tancat
     * @param _limitVent Enter per determinar la velocitat de vent a la que
     * tanca el remuntador
     * @param _afectaVisibilitat Booleà per determinar si una visibilitat
     * "Dolenta" afecta al tancament del remuntador
     */
    public Remuntador(String _nom, String _sector, String _estat, int _limitVent, boolean _afectaVisibilitat) {
        this.nom = _nom;
        this.sector = _sector;
        this.estat = _estat;
        this.limitVent = _limitVent;
        this.afectaVisibilitat = _afectaVisibilitat;
    }

    // Setters i Getters
    /**
     * Mètode per fixar un estat pel Remuntador: "En servei" o "Fora de servei"
     *
     * @param estat String amb l'estat que volem que tingui el Remuntador
     */
    public void setEstat(String estat) {
        this.estat = estat;
    }

    /**
     * Mètode per saber si al Remuntador li afecta una visibilitat "Dolenta"
     *
     * @return afectaVisibilitat booleà per saber si li afecta una visibilitat
     * "Dolenta"
     */
    public boolean getAfectaVisibilitat() {
        return this.afectaVisibilitat;
    }

    /**
     * Mètode per obtindre el límit de vent que pot suportar un remuntador
     *
     * @return limitVent Enter del vent que pot suportar el remuntador
     */
    public int getLimitVent() {
        return this.limitVent;
    }

    // Methods
    /**
     * Mètode que serà usat a les classes filles
     *
     * @return String que ens indicarà per a cada classe filla el seu tipus
     */
    public abstract String tipus();

    /**
     * Aquest mètode actualitza la funcionalitat dels remuntadors en funció de
     * la visibilitat i de la velocitat del vent
     *
     * @param meteo Objecte meteo que s'usarà per determinar si s'han de tancar
     * remuntadors
     */
    public void actualitzar(Meteo meteo) {
        // S'hi pot accedir als atributs directament ja que ens trobem dins la 
        // mateixa classe pero ho fem amb getters i setters per si acàs

        // Canvi per visibilitat
        if (meteo.getVisibilitat().equals("Dolenta") && this.getAfectaVisibilitat()) {
            this.setEstat("Fora de Servei");
        } else {
            this.setEstat("En Servei");
        }

        // Canvi per velocitat del vent
        // desigualtat estricta (enunciado ambigu)
        if (meteo.getVelocitatVent() > this.getLimitVent()) {
            this.setEstat("Fora de Servei");
        } else {
            // aunq pueda estar en servei por el viento, puede que la visibilidad le afecte, entonces no puede estar en servei
            if (meteo.getVisibilitat().equals("Dolenta") && this.getAfectaVisibilitat()) {
                // return;
                // aqui siempre estar ya en fora de servei pero para prevenir lo vuelvo a modificar
                this.setEstat("Fora de Servei");
                return;
            }

            this.setEstat("En Servei");
        }

    }

    @Override
    public String toString() {
        return ("Remuntador: " + this.nom + ", Tipus: " + this.tipus()
                + ", Sector: " + this.sector + ", Estat: " + this.estat);
    }

}

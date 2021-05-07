package prog2.model;

public class Meteo {

    // Atributs
    private int velocitatVent;
    private String visibilitat;

    /**
     * Constructor amb paràmetres de la classe Meteo
     *
     * @param _velocitatVent enter que indica en km/h la velocitat del vent
     * @param _visibilitat String que ens diu si la visibilitat és "Bona" o
     * "Dolenta"
     */
    public Meteo(int _velocitatVent, String _visibilitat) {
        this.velocitatVent = _velocitatVent;
        this.visibilitat = _visibilitat;
    }

    //Setters:
    /**
     * Mètode per fixar la velocitat del vent, si hem obtingut una velocitat
     * erronea no fem res i imprimim per consola que hem tingut un error
     *
     * @param _velocitatVent enter que indica en km/h la velocitat del vent
     *
     */
    public void setVelocitatVent(int _velocitatVent) {
        if (_velocitatVent < 0) {
            System.out.println(">> Error! No s'ha pogut canviar la velocitat del vent (ha de ser un enter positiu, >0 km/h)");
            return;
        }
        this.velocitatVent = _velocitatVent;
        System.out.println(">> Velocitat del vent actualitzada a " + this.getVelocitatVent() + " km/h amb èxit.");
    }

    /**
     * Mètode per fixar la visibilitat, si hem obtingut una visibilitat erronea
     * no fem res i imprimim per consola que hem tingut un error
     *
     * @param _visibilitat enter que indica en km/h la velocitat del vent
     *
     */
    public void setVisibilitat(String _visibilitat) {
        // Implementado para el metodo Opcio 10 comentado al final de la clase VistaEstacioEsqui que usa Strings como parámetros de entrada.
        if (!(_visibilitat.equals("Dolenta") || _visibilitat.equals("Bona"))) {
            System.out.println(">> Error! No s'ha pogut canviar la visibilitat (ha de ser 'Bona' o 'Dolenta')");
            return;
        }
        this.visibilitat = _visibilitat;
    }

    // Getters
    /**
     * Retorna la velocitat del vent
     *
     * @return velocitatVent en km/h
     */
    public int getVelocitatVent() {
        return this.velocitatVent;
    }

    /**
     * Retorna la visibilitat
     *
     * @return visibilitat
     */
    public String getVisibilitat() {
        return this.visibilitat;
    }

    // Methods
    @Override
    public String toString() {
        return ("VelocitatVent: " + this.velocitatVent + ", visibilitat: "
                + this.visibilitat);
    }

}

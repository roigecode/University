package prog2.model;

public class Pista {

    // Atributs
    private String nom; // Pn
    private String sector; // Nord, Sud
    private String color; // Negra, Vermella, ...
    private float longitud;
    private String estatNeu; // Dura, Pols, Primaver
    private String estatPista; // Oberta, Tancada
    private final LlistaRemuntadors dependencies = new LlistaRemuntadors();

    /**
     * Constructor amb paràmetres de la classe Pista
     *
     * @param _nom String amb el nom de la pista
     * @param _sector String amb el sector al que pertany la pista
     * @param _color String amb el color de dificultat de la pista
     * @param _longitud float amb la longitud en km de la pista
     * @param _estatNeu String amb l'estat de la neu de la pista
     * @param _estatPista String per saber si la pista està oberta o tancada
     */
    public Pista(String _nom, String _sector, String _color, float _longitud, String _estatNeu, String _estatPista) {
        this.nom = _nom;
        this.sector = _sector;
        this.color = _color;
        this.longitud = _longitud;
        this.estatNeu = _estatNeu;
        this.estatPista = _estatPista;

    }

    // Setters & Getters
    /**
     * Aquest métode ens retorna el nom d'una pista si existeix. Sino llança una
     * excepció del tipus IllegalArgumentException
     *
     * @return String nom
     * @throws IllegalArgumentException quan la pista entrada per modificar és
     * inexistent (ex. P99)
     */
    public String getNom() {
        // Excepcion para la Opción 7 : SWITCH por si la pista NO existe:
        if (this.nom == null) {
            throw new IllegalArgumentException();
        } else {
            return nom;
        }
    }

    /**
     * Fixa el nom de la pista
     *
     * @param nom String amb el nom de la pista
     */
    public void setNom(String nom) {
        this.nom = nom;
    }

    /**
     * Mètode que retorna el sector on es troba la pista
     *
     * @return sector String amb el sector on es troba la pista
     */
    public String getSector() {
        return sector;
    }

    /**
     * Mètode per fixar el sector on es troba la pista
     *
     * @param sector String del sector on volem que es trobi la pista
     */
    public void setSector(String sector) {
        this.sector = sector;
    }

    /**
     * Mètode per saber el color de dificultat d'una pista
     *
     * @return color String amb el color de la pista
     */
    public String getColor() {
        return color;
    }

    /**
     * Mètode per fixar el color d'una pista
     *
     * @param color String amb el color a fixar per la pista
     */
    public void setColor(String color) {
        this.color = color;
    }

    /**
     * Mètode per saber la longitud d'una pista
     *
     * @return longitud float amb els km de longitud de la pista
     */
    public float getLongitud() {
        return longitud;
    }

    /**
     * Mètode per fixar la longitud d'una pista
     *
     * @param longitud Longitud de la pista en km
     */
    public void setLongitud(float longitud) {
        this.longitud = longitud;
    }

    /**
     * Mètode per saber l'estat de la neu d'una pista
     *
     * @return estatNeu String amb ñ'estat de la neu d'una pista
     */
    public String getEstatNeu() {
        return estatNeu;
    }

    /**
     * Mètode per fixar l'estat de la neu d'una pista
     *
     * @param estatNeu String de l'estat de la neu que volem fixar per la pista
     */
    public void setEstatNeu(String estatNeu) {
        this.estatNeu = estatNeu;
    }

    /**
     * Mètode que retorna l'estat de neu d'una pista
     *
     * @return String amb l'estat de neu de la pista
     */
    public String getEstatPista() {
        return estatPista;
    }

    /**
     * Mètode que fixa l'estat de la pista com a "Oberta" o "Tancada"
     *
     * @param estatPista String amb l'estat de la pista
     */
    public void setEstatPista(String estatPista) {
        this.estatPista = estatPista;
    }

    // Methods:
    /**
     * Aquest mètode actualitza l'etat d'una pista en funció de si els
     * Remuntadors dels que depen es troben oberts o tancats.
     */
    public void actualitzar() {
        if (this.dependencies.totsForaDeServei()) {
            this.estatPista = "Tancada";
        } else {
            this.estatPista = "Oberta";
        }
    }

    /**
     * Aquest mètode afegeix un remuntador adicional del qual dependrà la pista.
     *
     * @param rm Remuntador del qual volem fer que depengui la pista
     */
    public void afegirDependencia(Remuntador rm) {
        this.dependencies.getLlista().add(rm);
    }

    @Override
    public String toString() {
        return ("Pista: " + this.nom + ", Sector: " + this.sector + ", Color: " + this.color
                + ", Longitud: " + this.longitud + ", Estat de la Neu: " + this.estatNeu
                + ", Estat de la Pista: " + this.estatPista
                + ", Dependències: " + this.dependencies.getNoms());
    }

}

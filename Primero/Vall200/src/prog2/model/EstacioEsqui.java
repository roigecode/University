package prog2.model;

public class EstacioEsqui {

    // Atributs
    private final LlistaRemuntadors llistaRemuntadors = new LlistaRemuntadors();
    private final LlistaPistes llistaPistes = new LlistaPistes();
    private final String nom;
    private final Meteo meteo;

    /**
     * Constructor amb paràmetres de la Estacio d'Esqui
     *
     * @param _nom Nom de la estació
     * @param velocitatVent Enter que ens diu la velocitat del vent en km/h
     * @param visibilitat String que ens diu si la visibilitat es "Bona" o
     * "Dolenta"
     */
    public EstacioEsqui(String _nom, int velocitatVent, String visibilitat) {
        this.nom = _nom;
        this.meteo = new Meteo(velocitatVent, visibilitat);
    }

    // Getters
    /**
     * Metode que ens retorna la llista de remuntadors
     *
     * @return llistaRemuntadors Llista dels remuntadors de l'estació
     */
    public LlistaRemuntadors getLlistaRemuntadors() {
        return this.llistaRemuntadors;
    }

    /**
     * Mètode que retorna el nom de l'estació d'esquí
     *
     * @return nom Nom de l'estació d'esquí
     */
    public String getNom() {
        return this.nom;
    }

    public LlistaPistes getLlistaPistes() {
        return this.llistaPistes;
    }

    public Meteo getMeteo() {
        return this.meteo;
    }

    // Methods
    /**
     * Mètode que ens permet actualitzar els remuntadors i posteriorment les
     * pistes en funció de la meteorologia
     */
    public void actualitzar() {
        // Importante primero actualizar remuntadors antes que pistes por la relación
        // de dependencia:
        this.llistaRemuntadors.actualitzar(this.getMeteo());
        this.llistaPistes.actualitzar();

    }

    /**
     * Mètode per inicialitzar les dades de les pistes i els remuntadors de
     * l'estació
     */
    public void inicialitzaDadesVall2000() {
        // Hem hagut de canviar del codi de l'enunciat .add a .afegir, que és com ho especifica la resta de l'enunciat

        /* Remuntadors */
        Telecadira RM1 = new Telecadira("RM1", "Nord", "En Servei", 35, false);
        llistaRemuntadors.afegirRemuntador(RM1);
        Teleesqui RM2 = new Teleesqui("RM2", "Nord", "En Servei", 35, false);
        llistaRemuntadors.afegirRemuntador(RM2);
        Telecadira RM3 = new Telecadira("RM3", "Nord", "En Servei", 35, false);
        llistaRemuntadors.afegirRemuntador(RM3);
        Teleesqui RM4 = new Teleesqui("RM4", "Nord", "En Servei", 60, false);
        llistaRemuntadors.afegirRemuntador(RM4);
        Telecabina RM5 = new Telecabina("RM5", "Nord", "En Servei", 60, false);
        llistaRemuntadors.afegirRemuntador(RM5);
        CintaTransportadora RM6 = new CintaTransportadora("RM6", "Nord", "En Servei", 60, false);
        llistaRemuntadors.afegirRemuntador(RM6);
        Teleesqui RM7 = new Teleesqui("RM7", "Sud", "En Servei", 60, false);
        llistaRemuntadors.afegirRemuntador(RM7);
        Telecadira RM8 = new Telecadira("RM8", "Sud", "En Servei", 60, false);
        llistaRemuntadors.afegirRemuntador(RM8);
        Telecabina RM9 = new Telecabina("RM9", "Sud", "Fora de Servei", 60, true);
        llistaRemuntadors.afegirRemuntador(RM9);
        Teleferic RM10 = new Teleferic("RM10", "Inter-Sector", "En Servei", 60, false);
        llistaRemuntadors.afegirRemuntador(RM10);

        /* Pistes */
        Pista P1 = new Pista("P1", "Nord", "Negra", 0.8f, "Dura", "Oberta");
        llistaPistes.afegirPista(P1);
        Pista P2 = new Pista("P2", "Nord", "Vermella", 1.1f, "Dura", "Oberta");
        llistaPistes.afegirPista(P2);
        Pista P3 = new Pista("P3", "Nord", "Blava", 1.8f, "Pols", "Oberta");
        llistaPistes.afegirPista(P3);
        Pista P4 = new Pista("P4", "Nord", "Vermella", 1.2f, "Dura", "Oberta");
        llistaPistes.afegirPista(P4);
        Pista P5 = new Pista("P5", "Nord", "Blava", 2.1f, "Primavera", "Oberta");
        llistaPistes.afegirPista(P5);
        Pista P6 = new Pista("P6", "Nord", "Blava", 2.9f, "Pols", "Oberta");
        llistaPistes.afegirPista(P6);
        Pista P7 = new Pista("P7", "Nord", "Verda", 1.2f, "Primavera", "Oberta");
        llistaPistes.afegirPista(P7);
        Pista P8 = new Pista("P8", "Nord", "Verda", 0.9f, "Pols", "Oberta");
        llistaPistes.afegirPista(P8);
        Pista P9 = new Pista("P9", "Sud", "Vermella", 2.1f, "Dura", "Tancada");
        llistaPistes.afegirPista(P9);
        Pista P10 = new Pista("P10", "Sud", "Negra", 0.6f, "Primavera", "Tancada");
        llistaPistes.afegirPista(P10);
        Pista P11 = new Pista("P11", "Sud", "Vermella", 1.3f, "Primavera", "Oberta");
        llistaPistes.afegirPista(P11);
        Pista P12 = new Pista("P12", "Sud", "Blava", 1.9f, "Pols", "Oberta");
        llistaPistes.afegirPista(P12);

        /* Dependencies */
        P1.afegirDependencia(RM1);
        P2.afegirDependencia(RM2);
        P2.afegirDependencia(RM3);
        P3.afegirDependencia(RM5);
        P4.afegirDependencia(RM5);
        P5.afegirDependencia(RM5);
        P6.afegirDependencia(RM4);
        P7.afegirDependencia(RM5);
        P8.afegirDependencia(RM5);
        P8.afegirDependencia(RM6);
        P9.afegirDependencia(RM9);
        P10.afegirDependencia(RM9);
        P11.afegirDependencia(RM7);
        P11.afegirDependencia(RM9);
        P12.afegirDependencia(RM8);
    }

}

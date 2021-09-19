/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.controlador;

import prog2.model.Dades;
import prog2.vista.MercatException;
import java.util.List;

/**
 *
 * @author Roige
 */
public class Controlador {

    // Atributs:
    Dades dades;

    // Constructor:
    /**
     * Constructor del mètode Controlador
     */
    public Controlador() {
        dades = new Dades();
    }

    // Methods:
    /**
     * Aquest mètode afegeix un article fent una crida al mètode de Dades
     *
     * @param id
     * @param nom
     * @param preu
     * @param temps
     * @param admetUrgent
     * @throws MercatException
     */
    public void afegirArticle(String id, String nom, float preu, int temps, boolean admetUrgent) throws MercatException {
        dades.afegirArticle(id, nom, preu, temps, admetUrgent);
    }

    /**
     * Aquest mètode ens permet imprimit els articles ja existents
     *
     * @return dades.recuperaArticles();
     */
    public List<String> recuperaArticles() {
        return dades.recuperaArticles();
    }

    /**
     * Aquest mètode ens permet afegir un client a la llista de clients
     *
     * @param email
     * @param nom
     * @param adreca
     * @param esPremium
     * @throws MercatException
     */
    public void afegirClient(String email, String nom, String adreca, boolean esPremium) throws MercatException {
        dades.afegirClient(email, nom, adreca, esPremium);
    }

    /**
     * Aquest mètode ens permet imprimir la llista de clients
     *
     * @return dades.recuperaClients();
     */
    public List<String> recuperaClients() {
        return dades.recuperaClients();
    }

    /**
     * Aquest mètode ens permet afegir una comanda a la llista de comandes
     *
     * @param articlePos
     * @param clientPos
     * @param quantitat
     * @param esUrgent
     * @throws MercatException
     */
    public void afegirComanda(int articlePos, int clientPos, int quantitat, boolean esUrgent) throws MercatException {
        dades.afegirComanda(articlePos, clientPos, quantitat, esUrgent);
    }
    
    /**
     * Aquest mètode permet esborrar una comanda de la llista
     * @param position
     * @throws MercatException 
     */
    public void esborrarComanda(int position) throws MercatException {
        dades.esborrarComanda(position);
    }
    
    /**
     * Aquest mètode ens permet visualitzar totes les comandes existents
     * @return  dades.recuperaComandes();
     */
    public List<String> recuperaComandes() {
        return dades.recuperaComandes();
    }

    /**
     * Aquest mètode ens permet visualitzar només les comandes urgents
     * @return 
     */
    public List<String> recuperaComandesUrgents() {
        return dades.recuperaComandesUrgents();
    }

    // Persistencia
    
    // Se considera que el archivo es conocido que es como se haría en un caso real.
    
    /**
     * Aquest mètode ens permet guardar a un fitxer .dat
     * @throws MercatException 
     */
    public void guardar() throws MercatException {
        this.dades.guardaDades("./dades.dat");
    }

    /**
     * Aques mètode permet carregar les dades d'un fitxer .dat
     * @throws MercatException 
     */
    public void carregar() throws MercatException {
        Dades novesDades = Dades.carregaDades("./dades.dat");
        if (novesDades != null) {
            this.dades = novesDades;
        }
    }

}

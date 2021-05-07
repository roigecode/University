package prog2.model;

import prog2.vista.ExcepcioClub;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ClubUB {

    // Atrib.
    public float preuExcursio = 20;
    public float quotaMensual = 25;
    public float descompteExcursio = 0.2f;
    public float descompteQuota = 0.3f;
    LlistaSocis llistaSocis;

    /**
     * Constructor de la classe ClubUB
     */
    public ClubUB() {
        this.llistaSocis = new LlistaSocis(100);
    }

    // Getter
    public LlistaSocis getLlistaSocis() {
        return this.llistaSocis;
    }

    public float getPreuExcrusio() {
        return this.preuExcursio;
    }

    public float getQuotaMenusal() {
        return this.quotaMensual;
    }

    /**
     * Aquest mètode afegeix un nou soci federat
     * @param nom nom
     * @param DNI DNI
     * @param nomFed nom de la Federació
     * @param preuFed preu de la Federació
     */
    public void afegirSociFederat(String nom, String DNI, String nomFed, float preuFed) {
        try {
            SociFederat soci = new SociFederat(nom, DNI, nomFed, preuFed);
            this.llistaSocis.addSoci(soci);
        } catch (ExcepcioClub e) {
            System.out.println(e);
        }

    }

    /**
     * Aquest mètode afegeix un nou soci estandard
     * @param nom nom
     * @param DNI DNI
     * @param tipusAss tipus de la assegurança
     * @param preuAss preu de la assegurança
     */
    public void afegirSociEstandard(String nom, String DNI, String tipusAss, float preuAss) {
        try {
            SociEstandard soci = new SociEstandard(nom, DNI, tipusAss, preuAss);
            this.llistaSocis.addSoci(soci);
        } catch (ExcepcioClub e) {
            System.out.println(e);
        }
    }

       /**
     * Aquest mètode afegeix un nou soci junior
     * @param nom nom
     * @param DNI DNI
     */
    public void afegirSociJunior(String nom, String DNI) {
        try {
            SociJunior soci = new SociJunior(nom, DNI);
            this.llistaSocis.addSoci(soci);
        } catch (ExcepcioClub e) {
            System.out.println(e);
        }
    }

    /**
     * Aquest mètode fa una crida al mètode save de llistaSocis
     */
    public void guardar(){
        this.llistaSocis.save("./llistasocis.dat");
        System.out.println("Guardado con éxito en ./llistasocis.dat");
    }
    
    /**
     * Aquest mètode fa una crida al mètode load de llistaSocis
     */
    public void carregar(){
        LlistaSocis nova = this.llistaSocis.load("./llistasocis.dat");
        if(nova!=null){
            System.out.println(nova + " leyendo el fichero ./llistasocis.dat");
        }
        this.llistaSocis = nova;
        
    }
}

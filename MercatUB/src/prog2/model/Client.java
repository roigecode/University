/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.model;

import java.io.Serializable;

/**
 *
 * @author Roige
 */
public abstract class Client implements Serializable{
    /**
     * Atributs de la classe Client
     */
    protected String correuElectronic;
    protected String nomClient;
    protected String adreca;

    /**
     * Constructor de Client
     * @param correuElectronic
     * @param nomClient
     * @param adreca 
     */
    public Client(String correuElectronic, String nomClient, String adreca) {
        this.correuElectronic = correuElectronic;
        this.nomClient = nomClient;
        this.adreca = adreca;
    }

    public abstract String tipusClient();
    public abstract float calcMensual();
    public abstract float descompteEnv();
    
    /**
     * Getter de correu electrònic
     * @return correuElectronic
     */
    public String getCorreuElectronic() {
        return correuElectronic;
    }
    
    public void setCorreuElectronic(String correuElectronic) {
        this.correuElectronic = correuElectronic;
    }

    public String getNomClient() {
        return nomClient;
    }

    public void setNomClient(String nomClient) {
        this.nomClient = nomClient;
    }

    public String getAdreca() {
        return adreca;
    }

    public void setAdreca(String adreca) {
        this.adreca = adreca;
    }
    
    @Override
    public String toString(){
        return "Tipus="+ this.tipusClient() +", Email="+correuElectronic+", Nom="+nomClient+
                ", Adreça="+adreca+", Descompte Enviament="+this.descompteEnv()+
                ", Mensualitat="+this.calcMensual();
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.model;


/**
 *
 * @author Roige
 */
public class ClientPremium extends Client{

    /**
     * Constructor de ClientPremium
     * @param correuElectronic
     * @param nomClient
     * @param adreca 
     */
    public ClientPremium(String correuElectronic, String nomClient, String adreca) {
        super(correuElectronic, nomClient, adreca);
    }

    /**
     * Getter de tipus de client premium
     * @return 
     */
    @Override
    public String tipusClient() {
        return "Premium";
    }

    /**
     * Càlcul mensual del càlcul mensual del client premium
     * @return 4.0f
     */
    @Override
    public float calcMensual() {
        return 4.0f;
    }

    /**
     * Càlcul del descompte del client premium
     * @return 20.0f
     */
    @Override
    public float descompteEnv() {
        return 20.0f;
    }
}

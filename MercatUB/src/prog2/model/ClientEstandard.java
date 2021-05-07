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
public class ClientEstandard extends Client{
    
    /**
     * Constructor de Client Estandard
     * @param correuElectronic
     * @param nomClient
     * @param adreca 
     */
    public ClientEstandard(String correuElectronic, String nomClient, String adreca){
        super(correuElectronic, nomClient, adreca);
    }
    
    /**
     * Getter sobrescrit de tipus de Client
     * @return 
     */
    @Override
    public String tipusClient(){
        return "Estandard";
    }
    
    /**
     * Calcul mensual de ClientEstandard
     * @return 0f
     */
    @Override
    public float calcMensual(){
        return 0f;
    }
    
    /**
     * Calcul mensual del descompte del Client Estandard
     * @return 0f
     */
    @Override
   public float descompteEnv(){
       return 0f;
   } 
}

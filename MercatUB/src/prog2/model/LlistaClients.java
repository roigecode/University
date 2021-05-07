/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.model;

import java.io.Serializable;
import prog2.vista.MercatException;

/**
 *
 * @author Roige
 */
public class LlistaClients extends Llista<Client> implements Serializable{
    
    
    // En LlistaClients no es podran afegir dos clients amb el mateix
    // correu electrònic.
    @Override
    public void afegir(Client c) throws MercatException{
        if (this.contains(c)){
            throw new MercatException("\n· EXCEPCIÓ: No s'ha pogut afegir el client >> Client amb correu electrònic repetit!");
        }
        else{
            this.llista.add(c);
        }          
    }
    
    private boolean contains(Client client){
        for (Client c : this.llista){
            if (client.getCorreuElectronic().equals(c.getCorreuElectronic())){
                return true;
            }
        }
        return false;
            
    }
}

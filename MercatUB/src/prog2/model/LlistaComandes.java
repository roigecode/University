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
public class LlistaComandes extends Llista<Comanda> implements Serializable {
    
    // En LlistaComandes no es podrà afegir un objecte de tipus
    //ComandaUrgent si l'article que ha d'enviar-se no admet
    //enviament urgent
    @Override
    public void afegir(Comanda c) throws MercatException{
        if (c instanceof ComandaUrgent && !c.getArticle().isEnviamentUrgent()){
            throw new MercatException("\n· EXCEPCIÓ: No s'ha pogut afegir la comanda >> L'article hauria de ser urgent!");
        }
        else
            this.llista.add(c);
    }
   
}

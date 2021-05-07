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
public class LlistaArticles extends Llista<Article> implements Serializable {
   // En LlistaArticles no es podran afegir dos articles amb el
   // mateix identificador.
    @Override
    public void afegir(Article a) throws MercatException{
        if (this.contains(a)){
            throw new MercatException("\n· EXCEPCIÓ: No s'ha pogut afegir l'article >> Article amb identificador repetit!");
        }
        else{
            this.llista.add(a);
        }          
    }
    
    private boolean contains(Article article){
        for (Article a : this.llista){
            if (article.getId().equals(a.getId())){
                return true;
            }
        }
        return false;
            
    }
}

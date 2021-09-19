/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.model;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import prog2.vista.MercatException;


/**
 *
 * @author Roige
 */
public class Dades implements InDades, Serializable{
    
    /**
     * Atributs de la classe Dades
     */
    LlistaClients llistaClients;
    LlistaArticles llistaArticles;
    LlistaComandes llistaComandes;
    
    /**
     * Constructor de la classe Dades
     */
    public Dades() {
        llistaClients = new LlistaClients();
        llistaArticles = new LlistaArticles();
        llistaComandes = new LlistaComandes();
    }

    /**
     * Mètode que serveix per afegir un article
     * @param id
     * @param nom
     * @param preu
     * @param temps
     * @param admetUrgent
     * @throws MercatException 
     */
    @Override
    public void afegirArticle(String id, String nom, float preu, int temps, boolean admetUrgent) throws MercatException {
        Article article = new Article(id, nom, preu, temps, admetUrgent);
        this.llistaArticles.afegir(article);
    }

    // es mejor usar ArrayList que la clase Llista porque el metodo afegir de
    // la clase Llista tiene throws en la descripción y habria que modificar
    // este tambien.
    
    /**
     * Sobreescriptura del mètode per a recuperar articles
     * @return ArrayList d'articles
     */
    @Override
    public List<String> recuperaArticles() {
        ArrayList<String> arr = new ArrayList<>();
        for (Article a : this.llistaArticles.getArrayList()){
            arr.add(a.toString());
        }
        return arr;
    }

    /**
     * Sobreescriptura del mètode per afegir clients
     * @param email
     * @param nom
     * @param adreca
     * @param esPremium
     * @throws MercatException 
     */
    @Override
    public void afegirClient(String email, String nom, String adreca, boolean esPremium) throws MercatException {
        if (esPremium){
            ClientPremium client = new ClientPremium(email, nom, adreca);
            this.llistaClients.afegir(client);
            return;
        }
        else{
            ClientEstandard client = new ClientEstandard(email, nom, adreca);
            this.llistaClients.afegir(client);
        } 
    }

    /**
     * Sobreescriptura del mètode per recuperar Clients
     * @return ArrayList de clients
     */
    @Override
    public List<String> recuperaClients() {
        ArrayList<String> arr = new ArrayList<>();
        for (Client c : this.llistaClients.getArrayList()){
            arr.add(c.toString());
        }
        return arr;
    }

    /**
     * Sobreescriptura pel mètode d'afegir comandes
     * @param articlePos
     * @param clientPos
     * @param quantitat
     * @param esUrgent
     * @throws MercatException 
     */
    @Override
    public void afegirComanda(int articlePos, int clientPos, int quantitat, boolean esUrgent) throws MercatException {
        if (articlePos >= llistaArticles.getSize() || clientPos >= llistaClients.getSize() || articlePos < 0 || clientPos < 0){
            throw new MercatException("\n· EXCEPCIÓ: No s'ha pogut afegir la comanda >> Index incorrecte");
        }
        
        if (esUrgent){
            ComandaUrgent comanda = new ComandaUrgent(this.llistaArticles.getAt(articlePos), this.llistaClients.getAt(clientPos), quantitat); 
            this.llistaComandes.afegir(comanda);
        }
        else{
            ComandaNormal comanda = new ComandaNormal(this.llistaArticles.getAt(articlePos), this.llistaClients.getAt(clientPos), quantitat);
            this.llistaComandes.afegir(comanda);
        }
    }

    /**
     * Sobreescriptura del mètode per esborrar comandes
     * @param position
     * @throws MercatException 
     */
    @Override
    public void esborrarComanda(int position) throws MercatException {
        
        if(llistaComandes.isEmpty()){
            throw new MercatException("\n· EXCEPCIÓ: No s'ha pogut esborrar la comanda >> Llista de Comandes buida");
        }else if (position >= llistaComandes.getSize() || position < 0){
            throw new MercatException("\n· EXCEPCIÓ: No s'ha pogut esborrar la comanda >> Index incorrecte");
        }else if (this.llistaComandes.getAt(position).comandaEnviada()){
            throw new MercatException("\n· EXCEPCIÓ: No s'ha pogut esborrar la comanda >> Comanda ja enviada");
        }else{
            this.llistaComandes.esborrar(this.llistaComandes.getAt(position));
        }
    }

     /**
     * Sobreescriptura del mètode per recuperar Comandes
     * @return ArrayList de comandes
     */
    @Override
    public List<String> recuperaComandes() {
        ArrayList<String> arr = new ArrayList<>();
        for (Comanda comanda : this.llistaComandes.getArrayList()){
            arr.add(comanda.toString());
        }
        return arr;   
    }

    /**
     * Sobreescriptura del mètode recuperaComandesUrgents()
     * @return ArrayList de comandes urgents
     */
    @Override
    public List<String> recuperaComandesUrgents() {
        ArrayList<String> arr = new ArrayList<>();
        for (Comanda comanda : this.llistaComandes.getArrayList()){
            if (comanda instanceof ComandaUrgent){
                arr.add(comanda.toString());   
            }
        }
        return arr; 
    }
    
    
    // Persistencia
    /**
     * Mètode per a guardar les dades a un fitxer .dat
     * @param camiDesti
     * @throws MercatException 
     */
    public void guardaDades(String camiDesti) throws MercatException{
        File file = new File(camiDesti);
        FileOutputStream fout = null;
        
        try{
            fout = new FileOutputStream(file);
            ObjectOutputStream oos = new ObjectOutputStream(fout);
            oos.writeObject(this);
        }catch(IOException e){
            throw new MercatException(e.getMessage()); 
        }finally{
            try{
                fout.close();
            }catch (IOException ex){
                throw new MercatException(ex.getMessage());
            }
        }    
    }
    
    
    public static Dades carregaDades(String camiOrigen) throws MercatException{
        File file = new File(camiOrigen);
        Dades dades = null;
        FileInputStream fin = null;
        
        try{
            fin = new FileInputStream(file);
            ObjectInputStream ois = new ObjectInputStream(fin);
            dades = (Dades) ois.readObject();
        }catch (IOException | ClassNotFoundException e){
            throw new MercatException(e.getMessage());  
        } finally{
            try{
                fin.close();  
            }catch(IOException ex){
                throw new MercatException(ex.getMessage());
            }
        }
        return dades;
    }
}

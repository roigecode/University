/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.model;

import prog2.vista.ExcepcioClub;

/**
 * Interfície InSoci
 * @author laura
 */
public interface InSoci {
    
    public void setNom(String nom);
    public String getNom();
    public void setDNI(String dni);
    public String getDNI();
    
    
    // per calcular el preu de l'excursio i de la quota per a un soci federat
    // cal tenir la info dels descomptes. El metode per calcularles no passa
    // aquesta informacio per argument. En lenunciat ens fan definir auqesta
    // info com atributs de la clase clubUb. Podriem accedir a ella des d'aqui
    // fent extends ClubUB (no tindria gaire sentit), passantla com a argument
    // (llavors modificariem la signatura del metode que ens ha esta donada per
    // lenunciat) o redefinintla aqui (seria molt redundant). Hem optat per la
    // segona opcio.
    
    public float calculaQuota(float quotaBase) throws ExcepcioClub;
    
    public abstract float calculaPreuExcursio(float preuExcursioBase) throws ExcepcioClub;
    
    public abstract String tipus();
    
}

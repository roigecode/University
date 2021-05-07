package prog2.model;
// necesito hacer import de esto aqui tambien porque pongo el throws de la
// function signature como en la interface
import prog2.vista.ExcepcioClub; 
import java.io.*;

public abstract class Soci implements InSoci, Serializable {
    
    // Atrib.
    String nom;
    String DNI;
    
  
    // Constr.
    
    /**
    * Constructor de la classe soci
    * @param nom Nom
    * @param DNI DNI
    */
    public Soci(String nom, String DNI){
        this.nom = nom;
        this.DNI = DNI;
    }

    // Methods
    @Override
    public void setNom(String nom){
        this.nom = nom;
    }
    
    @Override
    public String getNom(){
        return this.nom;
    }
    
    @Override
    public void setDNI(String dni){
        this.DNI = dni;
    }
    
    @Override
    public String getDNI(){
        return this.DNI;
    }
    
    /**
     * Aquest mètode calcula la quota d'un soci
     * @param quotaBase 25€ Quota base per tots els socis
     */
    @Override
    public float calculaQuota(float quotaBase) /*throws ExcepcioClub*/{
        // quotaBase per socis junior o estandard, per federats apliquem
        // descompte (fem override per classe SociFederat)
        return quotaBase;  
    }
    
    @Override
    /**
     * Aquest mètode és abstracte ja que s'implementa a les respectives classes
     * @param preuExcursioBase 25€
     */
    public abstract float calculaPreuExcursio(float preuExcursioBase) /*throws ExcepcioClub*/;
    
    /**
     * Override del metode toString()
     */
    @Override
    public String toString(){
        // per socis junior aquesta es tota la info
        // per la resta de socis fem override en les respectives classes
        // per mostrar la informacio espcifica daquests
        return "Nom = " + this.nom + ", DNI: " + this.DNI + ".";
    }
    
    /**
     * Aquest mètode comprova si un soci és igual a un altre
     * @param altre Objecte de tipus soci amb el que es compararà
     * @return boolea
     */
    public boolean equals(Soci altre){
        return this.DNI.equals(altre.DNI);
        
    }
    
    /**
     * Mètode abstracte que es sobreescriu a les classes filles
     */
    @Override
    public abstract String tipus();
    
    public abstract void setTipusAsseguranca(String tipus) throws ExcepcioClub;
}

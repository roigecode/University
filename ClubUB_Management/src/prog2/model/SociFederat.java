package prog2.model;
import prog2.vista.ExcepcioClub;

public class SociFederat extends Soci {
    
    // Atrib.
    public Federacio federacio;
    // hem considerat necessari tenir aquestes dades com a membres de SociFederat
    public float descompteExcursio = 0.2f;
    public float descompteQuota = 0.3f;
    
    /**
     * Constructor de la classe SociFederat
     * @param nom nom
     * @param DNI DNI
     * @param nomFed String amb el nom de la federació
     * @param preuFed float amb el preu de la federació
     * @throws ExcepcioClub
     */
    public SociFederat(String nom, String DNI, String nomFed, float preuFed)throws ExcepcioClub{
        super(nom, DNI);
        federacio = new Federacio(nomFed, preuFed);
        comprova();      
    }
    
    /**
     * Aquest mètode retorna una excepció si el preu de la federació és inferior a 100
     * @throws ExcepcioClub
     */
    private void comprova()throws ExcepcioClub {
        if (federacio.getPreu() < 100){
            throw new ExcepcioClub("EXCEPTION: El preu de la federació no és correcte!");
        }
        
    }
    
    @Override
    public String toString(){
        return (super.toString() + " " + this.federacio.toString() + ".");
    }
    
     /**
     * Aquest mètode calcula el preu de les excursions per a un soci federat
     * @param preuExcursioBase 20€
     * @return preuExcursio descomptat
     */
    @Override
    public float calculaPreuExcursio(float preuExcursioBase) /*throws ExcepcioClub*/{
        return preuExcursioBase * (1 - descompteExcursio);
        
        
    }
    
    /**
     * Aquest mètode calcula la quota per a un soci federat
     * @param quotaBase 25€
     * @return quotaBase descomptada
     */
    @Override
    public float calculaQuota(float quotaBase) /*throws ExcepcioClub*/{
        return quotaBase * (1 - descompteQuota);
        
    }
    
    @Override
    public String tipus(){
        return "federat";
    }
    
    /** Setter del tipus d'asseguraça
     * @throws ExcepcioClub Aquest soci no té assegurança
     */
    @Override
    public void setTipusAsseguranca(String tipus) throws ExcepcioClub{
        throw new ExcepcioClub("EXCEPTION: Aquest soci no té assegurança!");
    }
    
    
    
}

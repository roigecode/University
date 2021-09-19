package prog2.model;
import prog2.vista.ExcepcioClub;

public class SociJunior extends Soci {
    
    /**
     * Constructor de la classe SociJunior
     * @param nom nom
     * @param DNI DNI
     */
    public SociJunior (String nom, String DNI){
        super(nom, DNI);
    }
    
    /**
     * Aquest mètode calcula el preu d'una excursió per un Soci Junior, és a dir
     * , retorna sempre 0(€).
     * @param preuExcursioBase 25€ per defecte
     */
    @Override
    public float calculaPreuExcursio(float preuExcursioBase) /*throws ExcepcioClub*/{
        return 0f;
    }
    
    /**
     * Aquest mètode retorna el tipus de soci, és a dir, junior.
     * @return junior
     */
    @Override
    public String tipus(){
        return "junior";
    }
    
    /**
     * Aquest mètode llença una excepció
     * @throws ExcepcioClub El soci no té assegurança
     */
    @Override
    public void setTipusAsseguranca(String tipus) throws ExcepcioClub{
         throw new ExcepcioClub("EXCEPTION: Aquest soci no té assegurança!");
    }
    
}

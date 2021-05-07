package prog2.model;
import prog2.vista.ExcepcioClub;

public class SociEstandard extends Soci{
    
    // Atrib.
    public Asseguranca asseguranca;
    
    // Constr.
      /**
     * Constructor de SociEstandard
     * @param nom Nom
     * @param DNI DNI
     * @param tipusAss Tipus d'assegurança
     * @param preuAss Preu de la assegurança
     * @throws ExcepcioClub
     */
    public SociEstandard(String nom, String DNI, String tipusAss, float preuAss) throws ExcepcioClub{
        super(nom, DNI);
        asseguranca = new Asseguranca(tipusAss, preuAss);
        comprova();
    }
    
    // Methods
    
    /**
     * Aquest metode comprova que l'assegurança d'un soci és o Basica o Completa
     * @throws ExcepcioClub Tipus d'assegurança incorrecte
     */
    private void comprova()throws ExcepcioClub {
        if (this.asseguranca.getTipus().equals("Basica") || this.asseguranca.getTipus().equals("Completa")){
        }
        else{
            throw new ExcepcioClub("EXCEPTION: El tipus d'assegurança no és correcte - Has introduit:" + asseguranca.getTipus());           
        }
    }
    
    @Override
    public String toString(){
        return (super.toString() + " " + this.asseguranca.toString() + ".");
    }
    
     /**
     * Aquest metode calcula el preu de les excursions
     * @param preuExcursioBase preu base de les excursions: 25€
     * @return Retorna el preu total de les excursions
     */
    @Override
    public float calculaPreuExcursio(float preuExcursioBase) /*throws ExcepcioClub*/{
        return preuExcursioBase + this.asseguranca.getPreu();
    }
    
     /**
     * Aquest metode retorna el tipus de soci que és
     * @return Tipus del soci
     */
    @Override
    public String tipus(){
        return "estandard";
    }
   
  /**
     * Aquest metode llença una excepció si l'assegurança que s'intenta 
     * afegir a un soci NO és o Basica o Completa
     * @throws ExcepcioClub Tipus d'assegurança incorrecte
     */
    @Override
    public void setTipusAsseguranca(String tipus) throws ExcepcioClub{
        if (tipus.equals("Basica") || tipus.equals("Completa")){
        }
        else{
            throw new ExcepcioClub("prog2.vista.ExcepcioClub: EXCEPTION: El tipus d'assegurança no és correcte");
        }
        asseguranca.setTipus(tipus);   
    }
}

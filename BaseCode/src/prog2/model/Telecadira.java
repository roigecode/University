package prog2.model;

public class Telecadira extends Remuntador {

    /**
     * Constructor amb paràmetres de la classe filla de Remuntador
     *
     * @param _nom Nom de la Telecadira
     * @param _sector Sector al que pertany
     * @param _estat Estat de la Telecadira
     * @param _limitVent Velocitat màxima de vent que suporta
     * @param _afectaVisibilitat Booleà per saber si amb visibilitat Dolenta
     * tanca
     */
    public Telecadira(String _nom, String _sector, String _estat, int _limitVent, boolean _afectaVisibilitat) {
        super(_nom, _sector, _estat, _limitVent, _afectaVisibilitat);
    }

    // Methods
    @Override
    public String tipus() {
        return "Telecadira";
    }

}

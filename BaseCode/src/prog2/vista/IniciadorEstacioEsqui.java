/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.vista;

/**
 *
 * @author ricardo.marques
 * @author martinez.ignacio
 * @author roige.alejandro
 */
public class IniciadorEstacioEsqui {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Definim el nom i les condicions meteorologiques inicials a l'estació

        /**
         * Las condiciones iniciales no se corresponden a las del enunciado las
         * cambiamos a las que dicta el enunciado para que asi el estado inicial
         * de los objetos pista/remuntador inicializados por la función que da
         * el enunciado sean correctos
         *
         * Actualment, a la Vall2000, el vent és de 10 Km/h, mentre que la
         * visibilitat és Dolenta, el que explica el remuntador RM9 fora de
         * servei i les pistes P9 i P10 tancades.
         */
        String nomEstacio = "Vall2000";
        int velocitatVent = 10;
        String visibilitat = "Dolenta";

        // Creem un objecte de la vista i li passem el nom i condicions meteorologiques inicials a l'estació
        //////////////////////////////////////////
        VistaEstacioEsqui vistaEstacioVall2000 = new VistaEstacioEsqui(nomEstacio, velocitatVent, visibilitat);

        // Inicialitzem l'execució de la vista
        vistaEstacioVall2000.gestioEstacio();
    }

}

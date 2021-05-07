/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prog2.vista;

import java.util.Scanner;
// N
import prog2.model.EstacioEsqui;

/**
 * @author ricardo.marques
 * @author roige.alejandro
 * @author martinez.ignacio
 */
public class VistaEstacioEsqui {

    /* Atributs */
    private final EstacioEsqui estacio;

    /* Constructor de la Vista*/
    ///////////////////////////////////////////////////////////////////////////////////////////
    /**
     * Constructor amb paràmetres de la classe VistaEstacioEsqui
     *
     * @param nomEstacio Nom de l'estació d'Esqui
     * @param velocitatVent Enter que ens mostra la velocitat del vent
     * @param visibilitat String per saber si la visibilitat és "Bona" o
     * "Dolenta"
     */
    public VistaEstacioEsqui(String nomEstacio, int velocitatVent, String visibilitat) {
        this.estacio = new EstacioEsqui(nomEstacio, velocitatVent, visibilitat);
        this.estacio.inicialitzaDadesVall2000();
    }

    ;
       
    /* Métodes */    

    
    /**
     * Crida al metode d'actualitzar de l'estació. Usat quan es canvia la meteorologia
     */
    public void actualitzar() {
        this.estacio.actualitzar();
    }

    /**
     * Mètode per a la gestió de l'estació
     */
    public void gestioEstacio() {
        // Creació d'un objecte per a la lectura de la informació introduida per
        // teclat.
        Scanner sc = new Scanner(System.in);
        // Cridar a la funció que gestiona el menú
        gestioMenu(sc);
    }

    /* ******************************************** */
 /* Gestion, Opciones y Descripcion del Menu (M) */
 /* ******************************************** */
    private static enum OpcionesMenu {
        M_Opcion_1_ListarPistas,
        M_Opcion_2_ListarPistasAbiertas,
        M_Opcion_3_ListarPistasCerradas,
        M_Opcion_4_ListarRemontadores,
        M_Opcion_5_ListarRemontadoresEnServicio,
        M_Opcion_6_ListarRemontadoresFueraServicio,
        M_Opcion_7_ModificarEstadoNieve,
        M_Opcion_8_CalcularTotalKms,
        M_Opcion_9_Modificar_Vent,
        M_Opcion_10_Modificar_Visibilitat,
        M_Opcion_11_Report_Meteo,
        M_Opcion_12_Salir
    };

    // Descripcion de las opciones del menu principal
    private static final String[] descMenu = {
        "Llistar la informació de totes les pistes", // Opcion 1
        "Llistar la informació de les pistes obertes", // Opcion 2
        "Llistar la informació de les pistes tancades", // Opcion 3
        "Llistar la informació de tots els remuntadors mecànics", // Opcion 4
        "Llistar la informació dels remuntadors en servei", // Opcion 5
        "Llistar la informació dels remuntadors fora de servei", // Opcion 6
        "Modificar l'estat de la neu d'una pista", // Opcion 7
        "Calcular i mostrar el total de kilometres de pistes i de pistes obertes", // Opcion 8
        "Modificar la velocitat del vent", // Opcion 9
        "Modificar la visibilitat", // Opcion 10
        "Mostrar les condicions meteorologiques actuals", // Opcion 11
        "Sortir del gestor de l'estació" // Opcion 12
    };

    /* Funcion que gestiona el menu principal de la aplicacion
     * Tiene 3 pasos principales:
     *   1. Crear el objeto que representa (contiene) el menu
     *   2. Asignar las descripciones del menu
     *   3. Bucle donde se trata la opcion seleccionada por el usuario
     * @param sc
     */
    public void gestioMenu(Scanner sc) {
        // Creación del objeto que representa el menu. El primer argumento del contructor es el nombre del menu
        Menu<OpcionesMenu> menuEstacio = new Menu<>("Menu " + this.estacio.getNom(), OpcionesMenu.values());
        //Menu<OpcionesMenu> menuEstacio = new Menu<>("Menu " + estacio.getNomEstacio(), OpcionesMenu.values());

        // Assignar una descripción a cada una de las opciones
        //  - OPCIONAL - Por defecto enseña el nombre de la opción
        menuEstacio.setDescripcions(descMenu);

        // Variable (de tipo enumerado igual a las opciones del menu) que contiene la opcion escogida
        OpcionesMenu opcionMenu;

        // Lançar el bucle principal de la aplicación
        do {
            menuEstacio.mostrarMenu();
            opcionMenu = menuEstacio.getOpcio(sc);

            switch (opcionMenu) {
                case M_Opcion_1_ListarPistas:
                    llistarPistes();
                    break;
                case M_Opcion_2_ListarPistasAbiertas:
                    llistarPistesObertes();
                    break;
                case M_Opcion_3_ListarPistasCerradas:
                    llistarPistesTancades();
                    break;
                case M_Opcion_4_ListarRemontadores:
                    llistarRemuntadors();
                    break;
                case M_Opcion_5_ListarRemontadoresEnServicio:
                    llistarRemuntadorsEnServei();
                    break;
                case M_Opcion_6_ListarRemontadoresFueraServicio:
                    llistarRemuntadorsForaServei();
                    break;
                case M_Opcion_7_ModificarEstadoNieve:
                    modificarEstatNeuPista(sc);
                    break;
                case M_Opcion_8_CalcularTotalKms:
                    calcularTotalKM();
                    break;
                case M_Opcion_9_Modificar_Vent:
                    modificarVelocitatVent(sc);
                    break;
                case M_Opcion_10_Modificar_Visibilitat:
                    modificarVisibilitat(sc);
                    break;
                case M_Opcion_11_Report_Meteo:
                    condicionsMeteorologiques();
                    break;
            }

        } while (opcionMenu != OpcionesMenu.M_Opcion_12_Salir);
    }

    //////////////////////////
    ///      OPCIONS       ///
    //////////////////////////
    
    // No es comenten els métodes ja que són autodescriptius.
    
    /**
     * OPCIO 1: Mostra un llistat de totes les pistes
     */
    public void llistarPistes() {
        System.out.println(this.estacio.getLlistaPistes().llistarPistes("Tots"));
    }

    /**
     * OPCIO 2: Mostra un llistat de les pistes obertes
     */
    public void llistarPistesObertes() {
        System.out.println(this.estacio.getLlistaPistes().llistarPistes("Oberta"));
    }

    /**
     * OPCIO 3: Mostra un llistat de les pistes tancades
     */
    public void llistarPistesTancades() {
        System.out.println(this.estacio.getLlistaPistes().llistarPistes("Tancada"));
    }

    /**
     * OPCIO 4: Mostra un llistat de tots els remuntadors
     */
    public void llistarRemuntadors() {
        System.out.println(this.estacio.getLlistaRemuntadors().llistarRemuntadors("Tots"));
    }

    /**
     * OPCIO 5: Mostra un llistat dels remuntadors en servei
     */
    public void llistarRemuntadorsEnServei() {
        System.out.println(this.estacio.getLlistaRemuntadors().llistarRemuntadors("En Servei"));
    }

    /**
     * OPCIO 5: Mostra un llistat dels remuntadors fora de servei
     */
    public void llistarRemuntadorsForaServei() {
        System.out.println(this.estacio.getLlistaRemuntadors().llistarRemuntadors("Fora de Servei"));
    }

    /**
     * OPCIO 7 - AMB EXCEPCIONS: Modifica l'estat de neu d'una pista
     *
     * @param sc Scanner per llegir dades d'entrada per consol·la
     */
    public void modificarEstatNeuPista(Scanner sc) {
        String opcio_pista;
        int eleccio;

        System.out.println("Indica el nom de la pista (ex. P11) de la que vols modificar l'estat de la neu: ");
        opcio_pista = sc.nextLine();

        // Comprobación de que la pista existe implementada en el metodo pista.getNom(); 
        // hace throw de una IllegalArgumentException();
        try {
            System.out.println(">>> Modificant: " + this.estacio.getLlistaPistes().getPista(opcio_pista).getNom() + " l'estat actual de la seva neu és: "
                    + this.estacio.getLlistaPistes().getPista(opcio_pista).getEstatNeu());

            System.out.println("A quin estat de neu vols modificar-ho? \n \t (1) Pols \n \t (2) Primavera \n \t (3) Dura");
            eleccio = sc.nextInt();

            // Switch para no tener que hacer más Error Handling sobre el input:
            switch (eleccio) {
                case 1:
                    this.estacio.getLlistaPistes().getPista(opcio_pista).setEstatNeu("Pols");
                    System.out.println(">> Estat de la neu a la pista: " + this.estacio.getLlistaPistes().getPista(opcio_pista).getNom() + " actualitzat a: Pols amb èxit.");
                    break;
                case 2:
                    this.estacio.getLlistaPistes().getPista(opcio_pista).setEstatNeu("Primavera");
                    System.out.println(">> Estat de la neu a la pista: " + this.estacio.getLlistaPistes().getPista(opcio_pista).getNom() + " actualitzat a: Primavera amb èxit.");
                    break;
                case 3:
                    this.estacio.getLlistaPistes().getPista(opcio_pista).setEstatNeu("Dura");
                    System.out.println(">> Estat de la neu a la pista: " + this.estacio.getLlistaPistes().getPista(opcio_pista).getNom() + " actualitzat a: Dura amb èxit.");
                    break;
                default:
                    System.out.println(">> Opció escollida incorrecte, tria entre 1, 2 o 3.");
            }
        } catch (Exception pista_incorrecta) {
            System.out.println(">> Error! Nom de pista incorrecte.");
        }
    }

    /**
     * OPCIO 8 Calcula el total de km esquiables i els km totals de pistes de l'estació
     */
    public void calcularTotalKM() {
        System.out.println("Kilómetres totals de les pistes de l'estació " + this.estacio.getNom() + ": "
                + this.estacio.getLlistaPistes().calculaKmsPistes("Tots") + " km.");

        System.out.println("Kilómetres esquiables de l'estació " + this.estacio.getNom() + ": "
                + this.estacio.getLlistaPistes().calculaKmsPistes("Oberta") + " km.");
    }

    /**
     * OPCIO 9 Modificar la velocitat del vent
     *
     * @param sc Scanner per llegir dades d'entrada per consol·la
     */
    public void modificarVelocitatVent(Scanner sc) {
        int vel;
        System.out.println("La velocitat actual del vent és de: " + this.estacio.getMeteo().getVelocitatVent() + " km/h.");
        System.out.println(">> Digita la nova velocitat del vent: ");
        // verifiquem input correcte amb el setter
        vel = sc.nextInt();
        this.estacio.getMeteo().setVelocitatVent(vel);

        // llamar funciones actualizar
        this.actualitzar();
    }

    /**
     * OPCIO 10 : SWITCH Modificar la visibilitat
     *
     * @param sc Scanner per llegir dades d'entrada per consol·la
     */
    public void modificarVisibilitat(Scanner sc) {
        System.out.println("Visibilitat actual: " + this.estacio.getMeteo().getVisibilitat());
        System.out.println(">> Nova visibilitat: \n \t (1) Bona \n \t (2) Dolenta");

        int opcio_visibilitat = sc.nextInt();

        // Usamos Switch para poder usar el 'default' y no tener más error handling ni excepciones:
        switch (opcio_visibilitat) {
            case 1:
                this.estacio.getMeteo().setVisibilitat("Bona");
                System.out.println("Visibilitat canviada a " + this.estacio.getMeteo().getVisibilitat() + " amb èxit.");
                this.actualitzar();
                break;
            case 2:
                this.estacio.getMeteo().setVisibilitat("Dolenta");
                System.out.println("Visibilitat canviada a " + this.estacio.getMeteo().getVisibilitat() + " amb èxit.");
                this.actualitzar();
                break;
            default:
                System.out.println("Elecció incorrecta. Escull entre (1) i (2).");
                this.actualitzar();
                break;
        }
    }

    // OPCIO 11
    public void condicionsMeteorologiques() {
        System.out.println("Velocitat del vent: "
                + this.estacio.getMeteo().getVelocitatVent() + " km/h");
        System.out.println("Visibilitat: "
                + this.estacio.getMeteo().getVisibilitat());
    }

    // OPCIO 7 - SIMPLE:
    /*
        public void modificarEstatNeuPista(){
        String nom, estat;
        Scanner sc = new Scanner(System.in);
        System.out.println("Entra el nom de la pista a modificar:");
        nom = sc.nextLine();
        if (estacio.getLlistaPistes().getPista(nom) == null){
            System.out.println("Nom de pista incorrecte");
            return;
        }
        
        System.out.println("Entra el nou estat de la neu:");
        estat = sc.nextLine();
        if (!(estat.equals("Dura") || estat.equals("Pols") || estat.equals("Primavera"))){
            System.out.println("Estat incorrecte");
            return;
        }
        // si arribem aquí tant nom com estat són vàlids
        estacio.getLlistaPistes().getPista(nom).setEstatNeu(estat);
    }
    
    // OPCIO 10 : STRINGS
    /*public void modificarVisibilitat(Scanner sc){
        String vis;
        System.out.println("La visibilitat actual és: "+estacio.getMeteo().getVisibilitat());
        System.out.println(">> Nova visibilitat (Bona/Dolenta):");
        // verifiquem input correcte amb el setter
        vis = sc.next();
        this.estacio.getMeteo().setVisibilitat(vis);
        
        System.out.println(">> Nova visibilitat canviada a "+estacio.getMeteo().getVisibilitat()+" amb èxit.");
        // llamar funciones actualizar
        this.actualitzar();
    }*/
}

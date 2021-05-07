package prog2.vista;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import prog2.model.ClubUB;

public class VistaClubUB {

    // Atrib
    private final ClubUB club;

    // Constr.
    public VistaClubUB() {
        this.club = new ClubUB();

    }

    // Methods
    public void gestioClubUB() {
        Scanner sc = new Scanner(System.in);
        gestioMenu(sc);
    }

    private static enum OpcionesMenu {
        M_Opcion_1_DonarAlta,
        M_Opcion_2_MostrarLlista,
        M_Opcion_3_EliminarSoci,
        M_Opcion_4_MostrarFactura,
        M_Opcion_5_ModificarNom,
        M_Opcion_6_ModificarAsseguranca,
        M_Opcion_7_GuardarLlista,
        M_Opcion_8_RecuperarLlista,
        M_Opcion_9_Sortir
    };

    private static final String[] descMenu = {
        "Donar d'alta un nou soci",
        "Mostrar llista de socis",
        "Eliminar soci",
        "Mostrar fatura",
        "Modificar nom soci",
        "Modificar tipus assegurança soci",
        "Guardar llista",
        "Recuperar llista",
        "Sortir"
    };

    public void gestioMenu(Scanner sc) {
        Menu<OpcionesMenu> menuEstacio = new Menu<>("club ub", OpcionesMenu.values());
        menuEstacio.setDescripcions(descMenu);
        OpcionesMenu opcionMenu;

        do {
            menuEstacio.mostrarMenu();
            opcionMenu = menuEstacio.getOpcio(sc);

            switch (opcionMenu) {
                case M_Opcion_1_DonarAlta:
                    donarAlta(sc);
                    break;
                case M_Opcion_2_MostrarLlista:
                    mostrarLlista();
                    break;
                case M_Opcion_3_EliminarSoci:
                    eliminarSoci(sc);
                    break;
                case M_Opcion_4_MostrarFactura:
                    mostrarFactura(sc);
                    break;
                case M_Opcion_5_ModificarNom:
                    modificarNomSoci(sc);
                    break;
                case M_Opcion_6_ModificarAsseguranca:
                    modificarTipusAsseguranca(sc);
                    break;
                case M_Opcion_7_GuardarLlista:
                    this.club.guardar(); break;
                case M_Opcion_8_RecuperarLlista:
                    this.club.carregar(); break;
            }
        } while (opcionMenu != OpcionesMenu.M_Opcion_9_Sortir);

    }

    // OPCIONS MENU
    // OPCIO 1
    public void donarAlta(Scanner sc) {
        // menu per escollir tipus de soci
        // TODO explicar pq hardcoded
        int opcio;
        String nom, DNI, nomFed, tipusAss;
        float preuFed, preuAss;

        do {
            System.out.println("\n\t Quin tipus de soci vol donar d'alta?");
            System.out.println("\t\t [1] Afegir soci federat");
            System.out.println("\t\t [2] Afegir soci estàndard");
            System.out.println("\t\t [3] Afegir soci junior");
            System.out.println("\t\t [4] Torna al menú anterior");
            System.out.print("\t >> ");
            opcio = sc.nextInt();
            System.out.println("");

            switch (opcio) {
                case 1: {
                    System.out.print("\t\t Entri nom: ");
                    nom = sc.next();
                    System.out.print("\t\t Entri DNI: ");
                    DNI = sc.next();
                    System.out.print("\t\t Entri nom de la federació: ");
                    nomFed = sc.next();
                    System.out.print("\t\t Entri preu de la federació: ");
                    preuFed = sc.nextFloat();
                    this.club.afegirSociFederat(nom, DNI, nomFed, preuFed);
                    break;
                }
                case 2: {
                    System.out.print("\t\t Entri nom: ");
                    nom = sc.next();
                    System.out.print("\t\t Entri DNI: ");
                    DNI = sc.next();
                    System.out.print("\t\t Entri tipus d'assegurança: ");
                    tipusAss = sc.next();
                    System.out.print("\t\t Entri preu de l'assegurança: ");
                    preuAss = sc.nextFloat();
                    this.club.afegirSociEstandard(nom, DNI, tipusAss, preuAss);
                    break;
                }
                case 3: {
                    System.out.print("\t\t Entri nom: ");
                    nom = sc.next();
                    System.out.print("\t\t Entri DNI: ");
                    DNI = sc.next();
                    this.club.afegirSociJunior(nom, DNI);
                    break;
                }
                case 4:
                    break;
                default:
                    System.out.println("Opció incorrecte!");
            }
        } while (opcio != 4);
    }

    // Opcio 2
    public void mostrarLlista() {
        System.out.println(this.club.getLlistaSocis().toString());
    }

    // Opcio 3
    public void eliminarSoci(Scanner sc) {
        try {
            int index;

            System.out.print("\tEntri la posició: ");
            index = sc.nextInt();
            this.club.getLlistaSocis().removeSoci(this.club.getLlistaSocis().getAt(index - 1));
        } catch (ExcepcioClub e) {
            System.out.println(e);
        }
    }

    // Opcio 4
    public void mostrarFactura(Scanner sc) {
        try {
            String DNI;
            int n;
            float preu;
            System.out.print("\tEntri el DNI: ");
            DNI = sc.next();
            System.out.print("\tEntri el nombre d'excursions: ");
            n = sc.nextInt();

            preu = (this.club.getLlistaSocis().getSoci(DNI).calculaPreuExcursio(this.club.getPreuExcrusio()) * n)
                    + this.club.getLlistaSocis().getSoci(DNI).calculaQuota(this.club.getQuotaMenusal());
            System.out.print("El preu a pagar es de " + preu + " euros\n");
        } catch (ExcepcioClub ex) {
            System.out.println(ex);
        }
    }

    // Opcio 5
    public void modificarNomSoci(Scanner sc) {
        try {
            String DNI, nom;
            System.out.print("\tEntri el DNI del soci al que vol modificar el nom: ");
            DNI = sc.next();
            System.out.print("\tEntri el nou nom: ");
            nom = sc.next();
            this.club.getLlistaSocis().getSoci(DNI).setNom(nom);
        } catch (ExcepcioClub ex) {
            System.out.println(ex);
        }

    }

    // Opcio 6
    public void modificarTipusAsseguranca(Scanner sc) {
        try {
            String DNI, tipusAss;
            System.out.print("\tEntri el DNI del soci al que vol modificar el tipus d'assegurança: ");
            DNI = sc.next();
            System.out.print("\tEntri el nou tipus d'assegurança: ");
            tipusAss = sc.next();
            
            this.club.getLlistaSocis().getSoci(DNI).setTipusAsseguranca(tipusAss);
            
        } catch (ExcepcioClub ex) {
            System.out.println(ex);
        }

    }

}

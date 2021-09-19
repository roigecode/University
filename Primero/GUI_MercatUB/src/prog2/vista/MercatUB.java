package prog2.vista;

import java.util.Scanner;
import prog2.controlador.Controlador;
import prog2.model.Article;
import prog2.model.Client;

public class MercatUB {
//
//    private final Controlador controlador;
//
//    public MercatUB() {
//        controlador = new Controlador();
//    }
//
//    public void gestioMercatUB() {
//        Scanner sc = new Scanner(System.in);
//        gestioMenu(sc);
//    }
//
//    private static enum OpcionesMenu {
//        M_Opcion_1_GestioArticles,
//        M_Opcion_2_GestioClients,
//        M_Opcion_3_GestioComandes,
//        M_Opcion_4_GuardarDades,
//        M_Opcion_5_CarregarDades,
//        M_Opcion_6_Sortir,
//    };
//
//    private static final String[] descMenu = {
//        "Gestió Artícles",
//        "Gestió Clients",
//        "Gestió Comandes",
//        "Guardar Dades",
//        "Carregar Dades",
//        "Sortir"
//    };
//
//    public void gestioMenu(Scanner sc) {
//        Menu<OpcionesMenu> menuEstacio = new Menu<>("mercat ub", OpcionesMenu.values());
//        menuEstacio.setDescripcions(descMenu);
//        OpcionesMenu opcionMenu;
//
//        do {
//            menuEstacio.mostrarMenu();
//            opcionMenu = menuEstacio.getOpcio(sc);
//
//            switch (opcionMenu) {
//                case M_Opcion_1_GestioArticles:
//                    gestioArticles(sc);
//                    break;
//                case M_Opcion_2_GestioClients:
//                    gestioClients(sc);
//                    break;
//                case M_Opcion_3_GestioComandes:
//                    gestioComandes(sc);
//                    break;
//                case M_Opcion_4_GuardarDades:
//                    guardarDades();
//                    break;
//                case M_Opcion_5_CarregarDades:
//                    carregaDades();
//                    break;
//            }
//        } while (opcionMenu != OpcionesMenu.M_Opcion_6_Sortir);
//
//    }
//
//    //OPCIONES:
//    //OPCIO 1:
//    /**
//     * Aquest mètode permet afegir articles i visualitzar els articles
//     * existents.
//     *
//     * @param Scanner sc
//     */
//    private void gestioArticles(Scanner sc) {
//        int opcio, tempsEnviament;
//        float preu;
//        String id, nom;
//        boolean esUrgent;
//
//        do {
//            System.out.println("\t 1 Afegir Article");
//            System.out.println("\t 2 Visualitzar Articles");
//            System.out.println("\t 3 Sortir");
//            System.out.print(">> ");
//            opcio = sc.nextInt();
//
//            switch (opcio) {
//                case 1:
//                    System.out.println("Escrigui les següents dades: ");
//                    System.out.println("------------------------------");
//                    System.out.print("Identificador: ");
//                    id = sc.next();
//                    System.out.print("Nom: ");
//                    nom = sc.next();
//                    System.out.print("Preu: ");
//                    preu = sc.nextInt();
//                    System.out.print("Temps d'enviament: ");
//                    tempsEnviament = sc.nextInt();
//                    System.out.print("Admet enviament urgent: ");
//                    esUrgent = sc.nextBoolean();
//
//                     {
//                        try {
//                            controlador.afegirArticle(id, nom, preu, tempsEnviament, esUrgent);
//                            System.out.println("\n··· Article afegit amb èxit! ···\n");
//                        } catch (MercatException ex) {
//                            System.err.println(ex.getMessage());
//                        }
//                    }
//                    break;
//
//                case 2:
//                    System.out.println("");
//
//                    for (String a : controlador.recuperaArticles()) {
//                        System.out.println(a);
//                    }
//
//                    System.out.println("");
//                    break;
//
//                case 3:
//                    break;
//                default:
//                    System.out.println("Opció incorrecte!");
//                    break;
//            }
//
//        } while (opcio != 3);
//    }
//
//    // OPCIO 2:
//    /**
//     * Aquest mètode permet afegir articles i visualitzar els clients existents.
//     *
//     * @param Scanner sc
//     */
//    private void gestioClients(Scanner sc) {
//        int opcio;
//        String correuElectronic;
//        String nomClient;
//        String adreca;
//        boolean tipusClient;
//
//        do {
//
//            System.out.println("\t 1 Afegir Client");
//            System.out.println("\t 2 Visualitzar Clients");
//            System.out.println("\t 3 Sortir");
//            System.out.print(">> ");
//            opcio = sc.nextInt();
//
//            switch (opcio) {
//                case 1:
//                    System.out.println("Escrigui les següents dades: ");
//                    System.out.println("------------------------------");
//                    System.out.println("Tipus de client: ");
//                    System.out.print("\t > És Premium?");
//                    System.out.print(" >> ");
//                    tipusClient = sc.nextBoolean();
//
//                    System.out.print("Nom del Client: ");
//                    nomClient = sc.next();
//                    System.out.print("Correu electrònic: ");
//                    correuElectronic = sc.next();
//                    System.out.print("Adreça: ");
//                    adreca = sc.next();
//                    
//                        try {
//                            controlador.afegirClient(correuElectronic, nomClient, adreca, tipusClient);
//                            System.out.println("\n··· Client afegit amb èxit! ···\n");
//                        } catch (MercatException ex) {
//                            System.err.println(ex.getMessage());
//                        }
//                    
//                    break;
//                case 2:
//                    System.out.println("");
//                    for (String a : controlador.recuperaClients()) {
//                        System.out.println(a);
//                    }
//                    System.out.println("");
//                    break;
//                case 3:
//                    break;
//                default:
//                    System.out.println("Opcio incorrecta!");
//                    break;
//            }
//
//        } while (opcio != 3);
//    }
//
//    // OPCIO 3:
//    /**
//     * Aquest mètode permet afegir articles i visualitzar les comandes
//     * existents.
//     *
//     * @param Scanner sc
//     */
//    private void gestioComandes(Scanner sc) {
//        Article article;
//        Client client;
//        int quantitat, opcio, indexArticle, indexClient, indexEsborrar;
//        boolean esUrgent;
//
//        do {
//
//            System.out.println("\t 1 Afegir Comanda");
//            System.out.println("\t 2 Esborrar Comanda");
//            System.out.println("\t 3 Visualitzar Comandes");
//            System.out.println("\t 4 Visualitzar Comandes Urgents");
//            System.out.println("\t 5 Sortir");
//
//            System.out.print(">> ");
//            opcio = sc.nextInt();
//
//            
//                switch (opcio) {
//                    case 1:
//                        System.out.print("Introdueix l'índex de l'article: ");
//                        indexArticle = sc.nextInt();
//                        System.out.print("Introdueix l'índex del client: ");
//                        indexClient = sc.nextInt();
//                        System.out.print("Introdueix les unitats d'article: ");
//                        quantitat = sc.nextInt();
//                        System.out.print("És urgent? ");
//                        esUrgent = sc.nextBoolean();
//                        
//                        try{
//                        controlador.afegirComanda(indexArticle, indexClient, quantitat, esUrgent);
//                        System.out.println("\n··· Comanda afegida amb èxit! ···\n");
//                        }catch(MercatException ex){
//                            System.err.println(ex.getMessage());
//                        }
//                        
//
//                        break;
//                    case 2:
//                        System.out.print("Digita l'índex de la comanda a esborrar: ");
//                        indexEsborrar = sc.nextInt();
//                        
//                        try{
//                        controlador.esborrarComanda(indexEsborrar);
//                        System.out.println("\n··· Comanda esborrada amb èxit! ···\n");
//                        }catch(MercatException ex){
//                            System.err.println(ex.getMessage());
//                        }
//
//                        break;
//                    case 3:
//                        System.out.println("");
//                        for (String a : controlador.recuperaComandes()) {
//                            System.out.println(a);
//                        }
//                        System.out.println("");
//                        break;
//                    case 4:
//                        System.out.println("");
//                        for (String a : controlador.recuperaComandesUrgents()) {
//                            System.out.println(a);
//                        }
//                        System.out.println("");
//                        break;
//                    case 5:
//                        break;
//                    default:
//                        System.out.println("Opcio incorrecte!");
//                }
//        } while (opcio != 5);
//
//    }
//
//    // OPCIO 4:
//    /**
//     * Aquest mètode permet guardar a un fitxer .dat les Dades del programa.
//     */
//    private void guardarDades() {
//        try {
//            controlador.guardar();
//            System.out.println("Dades guardades correctament.");
//        } catch (MercatException ex) {
//            System.err.println(ex.getMessage());
//        }
//
//    }
//
//    // OPCIO 5:
//    /**
//     * Aquest mètode permet carregar a un fitxer .dat les Dades del programa.
//     */
//    private void carregaDades() {
//        try {
//            controlador.carregar();
//            System.out.println("Dades carregades correctament.");
//        } catch (MercatException ex) {
//            System.err.println(ex.getMessage());
//        }
//    }
}

package prog2.model;

import java.util.*;
import prog2.vista.ExcepcioClub;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class LlistaSocis implements InSociList, Serializable {

    // Atrib.
    ArrayList<Soci> llistaSocis;
    int maxSize = 100;

    /**
     * Constructor de la classe LlistaSocis
     * @param maxSize int amb la mida maxima
     */
    public LlistaSocis(int maxSize) {
        llistaSocis = new ArrayList<>();
        this.maxSize = maxSize;
    }

    // Methods
    @Override
    public int getSize() {
        return this.llistaSocis.size();
    }

    /**
     * Aquest mètode afegeix un objecte de tipus Soci a la llista si no està repetit
     * @param soci Objecte de tipus soci
     * @throws ExcepcioClub Soci repetit!
     */
    @Override
    public void addSoci(Soci soci) throws ExcepcioClub {
        if (contains(soci)) {
            throw new ExcepcioClub("EXCEPTION: Soci repetit!");
        }
        this.llistaSocis.add(soci);
    }

     /**
     * Aquest mètode esborra un objecte de tipus Soci a la llista si existeix
     * @param soci Objecte de tipus soci
     * @throws ExcepcioClub Soci inexistent!
     */
    @Override
    public void removeSoci(Soci soci) throws ExcepcioClub {
        if (this.llistaSocis.contains(soci)) {
            this.llistaSocis.removeIf(obj -> obj.equals(soci));
        } else {
            throw new ExcepcioClub("EXCEPTION: Soci inexistent!");
        }
    }

    /**
     * Aquest mètode retorna el soci a una posició determinada
     * @param position int amb la posicio desitjada
     * @throws ExcepcioClub Index fora de rang!
     */
    @Override
    public Soci getAt(int position) throws ExcepcioClub {
        if (position < 0 || position > this.llistaSocis.size() - 1) {
            throw new ExcepcioClub("EXCEPTION: Index fora de rang!");
        } else {
            return this.llistaSocis.get(position);
        }
    }

    /**
     * Aquest mètode retorna el soci a partir del seu DNI
     * @param dni DNI
     * @throws ExcepcioClub Soci inexistent!
     */
    @Override
    public Soci getSoci(String dni) throws ExcepcioClub {
        for (Soci soci : this.llistaSocis) {
            if (soci.getDNI().equals(dni)) {
                return soci;
            }
        }
        throw new ExcepcioClub("EXCEPTION: Soci inexistent!");
    }

    @Override
    public void clear() throws ExcepcioClub {
        this.llistaSocis.clear();
    }

    @Override
    public boolean isFull() throws ExcepcioClub {
        return this.llistaSocis.size() == this.maxSize;

    }

    @Override
    public boolean isEmpty() throws ExcepcioClub {
        return this.llistaSocis.isEmpty();
    }

    
    /**
     * Aquest mètode retorna true si el soci passat per paràmetre es troba dins la llista
     * @param soci soci
     * @return trobat Booleà per saber si hem trobat el soci a la llista
     */
    @Override
    public boolean contains(Soci soci) {
        boolean trobat = false;
        for (int i = 0; i < llistaSocis.size(); i++) {
            if (llistaSocis.get(i).equals(soci)) {
                trobat = true;
            }
        }
        return trobat;
    }

    @Override
    public String toString() {
        String s = "";

        s += "Llista de Socis:\n================\n";
        for (int i = 0; i < this.llistaSocis.size(); i++) {
            s += ("[" + (i + 1) + "] ") + this.llistaSocis.get(i).toString() + "\n";
        }
        return s;
    }

    /**
     * Aquest mètode serveix per guardar la llista de socis a un arxiu .dat
     * @param filename nom del archiu .dat.
     */
    public void save(String filename) {
        File file = new File(filename);
        FileOutputStream fout = null;

        try {
            fout = new FileOutputStream(file);
            ObjectOutputStream oos = new ObjectOutputStream(fout);
            oos.writeObject(this);
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                fout.close();
            } catch (IOException ex) {
                System.out.println(ex);
            }
        }
    }

    /**
     * Aquest mètode carrega la llista de socis d'un archiu .dat donat
     * @param fileName archiu .dat
     *  @return llista Llista de socis
     */
    public static LlistaSocis load(String fileName) {
        File file = new File(fileName);
        LlistaSocis llista = null;
        FileInputStream fin = null;

        try {
            fin = new FileInputStream(file);
            ObjectInputStream ois = new ObjectInputStream(fin);
            llista = (LlistaSocis) ois.readObject();
        } catch (Exception e) {
            System.out.println(e);
        } finally {
            try {
                fin.close();
            } catch (IOException ex) {
                System.out.println(ex);
            }
        }

        return llista;

    }

}

import java.lang.ClassCastException;
import java.util.*;
import java.lang.IllegalArgumentException;

public class HuffmanTree extends BinaryTree{

    private Map<String, Integer> dict = new HashMap<String, Integer>();

    // Bubble sort per riordinare la queue
    public static ArrayList<Nodo> order(ArrayList<Nodo> q){
        for(int i = 0; i < q.size(); i++){
            boolean flag = false;
            for(int j = 0; j < q.size() - 1; j++){
                if(q.get(j+1).info.minore(q.get(j).info)){
                    Nodo t = q.get(j);
                    q.set(j, q.get(j+1));
                    q.set(j+1, t);
                    flag = true;
                }
            }
            if(!flag)
                break;
        }
        return q;
    }

    public HuffmanTree(){
        dict = null;
    }

    public HuffmanTree(String s) throws IllegalArgumentException{
        if(s.length() == 0)
            throw new IllegalArgumentException("Stringa vuota");

        // Per ogni carattere della stringa conto la sua frequenza
        for(int i = 0; i < s.length(); i++){
            String key = String.valueOf(s.charAt(i));

            if(dict.containsKey(key))
                dict.put(key, dict.get(key) + 1);
            else
                dict.put(key, 1);
        }
        buildTree(dict);
    }

    // Metodo che effettua la costruzione dell'albero
    private void buildTree(Map<String, Integer> d){

        // Se il dizionario e vuoto "distruggo" la radice
        if(dict.isEmpty()){
            root = null;
            return;
        }

        // Altrimenti creo una lista di queue per i nuvoi elementi da inserire
        ArrayList<Nodo> queue = new ArrayList<Nodo>();

        // Per ogni elemento del dizionario creo un nodo e lo inserisco nella queue
        for (Map.Entry<String, Integer> entry : dict.entrySet()) {
            queue.add(new Nodo(new Huffman(entry.getKey(), entry.getValue())));
        }


        while (queue.size() > 1){
            queue = order(queue);

            // estraggo i primi due elementi della queue
            Nodo a = queue.remove(0);
            Nodo b  = queue.remove(0);

            Huffman x = (Huffman) a.info;
            Huffman y = (Huffman)b.info;

            // Creo un nuovo nodo dalla somma dei due estratti
            Nodo tmp = new Nodo(x.somma(y), null, a, b);

            a.parent = tmp;
            b.parent = tmp;

            // Aggiungo il nuovo nodo e ridimensiono la queue
            queue.add(tmp);
            queue.trimToSize();
        }

        // Imposto la root al primo elemento della queue
        root = queue.get(0);

        // != compare reference
        // equals object equals
        // Se il dizionario passato e diverso da quello che ho nell'oggeto allora lo copio
        if(dict != d)
            dict.putAll(d);

    }

    public void insert(Tipo t) throws ClassCastException{
        if(!(t instanceof Huffman))
            throw new ClassCastException("Tipo passato non valido");

        Huffman h = (Huffman) t;
        if(h.getData().length() == 0)
            throw  new ClassCastException("Stringa vuota");

        if(dict.containsKey(h.getData()))
            dict.put(h.getData(), h.getFrequency() + dict.get(h.getData()));
        else
            dict.put(h.getData(), h.getFrequency());

        buildTree(dict);
    }


    private Nodo searchNodo(Nodo r, Huffman t){
        if(r == null)
            return  null;

        Huffman p = (Huffman)r.info;

        if(t.checkKey(p))
            return r;
        else{
            Nodo s = searchNodo(r.left, t);
            if(s != null)
                return s;
            return searchNodo(r.right, t);
        }
    }

    public Tipo search(Tipo t) throws ClassCastException, ArithmeticException{
        if(!(t instanceof Huffman))
            throw new ClassCastException("Tipo passato non valido");

        Huffman p = (Huffman)t;
        Nodo tmp = searchNodo(root, p);

        if(tmp == null)
            throw new ArithmeticException("Nodo non trovato");

        return tmp.info.copia();
    }




    public Huffman max(){
        if(root == null)
            throw new ClassCastException("Radice vuota");

        Map.Entry<String, Integer> save = dict.entrySet().iterator().next();


        for(Map.Entry<String, Integer> entry : dict.entrySet()){
            if(entry.getValue() >  save.getValue())
                save = entry;
        }

        return new Huffman(save.getKey(), save.getValue());
    }

    public Huffman min() throws ClassCastException{
        if(root == null)
            throw new ClassCastException("Radice vuota");

        Map.Entry<String, Integer> save = dict.entrySet().iterator().next();


        for(Map.Entry<String, Integer> entry : dict.entrySet()){
            if(entry.getValue() <  save.getValue())
                save = entry;
        }

        return new Huffman(save.getKey(), save.getValue());
    }

    public HuffmanTree copia(){
        HuffmanTree p = new HuffmanTree();
        p.root = copiaRoot(root, null);
        p.dict.putAll(dict);
        return p;
    }

    public void deleteNodo(Tipo t) throws ClassCastException{
        //for (Map.Entry<String, Integer> entry : dict.entrySet()) {
        //    System.out.println(entry.getKey() + " " + entry.getValue());
        //}
        if(!(t instanceof Huffman))
            throw new ClassCastException("Dato da cancellare non valido");

        Huffman h = (Huffman) t;
        boolean check = false;
        String s = null;

        for(Map.Entry<String, Integer> entry : dict.entrySet()){
            if(entry.getKey().equals(h.getData())){
                s  = entry.getKey();
                check = true;
            }
            if(check)
                break;
        }

        if(check){
            dict.remove(s);
            buildTree(dict);
        }
        else
            throw new ClassCastException("Nessun valore trovato");
    }

    private void printRic(Nodo r){
        if(r == null)
            System.out.print("_");
        else{
            System.out.print(r.info.toString() + "(");
            printRic(r.left);
            System.out.print(",");
            printRic(r.right);
            System.out.print(")");
        }
    }
    public void print(){
       printRic(root);
       System.out.println("");
    }

    protected Nodo copiaRoot(Nodo t, Nodo p){
        if(t != null){
            Nodo x = new Nodo(t.info.copia(), p);
            x.left = copiaRoot(t.left, x);
            x.right = copiaRoot(t.right, x);
            return x;
        }
        else
            return null;
    }

    private void getCompression(Nodo r, Map<String, String> d, String s){
        if(r != null) {
            getCompression(r.left, d, s += "1");

            if (r.left == null && r.right == null) {
                Huffman p = (Huffman) r.info;
                d.put(p.getData(), s);
            }

            s = s.substring(0, s.length() - 1);
            getCompression(r.right, d, s += "0");
        }
    }

    public Map<String, String> compression(){
        Map<String, String> d = new HashMap<String, String>();
        getCompression(root, d, "");
        return d;
    }


}

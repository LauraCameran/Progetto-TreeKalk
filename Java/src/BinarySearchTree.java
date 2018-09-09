import java.lang.ClassCastException;
import java.lang.ArithmeticException;


public class BinarySearchTree extends BinaryTree{

    public void insert(Tipo t) throws  ClassCastException{
        if(root != null) {
            if(t.getClass() != root.info.getClass())
                throw new ClassCastException("Tipo inserito incompatibile");

            insertNodo(root, t);
        }
        else
            root = new Nodo(t);
    }


    private void insertNodo(Nodo r, Tipo t) throws  ArithmeticException{
        if(r != null) {
            if (t.minore(r.info)) {
                if (r.left != null) {
                    insertNodo(r.left, t);
                } else {
                    r.left = new Nodo(t, r);
                }
            } else {
                if (r.right != null)
                    insertNodo(r.right, t);
                else
                    r.right = new Nodo(t, r);
            }
        }
    }

    public  Tipo search(Tipo t) throws ArithmeticException{
        if(root == null)
            throw new ArithmeticException("Ricerca su radice nulla");

        Nodo s = searchNodo(root, t);

        if(s == null)
            return  null;
        return s.info.copia();
    }

    private Nodo searchNodo(Nodo r, Tipo t){
        if(r == null)
            return null;
        if(r.info.uguale(t))
            return r;
        if(r.info.minore(t))
            return searchNodo(r.left, t);
        else
            return searchNodo(r.right, t);
    }

    public  Tipo max() throws  ArithmeticException{
        if(root == null)
            throw new ArithmeticException("Ricerca massimo su radice nulla");
        return  maxNodo(root).info.copia();
    }

    private Nodo maxNodo(Nodo r){
        if(r.right != null)
            return maxNodo(r.right);
        return r;
    }

    public  Tipo min() throws ArithmeticException{
        if(root == null)
            throw new ArithmeticException("Ricerca minimo su radice nulla");
        return minNodo(root).info.copia();
    }

    private Nodo minNodo(Nodo r){
        if(r.left != null)
            return minNodo(r.left);
        return r;
    }

    public BinarySearchTree copia(){
        BinarySearchTree t = new BinarySearchTree();
        t.root = copiaRoot(root, null);
        return t;
    }

    protected Nodo copiaRoot(Nodo t, Nodo p) throws ArithmeticException{
        if(t != null){
            Nodo x = new Nodo(t.info.copia(), p);
            x.left = copiaRoot(t.left, x);
            x.right = copiaRoot(t.right, x);
            return x;
        }
        else
            return null;
    }

    private Nodo succ(Nodo x){
        if(x.right != null)
            return minNodo(x.right);
        else{
            Nodo p = x.parent;
            while(p != null && p.right != null){
                x = p;
                p = p.parent;
            }
            return p;
        }
    }


    public void deleteNodo(Tipo t) throws ArithmeticException{
        Nodo x = null;
        Nodo y = null;
        Nodo z = searchNodo(root, t);


        if(z == null)
            throw new ArithmeticException("Nodo da cancellare non trovato");

        if(z.left == null || z.right == null)
            y = z;
        else
            y = succ(z);

        if(y.left != null)
            x = y.left;
        else
            x = y.right;
        if(x != null)
            x.parent = y.parent;

        if(y.parent == null)
            root = x;
        else if(y == y.parent.left)
            y.parent.left = x;
        else
            y.parent.right = x;
        if(y != z)
            z.info = y.info;

        // Nessuna delete y garbage collector fara il resto

    }


    private void printRic(Nodo x){
        if(x == null)
            System.out.print("_");
        else{
            System.out.print(x.info.toString() + "(");
            printRic(x.left);
            System.out.print(",");
            printRic(x.right);
            System.out.print(")");
        }
    }

    public void print(){

        printRic(root);
        System.out.println("");

    }

    private Nodo sommaRic(Nodo a, Nodo b, Nodo p){
        if(a != null && b != null){
            Nodo t = null;
            t = new Nodo(a.info.somma(b.info), t, sommaRic(a.left, b.left, t), sommaRic(a.right, b.right, t));
            return t;
        }
        return null;
    }

    public BinarySearchTree somma(BinarySearchTree b){
        if(b == null)
            throw new ClassCastException("Parametro passato non valido");
        BinarySearchTree p = new BinarySearchTree();
        p.root = sommaRic(root, b.root, null);
        return p;
    }


    private Nodo sottrazioneRic(Nodo a, Nodo b, Nodo p){
        if(a != null && b != null){
            Nodo t = null;
            t = new Nodo(a.info.sottrazione(b.info), t, sottrazioneRic(a.left, b.left, t), sottrazioneRic(a.right, b.right, t));
            return t;
        }
        return null;
    }

    public BinarySearchTree sottrazione(BinarySearchTree b){
        if(b == null)
            throw new ClassCastException("Parametro passato non valido");
        BinarySearchTree p = new BinarySearchTree();
        p.root = sottrazioneRic(root, b.root, null);
        return p;
    }


}




















public abstract class BinaryTree {

    // Perche static ?
    protected static class Nodo{
        protected Tipo info;

        protected Nodo left;
        protected Nodo right;
        protected Nodo parent;

        protected Nodo(Tipo t, Nodo p, Nodo l, Nodo r){
            info = t;
            parent = p;
            left = l;
            right = r;
        }

        protected Nodo(Tipo t, Nodo p, Nodo l){
            this(t, p, l, null);
        }

        protected  Nodo(Tipo t, Nodo p){
            this(t, p, null, null);
        }

        protected Nodo(Tipo t){
            this(t, null, null, null);
        }

        protected Nodo(){
            this(null, null, null, null);
        }

    }



    public abstract void insert(Tipo t);
    public abstract Tipo search(Tipo t);
    public abstract Tipo max();
    public abstract Tipo min();

    public abstract BinaryTree copia();

    public abstract void deleteNodo(Tipo t);

    public boolean empty(){
        if(root == null)
            return true;
        else
            return false;
    }

    public abstract void print();

    protected Nodo root = null;

    protected abstract Nodo copiaRoot(Nodo t, Nodo p);

    // non serve il metodo per distruggere
    protected static int conta(Nodo r){
        if(r != null)
            return 1 + conta(r.left) + conta(r.right);
        return 0;
    }

}


import java.lang.Exception;
import java.lang.Math;

public class AVLTree extends BinaryTree {

    protected static class Node extends Nodo{
        public int balance;

        Node(Tipo i, Nodo p, Nodo l, Nodo r){
            super(i, p, l, r);
            balance = 0;
        }
        Node(Tipo i, Nodo p, Nodo l){
            this(i, p, l, null);
        }
        Node(Tipo i, Nodo p){
            this(i, p, null, null);
        }
        Node(Tipo i){
            this(i, null, null, null);
        }
    }


    public int height(Nodo r){
        if(r == null)
            return -1;
        return  1 + Math.max(height(r.left), height(r.right));
    }

    private void setBalance(Node n){
        n.balance = height(n.right) - height(n.left);
    }

    private Node rotateLeftThenRight(Node n){
        n.left = rotateLeft((Node) n.left);
        return rotateRight(n);
    }

    private Node rotateRightThenLeft(Node n){
        n.right = rotateRight((Node) n.right);
        return rotateLeft(n);
    }

    private Node rotateLeft(Node a){
        Node b = (Node)a.right;
        b.parent = a.parent;
        a.right = b.left;

        if(a.right != null)
            a.right.parent = a;

        b.left = a;
        a.parent = b;

        if(b.parent != null){
            if(b.parent.right != null){
                if(b.parent.right == a)
                    b.parent.right = a;
                else
                    b.parent.left = b;
            }
        }
        setBalance(a);
        setBalance(b);
        return b;
    }

    private Node rotateRight(Node a){
        Node b = (Node) a.left;
        b.parent = a.parent;
        a.left = b.right;

        if(a.left != null)
            a.left.parent = a;

        b.right = a;
        a.parent = b;

        if(b.parent != null){
            if(b.parent.right == a)
                b.parent.right = b;
            else
                b.parent.left = b;
        }
        setBalance(a);
        setBalance(b);
        return b;
    }

    private void rebalance(Node n){
        setBalance(n);
        if(n.balance == -2){
            if(height(n.left.left) >= height(n.left.right))
                n = rotateRight(n);
            else
                n = rotateLeftThenRight(n);
        }
        else{
            if(n.balance == 2){
                if(height(n.right.right) >= height(n.right.left)) {
                    n = rotateLeft(n);
                }
                else
                    n = rotateRightThenLeft(n);
            }
        }
        if(n.parent != null)
            rebalance((Node)n.parent);
        else
            root = n;
    }


    private void insertNodo(Nodo r, Tipo t){
        Node x = (Node) r;

        if(t.minore(x.info)){
            if(x.left != null)
                insertNodo(r.left, t);
            else
                x.left  = new Node(t, x);
        }
        else{
            if(x.right != null)
                insertNodo(r.right, t);
            else
                x.right = new Node(t, x);
        }
        rebalance(x);
    }

    public  void insert(Tipo t){
        if(root != null)
            insertNodo(root, t.copia());
        else
            root = new Node(t.copia());
    }


    private Node searchNodo(Nodo r, Tipo t){
        if(r == null)
            return null;
        else{
            if(t.uguale(r.info))
                return (Node)r;
            else{
                if(t.minore(r.info))
                    return searchNodo(r.left, t) ;
                else
                    return searchNodo(r.right, t);
            }
        }
    }

    public Tipo search(Tipo t){
        Nodo p = searchNodo(root, t);
        if(p == null)
            return null;
        return p.info.copia();
    }

    private Nodo maxNodo(Nodo r){
        if(r.right != null)
            return maxNodo(r.right);
        return r;
    }

    public Tipo max(){
        if(root != null)
            return maxNodo(root).info.copia();
        return  null;
    }

    private Nodo minNodo(Nodo r){
        if(r.left != null)
            return minNodo(r.left);
        return r;
    }

    public Tipo min(){
        if(root != null)
            return minNodo(root).info.copia();
        return null;
    }

    protected Node copiaRoot(Nodo r, Nodo p){
        if(r != null){
            Node x = new Node(r.info.copia(), p);
            x.left = copiaRoot(r.left, x);
            x.right = copiaRoot(r.right, x);
            return x;
        }
        else
            return  null;
    }




    public AVLTree copia(){
        AVLTree p = new AVLTree();
        p.root = copiaRoot(root, null);
        return p;
    }

    private Node succ(Nodo x){
        if(x.right != null)
            return (Node) minNodo(x.right);
        else{
            Nodo p = x.parent;
            while(p != null && p.right != null){
                x = p;
                p = p.parent;
            }
            return (Node)p;
        }
    }


    public void deleteNodo(Tipo t){
        Node x = null;
        Node y = null;
        Node z = searchNodo(root, t);

        if(z == null)
            throw new ClassCastException("Parametro passato errato !");

        if(z.left == null || z.right == null)
            y = z;
        else
            y = succ(z);



        if(y.left != null)
            x = (Node)y.left;
        else
            x = (Node)x.right;

        if(x != null)
            x.parent = y.parent;

        if(y.parent == null)
            root = x;
        else if(y == y.parent.left)
            y.parent.left = x;
        else
            y.parent.right = x;

        if(y != z)
            z.info = y.info.copia();

        y = null;
        // delete y;

        if(x != null)
            rebalance(x);

        if(root != null){
            Nodo auxMin = minNodo(root);
            if(x != auxMin)
                rebalance((Node)auxMin);
            Nodo auxMax = maxNodo(root);
            if(x != auxMax)
                rebalance((Node)auxMax);

        }

    }




    private void printRic(Nodo x){
        if(x == null)
            System.out.print("_");
        else{
            Node tmp = (Node)x;
            System.out.print(tmp.info.toString() + "&" + tmp.balance + "(");
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

    public AVLTree subtree_preorder(){
        Node radix = preorder((Node)root);
        if(radix == null)
            return null;
        AVLTree subTree = new AVLTree();
        subTree.root = copiaRoot(radix, null);
        return  subTree;
    }



    public AVLTree subtree_invertorder(){
        Node radix = invertorder((Node)root);
        if(radix == null)
            return  null;
        AVLTree subTree = new AVLTree();
        subTree.root = copiaRoot(radix, null);
        return subTree;
    }

    private Node invertorder(Node n){
        if(n.balance == 0)
            return n;
        if(n.right != null)
            return  invertorder((Node)n.right);
        if(n.left != null)
            return invertorder((Node)n.left);

        return null;
    }

    private Node preorder(Node n){
        if(n.balance == 0)
            return n;
        if(n.left != null)
            return preorder((Node) n.left);

        if(n.right != null)
            return preorder((Node)n.right);

        return null;
    }

}

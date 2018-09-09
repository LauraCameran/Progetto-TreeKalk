import java.util.HashMap;
import java.util.Map;

public class main {
    public static void main(String [] args){

        System.out.println("------ BinarySearchTree ------");
        BinarySearchTree p = new BinarySearchTree();
        p.insert(new Intero(200));
        p.insert(new Intero(300));
        p.insert(new Intero(100));

        System.out.println("------ BinarySearchTree::sommma ------");
        BinarySearchTree t = p.somma(p);
        t.print();

        System.out.println("------ BinarySearchTree::sottrazione&somma ------");
        p = t.somma(p).somma(t);
        p.print();

        System.out.println("------ BinarySearchTree::max ------");
        System.out.println("Massimo: "+ p.max().toString());

        System.out.println("------ BinarySearchTree::min ------");
        System.out.println("Minimo: " + p.min().toString());

        System.out.println("------ HuffmanTree ------");
        HuffmanTree h = new HuffmanTree("aaabbbcc");
        h.print();

        System.out.println("------ HuffmanTree::deleteNodo ------");
        try {
            h.deleteNodo(new Huffman("a", 0));
        }catch (ClassCastException e){
            System.out.println(e.getMessage());
        }

        System.out.println("------ HuffmanTree::insert ------");
        Huffman tmp = new Huffman("j", 5);
        h.insert(tmp);
        h.print();

        System.out.println("------ HuffmanTree::compression ------");
        Map<String, String> d = h.compression();
        System.out.println(d);
        h.print();


        System.out.println("------ AVLTree ------");
        AVLTree avl = new AVLTree();
        avl.insert(new Intero(200));
        avl.insert(new Intero(300));
        avl.insert(new Intero(100));
        avl.insert(new Intero(50));
        avl.insert(new Intero(68));
        System.out.println("------ AVLTree::insert ------");
        avl.print();

        System.out.println("------ AVLTree::subtree_invertorder ------");
        AVLTree avl1 = new AVLTree();
        avl1 = avl.subtree_invertorder();
        avl1.print();

        System.out.println("------ AVLTree::subtree_preorder ------");
        AVLTree avl2 = new AVLTree();
        avl2 = avl.subtree_preorder();
        avl2.print();


    }
}


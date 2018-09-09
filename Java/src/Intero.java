import java.lang.ClassCastException;
import java.lang.ArithmeticException;


public class Intero implements Tipo{
    private int dato;

    public Intero(int n){
        dato = n;
    }

    public Intero copia(){
        return new Intero(dato);
    }

    public Tipo somma(Tipo t) throws ClassCastException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passato non vlido");
        Intero i = (Intero)t;
        return new Intero(dato + i.dato);
    }

    public Tipo sottrazione(Tipo t) throws ClassCastException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passato non valido");
        Intero i = (Intero)t;
        return new Intero(dato - i.dato);
    }

    public Tipo moltiplicazione(Tipo t) throws ClassCastException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passato non valido");
        Intero i = (Intero)t;
        return new Intero(dato * i.dato);
    }

    public Tipo divisione(Tipo t) throws ClassCastException, ArithmeticException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passato non valido");
        Intero i = (Intero)t;
        if(i.dato == 0)
            throw new ArithmeticException("Divisione per 0");

        return new Intero(dato / i.dato);
    }

    public boolean uguale(Tipo t) throws ClassCastException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passato non valid");
        Intero i = (Intero)t;
        if(dato == i.dato)
            return true;
        else
            return false;
    }

    public boolean minore(Tipo t) throws ClassCastException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passto non valido");
        Intero i = (Intero)t;
        if(dato < i.dato)
            return true;
        else
            return false;
    }

    public boolean maggiore(Tipo t) throws ClassCastException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passato non valido");
        Intero i = (Intero)t;
        if(dato > i.dato)
            return true;
        else
            return false;
    }

    public boolean minoreUguale(Tipo t) throws ClassCastException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passato non valido");
        Intero i = (Intero)t;
        if(dato <= i.dato)
            return true;
        else
            return false;
    }

    public boolean maggioreUguale(Tipo t) throws ClassCastException{
        if(!(t instanceof Intero))
            throw new ClassCastException("Tipo passato non valido");
        Intero i = (Intero)t;
        if(dato >= i.dato)
            return true;
        else
            return false;
    }

    public String toString(){
        return String.valueOf(dato);
    }

}

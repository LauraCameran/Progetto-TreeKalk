import java.lang.ClassCastException;
import java.lang.ArithmeticException;

public class Huffman implements Tipo{
	private String data; 
	private int frequency; 

	public Huffman(String s, int f) throws ArithmeticException{
		if(f < 0)
			throw new ArithmeticException("Frequenza negativa");
		data = s; 
		frequency = f; 
	}

	Huffman(){
		this("", 0);
	}

	public Huffman copia(){
		return new Huffman(data, frequency);
	}


	public boolean checkKey(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		Huffman h = (Huffman)t; 
		if(data.equals(h.data))
			return true; 
		else
			return false; 		
	}

	public String getData(){
		return data; 
	}
	
	public int getFrequency(){
		return frequency; 
	}


	public boolean uguale(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		Huffman h = (Huffman)t; 
		if(data.equals(h.data) && frequency == h.frequency)
			return true; 
		else
			return false; 
	}


	public boolean minore(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		Huffman h = (Huffman)t; 
		if(frequency < h.frequency)
			return true; 
		else
			return false; 
	}

	public boolean maggiore(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		Huffman h = (Huffman)t; 
		if(frequency > h.frequency)
			return true; 
		else
			return false; 
	}


	public boolean maggioreUguale(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passto non valido"); 
		Huffman h = (Huffman)t; 
		if(frequency >= h.frequency)
			return true; 
		else
			return false; 
	}

	public boolean minoreUguale(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		Huffman h = (Huffman)t; 
		if(frequency <= h.frequency)
			return true; 
		else
			return false; 
	}


	public Tipo somma(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		Huffman h = (Huffman)t; 
		return new Huffman(data + h.data, frequency + h.frequency);
	}

	public Tipo sottrazione(Tipo t) throws ClassCastException{
		throw new ClassCastException("Operazione di sottrazione non supportata"); 
	}

	public Tipo moltiplicazione(Tipo t) throws ClassCastException{
		throw new ClassCastException("Operazione di moltiplicazione non supportata"); 
	}

	public Tipo divisione(Tipo t) throws ClassCastException{
		throw new ClassCastException("Operazione di moltiplicazione non supportata"); 
	}

	public String toString(){
		return new String(data + "|" + String.valueOf(frequency)); 
	}

	public boolean checkKey(Huffman t){
		if(data.equals(t.data))
			return true;

		return false;
	}

    /*
    *
    *
bool Huffman::checkKey(const Tipo* x) const{
    const Huffman* p = dynamic_cast<const Huffman*>(x);
    if(p && p->data == data)
        return  true;
    else
        return false;
}
    * */







}



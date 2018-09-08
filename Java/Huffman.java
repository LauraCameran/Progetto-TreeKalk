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

	public Huffman copia(){
		return new Huffman(data, frequency);
	}

	public boolean checkKey(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 

		if(data.equals(t.data))
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

		if(data.equals(t.data) && frequency == t.frequency)
			return true; 
		else
			return false; 
	}


	public boolean minore(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		
		if(frequency < t.frequency)
			return true; 
		else
			return false; 
	}

	public boolean maggiore(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 

		if(frequency > t.frequency)
			return true; 
		else
			return false; 
	}


	public boolean maggioreUguale(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passto non valido"); 
		if(frequency >= t.frequency)
			return true; 
		else
			return false; 
	}

	public boolean minoreUguale(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		if(frequency <= t.frequency)
			return true; 
		else
			return false; 
	}

	public Tipo somma(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		return new Huffman(data + t.data, frequency + t.frequency);
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

	public String toString(Tipo t) throws ClassCastException{
		if(!(t instanceof Huffman))
			throw new ClassCastException("Tipo passato non valido"); 
		return new String(data + "|" + String.valueOf(frequency)); 
	}

}



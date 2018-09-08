

public interface Tipo{
	Tipo somma(Tipo t); 
	Tipo sottrazione(Tipo t); 
	Tipo moltiplicazione(Tipo t); 
	Tipo divisione(Tipo t); 

	
	boolean uguale(Tipo t); 
	boolean minore(Tipo t); 
	boolean maggiore(Tipo t); 
	boolean minoreUguale(Tipo t); 
	boolean maggioreUguale(Tipo t); 
	String toString(); 

}
package gui;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Configuration {
	int m_niveauALancer = -1, m_nbNiveau;
	List<String> m_listeCodes = new Vector<String>();
	
	public Configuration() {
		String code;
		int i=0;
		m_listeCodes = new Vector<String>(m_nbNiveau);
		File file = new File("codes.txt");
		
		try {
	        Scanner sc = new Scanner(file);

	        while (sc.hasNextLine() & i<m_nbNiveau) {
	            code = sc.next();
	            i += 1;
	            m_listeCodes.add(i, code);
	        }
	        sc.close();
	    } 
	    catch (FileNotFoundException e) {
	        e.printStackTrace();
	    }
	}
	
	public int trouve_niveau(String code) {
		for(int i=0; i<m_nbNiveau; i++){
	        if (m_listeCodes.get(i) == code)
	            return i+1;  //On retourne i+1 car la liste commence a l'indice 0
	    }
	    return -1;
	}
	
	protected void finalize() {
		
	}
}

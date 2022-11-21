package gui;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Configuration {
	int m_niveauALancer = -1, m_nbNiveau;
	
	public Configuration() {
		String code;
		int i=0;
		List<String> m_listeCodes = new Vector<String>(m_nbNiveau);
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
	
	protected void finalize() {
		
	}
}

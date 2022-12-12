package gui;
import java.io.*;
import java.util.Scanner;

public class Partie {
	
	int m_niv;
    int m_nbCaisses;
    Personnage m_perso;
    Caisse m_c[];
    Plateau m_plat;
    Configuration config;
	
	public Partie() {
		m_niv = 1;
	    m_nbCaisses = 1;
	    m_c = new Caisse[m_nbCaisses];
	    m_plat = new Plateau(0, 0, 0, 0);
	    config = new Configuration();
	}
	
	public void lancerNiveau(int niv){
		
		File file = new File(Integer.toString(niv)+".txt");
		int k=0; // L'entier k permet de numeroter les caisses et de les manipuler dans le tableau les contenant
	    
	    try {
	    	Scanner sc = new Scanner(file);
	    	
	    	String line = new String();
	    	//m_plat.m_la = 8;
	    	//m_plat.m_lo = 1;
	    	m_niv = Integer.parseInt(sc.nextLine());
	    	m_nbCaisses = Integer.parseInt(sc.nextLine());
	    	m_plat.m_la = Integer.parseInt(sc.nextLine());
	    	m_plat.m_lo = Integer.parseInt(sc.nextLine());
	    	m_c = new Caisse[m_nbCaisses];
	    	m_plat.tab = new ObjetImmobile[m_plat.m_la][m_plat.m_lo];
	    	
	    	for (int i=0; i<m_plat.m_la; i++){
	    		m_plat.tab[i] = new ObjetImmobile[m_plat.m_lo];
	    		line = sc.nextLine();
	            for (int j=0; j<m_plat.m_lo; j++){
	            	//System.out.println(j);
	            	m_plat.tab[i][j] = new ObjetImmobile(j,i,line.charAt(j));
	                //m_plat.tab[i][j].m_type = line.charAt(j);
	                //System.out.println(m_plat.tab[i][j].m_type);
	                //System.out.println(sc.nextLine().charAt(0));

	                if (m_plat.tab[i][j].m_type == '@' || m_plat.tab[i][j].m_type == '+') {
	                    m_perso = new Personnage(j,i);
	                    m_perso.img = ":/images/Joueur/playerDown.png";
	                }
	                if (m_plat.tab[i][j].m_type == '$'){
	                	m_c[k] = new Caisse(j,i);
	                    m_c[k].img = ":/images/Caisse/caisse.png";
	                    k++;
	                }
	                if (m_plat.tab[i][j].m_type == '*'){
	                	m_c[k] = new Caisse(j,i);
	                    m_c[k].img = ":/images/Caisse/caisseSurCible.png";
	                    k++;
	                }
	            }
	    	}
	    	sc.close();
	    }
	    catch(Exception e) {
	    	System.out.println(e);
	    }
	}
}

package code;
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
	}
	
	public void lancerNiveau(int niv){
		
		File file = new File(Integer.toString(niv)+".txt");
		int k=0; // L'entier k permet de numeroter les caisses et de les manipuler dans le tableau les contenant
	    
	    try {
	    	Scanner sc = new Scanner(file);
	    	
	    	m_niv = sc.nextInt();
	    	m_nbCaisses = sc.nextInt();
	    	m_plat.m_la = sc.nextInt();
	    	m_plat.m_lo = sc.nextInt();
	    	m_c = new Caisse[m_nbCaisses];
	    	m_plat.tab = new ObjetImmobile[m_plat.m_la][m_plat.m_lo];
	    	for (int i=0; i<m_plat.m_la; i++){
	            for (int j=0; j<m_plat.m_lo; j++){
	                m_plat.tab[i][j].m_type = sc.nextInt();

	                if (m_plat.tab[i][j].m_type == '@' || m_plat.tab[i][j].m_type == '+') {
	                    m_perso.setX(j);
	                    m_perso.setY(i);
	                    m_perso.img = ":/images/Joueur/playerDown.png";
	                }
	                if (m_plat.tab[i][j].m_type == '$'){
	                    m_c[k].setX(j);
	                    m_c[k].setY(i);
	                    m_c[k].img = ":/images/Caisse/caisse.png";
	                    k++;
	                }
	                if (m_plat.tab[i][j].m_type == '*'){
	                    m_c[k].setX(j);
	                    m_c[k].setY(i);
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

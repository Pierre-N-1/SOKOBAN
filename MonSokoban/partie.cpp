#include "partie.h"

Partie::Partie(){
    m_niv = 1;
    m_nbCaisses = 1;
    m_c = new Caisse[m_nbCaisses];
    for (int i=0; i<m_nbCaisses; i++){
        m_c[i] = Caisse();
    }
}

//Fonction permettant de lancer le niveau donne en parametre (par lecture d'un fichier texte)
void Partie::lancerNiveau(int niv){
    ifstream fichier(to_string(niv)+".txt", ios::in);
    int k=0; // L'entier k permet de numeroter les caisses et de les manipuler dans le tableau les contenant

    if(!fichier.fail()){
        fichier >> m_niv >> m_nbCaisses >> m_plat.m_la >> m_plat.m_lo;
        m_c = new Caisse[m_nbCaisses];
        for (int i=0; i<m_nbCaisses; i++)
             m_c[i] = Caisse();

        m_plat.tab = new ObjetImmobile*[m_plat.m_la];
        for (int i=0; i<m_plat.m_la; i++){
            m_plat.tab[i] = new ObjetImmobile[m_plat.m_lo];
            for (int j=0; j<m_plat.m_lo; j++){
                fichier >> m_plat.tab[i][j].m_type;

                if (m_plat.tab[i][j].m_type == '@' or m_plat.tab[i][j].m_type == '+') {
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
        fichier.close();
     }
     else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

int Partie::getNiv() const{
    return m_niv;
}

void Partie::setNiv(int n){
    m_niv=n;
}

void Partie::recommencerNiveau(int niv){
    this->lancerNiveau(niv);
}

int Partie::getNbCaisses()const{
    return m_nbCaisses;
}

void Partie::setNbCaisses(int nbCaisses){
    m_nbCaisses=nbCaisses;
}

//Renvoie le numero de la caisse si la case donnee en entree la contient et -1 sinon
int Partie::estCaisse(int x, int y){
    for(int i=0; i<m_nbCaisses; i++){
        if(m_c[i].getX()==x && m_c[i].getY()==y)
            return i;
    }
    return -1;
}

//Renvoie vrai si la case entree en parametre est vide et faux sinon
bool Partie::estVide(int x, int y) {
    return (m_plat.tab[y][x].m_type != '#' && estCaisse(x,y)==-1);
}

//Renvoie vrai si la caisse entree en parametre est sur une cible et faux sinon
bool Partie::caisseSurCible(Caisse &c){
    char type = m_plat.tab[c.getY()][c.getX()].m_type;
    if(type=='.' or type=='+' or type=='*'){
        c.img = ":/images/Caisse/caisseSurCible.png";
        return true;
     }
     else {
        c.img = ":/images/Caisse/caisse.png";
        return false;
    }
}

//Renvoie vrai si le niveau est termine et faux sinon
bool Partie::victoire(){
    int k=0;
    for(int i=0; i<m_nbCaisses; i++){
        if(this->caisseSurCible(m_c[i]))
            k++;
    }
    return(k==m_nbCaisses);
}

Partie::~Partie(){
    delete[] m_c;
}

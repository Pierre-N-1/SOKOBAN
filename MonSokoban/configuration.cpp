#include "configuration.h"

Configuration::Configuration()
{
    m_niveauALancer = -1; //Par default, le niveau a lancer est -1, c'est a dire que rien ne se lance
    ifstream fichier("codes.txt", ios::in);

    if(!fichier.fail()){
        string code;
        fichier >> m_nbNiveau;
        m_listeCodes = new QString[m_nbNiveau];

        for (int i=0; i<m_nbNiveau; i++) //On remplie notre liste avec les codes contenus dans le fichier
        {
             fichier >> code;
             m_listeCodes[i] = QString::fromStdString(code);
        }
        fichier.close();
     }
     else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

Configuration::~Configuration(){
    delete[] m_listeCodes;
}

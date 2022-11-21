#ifndef PARTIE_H
#define PARTIE_H

#include "plateau.h"
#include "personnage.h"
#include "caisse.h"
#include "configuration.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Partie
{
public:
    int m_niv;
    int m_nbCaisses;
    Personnage m_perso;
    Caisse* m_c;
    Plateau m_plat;
    Configuration config;

public:
    Partie();
    ~Partie();
    void lancerNiveau(int niv);
    bool estVide(int x, int y) ;
    void recommencerNiveau(int niv);
    bool victoire();
    void afficher();
    int getNiv() const;
    void setNiv(int n);
    int getNbCaisses()const;
    void setNbCaisses(int nbCaisses);
    int estCaisse(int x, int y);
    bool caisseSurCible(Caisse &c);
};

#endif // PARTIE_H

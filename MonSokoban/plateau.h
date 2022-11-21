#ifndef PLATEAU_H
#define PLATEAU_H

#include "objet.h"
#include "objetimmobile.h"

class Plateau: public Objet
{
public:
    ObjetImmobile** tab;
    int m_la;
    int m_lo;

public:
    Plateau(int x=0, int y=0, int la=0, int lo=0);
    ~Plateau();
};

#endif // PLATEAU_H

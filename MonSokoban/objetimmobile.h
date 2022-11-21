#ifndef OBJETIMMOBILE_H
#define OBJETIMMOBILE_H

#include "objet.h"

class ObjetImmobile : public Objet
{
public:
    char m_type;
public:
    ObjetImmobile(int x=0, int y=0, int t=0);
    char getType();
};

#endif // OBJETIMMOBILE_H

#include "plateau.h"

Plateau::Plateau(int x, int y, int la, int lo):Objet(x,y)
{
    m_la=la;
    m_lo=lo;
}

Plateau::~Plateau(){
    for (int i=0; i<m_la; i++)
        delete[] tab[i];
}

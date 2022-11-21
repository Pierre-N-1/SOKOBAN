#include "objetimmobile.h"

ObjetImmobile::ObjetImmobile(int x, int y, int t):Objet(x,y)
{
    m_type=t;
}

char ObjetImmobile::getType(){
    return m_type;
}

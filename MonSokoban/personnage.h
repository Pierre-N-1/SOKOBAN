#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "objetmobile.h"


class Personnage: public ObjetMobile{

    public :
        Personnage(int x=0, int y=0);
};


#endif // PERSONNAGE_H

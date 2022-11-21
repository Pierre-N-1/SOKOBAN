#ifndef OBJETMOBILE_H
#define OBJETMOBILE_H

#include "objet.h"

class ObjetMobile: public Objet{
    public :
        ObjetMobile(int x=0, int y=0);
        void deplacerDe(int dx, int dy);
        const char* img;
};

#endif // OBJETMOBILE_H

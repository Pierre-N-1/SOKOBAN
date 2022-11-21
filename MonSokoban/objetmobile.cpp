#include "objetmobile.h"

ObjetMobile::ObjetMobile(int x, int y):Objet(x,y){
}

void ObjetMobile::deplacerDe(int dx,int dy){
    this->setX(this->getX() + dx);
    this->setY(this->getY() + dy);
}

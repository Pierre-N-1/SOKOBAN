#include "objet.h"

Objet::Objet(int x, int y){
    m_x = x;
    m_y = y;
}

int Objet::getX(){
    return m_x;
}

int Objet::getY(){
    return m_y;
}

void Objet::setX(int newX){
    m_x = newX;
}

void Objet::setY(int newY){
    m_y = newY;
}

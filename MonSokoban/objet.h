#ifndef OBJET_H
#define OBJET_H


class Objet{
    private :
        int m_x;
        int m_y;

    public :
        Objet(int x=0, int y=0);
        int getX();
        void setX(int newX);
        int getY();
        void setY(int newY);
};

#endif // OBJET_H

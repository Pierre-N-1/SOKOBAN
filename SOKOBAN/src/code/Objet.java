package code;

public class Objet {
	
    int m_x, m_y;
    
    public Objet(int x, int y) {
    	m_x = x;
    	m_y = y;
    }
    public int getX(){
        return m_x;
    }

    public int getY(){
        return m_y;
    }

    public void setX(int newX){
        m_x = newX;
    }

    public void setY(int newY){
        m_y = newY;
    }
}

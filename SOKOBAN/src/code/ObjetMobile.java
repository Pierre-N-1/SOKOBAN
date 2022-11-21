package code;

public class ObjetMobile extends Objet{
	
	String img;

	public ObjetMobile(int x, int y) {
		super(x, y);
	}
	void deplacerDe(int dx,int dy){
	    setX(getX() + dx);
	    setY(getY() + dy);
	}
}

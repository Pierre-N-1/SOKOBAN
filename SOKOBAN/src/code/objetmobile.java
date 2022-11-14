package code;

public class objetmobile extends objet{
	
	String img;

	public objetmobile(int x, int y) {
		super(x, y);
	}
	void deplacerDe(int dx,int dy){
	    setX(getX() + dx);
	    setY(getY() + dy);
	}
}

package code;

public class Personnage extends ObjetMobile{
	
	String img;

	public Personnage(int x, int y) {
		super(x, y);
		img = ":/images/Joueur/playerDown.png";
	}
}

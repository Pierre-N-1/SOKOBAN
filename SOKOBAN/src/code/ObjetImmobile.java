package code;

public class ObjetImmobile extends Objet{
	
	int m_type;

	public ObjetImmobile(int x, int y, int t) {
		super(x, y);
		m_type = t;
	}
	
	public int getType(){
	    return m_type;
	}

}

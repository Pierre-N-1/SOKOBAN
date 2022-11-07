package code;

public class objetimmobile extends objet{
	
	int m_type;

	public objetimmobile(int x, int y, int t) {
		super(x, y);
		m_type = t;
	}
	
	public int getType(){
	    return m_type;
	}

}

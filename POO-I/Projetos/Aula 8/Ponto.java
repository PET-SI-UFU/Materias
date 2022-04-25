import java.lang.Math;

public class Ponto {
	private int X, Y;
	
	public int getX() {
		return X;
	}

	public void setX(int x) {
		if(x < 0 ) X = 0;
		else X = x;
	}

	public int getY() {
		return Y;
	}

	public void setY(int y) {
		if(y < 0 ) Y = 0;
		else Y = y;
	}

	public static double distância(Ponto A, Ponto B) {
		double D = 0;
		D = Math.sqrt(Math.pow((B.getX() - A.getX()), 2) + Math.pow((B.getY() - A.getY()),2));
		return D;
	}
	

}

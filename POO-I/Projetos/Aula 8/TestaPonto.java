
public class TestaPonto {

	public static void main(String[] args) {
		
		Ponto A = new Ponto();
		Ponto B = new Ponto();
		
		A.setX(0);
		A.setY(0);
		
		B.setX(4);
		B.setY(4);
		
		double distância = 0;
		distância = Ponto.distância(A, B);
		System.out.printf("A distância entre o ponto (%d,%d) e (%d, %d) eh %.1f\n",A.getX(),A.getY(),B.getX(),B.getY(),distância);


	}

}

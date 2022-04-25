
public class TestaQuadrado {

	public static void main(String[] args) {
		Quadrado q1 = new Quadrado();
		
		q1.lados = 10;
		System.out.println("Área: " + q1.area());
		System.out.println("Perímetro: " + q1.perimetro());
		
		q1.altera(2);
		System.out.println("Área: " + q1.area());
		System.out.println("Perímetro: " + q1.perimetro());

	}

}

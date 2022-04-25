
public class TestaCirculo {

	public static void main(String[] args) {
		Circulo c = new Circulo();
		Ponto p1 = new Ponto();
		Ponto p2 = new Ponto();
		
		p1.setX(0);
		p1.setY(0);
		
		p2.setX(5);
		p2.setY(0);
		
		c.setNome("Circunferência");
		c.setCentro(p1);
		c.setRaio(p2);
		
		double raio = c.raio();
		double diametro = c.diâmetro();
		double circunferencia = c.circunferência();
		double area = c.área();
		
		System.out.printf("Dados do círculo de raio %.2f\n",raio);
		System.out.printf("Diametro : %.2f\n",diametro);
		System.out.printf("Circunferencia : %.2f\n", circunferencia);
		System.out.printf("Area : %.2f\n", area);

	}

}

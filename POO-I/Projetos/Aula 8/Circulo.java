import java.lang.Math;

public class Circulo {
	private String nome;
	private Ponto centro;
	private Ponto raio;
	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Ponto getCentro() {
		return centro;
	}

	public void setCentro(Ponto centro) {
		this.centro = centro;
	}

	public Ponto getRaio() {
		return raio;
	}

	public void setRaio(Ponto raio) {
		this.raio = raio;
	}
	
	public double raio() {
		double R = Ponto.distância(centro, this.raio);
		return R;
	}

	public double diâmetro() {
		double R = raio();
		double D = 2 * R;
		return D;
	}
	
	public double área() {
		double R = raio();
		double área = Math.PI * Math.pow(R, 2);
		return área;
	}
	
	public double circunferência() {
		double R = raio();
		double circunferência = 2 * Math.PI * R;
		return circunferência;
	}
	
	
	
	
	

}

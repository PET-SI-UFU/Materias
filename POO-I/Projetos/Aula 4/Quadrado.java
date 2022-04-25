
public class Quadrado {
	public float lados;
	
	public void altera(float valor) {
		if(valor >= 0) 
			lados = valor;
	}
	
	public float area() {
		return lados * lados;
	}
	
	public float perimetro() {
		return lados * 4;
	}

}

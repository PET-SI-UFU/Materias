
public class Retangulo {
	public float lados[] = new float[2];
	
	public void alteraLado(float a, float b) {
		lados[0] = a;
		lados[1] = b;
	}
	
	public float calculaArea() {
		return lados[0]*lados[1];
	}

}


public class TestaVeiculo {

	public static void main(String[] args) {
		Veiculo v = new Veiculo();
		v.setCarga(300);
		v.setTipo("Carro");
		v.setModelo("1.0");
		v.setMarca("Mercedes");
		v.setStatus(false);
		
		System.out.printf("Dados do veículo\n");
		System.out.printf("Tipo: %s\n",v.getTipo());
		System.out.printf("Marca: %s\n",v.getMarca());
		System.out.printf("Modelo: %s\n",v.getModelo());
		System.out.printf("Carga: %s Kg\n",v.getCarga());
		if(v.isStatus() == false) System.out.println("O carro está desligado.");
	}

}


public class TestaContaBancaria {

	public static void main(String[] args) {
		ContaBancaria cElaine = new ContaBancaria();
		ContaBancaria cJoao = new ContaBancaria();
		
		cElaine.deposito(10000000);
		System.out.println(cElaine.saldo);
		
		cJoao.nome = "Joao";
		cJoao.deposito(100);
		System.out.println(cJoao.saldo);

	}

}

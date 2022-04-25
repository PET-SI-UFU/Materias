
public class ContaBancaria {
	public String nome;
	public int cpf;
	public float saldo;
	
	public float obtemSaldo() {
		return saldo;
	}
	
	public void saque(float valor) {
		if(saldo >= valor) {
			saldo = saldo - valor;
		}
	}
	
	public void deposito(float valor) {
		saldo = saldo + valor;
	}

}


public class TestaPessoa {

	public static void main(String[] args) {
		Pessoa p1 = new Pessoa();
		p1.nome = "Esme Cullen";
		p1.idade = 100;
		
		System.out.println(p1.nome + ", " + p1.idade + " anos");
		
		p1.incIdade();
		
		System.out.println(p1.nome + ", " + p1.idade + " anos");
		
		p1.alteraCt();
		
		//Observe que usamos a classe Pessoa para acessar um atributo estático
		System.out.println("Vampiros: " + Pessoa.ct);
		
		Pessoa p2 = new Pessoa();
		p2.nome = "Carlisle Cullen";
		p2.idade = 300;
		
		System.out.println("Vampiros: " + p2.ct);
		

	}

}

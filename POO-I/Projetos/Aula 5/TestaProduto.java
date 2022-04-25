
public class TestaProduto {

	public static void main(String[] args) {
		Produto p1 =  new Produto ();
		
		p1.nomeProduto = "arroz";
		p1.atribuiPreco(0, 10);
		p1.atribuiPreco(1, 20);
		p1.atribuiPreco(2, 30);
		p1.atribuiPreco(3, 40);
		p1.atribuiPreco(4, 50);
		
		System.out.println("Maior preço " + p1.calculaMaiorPreco());
		

	}

}

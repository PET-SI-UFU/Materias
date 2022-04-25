
public class Operadores {

	public static void main(String[] args) {
		int A = 10, B = 10, C = 0;
		char opcao = '+';
		
		System.out.println("Bem vindo a nossa calculadora!");
		System.out.println("+ - Somar");
		System.out.println("- - Subtrair");
		System.out.println("* - Multiplicar");
		System.out.println("/ - Dividir\n");
		
		switch(opcao) {
			case '+':
				C = A + B;
				System.out.println("O resultado é:" + C + "\n");
				break;
			case '-':
				C = A - B;
				break;
			case '*':
				C = A * B;
				System.out.println("O resultado é:" + C);
				break;
			case '/':
				C = A / B;
				System.out.println("O resultado é:" + C);
				break;
			default:
				System.out.println("A operação não pode ser realizada!");
		}
		
		System.out.println("Testando vetores!");
		int vet [] = new int [10];
		
		for(int i = 0; i<vet.length; i++) {
			vet[i] = i;
			System.out.println(vet[i]);
		}
		
		System.out.println("\nLidando com strings!");
		String fanfic = "A Stained Glass Soul";
		System.out.println(fanfic);

	}

}

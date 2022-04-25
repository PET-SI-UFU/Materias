import java.util.Scanner;

public class TestaVetores {

	public static void main(String[] args) {
		int c[] = {1,2,3,4,5,6};
		
		Scanner entrada = new Scanner(System.in);
		for(int i =0; i<c.length;i++) {
			System.out.println("Entre com o " + (i+1) + " o elemnto");
			c[i] = entrada.nextInt();
		}
		
		for(int elem: c) {
			System.out.println(elem);
		}
		
		entrada.close();

	}

}

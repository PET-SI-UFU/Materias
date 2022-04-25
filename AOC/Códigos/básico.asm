# básico.asm

# DESC: apresenta a a estrutura mínima de um programa em código de montagem

# Data: 02/08/2021

# int main(void){
#	int x = 10;
#	float f = 3.14.15;
#	int v[10];
#	return 0;
# }

# Aqui declaramos nossas variáveis estáticas, ou seja, aquelas localizadas na stack
.data

# Dê a etiqueta (label) x a um endereço de memória com 4 bytes armazenados que recebe o valor 10
	x: .word 10

# Dê a etiqueta f a um endereço de memória que receberá 3.1415 na notação de ponto flutuante		
	f: .float 3,1415
	
# Nesse caso eu não sei quais valores serão armazenados
# Portanto só vamos armazenar um espaço de memória de 40 bytes (4 * 10)
	v: .space 40
	
# Aqui temos as intruções do programa	
.text

# Existe uma conexão direta dos registradores com o resto do processador
# Usaremos os registradores para fazer operações
# Isso porque é mais fácil do que buscar valores na memória
# A função addiu permite a soma com uma constante
# O registrador $zero é o elemento neutro da soma
# Fazemos isso porque essa é uma arquitetura com conjunto reduzido de instruções
# Portanto, é mais fácil usar a instrução add do que criar uma para atribuir valores
	addiu $s1, $zero, 42 	# s1 <- $zero + 42
	
# Colocamos no registrador v0 o código 10
# Ao chamar syscall ele lê esse código e encerra o programa
# Equivalente a return 0
	addiu $v0, $zero, 10
	syscall

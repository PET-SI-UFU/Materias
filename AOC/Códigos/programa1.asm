# programa1.asm

# DESC: Tradução de um programa em C para asm

# Data: 5/08/2021

# int main(void){
#	int x = 42;
#	int y;
#	float f, pi = 3.1415;
#	int v[10] = {0,2,3,4,5,6,7,8,9};	
#
#	printf("Digite um int: ");
#	scanf("%d", &y);
#	
#	printf("A soma de 42 + %d eh: %d\n", y, (x+y));
#	printf("A multiplicação de pi * %d eh: %f\n",y,(pi * y));
#	
#	return 0;
# }

.data
	x: .word 42
	y: .space 4
	f: .space 4
	pi: .float 3.1415
	v: .word 0,1,2,3,4,5,6,7,8,9
	str1: .asciiz "Digite um int: "
	str2: .asciiz "A soma de 42 + "
	str3: .asciiz " eh: "
	str4: .asciiz "\n"
	
.text

# printf("Digite um int: ");
	addiu $v0, $zero, 4 	# 4 é o código para a syscall imprimir uma string
	la $a0, str1 		# a0 guarda o endereço de memória de str1
	syscall
	
# scanf("%d", &y);
	addiu $v0, $zero, 5	# 5 é o código para ler um inteiro
	syscall
	la $at, y		# at recebe o endereço de memória de y 
	sw $v0, 0($at)		# MEMÓRIA[at] <- v0
	addu $s0, $zero, $v0 	# No addu não temos uma constante
				# Salva o inteiro lido em s0
				
# printf("A soma de 42 + %d eh: %d\n", y, (x+y));
	# "A soma de 42 +" 
	addiu $v0, $zero, 4
	la $a0, str2		
	syscall
	
	# %d, y
	addiu $v0, $zero, 1
	addu $a0, $zero, $s0
	syscall
	
	# " eh: " 
	addiu $v0, $zero, 4
	la $a0, str3		
	syscall
	
	# x + y
	la $t0, x
	lw $s1, 0($t0)		# s1 <- MEMÓRIA[t0]
	addu $t0, $s0, $s1	# t0 <- x + y
	
	# %d de x + y
	addiu $v0, $zero, 1	
	addu $a0, $zero, $t0
	syscall
	
	# "\n" 
	addiu $v0, $zero, 4
	la $a0, str4		
	syscall
		
# return 0;
	addiu $v0, $zero, 10
	syscall

	
# fibonacci.asm

# DESC: Cálculo do Fibonacci

# Data: 10/08/2021

# int main(void){
#	
#	int n, i, anterior, atual;
#	
#	printf("Digite o num de termos: ");
#	scanf("%d", &n);
#	if(n<=0){
#		printf("O num de termos deve ser um inteiro positivo\n");
#		return 0;
#	}
#	if((n==1) || (n==2)){
#		printf("O fibonacci de %d eh 1\n",n);
#		return 0;
#	}
#	anterior = 1;
#	atual = 1;
#	for(i = 2; i<=n; i++){
#		tmp = atual;
#		atual = atual + anterior;
#		anterior = tmp;
#	}
#	printf("O fibonacci de %d eh: %d\n", n, atual);	
#	return 0;
# }

.data
	n: 		.space 4
	i: 		.space 4
	atual: 		.space 4
	anterior: 	.space 4
	str1:           .asciiz "Digite o num de termos: "
	str2: 		.asciiz "O num de termos deve ser um inteiro positivo"
	str3: 		.asciiz "O fibonacci de "
	str4:		.asciiz " eh 1\n"
	nl:		.asciiz "\n"
	eh:             .asciiz " eh: "
	
.text

# printf("Digite o num de termos: ");
	addiu 	$v0, $zero, 4
	la 	$a0, str1
	syscall
	
# scanf("%d", &n);
	addiu 	$v0, $zero, 5
	syscall
	addu 	$s0, $zero, $v0 	# s0 = n
	la 	$t0, n
	sw 	$s0, 0($t0)		#MEM[t0+0] = s0
	
# if(n<=0){	equivale 0 >= n
#	printf("O num de termos deve ser um inteiro positivo\n");
#	return 0;
# }

	slt	$t0, $zero, $s0		# 0 < n ? se sim t0 <- 1 senao t0 <- 0 
	bne	$t0, $zero, ELSE1
	# corpo do if
	addiu 	$v0, $zero, 4
	la 	$a0, str2
	syscall
	j	EXIT	
	# fim do if
		
ELSE1:

# if((n==1) || (n==2)){
#	printf("O fibonacci de %d eh 1\n",n);
#	return 0;
# }

	addiu $t1, $zero, 1
	addiu $t2, $zero, 2
	
	beq	$s0, $t1, IF2
	beq	$s0, $t2, IF2
	j	ELSE2
	
IF2: 
	#corpo do if
	addiu 	$v0, $zero, 4
	la 	$a0, str3
	syscall
	
	addiu	$v0, $zero, 1
	addu	$a0, $zero, $s0
	syscall
	
	addiu 	$v0, $zero, 4
	la 	$a0, str4
	syscall

	# fim do if

ELSE2:

# anterior = 1;
# atual = 1;
# for(i = 2; i<=n; i++){
#	tmp = atual;
#	atual = atual + anterior;
#	anterior = tmp;
# }
# printf("O fibonacci de %d eh: %d\n", n, atual);	

	addiu 	$s1, $zero, 1 	# anterior = 1;
	addiu	$s2, $zero, 1	# atual = 1;
	addiu	$s3, $zero, 2	# i = 2

FOR:	
	slt	$t0, $s3, $s0	# i < n? Se sim t0 <- 1, senão t0 <- 0 
	beq	$t0, $zero, RESPOSTA
	
	addu 	$s4, $zero, $s2	# tmp = atual;
	addu 	$s2, $s2, $s1	# atual = atual + anterior;
	addu	$s1, $zero, $s4 # anterior = tmp;
	 
	addiu 	$s3, $s3, 1	# i++
	j	FOR

RESPOSTA:
# printf("O fibonacci de %d eh: %d\n", n, atual);
	
	# printf("O fibonacci de 
	addiu 	$v0, $zero, 4
	la 	$a0, str3
	syscall
	
	# %d 
	addiu	$v0, $zero, 1
	addu	$a0, $zero, $s0
	syscall
	
	# eh: 
	addiu 	$v0, $zero, 4
	la 	$a0, eh
	syscall
	
	# %d
	addiu	$v0, $zero, 1
	addu	$a0, $zero, $s2
	syscall
	
	# \n
	addiu 	$v0, $zero, 4
	la 	$a0, nl
	syscall
	
# return 0;
EXIT:
	addiu $v0, $zero, 10
	syscall	
	
	
	
	
	
	
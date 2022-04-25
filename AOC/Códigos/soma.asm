# soma.asm

# DESC: Lê 10 números, calcule a sua soma, média e maior elemento

# Data: 13/08/2021

# int main(void){
#	int v[10] = {0};
#	int soma, media, maior;
#	
#	printf("Digite o valor de v[0]: ")
#	scanf("%d", &v[0]);
#	maior = v[0];
#	soma = v[0];
#	
#	for(int i = 1; i<10; i++){
#		printf("Digite o valor %d: ", (i+1));
#		scanf("%d", &v[i]);
#		soma+=v[i];
#		if(v[i]> maior) maior = v[i];
#	}
#	media = soma/10;
#	printf("Soma = %d\n", soma);
#	printf("Média = %d\n", media);
#	printf("Maior = %d\n", maior);
#	
#	return 0;
# }

.include "bibliUtil.asm"

.data
	.align 2	# Alinha a memória de 4 em 4 bytes
	
	v:	.space 40
	
	str1:	.asciiz "Digite o valor de v[0]: "
	str2:	.asciiz "Digite o valor "
	str3:	.asciiz ": "
	str4:	.asciiz "Soma = "
	str5:	.asciiz "Média = "
	str6:	.asciiz "Maior = "
	
.text
# printf("Digite o valor de v[0]: ")
	printStr(str1)

# scanf("%d", &v[0]);	
	readInt($s1)			# s1 = v[0]
	la	$t0, v
	sw	$s1, 0($t0)		# MEM[t0+0] = s1 ou v[0] = s1
	
# maior = v[0];
	addu	$t1, $zero, $s1		# t1 guarda o maior elemento
	
# soma = v[0];
	addu	$t2, $zero, $s1		# t2 quarda a soma
	
# for(int i = 1; i<10; i++){
	addiu	$s0, $zero, 1		# i = 1;
	la 	$s2, v			# s2 aponta para a posição v[0]
	addiu	$s2, $s2, 4		# s2 agora aponta para v[1]
	
FOR:	slti	$t0, $s0, 10 		# s0 < 10 -> t0 = 1
	beq	$t0, $zero, EXIT
	
	printStr(str2)			# printf("Digite o valor %d: ",i);
	printInt($s0)
	printStr(str3)
	
	readInt($s1)			# scanf("%d", &v[i]);
	sw	$s1, 0($s2)
	
	addu	$t2,$t2,$s1		# soma+=v[i];

	# if(v[i]> maior) maior = v[i];	
	slt	$t3, $t1, $s1		# v[i] < maior ? se sim t3 <- 1 senão t3 <-0
	beq	$t3, $zero, FOR		# Desvie se t3 == zero
	addu	$t1, $zero, $s1		# maior = v[i];

SAI_IF:
	addiu	$s2, $s2, 4     	# ponteiro para vetor ++
	addiu	$s0, $s0, 1		# i++
	j	FOR

EXIT:
	div	$t4, $t2, 10		# media = soma/10
	
	printNL
	# printf("Soma = %d\n", soma);	
	printStr(str4)
	printInt($t2)
	printNL
	
	# printf("Média = %d\n", media);
	printStr(str5)
	printInt($t4)
	printNL
	
	# printf("Maior = %d\n", maior);
	printStr(str6)
	printInt($t1)
	printNL		

	return0
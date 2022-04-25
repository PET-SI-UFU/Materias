# fatorial.asm

# DESC: Calculo de um fatorial N

# Data: 13/0/2021

# int main(void){
#	int n = 0;
#	int fat = 1;
#	
#	printf("Digite o fatorial: ");
#	scanf("%d", &n);
#	
#	for(int i = 1; i<=n; i++)
#		fat*=i;
#	
#	printf("O fatorial de %d eh: %d\n",n,fat);
#	
#	return 0;
# }

.include "bibliUtil.asm"

.data
	str1: 	.asciiz "Digite o fatorial: "
	str2:	.asciiz "O fatorial de "
	str3:	.asciiz " eh: "
	
.text

	printStr(str1)		# printf("Digite o fatorial: ");
	readInt($s1)		# scanf("%d", &n);
	
	addiu	$s2,$zero,1	# i = 1;
	addiu	$s3,$zero,1	# fat = 1;
	
FOR:	slt	$t0, $s1, $s2	# n < i ? Se sim t0 = 1, se não t0 = 0
	bne	$t0, $zero, RESPOSTA
	
	mul	$s3, $s3, $s2	#fat*=i;
	
	addiu 	$s2, $s2, 1	# i++
	j	FOR

RESPOSTA: 

	printStr(str2)
	printInt($s1)
	printStr(str3)
	printInt($s3)
	printNL
	
	return0
	

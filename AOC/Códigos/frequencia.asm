# frequencia.asm

# DESC: Calculo da frequencia de um elemento no array

# Data: 16/08/2021

# int main(void){
#	int n = 0, frequencia = 0;
#	int v[10] = {0,1,2,3,4,5,6,7,8,9};
#	
#	printf("Digite um número: ");
#	scanf("%d", &n);
#	
#	for(int i =0; i<n; i++){
#		if(v[i]==n) frequencia ++;
#	}
#	
#	printf("A frequencia do elemento %d no vetor eh: %d\n",n,frquencia);
#	
#	return 0;
# }

.include "bibliUtil.asm"

.data
	.align 2
	str1:	.asciiz	"Digite um número: "
	str2:	.asciiz	"A frequencia do elemento "
	str3:	.asciiz " no vetor eh: "
	v:	.word	0,2,5,4,5,6,7,8,9
	
.text
	printStr(str1)	# printf("Digite um número: ");
	readInt($s1)	# scanf("%d", &n);
	
	addu	$s0, $zero, $zero	# i = 0;
	la	$s2, v			# p = &v;
	lw	$s4, 0($s2)		# x = *p ou x = v[i];
	addiu 	$s3, $zero, 0		# frequencia = 0;
	
FOR:	slti	$t0, $s0, 10	# i < 10? Se sim t0 = 1, se não t0 = 0
	beq	$t0, $zero, EXIT
	
	bne	$s4, $s1,SAI_IF	# s4 != s1 ou v[i]!=n
	addiu	$s3, $s3, 1	#frequencia++
	
SAI_IF:	
	addiu	$s0, $s0, 1	# i++
	addiu	$s2, $s2, 4	# p++ ou p = v[i]
	lw	$s4, 0($s2)	# x = v[i];
	j	FOR
	
EXIT: 
	printStr(str2)
	printInt($s1)
	printStr(str3)
	printInt($s3)
	printNL
	return0	
	
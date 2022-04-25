#  bubbleSort.asm

# DESC: Implenta o algoritmo de ordenação bubble sort

# Data: 20/08/2021

# void bubble_sort (int vetor[], int n) {
#    int k, j, aux;
#
#    for (k = 1; k < n; k++) {
#        printf("\n[%d] ", k);
#
#        for (j = 0; j < n - k; j++) {
#            printf("%d, ", j);
#
#            if (vetor[j] > vetor[j + 1]) {
#                aux          = vetor[j];
#                vetor[j]     = vetor[j + 1];
#                vetor[j + 1] = aux;
#            }
#        }
#    }


.include "bibliUtil.asm"

.data
	.align 2
	vetor:	.word 9,8,7,6,5,4,3,2,1
	str1:	.asciiz "Bem vindo ao bubble sort em asm"
	
.text
	printStr(str1)
	printNL
	
	# Parâmetros da função
	la	$a0, vetor
	addiu	$a1,$zero,9
	jal SORT
	
	jal PRINT
	
	return0

# // SORT
	
SORT:	
	addu	$a2, $zero, $a0			# a2 aponta para vetor[0]
	addiu	$s1, $zero, 1			# k = 1

# for (k = 1; k < n; k++) {	
FOR1:	slt	$t0, $s1, $a1			# k < 9? Se sim t0 =1, se não t0 = 0
	beq	$t0, $zero, RESPOSTA

# for (j = 0; j < n - k; j++) {	
	subu	$s3, $a1, $s1 			# n - k	
	addu	$s2, $zero, $zero 		# j = 0
	FOR2:	slt	$t1, $s2, $s3 		# j < n - k? Se sim t1=1, se não t1 = 0
		beq	$t1, $zero, SAI_FOR2 
		
		# if (vetor[j] > vetor[j + 1]) {
		lw	$s4, 0($a2)	# s4 = v[j]
		addiu 	$a2, $a2, 4	# ponteiro ++ ou a0++
		lw	$s5, 0($a2)	#s5 = v[j+1]
		
		slt	$t2, $s5, $s4 	# vetor[j+1] < vetor[j]? se sim t2=1 se não t2 = 0
		beq	$t2, $zero, SAI_IF
		
			addu	$s6, $zero, $s4	# aux = vetor[j];
			addu	$s4, $zero, $s5 # vetor[j] = vetor[j + 1];
			addu	$s5, $zero, $s6 # vetor[j + 1] = aux;
		
			subiu 	$a2, $a2, 4
			sw	$s4, 0($a2)
			addiu 	$a2, $a2, 4
			sw	$s5, 0($a2)
	
	SAI_IF:	addiu	$s2,$s2,1		# j ++
		j	FOR2
	
	SAI_FOR2:
		addu	$a2, $zero, $a0			# a2 aponta para vetor[0]
		addiu	$s1, $s1, 1			# k++
		j	FOR1
	
RESPOSTA:					# Essa função não retorna nada
	jr	$ra				# contém o endereço da próxima instrução

# // SORT
	
PRINT:
	addu 	$a2, $zero, $a0			# a2 aponta para vetor[0]
	addu	$s1, $zero, $zero		# i = 0 
	
	FOR:	slt	$t0, $s1, $a1		# i < n? Se sim t0 =1 se não t0 = 0
		beq	$t0, $zero, TERMINA
		
		lw	$s2, 0($a2)
		printInt($s2)
		printNL
		addiu	$a2,$a2, 4
		
		addiu	$s1, $s1, 1
		j	FOR	
TERMINA:
	jr	$ra

	      
# funcoes.asm

# DESC: Funções em Assembly

# Data: 20/08/2021

.include "bibliUtil.asm"

.data

.text
	# Parâmetros da função
	addiu	$a0, $zero, 42	#a0 = 42
	addiu	$a1, $zero, 10	#a1 = 10
	jal	FUNC1
	
	addu	$a0, $zero, $v0
	printInt($a0)
	
	return0
	
FUNC1:	addu	$t0,$a0,$a1
	addu	$v0,$zero,$t0	#v0 é o retorno
	jr	$ra	# contém o endereço da instrução na linha 17
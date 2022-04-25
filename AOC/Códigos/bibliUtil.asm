# biblioteca.asm

# DESC: Biblioteca de funções em assembly

# Data: 13/08/2021

.macro return0
	addiu	$v0, $zero, 10
	syscall
.end_macro

.macro printInt(%d)
	addiu	$v0, $zero, 1
	addu	$a0, $zero, %d
	syscall
.end_macro

.macro printStr(%s)
	addiu	$v0, $zero, 4
	la	$a0, %s
	syscall
.end_macro

.macro printNL
	addiu	$v0, $zero, 4
	la	$a0, nl
	syscall
.end_macro

.macro readInt(%Int)
	addiu	$v0, $zero, 5
	syscall
	addu	%Int, $zero, $v0
.end_macro


.data
	nl:	.asciiz	"\n"
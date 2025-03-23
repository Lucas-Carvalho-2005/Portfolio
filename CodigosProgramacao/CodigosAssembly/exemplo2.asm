# Imprimir um n�mero inteiro

.data
numero: .word 42 # Declarando o n�mero 42 como um inteiro


.text
.globl main

main:
	# load word - Carregar a word (inteiro) em $a0
	lw $a0, numero
	
	# Carregar o c�digo da system call para imprimir inteiro em $v0
	li $v0, 1
	
	# Chamar a system call para imprimir o n�mero na tela
	syscall
	
	# Sair do programa
	li $v0, 10
	syscall
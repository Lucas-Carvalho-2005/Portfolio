# Imprimir um número inteiro

.data
numero: .word 42 # Declarando o número 42 como um inteiro


.text
.globl main

main:
	# load word - Carregar a word (inteiro) em $a0
	lw $a0, numero
	
	# Carregar o código da system call para imprimir inteiro em $v0
	li $v0, 1
	
	# Chamar a system call para imprimir o número na tela
	syscall
	
	# Sair do programa
	li $v0, 10
	syscall
#Vetores - acessar o terceiro elemento do vetor

.data
	vetor: .word 10, 20, 30, 40
	
.text
main:
	
	# Carregar o endereço do primeiro elemento do vetor no registrador $t2
	la $t2, vetor
	
	# Acessar o terceiro elemento do vetor (1 inteiro = 4 bytes)
	lw $t4, 8($t2)
	move $a0, $t4
	
	# Carregar o código da syscall para imprimir o inteiro 30
	li $v0, 1
	syscall
	
	# Sair do programa
	li $v0, 10
	syscall

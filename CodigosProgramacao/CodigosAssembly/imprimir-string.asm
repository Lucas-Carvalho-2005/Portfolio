.data
	nota: .asciiz "Estudando para a AP1 de PLP\n"

.text
main:
	la $a0, nota
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall
# if (a > b)  f = a - b   else   f = b - a

.data
	a: .word 1
	b: .word 5


.text
main:
	lw $t1, a
	lw $t2, b
	
	bgt $t1, $t2, a_maior_b
	sub $t3, $t2, $t1
	b fim
	
a_maior_b:
	sub $t3, $t1, $t2

fim:
	move $a0, $t3
	
	# Imprimir o resultado da subtração 
	li $v0, 1
	syscall
	
	# Sair do programa
	li $v0, 10
	syscall

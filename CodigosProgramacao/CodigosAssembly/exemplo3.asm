# Operações com inteiros

.data
	g: .word 4
	h: .word 6
	i: .word 3
	j: .word 2


.text
.globl main

main:
	lw $t1, g
	lw $t2, h
	add $t3, $t1, $t2
	
	lw $t1, i
	lw $t2, j
	add $t4, $t1, $t2
	
	sub $t5, $t3, $t4
	move $a0, $t5
	
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall

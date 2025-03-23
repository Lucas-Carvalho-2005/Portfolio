.data
a: .word 10
b: .word 3
c: .word 6
d: .word 1

.text
.globl main

main:
	lw $t1, a
	lw $t2, b
	sub $t3, $t1, $t2
	
	lw $t1, c
	lw $t2, d
	sub $t4, $t1, $t2
	
	sub $t5, $t3, $t4
	
	move $a0, $t5
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
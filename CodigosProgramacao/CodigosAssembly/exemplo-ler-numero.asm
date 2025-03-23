.data
msg: .asciiz "O número digitado é: "


.text
main:
	# Realizar a leitura do número e em seguida salvá-lo em $t0
	li $v0, 5
	syscall
	move $t0, $v0
	
	# Imprimir o conteúdo de "msg"
	la $a0, msg
	li $v0, 4
	syscall
	
	# Imprimir o número lido
	move $a0, $t0
	li $v0, 1
	syscall
	
	# Sair do programa
	li $v0, 10
	syscall
	
	
	
	
	
.data
msg: .asciiz "O n�mero digitado �: "


.text
main:
	# Realizar a leitura do n�mero e em seguida salv�-lo em $t0
	li $v0, 5
	syscall
	move $t0, $v0
	
	# Imprimir o conte�do de "msg"
	la $a0, msg
	li $v0, 4
	syscall
	
	# Imprimir o n�mero lido
	move $a0, $t0
	li $v0, 1
	syscall
	
	# Sair do programa
	li $v0, 10
	syscall
	
	
	
	
	
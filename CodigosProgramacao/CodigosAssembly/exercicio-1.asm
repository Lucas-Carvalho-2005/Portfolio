# Lucas Carvalho dos Santos

.data
msg1: .asciiz "Digite o primeiro n�mero: "
msg2: .asciiz "Digite o segundo n�mero: "
msg3: .asciiz "Digite o terceiro n�mero: "
result: .asciiz "O maior n�mero �: "

.text
main:
	# L� o primeiro n�mero
	la $a0, msg1       
	li $v0, 4          
	syscall
	
	li $v0, 5          
	syscall
	move $t0, $v0      
	
	
	# L� o segundo n�mero
	la $a0, msg2       
	li $v0, 4          
	syscall
	
	li $v0, 5          # Chamada de sistema para ler inteiro
	syscall
	move $t1, $v0      # Armazena o segundo n�mero em $t1
	
	
	# L� o terceiro n�mero
	la $a0, msg3       # Carrega a mensagem de entrada para o terceiro n�mero
	li $v0, 4          # Chamada de sistema para imprimir string
	syscall
	
	li $v0, 5          # Chamada de sistema para ler inteiro
	syscall
	move $t2, $v0      # Armazena o terceiro n�mero em $t2
	
	
	# Compara��es para encontrar o maior n�mero
	move $t3, $t0      # Assume que o primeiro n�mero ($t0) � o maior
	ble $t1, $t3, check_t2 # Se $t1 (2� n�mero) <= $t3, pula para verificar $t2
	move $t3, $t1      # Caso contr�rio, $t1 � o maior
	
check_t2:
	ble $t2, $t3, print_result # Se $t2 <= $t3, pula para imprimir o resultado
	move $t3, $t2      # Caso contr�rio, $t2 � o maior

print_result:
	la $a0, result     # Carrega a mensagem de resultado
	li $v0, 4          # Chamada de sistema para imprimir string
	syscall
	
	move $a0, $t3      # Move o maior n�mero para $a0 para impress�o
	li $v0, 1          # Chamada de sistema para imprimir inteiro
	syscall
	
	# Terminar o programa
	li $v0, 10         # Chamada de sistema para sair
	syscall

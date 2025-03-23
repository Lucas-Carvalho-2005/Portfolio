# Lucas Carvalho dos Santos

.data
msg1: .asciiz "Digite o primeiro número: "
msg2: .asciiz "Digite o segundo número: "
msg3: .asciiz "Digite o terceiro número: "
result: .asciiz "O maior número é: "

.text
main:
	# Lê o primeiro número
	la $a0, msg1       
	li $v0, 4          
	syscall
	
	li $v0, 5          
	syscall
	move $t0, $v0      
	
	
	# Lê o segundo número
	la $a0, msg2       
	li $v0, 4          
	syscall
	
	li $v0, 5          # Chamada de sistema para ler inteiro
	syscall
	move $t1, $v0      # Armazena o segundo número em $t1
	
	
	# Lê o terceiro número
	la $a0, msg3       # Carrega a mensagem de entrada para o terceiro número
	li $v0, 4          # Chamada de sistema para imprimir string
	syscall
	
	li $v0, 5          # Chamada de sistema para ler inteiro
	syscall
	move $t2, $v0      # Armazena o terceiro número em $t2
	
	
	# Comparações para encontrar o maior número
	move $t3, $t0      # Assume que o primeiro número ($t0) é o maior
	ble $t1, $t3, check_t2 # Se $t1 (2º número) <= $t3, pula para verificar $t2
	move $t3, $t1      # Caso contrário, $t1 é o maior
	
check_t2:
	ble $t2, $t3, print_result # Se $t2 <= $t3, pula para imprimir o resultado
	move $t3, $t2      # Caso contrário, $t2 é o maior

print_result:
	la $a0, result     # Carrega a mensagem de resultado
	li $v0, 4          # Chamada de sistema para imprimir string
	syscall
	
	move $a0, $t3      # Move o maior número para $a0 para impressão
	li $v0, 1          # Chamada de sistema para imprimir inteiro
	syscall
	
	# Terminar o programa
	li $v0, 10         # Chamada de sistema para sair
	syscall

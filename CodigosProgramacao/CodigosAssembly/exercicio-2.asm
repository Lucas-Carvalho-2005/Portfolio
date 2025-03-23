# Lucas Carvalho dos Santos

.data
msg: .asciiz "Digite a sua idade: "
menor: .asciiz "Você é menor de idade.\n"
maior: .asciiz "Você é maior de idade."
idoso: .asciiz "Você é idoso.\n"

.text
main:
	# Imprimir mensagem para pedir a idade
	la $a0, msg        
	li $v0, 4          
	syscall
	
	# Ler a idade
	li $v0, 5          
	syscall
	move $t0, $v0      
	
	# Verifica se é menor de idade (idade < 18)
	li $t1, 18         
	blt $t0, $t1, print_menor 
	
	# Verifica se é idoso (idade >= 60)
	li $t1, 60         
	bge $t0, $t1, print_idoso # Se $t0 >= 60, vai para print_idoso
	
	# Se for maior de idade, mas não idoso
	la $a0, maior      # Carrega a mensagem de maior de idade
	li $v0, 4          # Chamada de sistema para imprimir string
	syscall
	j fim     # Pula para o final
	
print_menor:
	la $a0, menor      # Carrega a mensagem de menor de idade
	li $v0, 4          # Chamada de sistema para imprimir string
	syscall
	j fim      		   # Pula para o final
	
print_idoso:
	la $a0, idoso      # Carrega a mensagem de idoso
	li $v0, 4          # Chamada de sistema para imprimir string
	syscall

fim:
	# Terminar o programa
	li $v0, 10         # Chamada de sistema para sair
	syscall

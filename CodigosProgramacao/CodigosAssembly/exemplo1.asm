#imprimir string

.data
MSG: .asciiz "OI MANAUS"


.text
la $a0, MSG
li $v0, 4
syscall

# Sair do programa
li $v0, 10
syscall
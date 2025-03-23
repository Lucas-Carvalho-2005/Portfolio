.data
    v: .word 10, 20, 30, 40, 50
    a: .word 4
    z: .word 2
    w: .word 3
    p: .word 5
    q: .word 6
    r: .word 7
    s: .word 8

.text
.globl main

main:
    # Carrega os valores das vari�veis a, z e w
    lw $t0, a      
    lw $t1, z      
    lw $t2, w      
    
    # Faz a1 = 16 * a
    li $t3, 16    
    mul $a0, $t0, $t3  # a0 = 16 * a
    
    # Faz b1 = z * w
    mul $a1, $t1, $t2  # a1 = z * w
    
    # Carrega as vari�veis p, q, r e s e chama a fun��o gun
    lw $a0, p      
    lw $a1, q      
    lw $a2, r      
    lw $a3, s      
    jal gun        
    move $a2, $v0  # a2 = retorno de gun
    
    # Faz d1 = v[3]
    la $t3, v      
    lw $a3, 12($t3) # Atribui a3 = v[2] (12 = 3 * 4 bytes)
    
    # Faz e1 = v[z]
    mul $t3, $t1, 4 # Calcula t3 = z * 4
    la $t4, v      # Carrega o endere�o base de v
    add $t3, $t4, $t3  # Calcula o endere�o de v[z]
    lw $t3, 0($t3) # Atribui t3 = v[z]
    
    # Faz f1 = z - 2
    li $t4, 2      # Carrega o valor 2
    sub $t4, $t1, $t4  # Calcula t4 = z - 2
    
    # Chama a fun��o fun com os valores calculados
    addiu $sp, $sp, -8  # Reserva espa�o na pilha para dois par�metros extras
    sw $t3, 0($sp)      # Salva v[z] na pilha
    sw $t4, 4($sp)      # Salva z - 2 na pilha
    
    # Chama a fun��o fun
    jal fun

    # Libera espa�o na pilha
    addiu $sp, $sp, 8
    
    # Imprime o resultado
    move $a0, $v0      
    li $v0, 1          
    syscall

    # Sai do programa
    li $v0, 10
    syscall

# Defini��o da fun��o gun
gun:
    add $v0, $a0, $a1  # Exemplo: gun retorna p + q
    jr $ra             # Retorna

# Defini��o da fun��o fun
fun:
    lw $t1, 0($sp)     # Recupera v[z] da pilha
    lw $t2, 4($sp)     # Recupera z - 2 da pilha

    # Implementa l�gica de fun
    add $v0, $a0, $a1
    add $v0, $v0, $a2
    add $v0, $v0, $a3
    add $v0, $v0, $t1
    add $v0, $v0, $t2

    jr $ra             # Retorna

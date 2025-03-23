.text
.globl main

main:
    # Atribui valores de exemplo para g, h, i, j
    li $a0, 100  
    li $a1, 20  
    li $a2, 30  
    li $a3, 40  

    # Chama a função fun
    jal fun     

    # O valor de retorno de fun é colocado em rk (simulando rk com $t0)
    move $t0, $v0  

    # Imprimir o valor de retorno
    move $a0, $t0  
    li $v0, 1      
    syscall

    # Sair do programa
    li $v0, 10  
    syscall

fun:
    # g + h, resultado armazenado em a0
    add $a0, $a0, $a1  # a0 <- g + h

    # i + j, resultado armazenado em a2
    add $a2, $a2, $a3  # a2 <- i + j

    # (g + h) - (i + j), resultado armazenado em a2
    sub $a2, $a0, $a2  # a2 <- (g + h) - (i + j)

    # Multiplica o resultado por 4 e coloca em v0
    sll $v0, $a2, 2    # v0 <- (resultado) * 4

    # Retorna para a função chamadora
    jr $ra             

        .data
source:  .asciiz "Ola, mundo!"
dest:    .space 20

        .text
        .globl main
main:   
        la $a0, source
        la $a1, dest
        jal strcopy

        li $v0, 10
        syscall

strcopy: 
        lb $t0, 0($a0)
        beqz $t0, end_strcopy
        sb $t0, 0($a1)
        addi $a0, $a0, 1
        addi $a1, $a1, 1
        j strcopy

end_strcopy:
        sb $zero, 0($a1)

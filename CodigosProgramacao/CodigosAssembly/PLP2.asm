fun:
    move $v0, $a0 
    jr $ra         

li $t4, 16          
mul $a0, $t0, $t4   

mul $a1, $t1, $t2  

move $a0, $t5      
move $a1, $t6       
move $a2, $t7       
move $a3, $t8       
jal gun             
move $a2, $v0       

li $t9, 3           
sll $t9, $t9, 2     
lw $a3, 0($t3)     

sll $t1, $t1, 2     
lw $t4, 0($t3)      
sw $t4, 0($sp)      

li $t5, 2           
sub $t6, $t1, $t5 
sw $t6, 4($sp)      

jal fun


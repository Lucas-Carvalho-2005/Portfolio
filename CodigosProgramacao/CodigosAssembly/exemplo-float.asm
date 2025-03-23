.data
num1: .float 3.5


.text
main:
	l.s $f12, num1 # Usa $f porque o num1 é float
	
	li $v0, 2
	syscall
	
	li $v0, 10
	syscall
	
	
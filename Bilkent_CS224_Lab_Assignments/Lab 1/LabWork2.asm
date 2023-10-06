## CS224
## Lab 1
## Section 1
## Ata Seren
## 21901575

## Lab Work 2 Part 4
## Gets inputs from user and computes
## A = (B * C + D / B - C ) % B equation
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:		
	la $a0,welcome	
	li $v0,4	# system call to print
	syscall		#   out a string
	
	la $a0,B
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall		# system call to read an int
	add $s0, $0, $v0
	
	la $a0,C	
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall
	add $s1, $0, $v0
	
	la $a0,D	
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall
	add $s2, $0, $v0
	
	mul $t0, $s0, $s1	#equation starts
	div $t1, $s2, $s0
	add $t0, $t0, $t1
	sub $t1, $t0, $s1
	div $t1,$s0
	mfhi $t2
	
	la $a0,bye	
	li $v0,4	
	syscall	
	
	li $v0, 1
    	move $a0, $t2
    	syscall
    	
    	li $v0,10  # system call to exit
	syscall	#    bye bye



#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
welcome:	.asciiz "To compute A = (B * C + D / B - C ) % B\n"
B:	.asciiz "Enter B: \n"
C:	.asciiz "Enter C: \n"
D:	.asciiz "Enter D: \n"
bye:	.asciiz "The result of equation is: "

##
## end of file LabWork2.asm
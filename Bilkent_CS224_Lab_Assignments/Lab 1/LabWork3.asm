## CS224
## Lab 1
## Section 1
## Ata Seren
## 21901575

## Lab Work 2 Part 4 
## Gets integer inputs from user and performs
## X = (A/B) + (C*D-A)%B equation
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:		
	la $a0,welcome	# welcome message
	li $v0,4	# system call to print
	syscall		#   out a string
	
	la $a0,A	
	li $v0,4	
	syscall	
	li $v0, 5	# syscall 5 reads an integer
	syscall
	add $s0, $0, $v0 # saved an int to a
	
	la $a0,B	
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall
	add $s1, $0, $v0 # saved an int to b
	
	la $a0,C	
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall
	add $s2, $0, $v0 # saved an int to c
	
	la $a0,D
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall
	add $s3, $0, $v0 # saved an int to d
	
	div $t0, $s0, $s1
	mul $t1, $s2, $s3
	sub $t1, $t1, $s0
	div $t1,$s1
	mfhi $t2	#for mod operation
	add $t3, $t0, $t2
		
	
	la $a0,bye	
	li $v0,4	
	syscall	
	
	li $v0, 1
    	move $a0, $t3
    	syscall
    	
    	li $v0,10  # system call to exit
	syscall	#    bye bye



#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
welcome:	.asciiz "To compute X = (A/B) + (C*D-A)%B\n"
A:	.asciiz "Enter A: \n"
B:	.asciiz "Enter B: \n"
C:	.asciiz "Enter C: \n"
D:	.asciiz "Enter D: \n"
bye:	.asciiz "The result of equation is: "

##
## end of file Prelim2.asm

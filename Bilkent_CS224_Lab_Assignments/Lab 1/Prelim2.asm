## CS224
## Lab 1
## Section 1
## Ata Seren
## 21901575

## Preliminary Work 2 Part 2 
## Gets integer inputs from user and performs
## x = a * (b - c) % d equation
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
	
	la $a0,a	
	li $v0,4	
	syscall	
	li $v0, 5	# syscall 5 reads an integer
	syscall
	add $s0, $0, $v0 # saved an int to a
	
	la $a0,b	
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall
	add $s1, $0, $v0 # saved an int to b
	
	la $a0,c	
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall
	add $s2, $0, $v0 # saved an int to c
	
	la $a0,d	
	li $v0,4	
	syscall	
	li $v0, 5	
	syscall
	add $s3, $0, $v0 # saved an int to d
	
	sub $t0, $s1, $s2 # equation starts
	mul $t1, $s0, $t0
	div $t1,$s3
	mfhi $t2	#for mod operation
	
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
welcome:	.asciiz "To compute x = a * (b - c) % d\n"
a:	.asciiz "Enter a: \n"
b:	.asciiz "Enter b: \n"
c:	.asciiz "Enter c: \n"
d:	.asciiz "Enter d: \n"
bye:	.asciiz "The result of equation is: "

##
## end of file Prelim2.asm

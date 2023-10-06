## CS224
## Lab 3
## Section 1
## Ata Seren
## 21901575

## Preliminary Work 2 Part 2
## A program that takes 2 value and performs a division recursively.
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:
	restart:
	la $a0, value1
	li $v0, 4
	syscall
		
	li $v0, 5	# syscall 5 reads an integer
	syscall
	add $s0, $0, $v0
	
	la $a0, enter
	li $v0, 4
	syscall
	
	la $a0, value2
	li $v0, 4
	syscall
	
	li $v0, 5	
	syscall
	add $s1, $0, $v0
	
	la $a0, enter
	li $v0, 4
	syscall
	
	move $a0, $s0
	move $a1, $s1
	add $v0, $0, $0
	jal recursiveDivision  # subprogram
	add $s2, $v0, $0
	
	la $a0, result
	li $v0, 4
	syscall
	
	li $v0, 1
	move $a0, $s2
	syscall
	
	la $a0, enter
	li $v0, 4
	syscall	
	
	la $a0, continue
	li $v0, 4
	syscall
	
	li $v0, 5	# value for restarting program
	syscall
	add $s3, $0, $v0
	
	la $a0, enter
	li $v0, 4
	syscall	
	
	beq $s3, 1, restart # If input is 1, restarts. Else if input is another integer, ends program.
	
	li $v0,10  # system call to exit
	syscall	#    bye bye

recursiveDivision:
	addi $sp, $sp, -12 # make room for 3 items
	sw $s0, 8($sp) # push $s0
	sw $a0, 4($sp) # push $a0
	sw $ra, 0($sp) # push $ra
	
	slt $s0, $a0, $a1
	beq $a0, $a1, equal
	bne $s0, $0, end
	equal:
	sub $a0, $a0, $a1
	add $v0, $v0, 1	
	jal recursiveDivision
	end:
	
	lw $ra, 0($sp) # restore $ra from stack
	lw $a0, 4($sp) # restore $a0 from stack
	lw $s0, 8($sp) # restore $s0 from stack
	addi $sp, $sp, 12 # deallocate stack space
	
	jr $ra
	
	

#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
result: .asciiz "Result of division: "	
continue: .asciiz "If you want to continue, enter 1. Else, enter another integer: "
value1: .asciiz "Enter value to be divided: "
value2: .asciiz "Enter dividing value: "
space: .asciiz " "
enter: .asciiz "\n"


##
## end of file Prelim2.asm


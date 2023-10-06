## CS224
## Lab 3
## Section 1
## Ata Seren
## 21901575

## Preliminary Work 1 Part 1
## Counts "add" and "lw" instructions in main and subprogram
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:
        L1: add $s0, $0, $0  # beginning address for main
	add $t0, $0, 1
	add $s0, $0, $0
	lw $s0, space
	add $s0, $s1, $s2
	sub $s1, $s0, $s0
	lw $s0, space
	lw $s0, space
	add $s0, $0, 1
	
	la $a0, L1
	la $a1, L2
	jal instructionCount  # checks for main
	add $s0, $v0, $0
	add $s1, $v1, $0
	
	la $a0, mainText
	li $v0, 4
	syscall
	
	la $a0, addText
	li $v0, 4
	syscall
	
	li $v0, 1
    	move $a0, $s0
    	syscall
	
	la $a0, enter
	li $v0, 4
	syscall
	
	la $a0, lwText
	li $v0, 4
	syscall
	
	li $v0, 1
    	move $a0, $s1
    	syscall
    	
    	la $a0, enter
	li $v0, 4
	syscall
	
	la $a0, enter
	li $v0, 4
	syscall
	
	la $a0, L3
	la $a1, L4
	jal instructionCount	# checks for subprogram
	add $s0, $v0, $0
	add $s1, $v1, $0
	
	la $a0, spText
	li $v0, 4
	syscall
	
	la $a0, addText
	li $v0, 4
	syscall
	
	li $v0, 1
    	move $a0, $s0
    	syscall
	
	la $a0, enter
	li $v0, 4
	syscall
	
	la $a0, lwText
	li $v0, 4
	syscall
	
	li $v0, 1
    	move $a0, $s1
    	syscall
	
	li $v0,10  # system call to exit
	L2:syscall	# end address for main
	
instructionCount:	
	L3:addi $sp, $sp, -20  # beginning address for subprogram
	sw $s0, 16($sp) 
	sw $s1, 12($sp) 
	sw $s2, 8($sp) 
	sw $s3, 4($sp) 
	sw $s4, 0($sp) 
	
	add $v0, $0, $0
	add $v1, $0, $0
	add $s0, $0, $a0
	add $s1, $a1, 4
	
	for:
	lw $s4, 0($s0)
	slt $s2, $s0, $s1 # $s0 = i 
	beq $s2, $0, done # if $s2 == 0, branch to done
	srl $s3, $s4, 26
	
	bne $s3, $0, if1 # if i != j, skip if block
	andi $s3, $s4, 63
	bne $s3, 32, if1
	add $v0, $v0, 1
	if1:
	srl $s3, $s4, 26
	
	bne $s3, 35, if2 # if i != j, skip if block
	add $v1, $v1, 1
	if2:
		
	addi $s0, $s0, 4 #increment
	j for
	done:
	
	lw $s4, 0($sp) 
	lw $s3, 4($sp) 
	lw $s2, 8($sp) 
	lw $s1, 12($sp)
	lw $s0, 16($sp)
	addi $sp, $sp, 20 
	
	L4: jr $ra  # end address for subprogram
	
	
#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
space: .asciiz " "
mainText: .asciiz "In main:\n\n"
spText: .asciiz "In subprogram:\n\n"
addText: .asciiz "Add instructions: "
lwText: .asciiz "Lw instructions: "
enter: .asciiz "\n"

##
## end of file Prelim1.asm


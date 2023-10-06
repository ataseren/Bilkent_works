## CS224
## Lab 2
## Section 1
## Ata Seren
## 21901575

## Lab Work 2 Part 4
## Reverses given decimal and prints it in hex form
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:
	lw $a0, pattern
	lw $a1, int
	lw $a2, pSize
	jal countPattern
	add $s0, $0, $v0

	la $a0, original
	li $v0, 4
	syscall
	li $v0, 34
	move $a0, $a1
	syscall
	la $a0, enter
	li $v0, 4
	syscall
	la $a0, found
	li $v0, 4
	syscall
	move $a0, $s0
	li $v0, 1
	syscall
	
	
	li $v0,10  # system call to exit
	syscall	#    bye bye
	
	
	
countPattern:
	addi $sp, $sp, -32
	sw $s0, 28($sp)
	sw $s1, 24($sp) 
	sw $s2, 20($sp) 
	sw $s3, 16($sp) 
	sw $s4, 12($sp) 
	sw $s5, 8($sp)
	sw $s6, 4($sp)
	sw $s7, 0($sp)
	
	add $s6, $0, 32
	add $s1, $0, $a2
	div  $s1, $s6, $s1
	add $s0, $0, $a1
	add $s2, $0, $0 # int i = 0
	lw $s3, max
	sub $s4, $s6, $a2
	srlv $s4, $s3, $s4
	add $v0, $0, $0
	for:
	beq $s2, $s1, done # if $s3 == 0, branch to done	
	and $s5, $s0, $s4
	mul $s7, $a2, $s2
	srlv $s5, $s5, $s7
	bne $s5, $a0, L1 # if i != j, skip if block
	add $v0, $v0, 1 # if block: f = g + h
	L1:
	sllv $s4, $s4, $a2
	add $s2, $s2, 1 #increment
	j for
	done:
	lw $s7, 0($sp) 
	lw $s6, 4($sp)
	lw $s5, 8($sp) 
	lw $s4, 12($sp) 
	lw $s3, 16($sp) 
	lw $s2, 20($sp) 
	lw $s1, 24($sp) 
	lw $s0, 28($sp) 
	addi $sp, $sp, 32 # deallocate stack space
	jr $ra # return to caller
	
	


#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
max:	.word 4294967295
int:	.word -252645136
pattern:	.word 3
original:	.asciiz "Original hexadecimal: "
found:	.asciiz "Amount of pattern found: "
pSize:	.word 4
space: .asciiz "                    "
enter: .asciiz "\n"


##
## end of file Prelim2.asm


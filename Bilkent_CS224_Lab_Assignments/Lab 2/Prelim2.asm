## CS224
## Lab 2
## Section 1
## Ata Seren
## 21901575

## Preliminary Work 2 Part 2
## Reverses given decimal and prints it in hex form
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:
	la $a0, original
	li $v0, 4
	syscall
	li $v0, 34
	lw $a0, int
	syscall
	la $a0, enter
	li $v0, 4
	syscall
	
	add $v0, $0, $0
	lw $a0, int
	add $a1, $0, 1
	jal reverseDecimal
	add $s4, $v0, $0
	
	la $a0, reverse
	li $v0, 4
	syscall
	li $v0, 34
	add $a0, $0, $s4
	syscall
	la $a0, enter
	li $v0, 4
	syscall
	
	li $v0,10  # system call to exit
	syscall	#    bye bye
	
	
	
reverseDecimal:
	addi $sp, $sp, -16 
	sw $s0, 12($sp) 
	sw $s1, 8($sp) 
	sw $s2, 4($sp) 
	sw $s3, 0($sp) 
	
	add $s0, $0, $a1
	add $s1, $0, 31 #int i = 0
	for:
	beq $s1, -1, done # if $s3 == 0, branch to done	
	and $s3, $s0, $a0
	sllv $s3, $s3, $s1
	or $v0, $v0, $s3
	sll $s0, $s0, 1
	
	sub $s1, $s1, 2 #increment
	j for
	done:
	
	add $s1, $0, 1 #int i = 0
	for2:
	beq $s1, 33, done2 # if $s3 == 0, branch to done	
	and $s3, $s0, $a0
	srlv $s3, $s3, $s1
	or $v0, $v0, $s3
	sll $s0, $s0, 1
	add $s1, $s1, 2 #increment
	j for2
	done2:
	
	lw $s3, 0($sp) 
	lw $s2, 4($sp) 
	lw $s1, 8($sp) 
	lw $s0, 12($sp) 
	addi $sp, $sp, 16 # deallocate stack space
	jr $ra # return to caller
	
	


#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
int:	.word 3
original:	.asciiz "Original hexadecimal: "
reverse:	.asciiz "Reverse hexadecimal: "
space: .asciiz "                    "
enter: .asciiz "\n"


##
## end of file Prelim2.asm


## CS224
## Lab 1
## Section 1
## Ata Seren
## 21901575

## Preliminary Work 1 Part 1
## Checks an array if it is symmetric or not
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 
	__start:
	addi $s0,$0,1 #boolean
	lw $t1, arrsize # $t1 = arrsize
	la $t0, array #array address

	addi $s2, $0, 0 # i = 0
	div $s6, $t1, 2 # for "for loop"


	loop:
	slt $s7, $s2, $s6 # if (i < arrsize/2) 
	beq $s7, $0, done # if $s7 == 0, branch
	sll $t2, $s2, 2 # $t2 = i*4 (byte offset)
	add $t3, $t2, $t0 # address of array[i]
	sub $t4, $t1, 1
	sll $t4, $t4, 2
	sub $t4, $t4, $t2
	add $t4, $t0, $t4
	lw $t6, 0($t3) # $t6 = array[i]
	lw $t7, 0($t4)# $t7 = array[arrsize-1-i]
	beq $t6, $t7, L1 # if i == j, skip if block
	add $s0, $0, $0 # if block
	L1:
	addi $s2, $s2, 1 
	j loop
	done:
	
	bne $s0, $0, else # if 
	la $a0,strn	
	li $v0,4	# system call to print
	syscall		#   out a string
	j L2 # skip past the else block
	else:
	la $a0,stry	
	li $v0,4	
	syscall		
	L2:
	li $v0,10		# system call to exit
	syscall		#    bye bye

#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
stry:	.asciiz "The above array is symmetric"
strn:	.asciiz "The above array is not symmetric"
array: .word 1, 2, 5, 2, 1
arrsize: .word 5


##
## end of file Prelim1.asm

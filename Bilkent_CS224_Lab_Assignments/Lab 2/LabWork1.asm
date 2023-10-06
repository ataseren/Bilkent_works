## CS224
## Lab 2
## Section 1
## Ata Seren
## 21901575

## Lab Work 1 Part 3
## A program that takes elements and size for a dynamically allocated array,
## prints the array and finds min and max elements
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:
	
	jal getArray
	add $s6, $0, $v0
	add $s7, $0, $v1
	
	bne $s7, $0, arrayYesMain
	j endProgramMain
	arrayYesMain: 
	la $a0, enter
	li $v0, 4
	syscall
	move $a0, $s6
	move $a1, $s7	
	jal checkSymmetric
	bne $v0, $0, else  
	la $a0,strn	
	li $v0,4	
	syscall		
	j L2 
	else:
	la $a0,stry	
	li $v0,4	
	syscall		
	L2:
	
	la $a0, enter
	li $v0, 4
	syscall
	move $a0, $s6
	move $a1, $s7
	jal findMinMax
	
	add $t0, $0, $v0
	add $t1, $0, $v1
	
	la $a0, max
	li $v0, 4
	syscall
	move $a0,$t1 
	li $v0, 1
	syscall
	la $a0, enter
	li $v0, 4
	syscall
	la $a0, min
	li $v0, 4
	syscall
	move $a0, $t0
	li $v0, 1
	syscall
	
	endProgramMain:
	li $v0,10  # system call to exit
	syscall	#    bye bye

getArray:
	
	addi $sp, $sp, -20 # make space on stack
	sw $s0, 16($sp) # save $s2 on stack
	sw $s1, 12($sp) # save $s2 on stack
	sw $s2, 8($sp) # save $s2 on stack
	sw $s3, 4($sp) # save $s3 on stack	
	sw $s4, 0($sp) # save $s4 on stack
	
	la $a0, getSize
	li $v0, 4
	syscall
	li $v0, 5	# syscall 5 reads an integer
	syscall
	add $s0, $0, $v0 # saved an int
	la $a0, enter
	li $v0, 4
	syscall
	la $a0, sizeIs
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $s0
	syscall
	la $a0, enter
	li $v0, 4
	syscall
	
	mul $s1, $s0, 4
	move $a0, $s1 # The bytes size of the memory location to be allocated
	li $v0, 9 # Used for dynamic storage allocation
	syscall # Perform storage allocation by using values stored in $a0 (memory size) and $v0 (action to be performed by syscall).
	add $s1, $0, $v0
	
	add $s2, $0, $0 #int i = 0
	for:
	slt $s3, $s2, $s0 # if (i < arrsize) $s3 = 1, else $s3 = 0
	beq $s3, $0, done # if $s3 == 0, branch to done
	sll $s4, $s2, 2 # $t0 = i*4 (byte offset)
	add $s4, $s4, $s1
	li $v0, 5	# syscall 5 reads an integer
	syscall
	sw $v0, 0($s4) # saved an int
	add $s2, $s2, 1 #increment
	j for
	done:
	
	add $v0, $0, $s1
	add $v1, $0, $s0
	
	lw $s4, 0($sp) # restore $s4 from stack
	lw $s3, 4($sp) # restore $s3 from stack
	lw $s2, 8($sp) # restore $s2 from stack
	lw $s1, 12($sp) # restore $s1 from stack
	lw $s0, 16($sp) # restore $s0 from stack
	addi $sp, $sp, 20 # deallocate stack space
	
	move $a0, $v0		
	move $a1, $v1
	
	addi $sp, $sp, -12 # make space on stack
	sw $ra, 8($sp) # save $s2 on stack
	sw $s6, 4($sp) # save $s2 on stack
	sw $s7, 0($sp) # save $s2 on stack
	add $s6, $0, $v0
	add $s7, $0, $v1
	
	bne $s7, $0, arrayYes
	la $a0, empty
	li $v0, 4
	syscall
	j endProgram
	arrayYes: 
	jal printArray
	endProgram:
	add $v0, $s6, $0
	add $v1, $s7, $0
	lw $s7, 0($sp) # restore $s0 from stack
	lw $s6, 4($sp) # restore $s3 from stack
	lw $ra, 8($sp) # restore $s2 from stack
	addi $sp, $sp, 4 # deallocate stack space
	
	jr $ra
	

printArray:
	
	addi $sp, $sp, -20 # make space on stack
	sw $s0, 16($sp) # save $s2 on stack
	sw $s1, 12($sp) # save $s2 on stack
	sw $s2, 8($sp) # save $s2 on stack
	sw $s3, 4($sp) # save $s3 on stack	
	sw $s4, 0($sp) # save $s4 on stack	
	add $s0, $0, $a0
	add $s1, $0, $a1
	add $s2, $0, $0
	la $a0, arrPrint
	li $v0, 4
	syscall
	for2:
	slt $s3, $s2, $s1 # if (i < arrsize) $s3 = 1, else $s3 = 0
	beq $s3, $0, done2 # if $s3 == 0, branch to done
	sll $s4, $s2, 2 # $s4 = i*4 (byte offset)
	add $s4, $s0, $s4
	lw $s4, 0($s4) # $s4 = array[i]
	li $v0, 1
    	move $a0, $s4
    	syscall
    	la $a0, space
	li $v0, 4
	syscall
	add $s2, $s2, 1 #increment
	j for2
	done2:
	lw $s4, 0($sp) # restore $s4 from stack
	lw $s3, 4($sp) # restore $s3 from stack
	lw $s2, 8($sp) # restore $s2 from stack
	lw $s1, 12($sp) # restore $s1 from stack
	lw $s0, 16($sp) # restore $s0 from stack
	addi $sp, $sp, 20 # deallocate stack space
	jr $ra # return to caller
	
checkSymmetric:
	addi $sp, $sp, -32 
	sw $s0, 28($sp) 
	sw $s1, 24($sp) 
	sw $s2, 20($sp) 
	sw $s3, 16($sp) 
	sw $s4, 12($sp) 
	sw $s5, 8($sp) 
	sw $s6, 4($sp) 
	sw $s7, 0($sp)
	
	add $s0, $0, $a0
	add $s1, $0, $a1

	addi $s3,$0,1 #boolean
	div $s4, $s1, 2 # for "for loop"
	for3:
	slt $s5, $s2, $s4 # if (i < arrsize/2) 
	beq $s5, $0, done3 # if $s5 == 0, branch
	sll $s5, $s2, 2 # $s5 = i*4 (byte offset)
	add $s6, $s5, $s0 # address of array[i]
	lw $s6, 0($s6) # $s6 = array[i]
	sub $s7, $s1, 1
	sll $s7, $s7, 2
	sub $s7, $s7, $s5
	add $s7, $s0, $s7
	lw $s7, 0($s7) # $s7 = array[arrsize-1-i]
	beq $s6, $s7, L1 # if i == j, skip if block
	add $s3, $0, $0 # if block
	L1:
	addi $s2, $s2, 1 
	j for3
	done3:
	add $v0, $0, $s3
	
	lw $s7, 0($sp) 
	lw $s6, 4($sp) 
	lw $s5, 8($sp) 
	lw $s4, 12($sp) 
	lw $s3, 16($sp) 
	lw $s2, 20($sp) 
	lw $s1, 24($sp)
	lw $s0, 28($sp)
	addi $sp, $sp, 32 
	jr $ra # return to caller
	
findMinMax:
	addi $sp, $sp, -24 
	sw $s0, 20($sp) 
	sw $s1, 16($sp) 
	sw $s2, 12($sp) 
	sw $s3, 8($sp) 
	sw $s4, 4($sp) 
	sw $s5, 0($sp) 
	
	add $s0, $0, $a0
	add $s1, $0, $a1
	
	lw $v1, 0($s0)	#max
	lw $v0, 0($s0)	#min
	addi $s2, $0, 0 # i = 0
	for4:
	slt $s3, $s2, $s1 # if (i < arrsize) $t1 = 1, else $t1 = 0
	beq $s3, $0, done4 # if $t1 == 0, branch to done
	sll $s4, $s2, 2 # $t0 = i*4 (byte offset)
	add $s4, $s4, $s0
	lw $s4, 0($s4) # $s4 = array[i]
	slt $s5, $s4, $v0 # if (i < arrsize) $s5 = 1, else $s5 = 0
	beq $s5, $0, L3 
	add $v0, $s4,$0
	L3:
	slt $s5, $v1, $s4 
	beq $s5, $0, L4 # if i != j, skip if block
	add $v1, $s4,$0
	L4:
	add $s2, $s2, 1 #increment
	j for4
	done4:
	
	lw $s5, 0($sp) 
	lw $s4, 4($sp) 
	lw $s3, 8($sp) 
	lw $s2, 12($sp) 
	lw $s1, 16($sp)
	lw $s0, 20($sp)
	addi $sp, $sp, 24 # deallocate stack space
	jr $ra # return to caller
	

#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
empty: .asciiz "There is no array. \n Because of that, we can't inspect any symmetry, \n or determine minium and maximum values."
getSize: .asciiz "Enter size: "
sizeIs:	.asciiz " Enter elements for your array of size "
space: .asciiz " "
stry:	.asciiz "The array is symmetric."
strn:	.asciiz "The array is not symmetric."
enter: .asciiz "\n"
arrPrint: .asciiz "Array: "
min: .asciiz "Min: "
max: .asciiz "Max: "

##
## end of file LabWork1.asm


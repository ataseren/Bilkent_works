## CS224
## Lab 1
## Section 1
## Ata Seren
## 21901575

## Lab Work 1 Part 3
## Computes average of elements of given array and
## finds its maximum and minimum elements 
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:
	la $s0, array		
	lw $s1, arrsize 
	addi $s2, $0, 0 # i = 0
	addi $s3, $0, 0 # sum = 0
	for:
	slt $t1, $s2, $s1 # if (i < arrsize) $t1 = 1, else $t1 = 0
	beq $t1, $0, done # if $t1 == 0, branch to done
	sll $t2, $s2, 2 # $t0 = i*4 (byte offset)
	add $t2, $t2, $s0
	lw $t3, 0($t2) # $t3 = array[i]
	add $s3, $s3, $t3
	add $s2, $s2, 1 #increment
	j for
	done:
	div $s3, $s3, $s1	#avg
	
	lw $t4, 0($s0)	#max
	lw $t5, 0($s0)	#min
	addi $s2, $0, 0 # i = 0
	for2:
	slt $t1, $s2, $s1 # if (i < arrsize) $t1 = 1, else $t1 = 0
	beq $t1, $0, done2 # if $t1 == 0, branch to done
	sll $t2, $s2, 2 # $t0 = i*4 (byte offset)
	add $t2, $t2, $s0
	lw $t3, 0($t2) # $t3 = array[i]
	slt $t1, $t3, $t4 # if (i < arrsize) $t1 = 1, else $t1 = 0
	bne $t1, $0, L1 
	add $t4, $t3,$0
	L1:
	slt $t1, $t5, $t3 # if (i < arrsize) $t1 = 1, else $t1 = 0
	bne $t1, $0, L2 # if i != j, skip if block
	add $t5, $t3,$0
	L2:
	add $s2, $s2, 1 #increment
	j for2
	done2:
	
	la $a0, first
	li $v0, 4
	syscall
	
	addi $s2, $0, 0 # i = 0
	for3:
	slt $t1, $s2, $s1 # if (i < arrsize) $t1 = 1, else $t1 = 0
	beq $t1, $0, done3 # if $t1 == 0 (i >= 101), branch to done
	sll $t2, $s2, 2 # $t0 = i*4 (byte offset)
	add $t2, $t2, $s0
	lw $t3, 0($t2) # $t3 = array[i]
	li $v0, 34
	add $a0, $0, $t2
	syscall
	la $a0, space
	li $v0, 4
	syscall
	li $v0, 1
	move $a0, $t3
	syscall
	la $a0, enter
	li $v0, 4
	syscall
	add $s2, $s2, 1 #increment
	j for3
	done3:
	
	la $a0, avg
	li $v0, 4
	syscall
	
	li $v0, 1
    	move $a0, $s3
    	syscall
    	
    	la $a0, enter
	li $v0, 4
	syscall
    	
    	la $a0, max
	li $v0, 4
	syscall
	
    	li $v0, 1
    	move $a0, $t4
    	syscall
    	
    	la $a0, enter
	li $v0, 4
	syscall
	
	la $a0, min
	li $v0, 4
	syscall
	
    	li $v0, 1
    	move $a0, $t5
    	syscall
	
	li $v0,10  # system call to exit
	syscall	#    bye bye

	
	


#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
array:	.word 30,82,105,2,3,3,2,9
arrsize: .word 8
first: .asciiz "Memory Address Position (hex)	Array Element Value (int)\n =============================	=========================\n"
space: .asciiz "                    "
enter: .asciiz "\n"
avg: .asciiz "Average: "
min: .asciiz "Min: "
max: .asciiz "Max: "

##
## end of file LabWork1.asm


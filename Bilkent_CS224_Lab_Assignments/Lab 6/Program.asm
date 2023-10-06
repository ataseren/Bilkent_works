## CS224
## Lab 6
## Section 1
## Ata Seren
## 21901575

## Preliminary Work Part 1.4
## A program that creates a NxN array
## and operates on it. 
#################################
#					 	#
#		text segment		#
#						#
#################################

	.text		
	.globl __start 

__start:

	la $a0, welcome
	li $v0, 4
	syscall
	la $a0, enter
	li $v0, 4
	syscall
	la $a0, input
	li $v0, 4
	syscall
printOps:la $a0, op
	li $v0, 4
	syscall
	la $a0, enter
	li $v0, 4
	syscall
inputPage:la $a0, opValue
	li $v0, 4
	syscall
	li $v0, 5	
	syscall
	
	beq $v0, 1, op1
	beq $v0, 2, op2
	beq $v0, 3, op3
	beq $v0, 4, op4
	beq $v0, 5, op5
	beq $v0, 6, op6
	beq $v0, 7, op7
	

op1:
	la $a0, op1text
	li $v0, 4
	syscall
	li $v0, 5 
	syscall
	add $s0, $0, $v0 #$s0 has N value
	mul $s1, $s0, $s0 #$s1 has size of array
	la $a0, op1done
	li $v0, 4
	syscall
	li $v0, 4 
	la $a0, enter
	syscall
	j inputPage
	
op2: 
	mul $a0, $s1, 4 #for displacement
	li $v0, 9 
	syscall 
	move $s2, $v0 #$s2 has base address for array
	add $t0, $0, $s2 
	addi $t1, $0, 1
	loopinit:
	sw $t1, 0($t0)
	addi $t0, $t0, 4
	addi $t1, $t1, 1
	ble $t1, $s1, loopinit
	li $v0, 4 
	la $a0, op2done
	syscall
	li $v0, 4 
	la $a0, enter
	syscall
	j inputPage
	
op3:
	la $a0, op3row
	li $v0, 4
	syscall
	li $v0, 5 
	syscall
	add $s3, $0, $v0 #$s3 has row value
	la $a0, op3column
	li $v0, 4
	syscall
	li $v0, 5 
	syscall
	add $s4, $0, $v0 #$s4 has column value
	subi $t0, $s3, 1 
	mul $t0, $t0, $s0
	mul $t0, $t0, 4
	subi $t1, $s4, 1
	mul $t1, $t1, 4
	add $t0, $t0, $t1 #$t0 = (rowNum - 1) x N x 4 + (colNum - 1) x 4
	add $t0, $t0, $s2 #$t0 has address of desired element
	li $v0, 4 
 	la $a0, op3done
	syscall
	li $v0, 1
	lw $a0, 0($t0) #$a0 has desired element
	syscall 
	li $v0, 4 
	la $a0, enter
	syscall
	j inputPage

op4:
	add $t1, $0, $0 #$t1 will hold average
	add $t2, $0, $s2 #base address stored in $t2 temporarily
	add $t3, $0, $s1 #size of array stored in $t3 temporarily
	looprow:
	lw $t0, 0($t2) #load the value in the matrix to $t0 ansd use it
	add $t1, $t1, $t0
	addi $t2, $t2, 4 #iterate over the matrix 
	subi $t3, $t3, 1
	bgt $t3, $0, looprow
	div $t1, $t1, $s1
	li $v0, 4 
	la $a0, op4done
	syscall
	li $v0, 1
	move $a0, $t1
	syscall 
	li $v0, 4 
	la $a0, enter
	syscall
	j inputPage

op5:
	add $t1, $0, $0 #$t1 will hold the average
	addi $t2, $0, 1 #row number
	addi $t3, $0, 1 #column number
	loopcol1:
	addi $t2, $0, 1 #row number
		loopcol2:
		subi $t4, $t2, 1
		mul $t4, $t4, $s0
		mul $t4, $t4, 4
		subi $t5, $t3, 1
		mul $t5, $t5, 4
		add $t4, $t4, $t5
		add $t4, $t4, $s2 #address of element
		lw $t0, 0($t4)
		add $t1, $t1, $t0
		addi $t2, $t2, 1
		ble $t2, $s0, loopcol2
	addi $t3, $t3, 1 #column number
	ble $t3, $s0, loopcol1
	div $t1, $t1, $s1
	li $v0, 4 
	la $a0, op5done
	syscall
	li $v0, 1
	move $a0, $t1
	syscall 
	li $v0, 4 
	la $a0, enter
	syscall
	j inputPage
op6:
	li $v0, 4 
	la $a0, enter
	syscall
	j printOps
op7:
	li	$v0, 10
	syscall

		 
	
	
	
	
	
	

#################################
#					 	#
#     	 data segment		#
#						#
#################################

	.data
welcome: .asciiz "Welcome! This program creates a square matrix in dimensions of your input.\nThen, it initializes consecutive values for its elements.\nYou can display data in desired index and get average value by using row-major or column-major fashion.\n"
input: .asciiz "Integer values for operations:\n"
op: .asciiz "1: Enter an integer value N for dimensions of NxN matrix\n2: Create an array with consecutive values\n3: Dispay desired element by entering row and column numbers\n4: Obtain the average of the matrix elements in a row-major and display\n5: Obtain the average of the matrix elements in a column-major and display\n6: Print operation list\n7: Exit the program"
opValue: .asciiz "Enter operation value: "
op1text: .asciiz "Enter N value: "
op1done: .asciiz "New array size saved."
op2done: .asciiz "New array initalized with last saved N value and filled with consecutive values."
op3row: .asciiz "Enter row value for desired element: "
op3column: .asciiz "Enter column value for desired element: "
op3done: .asciiz "Value at given location: "
op4done: .asciiz "Average of matrix elements by using row-major fashion: "
op5done: .asciiz "Average of matrix elements by using column-major fashion: "
space: .asciiz " "
enter: .asciiz "\n"
line:	.asciiz "\n --------------------------------------"

##
## end of file


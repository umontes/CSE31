.data 
str0: .asciiz "Welcome to BobCat Candy, home to the famous BobCat Bars!\n"
# Declare any necessary data here

str1: .asciiz "Please enter the price of a BobCat Bar:\n"
str2: .asciiz "Please enter the number of wrappers needed to exchange for a new bar: \n"
str3: .asciiz "How much money do you have? \n"
str4: .asciiz "Good! Let me run the number...\n"
str5: .asciiz "You first buy "
str5.1: .asciiz " bars.\n"
str6: .asciiz "Then, you will get another "
str6.1: .asciiz " bars.\n"
str7: .asciiz "With $"
str7.1: .asciiz ", you will receive a maximum of "
str7.2: .asciiz " BobCat Bars!"


.text

main:
		#This is the main program.
		#It first asks user to enter the price of each BobCat Bar.
		#It then asks user to enter the number of bar wrappers needed to exchange for a new bar.
		#It then asks user to enter how much money he/she has.
		#It then calls maxBars function to perform calculation of the maximum BobCat Bars the user will receive based on the information entered. 
		#It then prints out a statement about the maximum BobCat Bars the user will receive.
		
		      addi $sp, $sp -16	# Feel free to change the increment if you need for space.
			#sw $ra, 0($sp)
			# Implement your main here
		
		      li $v0, 4
		      la $a0, str0
		      syscall 		# prints, "Welcome to BobCat Candy, home to the famous BobCat Bars!\n"
		
		      li $v0, 4
		      la $a0, str1
		      syscall			# prints, "Please enter the price of a BobCat Bar:\n" (price)
		      li $v0, 5
		      syscall			# takes the input which was asked for by str1
		      add $s0, $v0, $0
		
		      li $v0, 4
		      la $a0, str2
		      syscall			# prints, "Please enter the number of wrappers needed to exchange for a new bar: \n" (n)
		      li $v0, 5
		      syscall			# takes the input which was asked for by str2
		      add $s1, $v0, $0
		
		      li $v0, 4
		      la $a0, str3
		      syscall			# prints, "How much money do you have? \n" (money)
		      li $v0, 5
		      syscall			# takes the input which was asked for by str3
		      add $s2, $v0, $0
		
		      li $v0, 4
		      la $a0, str4
		      syscall			# prints, "Good! Let me run the number...\n"
			
		      div $s2, $s0
		      mflo $a0
		      
		      sw $s2, 12($sp)
		      
		      beq $a0, $0, print		
		
		      li $v0, 4
		      la $a0, str5
		      syscall			# prints, "You first buy "
		      
		      li $v0, 1
		      div $s2, $s0
		      mflo $a0
		      syscall			# prints the quotient (the initial number of bars)
		      li $v0, 4
		      la $a0, str5.1		# prints, " bars.\n"
		      syscall
		
		      sw $s0, 4($sp)		# saves original value of price (price of one bar)
		      sw $s1, 8($sp)		# saves original value of n (number of wrappers needed to exchange for one bar)
		      sw $s2, 12($sp)		# saves original value of money (amount of money you have)

		      add $a0, $s0, $0
		      add $a1, $s1, $0
		      add $a2, $s2, $0

		      j maxBars 	# Call maxBars to calculate the maximum number of BobCat Bars

		# Print out final statement here
print:
		      li $v0, 4
		      la $a0, str7
		      syscall			# prints, "With $"
		
		      lw $s2, 12($sp)
		      add $a0, $s2, $0
		      li $v0, 1
		      syscall
		
		      li $v0, 4
		      la $a0, str7.1
		      syscall			# prints, ", you will receive a maximum of "
		
		      add $a0, $a1, $0
		      li $v0, 1
		      syscall
		
		      li $v0, 4
		      la $a0, str7.2
		      syscall			# prints, "BobCat Bars!"

		      j end			# Jump to end of program



maxBars:
		# This function calculates the maximum number of BobCat Bars.
		# It takes in 3 arguments ($a0, $a1, $a2) as n, price, and money. It returns the maximum number of bars
		
		      #sw $ra, 0($sp)
		
		      div $a2, $a0		# money/price = initial
		      mflo $a3	
		      add $a2, $0, $0
		      sw $a3, 16($sp)
		
		
		
		# $a1 and $a3 are going to be the arguments for newBars. They are n(number of wrappers needed for one bar) and initial(initial bars for the money)
		      jal newBars 	# Call a helper function to keep track of the number of bars.
		
		      lw $a3, 16($sp)
		      add $t0, $s3, $0
		      
		      add $a1, $a3, $t0
		
		      #lw $ra, 0($sp)
		   
		      j print
		# End of maxBars

newBars:
		  # This function calculates the number of BobCat Bars a user will receive based on n.
		  # It takes in 2 arguments ($a0, $a1) as number of bars so far and n.
		
		      div $a3, $a1
		      mflo $s0
		
		      bne $s0, $0, not_zero	
		
		      add $a0, $0, $0
		
		      jr $ra
		  # End of newBars
		
not_zero:	      li $v0, 4
		      la $a0, str6	
		      syscall
		
		      add $a0, $s0, $0
		      li $v0, 1
		      syscall
		
		      li $v0, 4
		      la $a0, str6.1
		      syscall
		
		      add $a3, $s0, $0
		
		      add $s3, $s0, $s3
		
		      j newBars
end: 
		# Terminating the program

		      addi $sp, $sp 16
		      li $v0, 10 
		      syscall

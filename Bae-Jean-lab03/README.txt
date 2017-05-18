======README=======

#Lab03

Bae Jean (811-413-786)

## Instructions

To clean my code, type make clean in the command line:

$ make clean

To compile my code, type make all:

$ make all

To run my code after compiling, type ./(program name)  (while in the Bae-Jean-lab03 directory)

$ ./bitsum

## Reflection
   In my brainstorm, I thought I was going to use a counter for the exclusive program but that 
was not the case. I used the XOR operator to XOR each number in the stringstream to see
which number occurs once. I did not know what to do initially for prime sum but I 
soon figured that a number is not prime if it is divisible by a number between 2 and
a number before it but the execution time for that took too long so I took the square root of the number being
passed into my bool function and had a for loop that modded every number from 2 to less than or equal to the number 
being passed. I had a for loop and called the bool function called isPrime on every number between 2 and 
long long max is prime. For the armstrong numbers, I just divided a number between 100-999 by 100 and then %100 
to get the remainder and did that for the tens digit and ones digits by modding and dividing by 10 and 1 respectively. 
I cubed those numbers individually and added them up and compared to the number within the range 100-999 in my for loop.
For bitsum, I took the integer and used the & operator with 1. If it equaled 1, then I did count++ for
my counter. Then I shifted one bit to the right and continued to do that while the number > 1.
For endtime, I thought I'd simply just add the start time and duration together and take that total and mod
by some number in my brainstorm. In actuality, I separated the hours and miinutes by modding and dividing by 100.
If the minutes of the duration and start time added together exceeded 60, I added an hour to the end time.
If the end time was greater than 2400, I made it restart from 0.

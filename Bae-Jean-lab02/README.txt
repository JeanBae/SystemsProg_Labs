======README=======

#Lab02

Bae Jean (811-413-786)

## Instructions

To clean my code, type make clean in the command line:

$ make clean

To compile my code, type make all:

$ make all

To run my code after compiling, type ./(program name)  (while in the Bae-Jean-lab02 directory)

$ ./stat

## Reflection
   In my brainstorm I knew I had to use stringstream but it took some research to understand
how it worked. I made two stringstreams for the stat problem so that I could take in all numbers 
to get the average and then made another stringstream copy to find the variance. For minmax, I 
used the constants for my variables. For numbers, I used bitset and used the to_string 
function to convert and store this into a string variable. From there, I inserted the 
apostrophes and printed the binary, octal, decimal, hexadecimal and the statements.For degrees, 
I used the formula to convert Celsius to Fahrenheit and had to use setprecision to format the integer 
to two decimal places. Time just required a formula to convert the seconds to hours, minutes and seconds.

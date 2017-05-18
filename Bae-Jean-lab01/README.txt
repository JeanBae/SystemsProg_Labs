======README=======

#Lab01

Bae Jean (811-413-786)

## Instructions

To clean my code, type make clean in the command line:

$ make clean

To compile my code, type make lab01:

$ make lab01

To run my code after compiling, type ./lab01 (while in the Bae-Jean-lab01 directory)

$ ./lab01

## Reflection

   I did not really know how to tackle the problem in my initial brainstorm and initially
thought about just shifting left and right while incorporating the bitwise operators.
After learning about masks, I decided to incorporate that into my code and have that
"erase" or "preserve" the previous values stored in order to set or retrieve those values.
The mask allowed me to compare a set of 0's or 1's against the value stored at that index.
The number of places to shift and how to generate a mask were the most difficult parts of the lab
but after realizing that everything was 2 to the 32/k power, it made shifting the bits a little
more obvious and creating the mask to be (1<<(32/k))-1 also more obvious.


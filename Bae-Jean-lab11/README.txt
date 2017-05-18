======README=======

#lab11

Jean Bae (811-413-786)


## Instructions

To clean my code, type make clean in the command line:

$ make clean

To compile my code, type make all:

$ make all

To run my code after compiling, type ./stat (while in the Bae-Jean-lab09 directory)

$ ./cp [source file][target file]

## Reflection

I initially thought this lab would be like our remove lab10 and it kind of was since we are copying files recursively.
The hardest part was copying a directory to another directory. Another thing to keep in mind was
permissions so I had to use fchmod after creating a new file to copy the source file's permissions.
I used the link below as a reference.

https://cboard.cprogramming.com/c-programming/143382-implementation-linux-cp-copy-command-c-language.html

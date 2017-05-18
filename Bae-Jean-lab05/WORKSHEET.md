1. In (5.3), what is the entire terminal command that you used to download ncurses?
   wget http://ftp.gnu.org/gnu/ncurses/ncurses-6.0.tar.gz

2. In (5.4), what do each of the options zxvf that were passed to the tar utility denote?
   z is unzip, x is extract, v is print filenames verbosely, f denotes that the following is a 
   filename

3. In (5.6), what is the purpose of executing the configure script?
   it matches the libraries on my computer with those required by the program before
   compiling from the source code

4. In (5.6), what does the --prefix option that was passed to the configure script denote?
   the directory named by the --prefix option is the location that will hold documentation,
   configuration files and data, so in my case, the home directory

5. In (5.8), where do the compiled and linked files get installed to when “make install” is executed?
   They're installed to the home directory in  ~/include and ~/lib folders

6. In (6.1), we change the LD LIBRARY PATH environmental variable. What is this variable generally used for? 
   this is used to set the path, and lets other programs know where to find the ncurses library   

7. In (6.1), why does LD LIBRARY PATH appear twice in the export statement?
   one is the environmental variable and you're setting the library path to be in your home directory which is why
   you have the second one

8. In (6.1), why do we place the export statement in your .bash login or .bash profile file?
   It's there so you don't have to link to the library each time, it does it when you log in

9. In (7), what do each of the lines of code (A)–(E) do?
   (A) initializes the terminal in curses mode and allocates memory for the present window
   (B) prints "Hello World !!!" behind the scenes
   (C) refresh() actually dumps contents of what happens in (B) onto the actual screen
   (D) waits for the user to press a key to get input
   (E) resets the screen

10. In (7), why is the -lncurses option needed when compiling the sample code? 
    The ncurses library needs to be compiled along with the source file. You need to
    prep the library from its location before using it.

11. In (7), why is the -lncurses option needed when linking the sample code?
    This is where the actual linking occurs.   

#include <ncurses.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::string;
using std::ifstream;
using std::endl;


int main(const int argc, const char * argv []){
  string fName{argv[1]};
  ifstream myFile(fName);
  string line;
  int row, col;
  WINDOW *pad;
  int pos{0};
  int ch{0};

   if(argc != 2){//if there are not two arguments, print an error
     cout <<"Error, try again" << endl;
   }

   else{//else do the below
     initscr();
     curs_set(0);//setting the cursor to not be visible
     getmaxyx(stdscr, row, col);
     pad = newpad(row + 30000, col); //adding extra lines to ensure that the window is large enough for the file
     keypad(pad, TRUE);
  
     if(myFile.is_open()){
       while(getline(myFile, line)){
	 wprintw(pad, "%s\n", line.c_str()); 
       }
     }

     prefresh(pad, pos, 0, 0, 0, row-1, col);//refresh pad
     while(true){
       ch = wgetch(pad);
       switch(ch){//using switch statement to get the user's input

       case KEY_UP://check if up arrow is pressed
	 if(pos >= 0){
	   pos--;
	 }
	 prefresh(pad, pos, 0, 0, 0, row-1, col);//refresh pad
	 break;

       case KEY_DOWN://check if down arrows are pressed
	 pos++;
	 prefresh(pad, pos, 0, 0, 0, row-1, col);//refresh pad
	 break;	

       case KEY_F(1):
	 pos++;
	 prefresh(pad, pos, 0, 0, 0, row-1, col);//refresh pad
	 break;
       }
       if(ch!=KEY_UP && ch!=KEY_DOWN && ch!=KEY_F(1)){//if key entered does not equal up or down, break out of the while loop
       break;
	}
    }
   }
   delwin(pad);//delete pad
   endwin();//close ncurses mode
   myFile.close();//close file
  return EXIT_SUCCESS;    
  
}    
    

#include <cstdlib>
#include <ncurses.h>



int main() {
  initscr();                 // (A)
  printw("Hello World !!!"); // (B)
  refresh(); //c
  getch();//d
  endwin();//e
  return EXIT_SUCCESS;
} // main

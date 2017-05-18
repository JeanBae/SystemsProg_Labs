/**
 * This program prints the current working directory
 * @authors Stone Daniel & Jean Bae
 */
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int main(){
  char *cwd;
  char buffer[PATH_MAX + 1];
  cwd = getcwd(buffer,PATH_MAX + 1);
  if(cwd != NULL){
    cout << cwd << endl; 
  }

  return EXIT_SUCCESS;
}

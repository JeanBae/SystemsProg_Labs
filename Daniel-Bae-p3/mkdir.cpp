/**
 * This program will create a directory, if -p is specified it will make directories
 * within directories, if -m is specified, it will change mode
 * @authors Stone Daniel & Jean Bae
 */
#include <cstdlib>
#include <cerrno>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <libgen.h>
#include <getopt.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>

using std::cout;
using std::string;
using std:: endl;
using std::atoi;

void makeDir(const char * dir,  const char * mode, bool isP){
  char tmp[256];
  char *p = nullptr;
  size_t len = 0;
  unsigned long octal = 0;
  char  *stopstring;

  if(isP != true)
    {
      octal = strtoul(mode,&stopstring, 8);
      snprintf(tmp, sizeof(tmp),"%s", dir);
      len = strlen(tmp);
      if(mkdir(tmp,octal))
      perror("error ");
      chmod(tmp, octal);
    }
	    
  
  else
    {
      octal = strtoul(mode,&stopstring, 8);
      snprintf(tmp, sizeof(tmp),"%s", dir);
      len = strlen(tmp);
      if(tmp[len - 1] == '/')
	tmp[len - 1] = 0;
      for(p = tmp + 1; *p; p++)
	if(*p == '/') {
	  *p = 0;
	  mkdir(tmp, octal);
	  chmod(tmp, octal);
	  *p = '/';
	}
      mkdir(tmp, octal);
      chmod(tmp, octal);   
    }   
}


int main(int argc, char * argv[]){
  char *  mode = nullptr;
  char * name;
  bool p = false;
  bool m = false;


  if(argv[1] == NULL)
    {
      cout << "missing operand" << endl;
    }
  else{
    for(int i = 1; i < argc; i++){
      if(strcmp((argv[i]), "-m") == 0){
	i++;
	if(isdigit(*argv[i])){
	  mode = argv[i];
	  m = true;
	}
	
	else{
	  cout << "incorrect formatting" << endl;
	  break;
	}
	
      }//strcmp -m
      
      else if(strcmp((argv[i]), "-p") == 0){
	p = true;
      }//strcmp -p
      
      else
	{
	  name = argv[i];
	}
      
    }

    if(m == false)
      {
	makeDir(name, "0755", p);
      }
    else{
      makeDir(name, mode, p);
    }
  }    
    
}

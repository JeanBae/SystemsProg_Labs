/**
 * This program copies its input files to standard output otherwise takes in standard input
 * @authors Stone Daniel & Jean Bae
 */


/* Used code from stackoverflow for isInteger*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sstream>
using namespace std;
bool isInteger(const string & s)
{
  if(s.empty() || (!isdigit(s[0])))
    return false;
  char * p;
  strtol(s.c_str(), &p, 10);
  return (*p == 0);
}
int main(int argc,const char * argv[])
{
  int size,fd,lines=100,count=0;
  char buffer[1];//1024
  stringstream stream;
  string temp,file,numLines,arg;
  if(argc == 1)
    {
      while((size = read(STDIN_FILENO,buffer,1)) > 0)
	{
	  write(STDOUT_FILENO,buffer,1);
	}
    }
  for(int i = 1;argv[i] != NULL;i++)
    {
      arg = argv[i];
      count = 0;
      if(arg == "-n")
	{
	  if(argv[i+1] != NULL)
	    {
	      i++;
	      if(isInteger(argv[i]))
		lines = atoi(argv[i]);
	      else
		{
		  cout << "Requires Integer Value after '-n'" << endl;
		  exit(-1);
		}
	      
			     
	    }
	  else
	    {
	      cout << "Argument Required for '-n'" << endl;
	    }
	}
      else if(arg == "-")
	{
	  while((size = read(STDIN_FILENO,buffer,1)) > 0)
	    {
	      write(STDOUT_FILENO,buffer,1);
	    }
	}
      else if(arg[0] == '-' && isInteger(arg.substr(1)))
	{
	  lines = stoi(arg.substr(1));
	}
      else if(arg[0] == '-' && !(isInteger(arg.substr(1))))
	{
	  cout << "Invalid Line Count for n value." << endl;
	  exit(-1);
	}
      else
	{
	  fd = open(argv[i], O_RDONLY);
	  if(fd<0)
	    {
	      perror(argv[i]);
	      exit(-1);
	    }
	  while((size = read(fd,buffer,1)) > 0 && count < lines)
	    {
	      write(STDOUT_FILENO,buffer,1);
	      if(*buffer == '\n')
		count++; 
	    }
	}
    }
  if(fd==0)
    {
      while((size = read(STDIN_FILENO,buffer,1)) > 0)
	{
	  write(STDOUT_FILENO,buffer,1);
	}
    }
}

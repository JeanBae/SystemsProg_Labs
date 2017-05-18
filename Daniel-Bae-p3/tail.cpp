/**
 * This program will copy its input files to standard output beginning
 * at a designated place. Copying will begin at the point in file for -c number or -n number
 * @authors Stone Daniel & Jean Bae
 */
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <fcntl.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
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
  int size,fd,lines=10,count=0,bytes;
  char buffer[1];//1024
  stringstream stream;
  string temp,file,numLines,arg;
  bool n = true,c,f;
  vector<string> myVec;
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
      if(arg == "-n")
	{
	  if(argv[i+1] != NULL)
	    {
	      i++;
	      if(isInteger(argv[i]))
		lines = atoi(argv[i]);
	      else
		{
		  cout << "Not valid number for -n " << argv[i] << endl;
		  exit(-1);
		}
			     
	    }
	  else
	    {
	      cout << "Argument Required for '-n'" << endl;
	      exit(-1);
	    }
	}
      else if (arg == "-c")
	{
	  n = false;
	  c = true;
	  if(argv[i+1] != NULL)
	    {
	      i++;
	      if(isInteger(argv[i]))
		lines = atoi(argv[i]);
	      else
		{
		  cout <<  "Not valid number for -c " << argv[i] << endl;
		  exit(-1);
		}
	    }
	  else
	    {
	      cout << "Argument Required for -c" << endl;
	      exit(-1);
	    }
	  
	  
	}
      else if(arg == "-f")
	f = true;
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
      else
	{
	  cout << endl << "==> " << argv[i] << " <==" << endl;
	  fd = open(argv[i], O_RDONLY);
	  if(fd<0)
	    {
	      perror(argv[i]);  
	      //exit(-1);
	    }
	  while((size = read(fd,buffer,1)) > 0) //&& count < lines)
	    {
	      temp.append(buffer,1);
	      bytes++;
	      /*write(STDOUT_FILENO,buffer,1);*/
	      if(*buffer == '\n')
		count++; 
	    }
	  stream << temp;
	  string s;
	  if(n)
	    {
	      for(int j = 0;j<count;j++)
		{
		  getline(stream,s);
		  if(j >= (count-lines))
		    cout << s << endl;
		}
	      if(f)
		{
		  while((size = read(STDIN_FILENO,buffer,1)) > 0)
		    {
		      //write(STDOUT_FILENO,buffer,1);
		    }
		}
	    }
	  else if (c)
	    {
	      cout << temp.substr(bytes-lines);
	      if(f)
		{
		  while((size = read(STDIN_FILENO,buffer,1)) > 0)
		    {
		      //write(STDOUT_FILENO,buffer,1);
		    }
		}
	    }
	    
	}//n
    }
  if(fd == 0)
    {
      while((size = read(STDIN_FILENO,buffer,1)) > 0)
	{
	  //write(STDOUT_FILENO,buffer,1);
	}
    }
}

/*int main(int argc, char * argv[])
{
  //vector myVector;
  string numLines,numBytes;
  for(int i = 1;argv[i] != NULL;i++)
    {
      if(argv[i][0] == '-')
	{

	}
    }
    }*/

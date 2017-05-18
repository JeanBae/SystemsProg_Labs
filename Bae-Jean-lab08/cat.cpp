#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <fcntl.h>

using std::cout;
using std::endl;

int main(const int argc, const char * argv []){
  int n{0};
  const int BUFF_SIZE{1024};
  char buffer[BUFF_SIZE];
  const char * file;
  int fd;
  
  if(argc < 2){
    while((n=read(STDIN_FILENO,buffer,BUFF_SIZE))>0){
      if(write(STDOUT_FILENO, buffer, n) != n){

      }
    }
  }
  
  else{
    for(int i = 1; i < argc; i++){
      file = argv[i];
      fd = open(file, O_RDONLY);

      if((*file) == '-'){
	while((n=read(STDIN_FILENO,buffer,BUFF_SIZE))>0){
	  if(write(STDOUT_FILENO, buffer, n) != n){
	  }
	}//end while
      }//end if


      else{
	while((n = read(fd, buffer, BUFF_SIZE)) > 0){
	  if(write(STDOUT_FILENO, buffer, n) != n){
	    cout<< "error = " << strerror(errno) << endl;
	  }
	}//end while
      }//end else
    }//end for loop
    
  }//end large else

  if(fd < 0){
    exit(0);
  }
  
  close(fd);
  return EXIT_SUCCESS;
}

  

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <getopt.h>
#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <dirent.h>
#include <libgen.h>

using std::string;
using std::cout;
using std::endl;

void copyFile(const char * src, const char * t)
{
  int fd = 0;
  const int BUFF_SIZE = 1024;
  char buffer[BUFF_SIZE];
  struct stat sb;
  string path = "";
  int n = 0; 
  int fdTarget = 0;
  mode_t mode = 0;
  DIR * dir = nullptr;

  stat(src, &sb);
  mode = sb.st_mode;

  //if both source and target are regular files and exist
  if(stat(t, &sb) > -1 && S_ISREG(sb.st_mode)){
    fd = open(src, O_RDONLY);
    fdTarget = open(t, O_WRONLY| O_TRUNC,mode);
  
  while((n=read(fd,buffer,BUFF_SIZE))>0){
      write(fdTarget, buffer, n);
    }
    fchmod(fdTarget, mode);
  }

  //if source file exists and target file does not
  if(stat(t, &sb) != 0){
    fd = open(src, O_RDONLY);
    fdTarget = open(t, O_WRONLY| O_TRUNC |O_CREAT,mode);
  
    while((n=read(fd,buffer,BUFF_SIZE))>0){
      write(fdTarget, buffer, n);
      
    }
    fchmod(fdTarget, mode);
  }

  //if source file exists and is being copied into a directory
  if(stat(t, &sb) > -1 && S_ISDIR(sb.st_mode)){
    if((dir = opendir(t)) != NULL){
      fd = open(src, O_RDONLY);
      path = t;
      path += "/";
      path += src;
      fdTarget = open(path.c_str(), O_WRONLY|O_TRUNC|O_CREAT, mode);
      while((n=read(fd,buffer,BUFF_SIZE))>0){
	write(fdTarget, buffer, n);
	
      }
    }
    fchmod(fdTarget, mode);    
  }
  
  
  close(fd);
  close(fdTarget);
  
}



void copyDir(const char * src, const char * t)
{
  struct stat sb;
  struct stat tb;
  struct dirent *ent = nullptr;
  DIR * dir = nullptr;
  string s = "";
  string target = "";
  string entry;
  string input;
  unsigned long mode;

  stat(src, &sb);
  mode = sb.st_mode;

  //if source directory exists and target directory exists
  if(stat(src, &sb) > -1 && S_ISDIR(sb.st_mode) && stat(t, &tb) > -1 && S_ISDIR(tb.st_mode)){
      string str = "";
      str = t;
      str+="/";
      str+= src;
      src = str.c_str();
      mkdir(src,mode);
      chmod(src, mode);
      }

  //if source directory exists and target directory does not
    if(stat(src, &sb) > -1 && S_ISDIR(sb.st_mode) && stat(t, &tb) != 0){
      mkdir(t, tb.st_mode);
      chmod(t, mode);
    
    
      if((dir = opendir(src)) != NULL)
	{
	  struct stat rem;
	  while((ent = readdir(dir)) != NULL)
	    {
	      entry = ent->d_name;
	      if(entry == "." || entry == "..")
		continue;
	      s = src;
	      s += "/";
	      s += entry;
	      target = t;
	      target += "/";
	      target += entry;
	      stat(s.c_str(), &rem);
	      if(S_ISDIR(rem.st_mode)){
		copyDir(s.c_str(), target.c_str());
	      }
	      if(S_ISREG(rem.st_mode)){
		copyFile(s.c_str(), target.c_str());
	      }
	    }
	}
      }
      closedir(dir); 
    
}


int main(const int argc, char * argv []){
  

  int c{0};
  struct stat sb;
  char * source = nullptr;
  char * target = nullptr;
  bool isR = false;


  if(argc < 2)
    {
      printf("cp: missing operand\n");
    }

  else if(argc == 2)
    {
      cout << "cp: missing destination file operand after `" << argv[1] << "'"<< endl;
    }

  else{
    while((c = getopt(argc, argv, "r:")) != -1){
      switch(c)
	{
	case 'r':
	  source = optarg;
	  target = argv[optind];
	  //printf("The argument of -r is %s\n\n", source);
	  //printf("The target file is %s\n\n", target);
	  
	  if(target == NULL){
	    cout << "cp: missing destination file operand after `" << source << "'"<< endl;
	    return EXIT_SUCCESS;
	  }
	  isR = true;
	  break;
	}
    }//while
    
    if(isR == false){
      //if -r was not used and they're both directories
      if(stat(argv[1],&sb) > -1 && S_ISDIR(sb.st_mode)){
	if(stat(argv[2],&sb) > -1 && S_ISDIR(sb.st_mode))
	  cout << "cp: omitting directory `" << argv[1] << "'" << endl;
      }
      
      //if source file is a directory and target file is a regular file
      if(stat(argv[1], &sb) > -1 && S_ISDIR(sb.st_mode)){
	if(stat(argv[2], &sb) > -1 && S_ISREG(sb.st_mode)){
	  cout << "cp: omitting directory `" << argv[1] << "'" << endl;
	}
      }
      //if source file is a directory and target file does not exist
      if(stat(argv[1], &sb) > -1 && S_ISDIR(sb.st_mode)){
	if(stat(argv[2], &sb) !=0){
	  cout << "cp: omitting directory `" << argv[1] << "'" << endl;
	}
      }
            

      //if source file doesn't exist and target is not null
      if(stat(argv[1], &sb) !=0 && argv[2] != NULL){
	cout << "cp: cannot stat `"<< argv[1]<< "'" << " :No such file or directory" <<endl;
      }
      
      //****if source file exists and is a regular file
      if(stat(argv[1],&sb) > -1 && S_ISREG(sb.st_mode)){
	source = argv[1];

	//if target file exists and is a regular file
	if(stat(argv[2], &sb) > -1 && S_ISREG(sb.st_mode)){
	  target = argv[2];
	  copyFile(source, target);
	}
	//if target file does not exist, make a new file
	if(stat(argv[2], &sb) != 0){
	  target = argv[2];
	  //cout << "making a new file" << endl;
	  copyFile(source, target);
	}
	//if target file is a directory, copy regular file into directory
	if(stat(argv[2], &sb) > -1 && S_ISDIR(sb.st_mode)){
	  target = argv[2];
	  copyFile(source, target);
	}

      }//****if source file is a regular file
      
    }//if(isR == false)
    


    //-r was specified 
    else{
      //if source is a directory and it exists
      if(stat(source, &sb) > -1 && S_ISDIR(sb.st_mode)){
	if(stat(target, &sb) > -1 && S_ISDIR(sb.st_mode)){
	  copyDir(source, target);
	}
	//if source is a directory and target does not exist, make a new directory
	if(stat(target, &sb) != 0){
	  copyDir(source, target);
	}
	//if source is a directory and target is a regular file
	if(stat(target,&sb) > -1 && S_ISREG(sb.st_mode)){
	  cout << "cp: cannot overwirte non-directory `" << target 
	       << "' with directory `" << source << "'" << endl; 
	}
      }
      
      //if source exists but is a regular file
      if(stat(source,&sb) > -1 && S_ISREG(sb.st_mode)){
	if(stat(target,&sb) > -1 && S_ISDIR(sb.st_mode)){
	  copyFile(source, target);
	}

      }
      //if source file doesn't exist and target is not null
      if(stat(source, &sb) !=0 && target != NULL){
	cout << "cp: cannot stat `"<< argv[1]<< "'" << " :No such file or directory" <<endl;
      }
      
    }//else
  }
  return EXIT_SUCCESS; 
}

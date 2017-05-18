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
#include <dirent.h>
#include <libgen.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::strcmp;


int remove(const char * file,bool r, bool f)
{
  struct stat sb;
  struct dirent *ent;
  DIR * dir;
  string s;
  string entry;
  string input;
  if((strcmp(file,".") == 0) || (strcmp(file,"..") == 0))
    return -1;

  stat(file,&sb);

  if(S_ISDIR(sb.st_mode))
    {	        
      if(r == true){
	if((dir = opendir(file)) != NULL)
	  {
	    while((ent = readdir(dir)) != NULL)
	      {
		entry = ent->d_name;
		if(entry == "." || entry == "..")
		  continue;
		s = file;
		s += "/";
		s += entry;
		remove(s.c_str(),r, f);
		
	      }
	    closedir(dir);
	    return remove(file);
	    
	  }
      }//if r == true

      else{
	rmdir(file);
	return 0;
      }
      return -1;
    }//end S_ISDIR

      
    else{
      if(S_ISREG(sb.st_mode) && ((sb.st_mode & S_IWUSR) != 0))
	{	
	  unlink(file);
	  return 0;
	}
      
      if(S_ISREG(sb.st_mode) && ((sb.st_mode & S_IWUSR) == 0) && f != true)
	{
	  cout << "rm: remove write-protected regular file `"<< file << "’?";
	  cin >> input;
	  if(input == "y" || input =="yes"){
	    unlink(file);
	    return 0;
	  }//if input is yes
	  else{
	    return EXIT_SUCCESS;
	  }
	  
	}
      
      if(S_ISREG(sb.st_mode) && ((sb.st_mode & S_IWUSR) == 0) && f == true)
	{
	  unlink(file);
	  return 0;
	}
      
      return -1;
    }//goes with else
}



int main(int argc, char *argv[]){
  bool force = false;
  bool recurse = false;
  char * name;

  for(int i = 1; i < argc; i++){

    if(strcmp((argv[i]), "-f") == 0){
      i++;
      force = true;
      name = argv[i];
      remove(name,recurse, force);

    }//strcmp -f
    
    
    if(strcmp((argv[i]), "-r") == 0){
      i++;
      recurse = true;
      name = argv[i];
      remove(name, recurse, force);
    }//strcmp -r
    
    if(strcmp((argv[i]), "-rf") == 0){
      i++;
      recurse = true;
      force = true;
      name = argv[i];
      remove(name, recurse, force);
    }//strcmp -rf
    name = argv[i];
    remove(name, recurse, force);
    
  }

}//end main

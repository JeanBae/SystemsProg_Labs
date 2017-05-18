/**
 * This program will create a hard link or if -s is specified, a symbolic one
 * @authors Stone Daniel & Jean Bae
 */

#include <unistd.h>
#include <string>
#include <cstring>

using std::strcmp;

int main(int argc, char *argv[]){
  const char *target = nullptr;
  const char *linkFile = nullptr;

  for(int i = 1; i < argc; i++){
    if(strcmp((argv[i]), "-s") == 0){
      i++;
      target = argv[i];
      i++;
      linkFile = argv[i];
      symlink(target, linkFile);
    }
    
    else{
      target = argv[i];
      i++;
      linkFile = argv[i];
      link(target, linkFile);
    }
  }
}//end main

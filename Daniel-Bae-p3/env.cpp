/**
 * This is to print out all the enviornment variables
 * @authors Stone Daniel & Jean Bae
 */
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[], char *envp[]){
  char**env;

  for(env = envp; *env != 0; ++env){
    char * thisEnv = *env;
    printf("%s\n", thisEnv);
  }
  return EXIT_SUCCESS;
}

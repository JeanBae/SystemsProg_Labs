/**
 * This program will format a date using strftime
 * @authors Stone Daniel & Jean Bae
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <getopt.h>

using std::cout;
using std::string;
using std:: endl;


int main(int argc, char * argv[]){

  char buffer[100];
  time_t rawtime;
  struct tm tm;
  

  if(argv[1] == NULL){
    
    time(&rawtime);
    tm = *localtime(&rawtime);  
    strftime(buffer, sizeof(buffer), "%a %b %e %T %Z %G", &tm);
    //printf(buffer);
    puts(buffer);
  
  }
  
  else{ 
    bool format = false;
    time(&rawtime);
    tm = *localtime(&rawtime);  
    string s;
    char c;
    int k = 0;
    for(int i = 1; i < argc; i++)
      {
	for(unsigned int j = 0; j <=sizeof(argv[i]); j++)
	  {
	    c = argv[i][j];

	    if(c == 'a')
	      s+= 'a';
	          
	    if(c == 'A')
	    s += "A";

	          
	    if(c == 'b')
	      s+= 'b';

	          
	    if(c== 'B')
	    s += "B";

	          
	    if(c == 'c')
	      s+= 'c';

	          
	    if(c == 'C')
	      s += "C";

	          
	    if(c== 'd')
	      s += "d";

	          
	    if(c== 'D')
	      s += "D";
	          
	          
	    if(c == 'e')
	      s += "e";

	          
	    if(c == 'F')
	      s += "F";
	          
	          
	    if(c== 'g')
	      s += "g";
	          
	          
	    if( c=='G')
	      s += "G";
	          
	          
	    if( c=='h')
	      s += "h";
	          
	          
	    if(c== 'H')
	      s += "H";
	          
	          
	    if( c== 'I')
	      s += "I";
	     
	          
	    if( c== 'j')
	      s += "j";
	     
	          
	    if( c=='k')
	      s += "k";
	     
	          
	    if( c=='l')
	      s += "l";
	          
	          
	    if( c=='m')
	      s += "m";
	          
	          
	    if(c== 'M')
	      s += "M";
	          
	          
	    if(c== 'n')
	      s += "n";
	          
	          
	    if(c== 'N')
	      s += "N";
	          
	          
	    if( c=='p')
	      s += "p";
	          
	          
	    if(c== 'P')
	      s += "P";
	          
	          
	    if(c== 'r')
	      s += "r";
	          
	          
	    if( c=='R')
	      s += "R";
	          
	          
	    if( c=='s')
	      s += "s";
	          
	          
	    if(c== 'S')
	      s += "S";
	          
	          
	    if(c== 't')
	      s += "t";
	          
	          
	    if(c== 'T')
	      s += "T";
	          
	          
	    if(c== 'u')
	      s += "u";
	          
	          
	    if(c== 'U')
	      s += "U";
	          
	          
	    if(c== 'V')
	      s += "V";
	          
	          
	    if(c== 'w')
	      s += "w";
	          
	          
	    if( c=='W')
	      s += "W";
	          
	          
	    if(c== 'x')
	      s += "x";
	          
	          
	    if( c=='X')
	      s += "X";
	          
	          
	    if(c== 'y')
	      s += "y";
	          
	    if(c== 'Y')
	      s += "Y";
	          
	    if(c== 'z')
	      s += "z";
	   
	    if(c== 'Z')
	      s += "Z";
	        
	    if(c== '%')
	      s+= "%";

	    if( c=='\'')
	      continue;

	    if(c == ' ')
	      s+= " ";
	    
	    //if(c == ':')
	    //s+= ":";

	    if(c == '+'){
	      format = true;
	      continue;
	    }
	    
	    if(c == '\0')
	      break;

	    k++;
	    
	  }//inner for
	break;
      }//for loop

    //cout << "string s: " << s << endl;
    
    if(format == true){

      strftime(buffer, sizeof(buffer), s.c_str(), &tm);
      puts(buffer);
    //printf(buffer);
    }

    else{
      cout << "date: invalid date `" << s << "'" <<endl;
    }
    
  }//end else
  
}//end main

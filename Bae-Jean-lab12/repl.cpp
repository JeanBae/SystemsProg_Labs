#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <libgen.h>
#include <fcntl.h>
#include <cstring>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;

//string quoteString (




int main(){

  while(1){
    int n = 0;
    vector<vector<string> >stuff;
    vector<vector<string> >moreStuff;
    vector <string> temp;			
    vector<string>args;
    const int BUFF_SIZE{1};
    char buffer[BUFF_SIZE]{};
    string str = "";
    
    write(STDOUT_FILENO, "repl$ ", 6);
    while((n = read(STDIN_FILENO,buffer,BUFF_SIZE)) > 0)
      {
	char c = *buffer;
	if(c == '\n'){
	  break;
	}
	else{
	  str += c;
	}
      }
    
    int numPipes = 0;
    string sub = "";
    string quoteStr = "";
    bool parseQ = false;
    for(unsigned int i = 0; i < str.size(); i++){
      if(str[i] == '"'){
	parseQ = true;
	continue;

      }
      else if(str[i] == '\\' && str[i++] == '"'){
	sub += str[i++];
      }

      else if(str[i] == '|'){
	temp.push_back(sub);
	stuff.push_back(temp);
	temp.clear();
	sub = "";
	numPipes++;
      }
      else{
	sub+= str[i];
      }
      

      if(i == str.size()-1){
	temp.push_back(sub);
	stuff.push_back(temp);      
      }
      
    }
    
    string stdin = "STDIN_FILENO";
    string stdout = "STDOUT_FILENO";
    string stderr = "STDERR_FILENO";
    bool stdOutTrunc = false;
    bool stdOutAppend = false;
    bool stdIn = false;
    bool stdErrAppend = false;
    bool stdErrTrunc = false;
    
    for(unsigned int i = 0; i<stuff.size(); i++){
      for(unsigned int j = 0; j < stuff[i].size(); j++){
	stringstream ss(stuff[i][j]);
	string s2;
	while(ss >> s2){
	  
	  if(stdOutTrunc == true){
	    stdout = s2 + " (truncate)";
	    stdOutTrunc = false;
	  }
	  if(stdIn == true){
	    stdin = s2;
	    stdIn = false;
	  }
	  
	  if(stdOutAppend == true){
	    stdout = s2 + " (append)";
	    stdOutAppend = false;
	  }
	  if(stdErrAppend == true){
	    stderr = s2 + " (append)";
	    stdErrAppend = false;
	  }
	  if(stdErrTrunc == true){
	    stderr = s2 + " (truncate)";
	    stdErrTrunc = false;
	  }
	  
	  if(s2 == ">"){
	    stdOutTrunc = true;
	  }
	  if(s2 == "<"){
	    stdIn = true;
	  }
	  if(s2 == ">>"){
	    stdOutAppend = true;
	  }
	  if(s2 == "e>>"){
	    stdErrAppend = true;
	  }
	  if(s2 == "e>"){
	    stdErrTrunc = true;
	  }
	  
	}
      }    
    }
    if(parseQ != true){
      for(unsigned int i = 0; i<stuff.size(); i++){
	for(unsigned int j = 0; j < stuff[i].size(); j++){
	  stringstream ss(stuff[i][j]);
	  string s2;
	  while(ss >> s2){
	    
	    if(s2 == ">" || s2 == "<" || s2 == ">>" || s2 == "e>>" || s2 == "e>"){
	      break;
	    }
	    else{
	      args.push_back(s2);
	    }
	    
	  }
	  moreStuff.push_back(args);
	  args.clear();
	}    
      }
    }
    else{
      for(unsigned int i = 0; i<stuff.size(); i++){
	for(unsigned int j = 0; j < stuff[i].size(); j++){
	  stringstream ss(stuff[i][j]);
	  string s2;
	  string quoteStr = "";
	  while(ss >> s2){
	    
	    if(s2 == ">" || s2 == "<" || s2 == ">>" || s2 == "e>>" || s2 == "e>"){
	      break;
	    }
	    else if(s2 != "echo"){
	      quoteStr += s2;
	    }

	    else{
	      args.push_back(s2);
	    }
	    
	  }
	  moreStuff.push_back(args);
	  args.clear();
	}    
      }
    }
    
    
  
  
    cout << endl;
    cout << "Job STDIN = " << stdin << endl;
    cout << "Job STDOUT = " << stdout << endl;
    cout << "Job STDERR = " << stderr << endl;
    cout << endl;
    cout << numPipes << " pipe(s)"  << endl;
    cout << stuff.size() << " process(es)\n" <<endl;
    
    for(unsigned int k = 0; k < moreStuff.size(); k++){
      cout << "Process " << k << " argv:" << endl;
      for(unsigned int l = 0; l < moreStuff[k].size(); l++){
	cout << l << ": " << moreStuff[k][l] << endl;      
	
      }
      cout << endl;
    } 
    
    //return EXIT_SUCCESS;
  }
}

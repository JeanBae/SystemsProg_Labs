#include <iostream>
#include <sstream>
#include <climits>
#include <bitset>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::bitset;
using std::to_string;
using std::string; 

int main(){

  int i{0};
  string s;

  while(i <= USHRT_MAX){//using constant USHRT_MAX to make sure it does not exceed the short max
      bitset<16>bin(i);
      s = bin.to_string();
      s.insert(4,"'");//inserting apostrophes into 4th index
      s.insert(9,"'");//"" into the 9th index
      s.insert(14,"'");//"" into the 14th index
      cout << "0b" << s << " " << std::oct << i;//printing the binary and octal representation
      cout<< " " << std::dec <<i;//printing the decimal representation
      cout<< " " << std::hex << std::showbase << i;//printing the hexadecimal + showbase representation

      if((i>= 3)&& (i%5 == 0) && (i%3 ==0)){
	cout<< " GoDawgs";
      }
    
      else if((i>= 3) && (i%3 == 0)){
	cout<< " Go";
      }

      else if((i>=3) && (i%5 == 0)){
	cout<< " Dawgs";
      }

      else{//this statement will print anything not divisible by 3 and 5 and for numbers lower than 3
	cout<< " Sic'Em";
      }
      
      ++i;
      cout <<""<<endl;
    }
  }
 

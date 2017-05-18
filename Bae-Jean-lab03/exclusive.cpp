#include <iostream>
#include <sstream>
#include <climits>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;
using std::string;
int main(){
  
  string input = "";
  int num{0};
  int exclusive{0};
 
  cout << "Enter integers: ";
  getline(cin, input);//get input

  stringstream ss(input);//initialize stringstream
  while(ss >> num){
   
    exclusive = exclusive ^ num;

  }//end of while loop
  cout << "Exclusive: " << exclusive <<endl;

}//end of main

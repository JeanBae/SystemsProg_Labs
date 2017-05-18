#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
  unsigned long input{0};
  int count{0};
  cout << "Enter integer: "; 
  cin >> input;
  
  while(input > 0){
  if(input & 1){
    count++;
  }
  input = input >> 1;
 
 }
  cout << "      Bit sum: " << count << endl;
  
}

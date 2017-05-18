/** 
 * This program takes user input to fill 32 bits of space with integers.
 * The user can partition these spaces when prompted and choose to fill
 * the allocates amount of spaces with an integer
 * that does not exceed the bit space of that index.
 * @author Jean Bae
 */

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

void setValue(unsigned int & var, unsigned int k, unsigned int i, unsigned int val){

  unsigned int mask= (1 << (32/k))-1; //creating a mask of all 1's
  mask <<= i*(32/k); //moving mask to the left a certain number of bits
  var &= ~mask; // using the complement of mask to change it to all 0's and ANDing with var
  var|= val<<i*(32/k); //ORing with user input and var and shifting to the left certain number of bits
}

unsigned int getValue(unsigned int var, unsigned int k, unsigned int i){
  
  if(k!=1){
    unsigned int mask = (1<<(32/k))-1;//creating mask of all 1's
    mask <<= i*(32/k);//shifting mask left to certain number of bits
    var &= mask; //using AND to compare with var and mask
    var >>= i*(32/k);//shifting var to the right certain number of bits
  }
  return var; 
}

int main(){

  unsigned int x {0};
  unsigned int numK {0};
  unsigned int value {0};
  unsigned int index {0};
  unsigned char c {0};

  bool isPlaying = true;
  
    cout << "Type in the number of values, k (1, 2, 4, 8, 16, 32)." << endl;
    cin >> numK;
    
    while(isPlaying){
      for(int j = 0; j < numK; j++){
	cout << "Type in a value to be set." << endl;
	cin >> value;
	cout << "Type in the index to store the value." << endl;
	cin >> index;
	setValue(x, numK, index, value);
      }
      for(int i = 0; i < numK; i++){
	cout << "index: " << i << " value: " << getValue(x, numK, i) << endl;
      }
      isPlaying = false;
    }
    
}

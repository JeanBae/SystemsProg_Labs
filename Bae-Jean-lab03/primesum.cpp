#include <iostream>
#include <climits>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

bool isPrime(long long x){
  bool isPrime{true};
  if(x == 2){ //if the number being passed is 2, automatically make it a prime
    isPrime = true;
  }

  else{
    for(long long i = 2; i <=  sqrt(x); i++){ //squaring x being passed, if x divisible by a number between 2 and <= its square root, not prime
      if(x%i == 0){
	isPrime = false;
	break;
      }
    }
  }
  return isPrime;
}


int main(){

  int input{0};
  long long sum{0};

  cout << "Enter integer: "; 
  cin >> input;
  
  for(long long i =2; i <= LLONG_MAX && input > 0; i ++){ //range of values to check
      if(isPrime(i)){
	sum += i;
	input--;
      }
    }//end for loop
  
  cout << "    Prime sum: " << sum << endl;
}

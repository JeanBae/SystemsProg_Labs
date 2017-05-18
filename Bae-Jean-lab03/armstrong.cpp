#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;


int main(){
  int remainder{0};
  int num{0};
  int sum{0};
  int cube{0};
  
  for(int i = 100; i <= 999; i++){
    num = i/100;
    remainder = i % 100;
    cube = num * num * num;
    sum +=cube;

    num = remainder/10;
    remainder = remainder % 10;
    cube = num * num * num;
    sum +=cube;

    num = remainder/1;
    if(num != 1){
      remainder = remainder % 1;
      cube = num * num * num;
      sum +=cube;
    }
    else{
      sum += num;
    }

    if(sum == i){
      cout << i << endl;
    }

    sum = 0;
  }

}

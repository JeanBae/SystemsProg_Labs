#include <iostream>
#include <sstream>
#include <string>
//#include <climits>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

int main(){
  
  string input = "";
  int num{0};
  //int min{INT_MAX}; 
  //int max{INT_MIN};
  int min{0};
  int max{0};
  int count{0};

  cout << "Enter integers: ";
  getline(cin, input);
  stringstream ss(input);

  while(ss >> num){
    count++;
    /*if(num < min){
      min = num;
    }
    
    if(num > max){
      max = num;
    }*/

    if(count == 1){
      min = num;
      max = num;
    }
    
    if(num > max){
      max = num;
    }
    if(num < min){
      min = num;
    }
  }

  cout << "           Min: " << min << endl;
  cout << "           Max: " << max << endl;
  


}

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

int main(){
  //creating variables for sum etc. and also creating a counter to count the numbers input
  string input = "";
  int num{0};
  double count{0};
  double sum{0};
  double average{0};
  double sumSquare{0};
  double variance{0};

  cout << "Enter integers: "; 
  getline(cin, input);
  stringstream ss(input);
  stringstream ss2(input);
  
  while(ss >> num){
    ++count;
    sum += num;
    sumSquare += num * num;
  }
  average = sum/count;
  
  while(ss2 >> num){
    variance += ((num - average)*(num-average));
  }

  variance /= count;
  
  printf("           Sum:%.1f ", sum);
  cout << "" << endl;
  cout << "       Average: " << average << endl;
  printf("Sum of Squares:%.1f ", sumSquare);
  cout << "" << endl;
  cout << "      Variance: " << variance <<endl;
}

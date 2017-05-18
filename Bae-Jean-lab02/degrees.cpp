#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int main(){

  double c{0};
  double f{0};
  cout << "Enter in a temperature in Celsius: ";
  cin >> c;
  f = c * 1.8 + 32;//formula used to convert from Celsius to Fahrenheit

  cout << std::fixed;
  cout << std::setprecision(2);//using setprecision to print to two decimal places
  cout << c << " degrees Celsius converts to " << f
       <<" degrees Fahrenheit." << endl;

}

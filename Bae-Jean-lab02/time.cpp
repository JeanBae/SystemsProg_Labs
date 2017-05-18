#include <iostream>

using std::cout;
using std:: cin;
using std::endl;

int main(){

  unsigned int x{0};

  cout << "Enter in the number of seconds as an integer: ";
  cin >> x;
  cout << "";

  cout << x << " is equivalent to " << x/3600 << " hours " << x%3600/60 << " minutes " << x%60 << " seconds." << endl;  
  







}

#include <iostream>
#include <cstdlib>
#include "Matrix.h"

using std::cout;
using std::endl;

int main(){

  Matrix m1(2,2);
  m1.at(0,0) = 1;
  m1.at(0,1) = 2;
  m1.at(1,0) = 1;
  m1.at(1,1) = 3;
  cout <<"m1: "<< endl;
  cout<<m1 << endl;

  Matrix m2(2,1);
  m2.at(0,0) = 3;
  m2.at(1,0) = 2;

  cout << "m2: " << endl;
  cout<< m2  << endl;

  Matrix m3 = m1.multiply(m2);
  cout << "m3: " << endl;
  cout << m3  << endl;
  

  Matrix m4 = {{1,2},
	      {3,4}};

  cout << "m4: " <<endl; 
  cout<<m4 << endl;

 
  Matrix c0 = m4 + 5.2;

  cout << "Matrix c0 = m4 + 5.2:" <<endl; 
  cout<< c0 << endl;

  Matrix c1 = m4 + m4;
  cout << "Matrix c1 = m4 + m4:" <<endl; 
  cout<< c1 << endl;

  Matrix c2 = m4 - 3.5;
  cout << "Matrix c2 = m4 - 3.5:" <<endl; 
  cout<< c2 << endl;


  Matrix c3 = m4 - m1;
  cout << "Matrix c3 = m4 - m1:" <<endl; 
  cout<< c3 << endl;
  
  Matrix m5(2,2);
  m5 = c0;
  cout << "Matrix m5 = c0" << endl;
  cout << m5 << endl;

  
  Matrix b = 4.0 + m4;
  cout << "Matrix b = 4.0 + m4:" << endl;
  cout << b << endl;

  Matrix c = 4.0 - m4;
  cout << "Matrix c = 4.0 - m4:" << endl;
  cout << c << endl;

  Matrix d(1,1);
  d(0,0) = 5;
  cout << "Matrix d: " << endl;
  cout << d << endl;
  cout << "d.at(0,0) overload: "<< endl;
  cout << d(0,0) << endl;

 
  cout << "transpose of m2: " << endl;
  cout << m2.t() << endl;

  Matrix e = {{1},
	      {4},
	      {5}};

  cout << "Matrix e: " << endl;
  cout << e << endl;
  cout << "transpose of Matrix e: " << endl;
  cout << e.t() << endl;

  Matrix f(2,3);
  f.at(0,0) = 1;
  f.at(0,1) = 2;
  f.at(0,2) = 3;
  f.at(1,0) = 4;
  f.at(1,1) = 5;
  f.at(1,2) = 6;

  Matrix g(3,2);
  g.at(0,0) = 7; 
  g.at(0,1) = 8;
  g.at(1,0) = 9;
  g.at(1,1) = 10;
  g.at(2,0) = 11;
  g.at(2,1) = 12;
 
  cout<< "Matrix f: " << endl;
  cout << f << endl;

  cout << "Matrix g: " << endl;
  cout << g << endl;

  cout <<"Matrix f times g: "<< endl;
  cout<< f.multiply(g) << endl;

  Matrix m6 = {{20,22},
	      {16,4}};

  Matrix m7 = {{2,5},
	      {10,4}};

  Matrix m8 = 20.0 / m7;

  cout << "Matrix m6 :" << endl;
  cout <<m6 <<endl;

  cout << "m6 divided by scalar 2:  " << endl; 
  cout << m6.divide(2) << endl;

  cout << "Matrix m7: " << endl;
  cout << m7 << endl;
  cout << "Matrix m8 = 20.0 / m7: " << endl;
  cout << m8 << endl;

  Matrix m9(3,2);
  m9 = g;
  cout << "Matrix m9 = g, copy assignment operator:" << endl;
  cout << m9 << endl;
  
  cout << "Negation of Matrix m9:" << endl;
  cout << -m9 << endl;
  Matrix m10 =  m6 + m7;
  cout << "Matrix m10 = m6 + m7: " << endl;
  cout << m10 << endl;
}

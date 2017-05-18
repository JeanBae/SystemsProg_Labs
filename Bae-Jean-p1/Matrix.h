#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>
#include <cstdlib>

using std::initializer_list;
using std::ostream;

typedef unsigned int uint;
typedef initializer_list<initializer_list<double>> i_list;

class Matrix {

  uint rows;
  uint cols;
  double** array = nullptr;

 public:


  Matrix(uint rows, uint cols); // constructor (all elements initialized to 0)
  Matrix(const i_list & list); // constructor (using initializer list)
  Matrix(const Matrix & m); // copy constructor
  ~Matrix(); //destructor

  Matrix add(double s) const; // add scalar to this matrix
  Matrix add(const Matrix & m) const; // add this matrix and another matrix

  Matrix subtract(double s) const; // subtract scalar from this matrix
  Matrix subtract(const Matrix & m) const; // subtract another matrix from this matrix

  Matrix multiply(double s) const; // multiply this matrix by a scalar
  Matrix multiply(const Matrix & m) const; // multiply this matrix by another matrix

  Matrix divide(double s) const; // divide this matrix by a scalar
  Matrix t() const; // transpose of this matrix

  const uint numRows() const; // returns the number of rows
  const uint numCols() const; // returns the number of columns

  double & at(uint row, uint col); // get/set element at row,col
  const double & at (uint row, uint col) const; // get element at row,col (when using a const object)
  
  //member overload function
 
  double& operator()(uint row, uint col);
  Matrix operator=(const Matrix &);
  Matrix operator-();
  Matrix operator+(double s);
  Matrix operator+(const Matrix & m);
  Matrix operator-(double s);
  Matrix operator-(const Matrix & m);
  Matrix operator*(double s);
  Matrix operator*(const Matrix & m);
  Matrix operator/(double s);


  };//end of class
//non-member overload function
std::ostream & operator<<(ostream &, const Matrix &);
Matrix operator+(double s, const Matrix & rhs);
Matrix operator-(double s, const Matrix & rhs);
Matrix operator*(double s, const Matrix & rhs);
Matrix operator/(double s, const Matrix & rhs);

#endif


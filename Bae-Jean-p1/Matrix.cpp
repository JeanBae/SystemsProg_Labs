/**
 * Matrix class composed of constructors and functions to add, subtract, multiply,
 * and divide matrices. Also gets/sets and returns rows and columns of a matrix
 * @author Jean Bae
 */

#include "Matrix.h"
#include <iostream>
#include <cstdlib>
/**
 *@param rows, cols to create a matrix
 *@return Matrix of size rowsxcols
 */
Matrix::Matrix(uint rows, uint cols){ // constructor (all elements initialized to 0)
  this->rows = rows;
  this->cols = cols;

  this->array = new double * [rows];
  for(uint i = 0; i < rows; i++){
    array[i] = new double [cols];
  }

  for(uint j = 0; j < rows; j++){
    for(uint k = 0; k < cols; k++){
      array[j][k] = 0;
    }
  }
}

/**
 *@param list to create a matrix using values of the list
 *@return Matrix of size of the list with values from list in corresponding spaces
 */
Matrix::Matrix(const i_list & list){ // constructor (using initializer list)
  this->rows = list.size();
  this->cols = list.begin()->size();
  auto row = list.begin();

  array = new double * [rows];
  for(uint i = 0; i < rows; i++){
    array[i] = new double [cols];
  }

  for (uint i = 0; i < rows; i++) {
    auto col = (row + i)->begin();
    for (uint j = 0; j < cols; j++) {
      array[i][j] =  *(col + j);
    }
  }
}

/**
 *@param reference to a matrix, m, to create a copy matrix
 *@return a copy of the matrix
 */
Matrix::Matrix(const Matrix & m){ // copy constructor
  rows = m.numRows();
  cols = m.numCols();

  array = new double * [rows];
  for(uint i = 0; i < rows; i++){
    array[i] = new double [cols];
  }

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      array[i][j] = m.at(i, j);
    }
  }
}

/**
 *destroying the array that it's pointing to
 */
Matrix::~Matrix(){ //destructor

  for(uint i = 0; i < rows; i++){
    delete [] array[i];
  }

  delete [] array;
}

/**
 *@param double scalar value
 *@return new Matrix of the size of original matrix with s added to values at the matrix
 */
Matrix Matrix:: add(double s) const{ // add scalar to this matrix
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = s + at(i,j);
    }
  }
  return ret;
}

/**
 *@param reference to another matrix
 *@return Matrix of the addition of this matrix and the passed matrix
 */
Matrix Matrix::add(const Matrix & m) const{ // add this matrix and another matrix
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j) + m.at(i,j);
    }
  }
  return ret;
}

/**
 *@param double s
 *@return Matrix with scalar subtracted from each element in the matrix
 */
Matrix Matrix::subtract(double s) const{ // subtract scalar from this matrix
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j) - s;
    }
  }
  return ret;
}

/**
 *@param reference to another matrix
 *@return Matrix of this matrix subtracted by another matrix
 */
Matrix Matrix::subtract(const Matrix & m) const{ // subtract another matrix from this matrix
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j) - m.at(i,j);
    }
  }
  return ret;
}

/**
 *@param double s
 *@return the product of the scalar and every element in this matrix
 */
Matrix Matrix::multiply(double s) const{ // multiply this matrix by a scalar
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j) * s;
    }
  }
  return ret;
}

/**
 *@param reference to another matrix
 *@return a matrix of the product of two matrices 
 */
Matrix Matrix::multiply(const Matrix & m) const{ // multiply this matrix by another matrix
  Matrix ret(rows,m.numCols());

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < m.numCols(); j++){
      for(uint k = 0; k < cols; k++){
	ret.at(i,j) += at(i,k) * m.at(k,j);
      }
    }
  }
  return ret;
}

/**
 *@param double s
 *@return new Matrix with elements of this matrix divided by scalar
 */
Matrix Matrix::divide(double s) const{ // divide this matrix by a scalar
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j)/s;
    }
  }
  return ret;
}

/**
 *@return Matrix of original matrix transposed
 */
Matrix Matrix::t() const{ // transpose of this matrix
  Matrix ret(cols,rows);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(j,i) = at(i, j);
    }
  }
  return ret;
}

/**
 *@return the number of rows
 */
const uint Matrix::numRows() const{//returns the number of rows
  return rows;
}


/**
 *@return the number of cols
 */
const uint Matrix::numCols() const{ // returns the number of columns
  return cols;
}


/**
 *@param row and col 
 *@return double at the row and col passed 
 */
double & Matrix:: at(uint row, uint col){ // get/set element at row,col
  return array[row][col];
}

/**
 *@param row and col
 *@return double at the row and col passed
 */
const double & Matrix:: at (uint row, uint col) const{ // get element at row,col (when using a const object)
  return array[row][col];
}

//member operator overloads
/**
 *@param row and col
 *@return the double in the matrix at row and col
 */
double& Matrix::operator()(uint row, uint col){
  return at(row,col);
}


/**
 *@param reference to matrix m
 *@return the copy of the matrix passed
 */
Matrix Matrix::operator=(const Matrix & m){
  for(uint i = 0; i < rows; i++){
    delete [] array[i];
  }
  delete [] array;
 
  this->rows = m.numRows();
  this->cols = m.numCols();
  
   array = new double * [rows];
  for(uint i = 0; i < rows; i++){
    array[i] = new double [cols];
  }
  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      array[i][j] = m.at(i,j);
    }
  }
  return (*this);
}

/**
 *@return the negation of the matrix
 */
Matrix Matrix::operator-(){
  
  return multiply(-1);
}

/**
 *@param double s
 *@return a matrix with scalar added to each element
 */
Matrix Matrix::operator+(double s){
  return add(s);
}

/**
 *@param reference to matrix, m
 *@return a new matrix with elements of the passed matrix added to each element of the current matrix 
 */
Matrix Matrix::operator+(const Matrix & m){
  return add(m);
}

/**
 *@param double s
 *@return a matrix with scalar subtracted to each element
 */
Matrix Matrix::operator-(double s){
  return subtract(s);
}

/**
 *@param reference to matrix, m
 *@return a new matrix with this matrix subtracted by
 * elements of the passed matrix
 */
Matrix Matrix::operator-(const Matrix & m){
  return subtract(m);
}

/**
 *@param double
 *@return a new matrix od the product of this matrix
 *and scalar
 */
Matrix Matrix::operator*(double s){
  return multiply(s);
}

/**
 *@param reference to matrix, m
 *@return a new matrix with this matrix multiplied by
 * elements of the passed matrix
 */
Matrix Matrix::operator*(const Matrix & m){
  return multiply(m);
}

/**
 *@param double
 *@return a new matrix with this matrix divided by
 * scalar
 */
Matrix Matrix::operator/(double s){
  return divide(s);
}

// non-member operator overloads
/**
 *@param double and reference to another matrix
 *@return a new matrix with this matrix added by
 * scalar
 */
Matrix operator+(double s, const Matrix & rhs){
  return rhs.add(s);
}

/**
 *@param double s, and reference to another matrix
 *@return a new matrix with this sclar subtracted by
 * the elements in the passed matrix
 */
Matrix operator-(double s, const Matrix & rhs){
  Matrix sMinusM(rhs.numRows(), rhs.numCols());

  for(uint i = 0; i < rhs.numRows(); i++){
    for(uint j = 0; j < rhs.numCols(); j++){
      sMinusM.at(i,j) = s - rhs.at(i,j);
    }
  }
  return sMinusM;
}

/**
 *@param double s and reference to another matrix
 *@return a new matrix with scalar divided by
 * elements of the matrix passed
 */
Matrix operator*(double s, const Matrix & rhs){
  Matrix product(rhs.numRows(),rhs.numCols());
  
  for(uint i = 0; i < rhs.numRows(); i++){
    for(uint j = 0; j < rhs.numCols(); j++){
      product.at(i,j) = s * rhs.at(i,j);
    }
  }
  return product;
}

/**
 *@param double and reference to another matrix
 *@return a new matrix with the scalar divided by
 *the elements of the matrix
 */
Matrix operator/(double s, const Matrix & rhs){
  Matrix result(rhs.numRows(), rhs.numCols());

  for(uint i = 0; i < rhs.numRows(); i++){
    for(uint j = 0; j < rhs.numCols(); j++){
      result.at(i,j) = s / rhs.at(i,j);
    }
  }

  return result;
}

/**
 *@param os stream reference and matrix reference
 *@return an ostream that prints values of the matrix
 */
ostream&operator<<(ostream &os, const Matrix & m){
  for(uint i = 0; i < m.numRows(); i++){
      os << "[ ";
    for(uint j = 0; j < m.numCols(); j++){
      os << m.at(i,j)<< " ";
    }
      os << "]\n";
  }
  return os;
}

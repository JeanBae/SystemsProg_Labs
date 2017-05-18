/**
 * Matrix class composed of constructors and functions to add, subtract, multiply,
 * and divide matrices. Also gets/sets and returns rows and columns of a matrix
 * @author Jean Bae
 */

#include "Matrix.h"
#include <iostream>
#include <cstdlib>


/**
 * 
 */
Matrix::Matrix(uint rows, uint cols){ // constructor (all elements initialized to 0)
  this->rows = rows;
  this->cols = cols;

  array = new double * [rows];
  for(uint i = 0; i < rows; i++){
    array[i] = new double [cols];
  }  
  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      array[i][j] = 0;
    }
  }
}

Matrix::Matrix(const i_list & list){ // constructor (using initializer list)
  this->rows = list.size();
  this->cols = list.begin()->size();
  auto row = list.begin();

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


Matrix::Matrix(const Matrix & m){ // copy constructor
  rows = m.numRows();
  cols = m.numCols();

  for(uint i = 0; i < rows; i++){
    array[i] = new double [cols];
  }
  
  
  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      array[i][j] = m.at(i, j);
    }
  } 
 
}

Matrix::~Matrix(){ //destructor

  for(uint i = 0; i < rows; i++){
    delete [] array[i];
  }  

  delete [] array;

}
 
Matrix Matrix:: add(double s) const{ // add scalar to this matrix
  Matrix ret(rows,cols);
  
  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = s + at(i,j);
    }
  }

  return ret;
}

Matrix Matrix::add(const Matrix & m) const{ // add this matrix and another matrix
  Matrix ret(rows,cols);
  
  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j) + m.at(i,j);
    }
  }
  
  return ret;
}


Matrix Matrix::subtract(double s) const{ // subtract scalar from this matrix
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j) - s;
    }
  }
  return ret;
}

Matrix Matrix::subtract(const Matrix & m) const{ // subtract another matrix from this matrix
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j) - m.at(i,j);
    }
  }
  return ret;
}

Matrix Matrix::multiply(double s) const{ // multiply this matrix by a scalar
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j) * s;
    }
  }
  return ret;
}

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

Matrix Matrix::divide(double s) const{ // divide this matrix by a scalar
  Matrix ret(rows,cols);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(i,j) = at(i,j)/s;
    }
  }
  return ret;
}

Matrix Matrix::t() const{ // transpose of this matrix

  Matrix ret(cols,rows);

  for(uint i = 0; i < rows; i++){
    for(uint j = 0; j < cols; j++){
      ret.at(j,i) = at(i, j);
    }
  }
  return ret;
}

const uint Matrix::numRows() const{//returns the number of rows
  return rows;
}

const uint Matrix::numCols() const{ // returns the number of columns
  return cols;
}

double & Matrix:: at(uint row, uint col){ // get/set element at row,col
  return array[rows][cols];
}

const double & Matrix:: at (uint row, uint col) const{ // get element at row,col (when using a const object)
  return array[rows][cols];
}

// operator overloads

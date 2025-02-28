#include "Matrix.h"
#include <cassert>
#include <iomanip>

// BEGIN: 2b
Matrix::Matrix(int nRows, int nColumns):rows{nRows}, columns{nColumns}{
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns]{0};
    }
}

Matrix::Matrix(int nRows) : Matrix{nRows, nRows} {
    assert(nRows>=0);
    for (int i = 0; i < nRows; i++)
    {
        matrix[i][i] = 1;
    }
    
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}
// END: 2b

// BEGIN: 2c
double Matrix::get(int row, int col) const{
    double value;
    value = matrix[row][col];
    return value;
}

void Matrix::set(int row, int col, double value){
    matrix[row][col] = value;
}
// END: 2c

// Her kan du gjøre 2d (frivillig):


// BEGIN: 2f
std::ostream& operator<<(std::ostream& os, Matrix& m){
    os << std::setw(4);
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getColumns(); j++)
        {
            os << m.get(i,j) << std::setw(4);
        }
    os << std::endl;
    }
    return os;
}
// END: 2f


// BEGIN: 4a
Matrix::Matrix(const Matrix& rhs){
    this -> rows = rhs.rows;
    this -> columns = rhs.columns;
    this -> matrix = new double* [rhs.rows] {};

    for (int i = 0; i < this->rows; i++){
        matrix[i] = new double[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            this->matrix[i][j] = rhs.matrix[i][j];
        }
        
    }

}
// END: 4a

// BEGIN: 4b
Matrix& Matrix::operator=(Matrix rhs){
    columns, rows = rhs.columns, rhs.rows;
    std::swap(this->matrix, rhs.matrix);
    return *this;
}
// END: 4b


// BEGIN: 5a

// END: 5a

// BEGIN: 5b

// END: 5b


void testMatrix() {
    // Her kan du teste løsningen din (oppgave 5c):
}

// Her kan du gjøre 5d (frivillig):
#include "Matrix.hpp"

ProxyRow::ProxyRow()
{
    cols_ = 0;
    data = nullptr;
}

void ProxyRow::AllocMemRow(size_t size)
{   
    if (size <= 0)
       throw std::out_of_range("ERR1: wrong size");
    
    cols_ = size;
    data = new int32_t[size];
}

int32_t& ProxyRow::operator[](size_t j)
{   
    if (j >= cols_)
        throw std::out_of_range("ERR2: wrong requested index");
    
    return data[j];
}

void ProxyRow::DelMemRow()
{
    if (data)
        delete[] data;
}


Matrix::Matrix(size_t rows, size_t cols)
{
    _rows = rows;
    _cols = cols;
    
    if ((_rows <= 0) || (_cols <= 0))
        throw std::out_of_range("ERR3: wrong dimension of matrix");
    
    matr = new ProxyRow[_rows];
    for (size_t i = 0; i < _rows; i++)
       matr[i].AllocMemRow(_cols);
    
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j< _cols; j++)
            matr[i][j] = 0;
}

size_t Matrix::GetRows() const
{
    return _rows;
}

size_t Matrix::GetCols() const
{
    return _cols;
}

Matrix& Matrix::operator=(const Matrix& m)
{
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            matr[i][j] = m.matr[i][j];
    
    return *this;
}

ProxyRow& Matrix::operator[](size_t i)
{
    if (i >= _rows)
        throw std::out_of_range("ERR4: wrong requested index");
    return matr[i];
}

bool Matrix::operator==(const Matrix& other) const
{
    if ((_rows != other._rows) || (_cols != other._cols))
        return false;

    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            if (matr[i][j] != other.matr[i][j])
                return false;

     return true;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    if ((_rows != other._rows) || (_cols != other._cols))
        throw std::out_of_range("ERR5: wrong operation +");
    
    Matrix res(_rows, _cols);
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            res.matr[i][j] = matr[i][j] + other.matr[i][j];
    
    return res;
}

Matrix& Matrix::operator*=(int32_t n)
{
    for (size_t i = 0; i < _rows; i++)
        for (size_t j = 0; j < _cols; j++)
            matr[i][j] *= n;
    
    return *this;
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < _rows; i++)
        matr[i].DelMemRow();
    
    delete[] matr;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m)
{
    for (size_t i = 0; i < m._rows; i++) {
        for (size_t j = 0; j < m._cols; j++)
            out << m.matr[i][j] << " ";
        out << std::endl;
    }
    
    return out;
}


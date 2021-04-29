#ifndef HPP_MATRIX
#define HPP_MATRIX

#include <iostream>

class ProxyRow
{
private:
    int32_t* data;
    size_t cols_;
public:
    ProxyRow();
    void AllocMemRow(size_t size);
    int32_t& operator[](size_t j);
    void DelMemRow();
};

class Matrix
{
public:
    Matrix(size_t rows, size_t cols);
    size_t GetRows() const;
    size_t GetCols() const;
    Matrix& operator=(const Matrix& m);
    ProxyRow& operator[](size_t i);
    bool operator==(const Matrix& other) const;
    Matrix operator+(const Matrix& other) const;
    Matrix& operator*=(int32_t n);
    ~Matrix();
    friend std::ostream& operator<<(std::ostream& out, const Matrix& m);

private:
    size_t _rows;
    size_t _cols;
    ProxyRow* matr; 
};

#endif


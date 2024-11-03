#ifndef TITLEMTX_H
#define TITLEMTX_H
#include <iostream>

class Matrix {
  private:
    size_t rows;
    size_t cols;
    int** data;
    void allocateMemory(size_t m, size_t n);
    void deallocateMemory(int ** data, size_t m);
  public:
    Matrix(size_t m, size_t n);
    ~Matrix();
    Matrix(const Matrix& other);
    size_t getRows() const;
    size_t getCols() const;
    void fill(int value);
    void resize(size_t newRows, size_t newCols);
    void input(std::istream& in);
    void print(std::ostream& out) const;
};

#endif

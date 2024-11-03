#include "titleMtx.h"
#include <iostream>
#include <stdexcept>

void allocateMemory(size_t m, size_t n)
{
  data = new int*[m];
  for (size_t i = 0; i < m; ++i)
  {
    data[i] = new int[n];
  }
}

void deallocateMemory(int ** data, size_t m)
{
  for (size_t i = 0; i < m; ++i)
  {
    delete[] data[i];
  }
  delete[] data;
}

Matrix(size_t m, size_t n) : rows(m), cols(n)
{
  allocateMemory(m, n);
}

~Matrix()
{
  deallocateMemory(int ** data, size_t m);
}

Matrix(const Matrix& other) : rows(other.rows), cols(other.cols)
{
  allocateMemory(rows, cols);
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      data[i][j] = other.data[i][j];
    }
  }
}

size_t getRows() const
{
  return rows;
}

size_t getCols() const
{
  return cols;
}

void fill(int value)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      data[i][j] = value;
    }
  }
}

void resize(size_t newRows, size_t newCols)
{
  int** newData = new int*[newRows];
  for (size_t i = 0; i < newRows; ++i)
  {
    newData[i] = new int[newCols];
  }
  for (size_t i = 0; i < std::min(rows, newRows); ++i)
  {
    for (size_t j = 0; j < std::min(cols, newCols); ++j)
    {
      newData[i][j] = data[i][j];
    }
  }
  deallocateMemory(int ** data, size_t m);
  data = newData;
  rows = newRows;
  cols = newCols;
}

void input(std::istream& in)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (!(in >> data[i][j]))
      {
        throw std::runtime_error("Invalid input format");
      }
    }
  }
}

void print(std::ostream& out) const
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      out << data[i][j] << ' ';
    }
    out << '\n';
  }
}

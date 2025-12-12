#include "class.h"
Matrix::Matrix(int M, int N) : row(M), col(N) {
  int size = row * col;
  data_ = new int[size];
  for (int i = 0; i < size; i++) {
    data_[i] = 0;
  }
}
Matrix::Matrix() {
  row = 0;
  col = 0;
  data_ = nullptr;
}
Matrix::~Matrix() {
  if (data_ != nullptr) {
    delete[] data_;
  }
}
Matrix::Matrix(const Matrix& m) {
  if (m.data_ != nullptr) {
    row = m.row;
    col = m.col;
    data_ = new int[row * col];
    for (int i = 0; i < row * col; i++) {
      data_[i] = m.data_[i];
    }
  } else {
    data_ = nullptr;
    row = col = 0;
  }
}
Matrix& Matrix::operator=(const Matrix& m) {
  if (&m == this) {
    return *this;
  }
  if (data_ != nullptr) {
    delete[] data_;
  }
  if (m.data_ == nullptr) {
    delete[] data_;
    row = 0;
    col = 0;
    data_ = nullptr;
    return *this;
  } else {
    row = m.row;
    col = m.col;
    data_ = new int[row * col];
    for (int i = 0; i < row * col; i++) {
      data_[i] = m.data_[i];
    }
    return *this;
  }
}
Matrix::Matrix(Matrix&& m) noexcept {
  row = m.row;
  col = m.col;
  data_ = m.data_;
  m.row = m.col = 0;
  m.data_ = nullptr;
}
Matrix& Matrix::operator=(Matrix&& m) {
  row = m.row;
  col = m.col;
  if (this == &m) {
    return *this;
  }
  if (data_ != nullptr) {
    delete[] data_;
  }
  data_ = m.data_;
  m.row = m.col = 0;
  m.data_ = nullptr;
  return *this;
}
int Matrix::get_row() const{
  return row;
};
void Matrix::set_row(int M) {
  if (data_ != nullptr) {
    if (row * col % M != 0) {
      row = M;
      return ;
    } else {
      col = row * col / M;
      row = M;
    }
  } 
}

bool Matrix::isSquare(){
  return row == col;
}
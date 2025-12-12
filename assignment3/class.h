#pragma once
class Matrix {
private:
  int row;
  int col;
  int* data_;
  bool isSquare();

public:
  Matrix(int row, int col);
  Matrix();
  ~Matrix();

  Matrix(const Matrix& m);
  Matrix& operator=(const Matrix& m);
  Matrix(Matrix&& m) noexcept;
  Matrix& operator=(Matrix&& m);
  int get_row() const;
  void set_row(int M);
};
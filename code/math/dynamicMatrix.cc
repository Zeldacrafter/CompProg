#include "../template.hh"
template<typename T>
struct matrix : public vector<vector<T>> {
  matrix(int sz) : vector<vector<T>>(sz, vector<T>(sz)) {}
  matrix(int sz, const T& val) : vector<vector<T>>(sz, vector<T>(sz)) {
    F0R (i, SZ(*this)) (*this)[i][i] = val;
  }
  matrix& operator+=(const matrix& o) {
    F0R (r, SZ(*this)) F0R (c, SZ(*this)) (*this)[r][c] += o[r][c];
    return *this;
  }
  matrix& operator-=(const matrix& o) {
    F0R (r, SZ(*this)) F0R (c, SZ(*this)) (*this)[r][c] -= o[r][c];
    return *this;
  }
  matrix& operator*=(const matrix& o) {
    return *this = *this * o;
  }
  matrix& operator*=(T v) {
    F0R (r, SZ(*this)) F0R (c, this->sz) (*this)[r][c] *= v;
    return *this;
  }
  friend matrix operator+(const matrix a, const matrix& b) {
    return a += b;
  }
  friend matrix operator-(const matrix a, const matrix& b) {
    return a -= b;
  }
  friend matrix operator*(const matrix& a, const matrix& b) {
    matrix res{SZ(a)};
    F0R (r, SZ(a)) F0R (c, SZ(a)) F0R (k, SZ(a)) res[r][c] += a[r][k] * b[k][c];
    return res;
  }
  friend matrix operator*(matrix a, T v) {
    return a *= v;
  }
  friend matrix operator*(T v, matrix a) {
    return a *= v;
  }
};

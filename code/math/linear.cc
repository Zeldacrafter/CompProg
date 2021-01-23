#include "../template.hh"
template<typename T, int R, int C>
struct matrix : public array<array<T, C>, R> {
  matrix() : array<array<T, C>, R>{} {}
  matrix(const T& val) : array<array<T, C>, R>{} {
    F0R (i, min(R, C)) (*this)[i][i] = val;
  }
  matrix(initializer_list<T> l) : array<array<T, C>, R>{} {
    int i = 0; for (T e : l) (*this)[i++][0] = e;
  }
  matrix(initializer_list<initializer_list<T>> l) : array<array<T, C>, R>{} {
    int i = 0; for (auto& lp : l) copy(ALL(lp), (*this)[i++].begin());
  }
  T& operator()(size_t i) { return (*this)[i][0]; }
  matrix& operator+=(const matrix& o) {
    F0R (r, R) F0R (c, C) (*this)[r][c] += o[r][c];
    return *this;
  }
  matrix& operator-=(const matrix& o) {
    F0R (r, R) F0R (c, C) (*this)[r][c] -= o[r][c];
    return *this;
  }
  matrix& operator*=(T v) {
    F0R (r, R) F0R (c, C) (*this)[r][c] *= v;
    return *this;
  }
  matrix operator-() {
    matrix res{*this};
    F0R (r, R) F0R (c, C) res[r][c] = -res[r][c];
    return res;
  }
  matrix operator+() { return *this; }
  friend matrix operator+(matrix a, const matrix& b) { return a += b; }
  friend matrix operator-(matrix a, const matrix& b) { return a -= b; }
  friend matrix operator*(matrix a, T v) { return a *= v; }
  friend matrix operator*(T v, matrix a) { return a *= v; }
};
template<typename T, int R, int K, int C>
matrix<T, R, C> operator*(const matrix<T, R, K>& a, const matrix<T, K, C>& b) {
  matrix<T, R, C> res{};
  F0R (r, R) F0R (c, C) F0R (k, K) res[r][c] += a[r][k] * b[k][c];
  return res;
}
template<typename T, int N>
using sqmat = matrix<T, N, N>;
template<typename T, int N>
using vec = matrix<T, N, 1>;
template<typename T, int N>
struct linear {
  using M = sqmat<T, N>; M m;
  using V = vec<T, N>; V v;
  linear() : m(1), v() {}
  linear(const M& _m) : m{_m}, v() {}
  linear(const V& _v) : m(1), v{_v} {}
  linear(const M& _m, const V& _v) : m{_m}, v{_v} {}
  V operator()(const V& x) { return calc(x); }
  V calc(const V& x) { return m * x + v; }
  linear combine(const linear& o) { // o(this(x))
    return linear(o.m * m, o.m * v + o.v);
  }
  linear combine(const M& o) {
    return linear(o * m, o * v);
  }
  linear combine(const V& o) {
    return linear(m, v + o);
  }
  linear combine(const M& om, const V& ov) {
    return combine(linear(om, ov));
  }
};
using L = linear<ll, 2>;

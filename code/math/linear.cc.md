---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"code/template.cc\"\n// this line is here for a reason\n\
    #include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii> vii;\ntypedef\
    \ vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define fi first\n#define se second\n\
    #define eb emplace_back\n#define pb push_back\n#define mp make_pair\n#define mt\
    \ make_tuple\n#define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n#define\
    \ RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x) (int)(x).size()\n#define FOR(a,\
    \ b, c) for (auto a = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\n\
    template <typename T>\nbool ckmin(T& a, const T& b) { return a > b ? a = b, true\
    \ : false; }\ntemplate <typename T>\nbool ckmax(T& a, const T& b) { return a <\
    \ b ? a = b, true : false; }\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define\
    \ dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__)\
    \ << \"] \"\n#line 2 \"code/math/linear.cc\"\ntemplate<typename T, int R, int\
    \ C>\nstruct matrix : public array<array<T, C>, R> {\n  matrix() : array<array<T,\
    \ C>, R>{} {}\n  matrix(const T& val) : array<array<T, C>, R>{} {\n    F0R (i,\
    \ min(R, C)) (*this)[i][i] = val;\n  }\n  matrix(initializer_list<T> l) : array<array<T,\
    \ C>, R>{} {\n    int i = 0; for (T e : l) (*this)[i++][0] = e;\n  }\n  matrix(initializer_list<initializer_list<T>>\
    \ l) : array<array<T, C>, R>{} {\n    int i = 0; for (auto& lp : l) copy(ALL(lp),\
    \ (*this)[i++].begin());\n  }\n  T& operator()(size_t i) { return (*this)[i][0];\
    \ }\n  matrix& operator+=(const matrix& o) {\n    F0R (r, R) F0R (c, C) (*this)[r][c]\
    \ += o[r][c];\n    return *this;\n  }\n  matrix& operator-=(const matrix& o) {\n\
    \    F0R (r, R) F0R (c, C) (*this)[r][c] -= o[r][c];\n    return *this;\n  }\n\
    \  matrix& operator*=(T v) {\n    F0R (r, R) F0R (c, C) (*this)[r][c] *= v;\n\
    \    return *this;\n  }\n  matrix operator-() {\n    matrix res{*this};\n    F0R\
    \ (r, R) F0R (c, C) res[r][c] = -res[r][c];\n    return res;\n  }\n  matrix operator+()\
    \ { return *this; }\n  friend matrix operator+(matrix a, const matrix& b) { return\
    \ a += b; }\n  friend matrix operator-(matrix a, const matrix& b) { return a -=\
    \ b; }\n  friend matrix operator*(matrix a, T v) { return a *= v; }\n  friend\
    \ matrix operator*(T v, matrix a) { return a *= v; }\n};\ntemplate<typename T,\
    \ int R, int K, int C>\nmatrix<T, R, C> operator*(const matrix<T, R, K>& a, const\
    \ matrix<T, K, C>& b) {\n  matrix<T, R, C> res{};\n  F0R (r, R) F0R (c, C) F0R\
    \ (k, K) res[r][c] += a[r][k] * b[k][c];\n  return res;\n}\ntemplate<typename\
    \ T, int N>\nusing sqmat = matrix<T, N, N>;\ntemplate<typename T, int N>\nusing\
    \ vec = matrix<T, N, 1>;\ntemplate<typename T, int N>\nstruct linear {\n  using\
    \ M = sqmat<T, N>; M m;\n  using V = vec<T, N>; V v;\n  linear() : m(1), v() {}\n\
    \  linear(const M& _m) : m{_m}, v() {}\n  linear(const V& _v) : m(1), v{_v} {}\n\
    \  linear(const M& _m, const V& _v) : m{_m}, v{_v} {}\n  V operator()(const V&\
    \ x) { return calc(x); }\n  V calc(const V& x) { return m * x + v; }\n  linear\
    \ combine(const linear& o) { // o(this(x))\n    return linear(o.m * m, o.m * v\
    \ + o.v);\n  }\n  linear combine(const M& o) {\n    return linear(o * m, o * v);\n\
    \  }\n  linear combine(const V& o) {\n    return linear(m, v + o);\n  }\n  linear\
    \ combine(const M& om, const V& ov) {\n    return combine(linear(om, ov));\n \
    \ }\n};\nusing L = linear<ll, 2>;\n"
  code: "#include \"../template.hh\"\ntemplate<typename T, int R, int C>\nstruct matrix\
    \ : public array<array<T, C>, R> {\n  matrix() : array<array<T, C>, R>{} {}\n\
    \  matrix(const T& val) : array<array<T, C>, R>{} {\n    F0R (i, min(R, C)) (*this)[i][i]\
    \ = val;\n  }\n  matrix(initializer_list<T> l) : array<array<T, C>, R>{} {\n \
    \   int i = 0; for (T e : l) (*this)[i++][0] = e;\n  }\n  matrix(initializer_list<initializer_list<T>>\
    \ l) : array<array<T, C>, R>{} {\n    int i = 0; for (auto& lp : l) copy(ALL(lp),\
    \ (*this)[i++].begin());\n  }\n  T& operator()(size_t i) { return (*this)[i][0];\
    \ }\n  matrix& operator+=(const matrix& o) {\n    F0R (r, R) F0R (c, C) (*this)[r][c]\
    \ += o[r][c];\n    return *this;\n  }\n  matrix& operator-=(const matrix& o) {\n\
    \    F0R (r, R) F0R (c, C) (*this)[r][c] -= o[r][c];\n    return *this;\n  }\n\
    \  matrix& operator*=(T v) {\n    F0R (r, R) F0R (c, C) (*this)[r][c] *= v;\n\
    \    return *this;\n  }\n  matrix operator-() {\n    matrix res{*this};\n    F0R\
    \ (r, R) F0R (c, C) res[r][c] = -res[r][c];\n    return res;\n  }\n  matrix operator+()\
    \ { return *this; }\n  friend matrix operator+(matrix a, const matrix& b) { return\
    \ a += b; }\n  friend matrix operator-(matrix a, const matrix& b) { return a -=\
    \ b; }\n  friend matrix operator*(matrix a, T v) { return a *= v; }\n  friend\
    \ matrix operator*(T v, matrix a) { return a *= v; }\n};\ntemplate<typename T,\
    \ int R, int K, int C>\nmatrix<T, R, C> operator*(const matrix<T, R, K>& a, const\
    \ matrix<T, K, C>& b) {\n  matrix<T, R, C> res{};\n  F0R (r, R) F0R (c, C) F0R\
    \ (k, K) res[r][c] += a[r][k] * b[k][c];\n  return res;\n}\ntemplate<typename\
    \ T, int N>\nusing sqmat = matrix<T, N, N>;\ntemplate<typename T, int N>\nusing\
    \ vec = matrix<T, N, 1>;\ntemplate<typename T, int N>\nstruct linear {\n  using\
    \ M = sqmat<T, N>; M m;\n  using V = vec<T, N>; V v;\n  linear() : m(1), v() {}\n\
    \  linear(const M& _m) : m{_m}, v() {}\n  linear(const V& _v) : m(1), v{_v} {}\n\
    \  linear(const M& _m, const V& _v) : m{_m}, v{_v} {}\n  V operator()(const V&\
    \ x) { return calc(x); }\n  V calc(const V& x) { return m * x + v; }\n  linear\
    \ combine(const linear& o) { // o(this(x))\n    return linear(o.m * m, o.m * v\
    \ + o.v);\n  }\n  linear combine(const M& o) {\n    return linear(o * m, o * v);\n\
    \  }\n  linear combine(const V& o) {\n    return linear(m, v + o);\n  }\n  linear\
    \ combine(const M& om, const V& ov) {\n    return combine(linear(om, ov));\n \
    \ }\n};\nusing L = linear<ll, 2>;\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/math/linear.cc
  requiredBy: []
  timestamp: '2021-01-23 14:30:21+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/math/linear.cc
layout: document
redirect_from:
- /library/code/math/linear.cc
- /library/code/math/linear.cc.html
title: code/math/linear.cc
---

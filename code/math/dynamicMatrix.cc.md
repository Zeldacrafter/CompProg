---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ << \"] \"\n#line 2 \"code/math/dynamicMatrix.cc\"\ntemplate<typename T>\nstruct\
    \ matrix : public vector<vector<T>> {\n  matrix(int sz) : vector<vector<T>>(sz,\
    \ vector<T>(sz)) {}\n  matrix(int sz, const T& val) : vector<vector<T>>(sz, vector<T>(sz))\
    \ {\n    F0R (i, SZ(*this)) (*this)[i][i] = val;\n  }\n  matrix& operator+=(const\
    \ matrix& o) {\n    F0R (r, SZ(*this)) F0R (c, SZ(*this)) (*this)[r][c] += o[r][c];\n\
    \    return *this;\n  }\n  matrix& operator-=(const matrix& o) {\n    F0R (r,\
    \ SZ(*this)) F0R (c, SZ(*this)) (*this)[r][c] -= o[r][c];\n    return *this;\n\
    \  }\n  matrix& operator*=(const matrix& o) {\n    return *this = *this * o;\n\
    \  }\n  matrix& operator*=(T v) {\n    F0R (r, SZ(*this)) F0R (c, this->sz) (*this)[r][c]\
    \ *= v;\n    return *this;\n  }\n  friend matrix operator+(const matrix a, const\
    \ matrix& b) {\n    return a += b;\n  }\n  friend matrix operator-(const matrix\
    \ a, const matrix& b) {\n    return a -= b;\n  }\n  friend matrix operator*(const\
    \ matrix& a, const matrix& b) {\n    matrix res{SZ(a)};\n    F0R (r, SZ(a)) F0R\
    \ (c, SZ(a)) F0R (k, SZ(a)) res[r][c] += a[r][k] * b[k][c];\n    return res;\n\
    \  }\n  friend matrix operator*(matrix a, T v) {\n    return a *= v;\n  }\n  friend\
    \ matrix operator*(T v, matrix a) {\n    return a *= v;\n  }\n};\n"
  code: "#include \"../template.hh\"\ntemplate<typename T>\nstruct matrix : public\
    \ vector<vector<T>> {\n  matrix(int sz) : vector<vector<T>>(sz, vector<T>(sz))\
    \ {}\n  matrix(int sz, const T& val) : vector<vector<T>>(sz, vector<T>(sz)) {\n\
    \    F0R (i, SZ(*this)) (*this)[i][i] = val;\n  }\n  matrix& operator+=(const\
    \ matrix& o) {\n    F0R (r, SZ(*this)) F0R (c, SZ(*this)) (*this)[r][c] += o[r][c];\n\
    \    return *this;\n  }\n  matrix& operator-=(const matrix& o) {\n    F0R (r,\
    \ SZ(*this)) F0R (c, SZ(*this)) (*this)[r][c] -= o[r][c];\n    return *this;\n\
    \  }\n  matrix& operator*=(const matrix& o) {\n    return *this = *this * o;\n\
    \  }\n  matrix& operator*=(T v) {\n    F0R (r, SZ(*this)) F0R (c, this->sz) (*this)[r][c]\
    \ *= v;\n    return *this;\n  }\n  friend matrix operator+(const matrix a, const\
    \ matrix& b) {\n    return a += b;\n  }\n  friend matrix operator-(const matrix\
    \ a, const matrix& b) {\n    return a -= b;\n  }\n  friend matrix operator*(const\
    \ matrix& a, const matrix& b) {\n    matrix res{SZ(a)};\n    F0R (r, SZ(a)) F0R\
    \ (c, SZ(a)) F0R (k, SZ(a)) res[r][c] += a[r][k] * b[k][c];\n    return res;\n\
    \  }\n  friend matrix operator*(matrix a, T v) {\n    return a *= v;\n  }\n  friend\
    \ matrix operator*(T v, matrix a) {\n    return a *= v;\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/math/dynamicMatrix.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/math/dynamicMatrix.cc
layout: document
redirect_from:
- /library/code/math/dynamicMatrix.cc
- /library/code/math/dynamicMatrix.cc.html
title: code/math/dynamicMatrix.cc
---

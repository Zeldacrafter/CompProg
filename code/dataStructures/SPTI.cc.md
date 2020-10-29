---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/sparse_tableI.static_rmq.test.cpp
    title: tests/yosupo/sparse_tableI.static_rmq.test.cpp
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ << \"] \"\n#line 2 \"code/dataStructures/SPTI.cc\"\ntemplate <typename T, typename\
    \ F> // F :: T -> T -> bool; first: true\nstruct SPTI { \n  vector<T> d;\n  vvi\
    \ idx;\n  F f;\n  SPTI (int n, F _f) : d(n), idx(32 - __builtin_clz(n), vi(n)),\
    \ f{_f} {\n    iota(ALL(idx[0]), 0);\n  }\n  SPTI (const vector<T>& v, F _f) :\
    \ SPTI(SZ(v), _f) {\n    d = v;\n    build();\n  }\n  void build() {\n    for\
    \ (int j = 1; (1 << j) <= SZ(d); ++j) {\n      for (int i = 0; i + (1 << j) <=\
    \ SZ(d); ++i) {\n        int k = i + (1 << (j - 1));\n        idx[j][i] = f(d[idx[j\
    \ - 1][i]], d[idx[j - 1][k]])\n          ? idx[j - 1][i] : idx[j - 1][k];\n  \
    \    }\n    }\n  }\n  int query(int l, int r) { // [l, r)\n    int k = 31 - __builtin_clz(r\
    \ - l);\n    return f(d[idx[k][l]], d[idx[k][r - (1 << k)]])\n      ? idx[k][l]\
    \ : idx[k][r - (1 << k)];\n  }\n};\n"
  code: "#include \"../template.hh\"\ntemplate <typename T, typename F> // F :: T\
    \ -> T -> bool; first: true\nstruct SPTI { \n  vector<T> d;\n  vvi idx;\n  F f;\n\
    \  SPTI (int n, F _f) : d(n), idx(32 - __builtin_clz(n), vi(n)), f{_f} {\n   \
    \ iota(ALL(idx[0]), 0);\n  }\n  SPTI (const vector<T>& v, F _f) : SPTI(SZ(v),\
    \ _f) {\n    d = v;\n    build();\n  }\n  void build() {\n    for (int j = 1;\
    \ (1 << j) <= SZ(d); ++j) {\n      for (int i = 0; i + (1 << j) <= SZ(d); ++i)\
    \ {\n        int k = i + (1 << (j - 1));\n        idx[j][i] = f(d[idx[j - 1][i]],\
    \ d[idx[j - 1][k]])\n          ? idx[j - 1][i] : idx[j - 1][k];\n      }\n   \
    \ }\n  }\n  int query(int l, int r) { // [l, r)\n    int k = 31 - __builtin_clz(r\
    \ - l);\n    return f(d[idx[k][l]], d[idx[k][r - (1 << k)]])\n      ? idx[k][l]\
    \ : idx[k][r - (1 << k)];\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/SPTI.cc
  requiredBy: []
  timestamp: '2020-10-28 23:01:50+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/sparse_tableI.static_rmq.test.cpp
documentation_of: code/dataStructures/SPTI.cc
layout: document
redirect_from:
- /library/code/dataStructures/SPTI.cc
- /library/code/dataStructures/SPTI.cc.html
title: code/dataStructures/SPTI.cc
---

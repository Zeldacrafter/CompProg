---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dataStructures/FT.cc
    title: code/dataStructures/FT.cc
  - icon: ':heavy_check_mark:'
    path: code/dataStructures/FT2D.cc
    title: code/dataStructures/FT2D.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://www.hackerrank.com/challenges/cube-summation/problem
    links:
    - https://www.hackerrank.com/challenges/cube-summation/problem
  bundledCode: "#line 1 \"tests/hackerrank/fenwick_tree_2d.cube-summation.test.cpp\"\
    \n#define PROBLEM \"https://www.hackerrank.com/challenges/cube-summation/problem\"\
    \n\n#line 1 \"code/template.cc\"\n// this line is here for a reason\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef pair<int,\
    \ int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii> vii;\ntypedef vector<vi>\
    \ vvi;\ntypedef vector<vii> vvii;\n#define fi first\n#define se second\n#define\
    \ eb emplace_back\n#define pb push_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(),\
    \ (x).rend()\n#define SZ(x) (int)(x).size()\n#define FOR(a, b, c) for (auto a\
    \ = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename\
    \ T>\nbool ckmin(T& a, const T& b) { return a > b ? a = b, true : false; }\ntemplate\
    \ <typename T>\nbool ckmax(T& a, const T& b) { return a < b ? a = b, true : false;\
    \ }\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define\
    \ dvar(...) \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2\
    \ \"code/dataStructures/FT.cc\"\ntemplate<typename T>\nstruct FT {\n  int n;\n\
    \  vector<T> A;\n  FT(int sz) : n{sz}, A(n, 0) {}\n  T query(int i) {\n    T sum\
    \ = 0;\n    for (--i; i >= 0; i = (i & (i + 1)) - 1) sum += A[i];\n    return\
    \ sum;\n  }\n  T query(int i, int j) { return query(j) - query(i); }\n  void update(int\
    \ i, T add) {\n    for (; i < n; i |= i + 1) A[i] += add;\n  }\n  // lb assumes\
    \ query(i, i) >= 0 forall i in [1, n]\n  // returns min p >= 1, so that [1, p]\
    \ >= sum\n  // if [1, n] < sum, return n + 1\n  /* TODO: 0 indexed\n  int lb(T\
    \ sum) {\n    int pos = 0;\n    for (int pw = 1 << 25; pw; pw >>= 1)\n      if\
    \ (pos + pw <= n && sum > A[pos | pw]) sum -= A[pos |= pw];\n    return pos +\
    \ !!sum;\n  }\n  */\n};\n#line 2 \"code/dataStructures/FT2D.cc\"\ntemplate<typename\
    \ T>\nstruct FT2D {\n  int n;\n  vector<FT<T>> fts;\n  FT2D(int sz1, int sz2)\
    \ : n{sz1}, fts(n + 1, FT<T>(sz2)) {};\n  T query(int i, int j1, int j2) {\n \
    \   T sum = 0;\n    for (--i; i >= 0; i = (i & (i + 1)) - 1) sum += fts[i].query(j1,\
    \ j2);\n    return sum;\n  }\n  T query(int i1, int i2, int j1, int j2) {\n  \
    \  return query(i2, j1, j2) - query(i1, j1, j2);\n  }\n  void update(int i, int\
    \ j, T add) {\n    for (; i < n; i |= i + 1) fts[i].update(j, add);\n  }\n};\n\
    #line 4 \"tests/hackerrank/fenwick_tree_2d.cube-summation.test.cpp\"\n\ntemplate<typename\
    \ T>\nstruct FT3D {\n  int n;\n  vector<FT2D<T>> fts;\n  FT3D(int sz1, int sz2,\
    \ int sz3) : n{sz1}, fts(n + 1, FT2D<T>(sz2, sz3)) {};\n  T query(int i, int j1,\
    \ int j2, int k1, int k2) {\n    T sum = 0;\n    for (--i; i >= 0; i = (i & (i\
    \ + 1)) - 1) sum += fts[i].query(j1, j2, k1, k2);\n    return sum;\n  }\n  T query(int\
    \ i1, int i2, int j1, int j2, int k1, int k2) {\n    return query(i2, j1, j2,\
    \ k1, k2) - query(i1, j1, j2, k1, k2);\n  }\n  void update(int i, int j, int k,\
    \ T add) {\n    for (; i < n; i |= i + 1) fts[i].update(j, k, add);\n  }\n};\n\
    \nvoid solve() {\n  int n, m;\n  cin >> n >> m;\n  FT3D<ll> ft(n + 1, n + 1, n\
    \ + 1);\n\n  F0R(i, m) {\n    string s;\n    cin >> s;\n    if(s == \"QUERY\"\
    ) {\n      int x1, x2, y1, y2, z1, z2;\n      cin >> x1 >> y1 >> z1 >> x2 >> y2\
    \ >> z2;\n      x1--; y1--; z1--; x2--; y2--; z2--;\n\n      cout << ft.query(x1,\
    \ x2 + 1, y1, y2 + 1, z1, z2 + 1) << endl;\n    } else {\n      assert(s == \"\
    UPDATE\");\n      int x, y, z;\n      ll w;\n      cin >> x >> y >> z >> w;\n\
    \      x--; y--; z--;\n\n      ll val = ft.query(x, x + 1, y, y + 1, z, z + 1);\n\
    \      ft.update(x, y, z, w - val);\n    }\n  }\n}\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int tc;\n  cin >> tc;\n  while(tc--) solve();\n\
    }\n\n\n\n"
  code: "#define PROBLEM \"https://www.hackerrank.com/challenges/cube-summation/problem\"\
    \n\n#include \"../../code/dataStructures/FT2D.cc\"\n\ntemplate<typename T>\nstruct\
    \ FT3D {\n  int n;\n  vector<FT2D<T>> fts;\n  FT3D(int sz1, int sz2, int sz3)\
    \ : n{sz1}, fts(n + 1, FT2D<T>(sz2, sz3)) {};\n  T query(int i, int j1, int j2,\
    \ int k1, int k2) {\n    T sum = 0;\n    for (--i; i >= 0; i = (i & (i + 1)) -\
    \ 1) sum += fts[i].query(j1, j2, k1, k2);\n    return sum;\n  }\n  T query(int\
    \ i1, int i2, int j1, int j2, int k1, int k2) {\n    return query(i2, j1, j2,\
    \ k1, k2) - query(i1, j1, j2, k1, k2);\n  }\n  void update(int i, int j, int k,\
    \ T add) {\n    for (; i < n; i |= i + 1) fts[i].update(j, k, add);\n  }\n};\n\
    \nvoid solve() {\n  int n, m;\n  cin >> n >> m;\n  FT3D<ll> ft(n + 1, n + 1, n\
    \ + 1);\n\n  F0R(i, m) {\n    string s;\n    cin >> s;\n    if(s == \"QUERY\"\
    ) {\n      int x1, x2, y1, y2, z1, z2;\n      cin >> x1 >> y1 >> z1 >> x2 >> y2\
    \ >> z2;\n      x1--; y1--; z1--; x2--; y2--; z2--;\n\n      cout << ft.query(x1,\
    \ x2 + 1, y1, y2 + 1, z1, z2 + 1) << endl;\n    } else {\n      assert(s == \"\
    UPDATE\");\n      int x, y, z;\n      ll w;\n      cin >> x >> y >> z >> w;\n\
    \      x--; y--; z--;\n\n      ll val = ft.query(x, x + 1, y, y + 1, z, z + 1);\n\
    \      ft.update(x, y, z, w - val);\n    }\n  }\n}\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int tc;\n  cin >> tc;\n  while(tc--) solve();\n\
    }\n\n\n\n"
  dependsOn:
  - code/dataStructures/FT2D.cc
  - code/dataStructures/FT.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/hackerrank/fenwick_tree_2d.cube-summation.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/hackerrank/fenwick_tree_2d.cube-summation.test.cpp
layout: document
redirect_from:
- /verify/tests/hackerrank/fenwick_tree_2d.cube-summation.test.cpp
- /verify/tests/hackerrank/fenwick_tree_2d.cube-summation.test.cpp.html
title: tests/hackerrank/fenwick_tree_2d.cube-summation.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: code/graphs/kruskal.cc
    title: code/graphs/kruskal.cc
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/kruskal.minimum_spanning_tree.test.cc
    title: tests/aoj/kruskal.minimum_spanning_tree.test.cc
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/unionfind.test.cpp
    title: tests/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
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
    \ << \"] \"\n#line 2 \"code/dataStructures/DSU.cc\"\nstruct DSU {\n  DSU(int size)\
    \ : msize(size), data(size, -1) {}\n  bool sameSet(int a, int b) { return find(a)\
    \ == find(b); }\n  int find(int x) {\n    return data[x] < 0 ? x : data[x] = find(data[x]);\n\
    \  }\n  bool join(int a, int b) {\n    a = find(a), b = find(b);\n    if (a ==\
    \ b) return false;\n    if (data[a] > data[b]) swap(a, b);\n    data[a] += data[b],\
    \ data[b] = a;\n    return --msize, true;\n  }\n  int size() { return msize; }\n\
    \  int size(int a) { return -data[find(a)]; }\n  int msize;\n  vi data;\n};\n"
  code: "#include \"../template.hh\"\nstruct DSU {\n  DSU(int size) : msize(size),\
    \ data(size, -1) {}\n  bool sameSet(int a, int b) { return find(a) == find(b);\
    \ }\n  int find(int x) {\n    return data[x] < 0 ? x : data[x] = find(data[x]);\n\
    \  }\n  bool join(int a, int b) {\n    a = find(a), b = find(b);\n    if (a ==\
    \ b) return false;\n    if (data[a] > data[b]) swap(a, b);\n    data[a] += data[b],\
    \ data[b] = a;\n    return --msize, true;\n  }\n  int size() { return msize; }\n\
    \  int size(int a) { return -data[find(a)]; }\n  int msize;\n  vi data;\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/DSU.cc
  requiredBy:
  - code/graphs/kruskal.cc
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/kruskal.minimum_spanning_tree.test.cc
  - tests/yosupo/unionfind.test.cpp
documentation_of: code/dataStructures/DSU.cc
layout: document
redirect_from:
- /library/code/dataStructures/DSU.cc
- /library/code/dataStructures/DSU.cc.html
title: code/dataStructures/DSU.cc
---

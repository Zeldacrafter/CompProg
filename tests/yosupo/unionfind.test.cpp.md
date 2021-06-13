---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dataStructures/DSU.cc
    title: code/dataStructures/DSU.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"tests/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
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
    \ \"code/dataStructures/DSU.cc\"\nstruct DSU {\n  DSU(int size) : msize(size),\
    \ data(size, -1) {}\n  bool sameSet(int a, int b) { return find(a) == find(b);\
    \ }\n  int find(int x) {\n    return data[x] < 0 ? x : data[x] = find(data[x]);\n\
    \  }\n  bool join(int a, int b) {\n    a = find(a), b = find(b);\n    if (a ==\
    \ b) return false;\n    if (data[a] > data[b]) swap(a, b);\n    data[a] += data[b],\
    \ data[b] = a;\n    return --msize, true;\n  }\n  int size() { return msize; }\n\
    \  int size(int a) { return -data[find(a)]; }\n  int msize;\n  vi data;\n};\n\
    #line 4 \"tests/yosupo/unionfind.test.cpp\"\n\nint main() {\n  cin.tie(0);\n \
    \ ios_base::sync_with_stdio(0);\n  \n  int n, q;\n  cin >> n >> q;\n  \n  DSU\
    \ dsu(n);\n  while(q--) {\n    int a, b ,c;\n    cin >> a >> b >> c;\n    if(!a)\
    \ {\n      dsu.join(b, c);\n    } else {\n      cout << dsu.sameSet(b, c) << endl;\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../code/dataStructures/DSU.cc\"\n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\
    \  \n  int n, q;\n  cin >> n >> q;\n  \n  DSU dsu(n);\n  while(q--) {\n    int\
    \ a, b ,c;\n    cin >> a >> b >> c;\n    if(!a) {\n      dsu.join(b, c);\n   \
    \ } else {\n      cout << dsu.sameSet(b, c) << endl;\n    }\n  }\n}\n"
  dependsOn:
  - code/dataStructures/DSU.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/unionfind.test.cpp
- /verify/tests/yosupo/unionfind.test.cpp.html
title: tests/yosupo/unionfind.test.cpp
---

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
    \ << \"] \"\n#line 2 \"code/dataStructures/DSUV.cc\"\ntemplate<typename V, typename\
    \ F>\nstruct DSU {\n  int sz;\n  vi p;\n  vector<V> v;\n  F f;\n  DSU(int size,\
    \ const V& v, F _f) :\n    sz{size}, p(size, -1), v(size, v), f{_f} {}\n  bool\
    \ sameSet(int a, int b) { return find(a) == find(b); }\n  int find(int x) { return\
    \ p[x] < 0 ? x : p[x] = find(p[x]); }\n  bool join(int a, int b) {\n    a = find(a),\
    \ b = find(b);\n    if (a == b) return false;\n    if (p[a] > p[b]) swap(a, b);\n\
    \    p[a] += p[b], p[b] = a;\n    v[a] = f(v[a], v[b]);\n    return --sz, true;\n\
    \  }\n  int size() { return sz; }\n  int size(int a) { return -p[find(a)]; }\n\
    };\n"
  code: "#include \"../template.hh\"\ntemplate<typename V, typename F>\nstruct DSU\
    \ {\n  int sz;\n  vi p;\n  vector<V> v;\n  F f;\n  DSU(int size, const V& v, F\
    \ _f) :\n    sz{size}, p(size, -1), v(size, v), f{_f} {}\n  bool sameSet(int a,\
    \ int b) { return find(a) == find(b); }\n  int find(int x) { return p[x] < 0 ?\
    \ x : p[x] = find(p[x]); }\n  bool join(int a, int b) {\n    a = find(a), b =\
    \ find(b);\n    if (a == b) return false;\n    if (p[a] > p[b]) swap(a, b);\n\
    \    p[a] += p[b], p[b] = a;\n    v[a] = f(v[a], v[b]);\n    return --sz, true;\n\
    \  }\n  int size() { return sz; }\n  int size(int a) { return -p[find(a)]; }\n\
    };\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/DSUV.cc
  requiredBy: []
  timestamp: '2021-02-09 05:05:28+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/dataStructures/DSUV.cc
layout: document
redirect_from:
- /library/code/dataStructures/DSUV.cc
- /library/code/dataStructures/DSUV.cc.html
title: code/dataStructures/DSUV.cc
---

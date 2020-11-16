---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: code/graphs/HLD.cc
    title: code/graphs/HLD.cc
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/hld.range_query_on_tree.test.cpp
    title: tests/aoj/hld.range_query_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/segment_tree.point_add_range_sum.test.cpp
    title: tests/yosupo/segment_tree.point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/segment_tree.static_range_sum.test.cpp
    title: tests/yosupo/segment_tree.static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/segment_tree.static_rmq.test.cpp
    title: tests/yosupo/segment_tree.static_rmq.test.cpp
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
    \ << \"] \"\n#line 2 \"code/dataStructures/STIT.cc\"\ntemplate<typename T, typename\
    \ F>\nstruct ST {\n  using value_type = T;\n  using merge_type = F; \n  const\
    \ int n;\n  const T e;\n  F merge;\n  vector<T> data;\n  ST(int sz, T _e, F m)\
    \ : n{sz}, e{_e}, merge{m}, data(2 * n, e) {}\n  void build() {\n    for (int\
    \ i = n - 1; i; --i)\n      data[i] = merge(data[i << 1], data[i << 1 | 1]);\n\
    \  }\n  T query(int l, int r) {\n    T li = e, ri = e;\n    for (l += n, r +=\
    \ n; l < r; r >>= 1, l >>= 1) {\n      if (l & 1) li = merge(li, data[l++]);\n\
    \      if (r & 1) ri = merge(data[--r], ri);\n    }\n    return merge(li, ri);\n\
    \  }\n  void update(int i, T val) {\n    for (data[i += n] = val; i > 1; i >>=\
    \ 1)\n      data[i >> 1] = merge(data[i & ~1], data[i | 1]);\n  }\n};\n"
  code: "#include \"../template.hh\"\ntemplate<typename T, typename F>\nstruct ST\
    \ {\n  using value_type = T;\n  using merge_type = F; \n  const int n;\n  const\
    \ T e;\n  F merge;\n  vector<T> data;\n  ST(int sz, T _e, F m) : n{sz}, e{_e},\
    \ merge{m}, data(2 * n, e) {}\n  void build() {\n    for (int i = n - 1; i; --i)\n\
    \      data[i] = merge(data[i << 1], data[i << 1 | 1]);\n  }\n  T query(int l,\
    \ int r) {\n    T li = e, ri = e;\n    for (l += n, r += n; l < r; r >>= 1, l\
    \ >>= 1) {\n      if (l & 1) li = merge(li, data[l++]);\n      if (r & 1) ri =\
    \ merge(data[--r], ri);\n    }\n    return merge(li, ri);\n  }\n  void update(int\
    \ i, T val) {\n    for (data[i += n] = val; i > 1; i >>= 1)\n      data[i >> 1]\
    \ = merge(data[i & ~1], data[i | 1]);\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/STIT.cc
  requiredBy:
  - code/graphs/HLD.cc
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/hld.range_query_on_tree.test.cpp
  - tests/yosupo/segment_tree.static_range_sum.test.cpp
  - tests/yosupo/segment_tree.static_rmq.test.cpp
  - tests/yosupo/segment_tree.point_add_range_sum.test.cpp
documentation_of: code/dataStructures/STIT.cc
layout: document
redirect_from:
- /library/code/dataStructures/STIT.cc
- /library/code/dataStructures/STIT.cc.html
title: code/dataStructures/STIT.cc
---

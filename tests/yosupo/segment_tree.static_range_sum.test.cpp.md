---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dataStructures/STIT.cc
    title: code/dataStructures/STIT.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"tests/yosupo/segment_tree.static_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line\
    \ 1 \"code/template.cc\"\n// this line is here for a reason\n#include <bits/stdc++.h>\n\
    using namespace std;\ntypedef long long ll;\ntypedef pair<int, int> ii;\ntypedef\
    \ vector<int> vi;\ntypedef vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii>\
    \ vvii;\n#define fi first\n#define se second\n#define eb emplace_back\n#define\
    \ pb push_back\n#define mp make_pair\n#define mt make_tuple\n#define endl '\\\
    n'\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n\
    #define SZ(x) (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c);\
    \ ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T&\
    \ a, const T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\n\
    bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef\
    \ DEBUG\n#define DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...)\
    \ \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/dataStructures/STIT.cc\"\
    \ntemplate<typename T, typename F>\nstruct ST {\n  using value_type = T;\n  using\
    \ merge_type = F; \n  const int n;\n  const T e;\n  F merge;\n  vector<T> data;\n\
    \  ST(int sz, T _e, F m) : n{sz}, e{_e}, merge{m}, data(2 * n, e) {}\n  void build()\
    \ {\n    for (int i = n - 1; i; --i)\n      data[i] = merge(data[i << 1], data[i\
    \ << 1 | 1]);\n  }\n  T query(int l, int r) {\n    T li = e, ri = e;\n    for\
    \ (l += n, r += n; l < r; r >>= 1, l >>= 1) {\n      if (l & 1) li = merge(li,\
    \ data[l++]);\n      if (r & 1) ri = merge(data[--r], ri);\n    }\n    return\
    \ merge(li, ri);\n  }\n  void update(int i, T val) {\n    for (data[i += n] =\
    \ val; i > 1; i >>= 1)\n      data[i >> 1] = merge(data[i & ~1], data[i | 1]);\n\
    \  }\n};\n#line 4 \"tests/yosupo/segment_tree.static_range_sum.test.cpp\"\n\n\
    int main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int n, q;\n\
    \  cin >> n >> q;\n\n  auto f = [](auto a, auto b) { return a + b; };\n  ST<ll,\
    \ decltype(f)> st(n, 0, f);\n\n  F0R(i, n)\n    cin >> st.data[n + i];\n  st.build();\n\
    \n  while(q--) {\n    int l, r;\n    cin >> l >> r;\n    cout << st.query(l, r)\
    \ << endl;\n  }\n}\n\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../code/dataStructures/STIT.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int n, q;\n  cin >> n >> q;\n\n  auto f\
    \ = [](auto a, auto b) { return a + b; };\n  ST<ll, decltype(f)> st(n, 0, f);\n\
    \n  F0R(i, n)\n    cin >> st.data[n + i];\n  st.build();\n\n  while(q--) {\n \
    \   int l, r;\n    cin >> l >> r;\n    cout << st.query(l, r) << endl;\n  }\n\
    }\n\n\n"
  dependsOn:
  - code/dataStructures/STIT.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/segment_tree.static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/segment_tree.static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/segment_tree.static_range_sum.test.cpp
- /verify/tests/yosupo/segment_tree.static_range_sum.test.cpp.html
title: tests/yosupo/segment_tree.static_range_sum.test.cpp
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/dataStructures/FT.cc
    title: code/dataStructures/FT.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"tests/yosupo/fenwick_tree.static_range_sum.test.cpp\"\n\
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
    \ \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/dataStructures/FT.cc\"\
    \ntemplate<typename T>\nstruct FT {\n  int n;\n  vector<T> A;\n  FT(int sz) :\
    \ n{sz}, A(n, 0) {}\n  T query(int i) {\n    T sum = 0;\n    for (--i; i >= 0;\
    \ i = (i & (i + 1)) - 1) sum += A[i];\n    return sum;\n  }\n  T query(int i,\
    \ int j) { return query(j) - query(i); }\n  void update(int i, T add) {\n    for\
    \ (; i < n; i |= i + 1) A[i] += add;\n  }\n  // lb assumes query(i, i) >= 0 forall\
    \ i in [1, n]\n  // returns min p >= 1, so that [1, p] >= sum\n  // if [1, n]\
    \ < sum, return n + 1\n  /* TODO: 0 indexed\n  int lb(T sum) {\n    int pos =\
    \ 0;\n    for (int pw = 1 << 25; pw; pw >>= 1)\n      if (pos + pw <= n && sum\
    \ > A[pos | pw]) sum -= A[pos |= pw];\n    return pos + !!sum;\n  }\n  */\n};\n\
    #line 4 \"tests/yosupo/fenwick_tree.static_range_sum.test.cpp\"\n\nint main()\
    \ {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int n, q;\n  cin >> n\
    \ >> q;\n  FT<ll> ft(n);\n\n  F0R(i, n) {\n    ll k;\n    cin >> k;\n    ft.update(i,\
    \ k);\n  }\n\n  while(q--) {\n    int l, r;\n    cin >> l >> r;\n    cout << ft.query(l,\
    \ r) << endl;\n  }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../code/dataStructures/FT.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int n, q;\n  cin >> n >> q;\n  FT<ll> ft(n);\n\
    \n  F0R(i, n) {\n    ll k;\n    cin >> k;\n    ft.update(i, k);\n  }\n\n  while(q--)\
    \ {\n    int l, r;\n    cin >> l >> r;\n    cout << ft.query(l, r) << endl;\n\
    \  }\n}\n\n"
  dependsOn:
  - code/dataStructures/FT.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/fenwick_tree.static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/fenwick_tree.static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/fenwick_tree.static_range_sum.test.cpp
- /verify/tests/yosupo/fenwick_tree.static_range_sum.test.cpp.html
title: tests/yosupo/fenwick_tree.static_range_sum.test.cpp
---

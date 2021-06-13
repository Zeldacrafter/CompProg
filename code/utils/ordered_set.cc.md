---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ << \"] \"\n#line 2 \"code/utils/ordered_set.cc\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\ntemplate <typename\
    \ T>\nusing oset = tree<T, null_type, less<T>, rb_tree_tag,\n                \
    \  tree_order_statistics_node_update>;\n// same operations as set w/ extra options:\n\
    // - oset.find_by_order(int k) returns iterator to the k-th smallest\n//   entry\
    \ (0 indexed)\n// - oset.oreder_of_key(int k) returns the number of keys strictly\n\
    //   smaller than k\n"
  code: "#include \"../template.hh\"\n#include <ext/pb_ds/assoc_container.hpp>\n#include\
    \ <ext/pb_ds/tree_policy.hpp>\nusing namespace __gnu_pbds;\ntemplate <typename\
    \ T>\nusing oset = tree<T, null_type, less<T>, rb_tree_tag,\n                \
    \  tree_order_statistics_node_update>;\n// same operations as set w/ extra options:\n\
    // - oset.find_by_order(int k) returns iterator to the k-th smallest\n//   entry\
    \ (0 indexed)\n// - oset.oreder_of_key(int k) returns the number of keys strictly\n\
    //   smaller than k\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/utils/ordered_set.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/utils/ordered_set.cc
layout: document
redirect_from:
- /library/code/utils/ordered_set.cc
- /library/code/utils/ordered_set.cc.html
title: code/utils/ordered_set.cc
---

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
    \ << \"] \"\n#line 2 \"code/dataStructures/WLTsmall.cc\"\n// only suitable for\
    \ relatively small alphabets ~10^6\ntemplate<typename T = int>\nstruct WLT {\n\
    \  using vt = typename vector<T>::iterator;\n  T H;\n  vvi M;\n  static inline\
    \ T mid(T a, T b) { return (a + b + 1) / 2; }\n  static inline int left(int i)\
    \ { return i << 1; }\n  static inline int right(int i) { return i << 1 | 1; }\n\
    \  // [0, hi)\n  WLT(vector<T> v, T hi) : H{hi}, M(H) {\n    build(ALL(v), 1,\
    \ 0, H);\n  }\n  void build(vt b, vt e, int i, T lo, T hi) {\n    if (lo + 1 ==\
    \ hi) return;\n    int m = mid(lo, hi);\n    M[i].reserve(distance(b, e) + 1);\
    \ M[i].pb(0);\n    auto less = [=](T k) { return k < m; };\n    for (auto it =\
    \ b; it != e; ++it) M[i].pb(M[i].back() + less(*it));\n    auto p = stable_partition(b,\
    \ e, less);\n    if (p != b) build(b, p, left(i), lo, m); \n    if (p != e) build(p,\
    \ e, right(i), m, hi);\n  }\n  // k-th smallest in [l, r)\n  T kthsmallest(int\
    \ l, int r, int k) {\n    T lo = 0, hi = H; int i = 1;\n    while (lo + 1 != hi)\
    \ {\n      if (k < M[i][r] - M[i][l]) {\n        l = M[i][l]; r = M[i][r];\n \
    \       i = left(i); hi = mid(lo, hi);\n      } else {\n        k -= M[i][r] -\
    \ M[i][l];\n        l -= M[i][l]; r -= M[i][r];\n        i = right(i); lo = mid(lo,\
    \ hi);\n      }\n    }\n    return lo;\n  }\n};\n"
  code: "#include \"../template.cc\"\n// only suitable for relatively small alphabets\
    \ ~10^6\ntemplate<typename T = int>\nstruct WLT {\n  using vt = typename vector<T>::iterator;\n\
    \  T H;\n  vvi M;\n  static inline T mid(T a, T b) { return (a + b + 1) / 2; }\n\
    \  static inline int left(int i) { return i << 1; }\n  static inline int right(int\
    \ i) { return i << 1 | 1; }\n  // [0, hi)\n  WLT(vector<T> v, T hi) : H{hi}, M(H)\
    \ {\n    build(ALL(v), 1, 0, H);\n  }\n  void build(vt b, vt e, int i, T lo, T\
    \ hi) {\n    if (lo + 1 == hi) return;\n    int m = mid(lo, hi);\n    M[i].reserve(distance(b,\
    \ e) + 1); M[i].pb(0);\n    auto less = [=](T k) { return k < m; };\n    for (auto\
    \ it = b; it != e; ++it) M[i].pb(M[i].back() + less(*it));\n    auto p = stable_partition(b,\
    \ e, less);\n    if (p != b) build(b, p, left(i), lo, m); \n    if (p != e) build(p,\
    \ e, right(i), m, hi);\n  }\n  // k-th smallest in [l, r)\n  T kthsmallest(int\
    \ l, int r, int k) {\n    T lo = 0, hi = H; int i = 1;\n    while (lo + 1 != hi)\
    \ {\n      if (k < M[i][r] - M[i][l]) {\n        l = M[i][l]; r = M[i][r];\n \
    \       i = left(i); hi = mid(lo, hi);\n      } else {\n        k -= M[i][r] -\
    \ M[i][l];\n        l -= M[i][l]; r -= M[i][r];\n        i = right(i); lo = mid(lo,\
    \ hi);\n      }\n    }\n    return lo;\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/WLTsmall.cc
  requiredBy: []
  timestamp: '2020-12-19 23:25:36+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/dataStructures/WLTsmall.cc
layout: document
redirect_from:
- /library/code/dataStructures/WLTsmall.cc
- /library/code/dataStructures/WLTsmall.cc.html
title: code/dataStructures/WLTsmall.cc
---

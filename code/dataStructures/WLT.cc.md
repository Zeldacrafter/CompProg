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
    \ << \"] \"\n#line 2 \"code/dataStructures/WLT.cc\"\n// alphabets like 10^9 possible\
    \ but for 200'000 values ~200MB\n// for smaller alphabets consider the non pointer\
    \ based variant\ntemplate<typename T = int>\nstruct WLT {\n  using vit = typename\
    \ vector<T>::iterator;\n  struct node : vi {\n    int l = -1, r = -1;\n  };\n\
    \  T H;\n  vector<node> M;\n  static inline T mid(T a, T b) { return (a + b +\
    \ 1) / 2; }\n  WLT(vector<T> v, T hi) : H{hi} { // [0, hi)\n    M.reserve(SZ(v)\
    \ * log2(H));\n    build(ALL(v), 0, H);\n  }\n  int build(vit b, vit e, T lo,\
    \ T hi) {\n    int idx = SZ(M);\n    M.eb();\n    if (lo + 1 == hi) return idx;\n\
    \    int m = mid(lo, hi);\n    M[idx].reserve(distance(b, e) + 1); M[idx].pb(0);\n\
    \    auto less = [=](T k) { return k < m; };\n    for (auto it = b; it != e; ++it)\
    \ M[idx].pb(M[idx].back() + less(*it));\n    auto p = stable_partition(b, e, less);\n\
    \    if (p != b) M[idx].l = build(b, p, lo, m); \n    if (p != e) M[idx].r = build(p,\
    \ e, m, hi);\n    return idx;\n  }\n  T kthsmallest(int l, int r, int k) {// k-th\
    \ smallest in [l, r)\n    T a = 0, b = H; int i = 0;\n    while (a + 1 != b) {\n\
    \      if (k < M[i][r] - M[i][l]) {\n        l = M[i][l]; r = M[i][r];\n     \
    \   i = M[i].l; b = mid(a, b);\n      } else {\n        k -= M[i][r] - M[i][l];\n\
    \        l -= M[i][l]; r -= M[i][r];\n        i = M[i].r; a = mid(a, b);\n   \
    \   }\n    }\n    return a;\n  }\n};\n"
  code: "#include \"../template.cc\"\n// alphabets like 10^9 possible but for 200'000\
    \ values ~200MB\n// for smaller alphabets consider the non pointer based variant\n\
    template<typename T = int>\nstruct WLT {\n  using vit = typename vector<T>::iterator;\n\
    \  struct node : vi {\n    int l = -1, r = -1;\n  };\n  T H;\n  vector<node> M;\n\
    \  static inline T mid(T a, T b) { return (a + b + 1) / 2; }\n  WLT(vector<T>\
    \ v, T hi) : H{hi} { // [0, hi)\n    M.reserve(SZ(v) * log2(H));\n    build(ALL(v),\
    \ 0, H);\n  }\n  int build(vit b, vit e, T lo, T hi) {\n    int idx = SZ(M);\n\
    \    M.eb();\n    if (lo + 1 == hi) return idx;\n    int m = mid(lo, hi);\n  \
    \  M[idx].reserve(distance(b, e) + 1); M[idx].pb(0);\n    auto less = [=](T k)\
    \ { return k < m; };\n    for (auto it = b; it != e; ++it) M[idx].pb(M[idx].back()\
    \ + less(*it));\n    auto p = stable_partition(b, e, less);\n    if (p != b) M[idx].l\
    \ = build(b, p, lo, m); \n    if (p != e) M[idx].r = build(p, e, m, hi);\n   \
    \ return idx;\n  }\n  T kthsmallest(int l, int r, int k) {// k-th smallest in\
    \ [l, r)\n    T a = 0, b = H; int i = 0;\n    while (a + 1 != b) {\n      if (k\
    \ < M[i][r] - M[i][l]) {\n        l = M[i][l]; r = M[i][r];\n        i = M[i].l;\
    \ b = mid(a, b);\n      } else {\n        k -= M[i][r] - M[i][l];\n        l -=\
    \ M[i][l]; r -= M[i][r];\n        i = M[i].r; a = mid(a, b);\n      }\n    }\n\
    \    return a;\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/WLT.cc
  requiredBy: []
  timestamp: '2020-12-19 23:25:36+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/dataStructures/WLT.cc
layout: document
redirect_from:
- /library/code/dataStructures/WLT.cc
- /library/code/dataStructures/WLT.cc.html
title: code/dataStructures/WLT.cc
---

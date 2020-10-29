---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
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
    \ << \"] \"\n#line 2 \"code/dataStructures/SPT2D.cc\"\n\ntypedef vector<vvi> vvvi;\n\
    typedef vector<vvvi> vvvvi;\nstruct SPT2D {\n  vvvvi spT;\n  int n, m, log2n,\
    \ log2m;\n\n  SPT2D(vvi& A) : n(SZ(A)), m(SZ(A[0])),\n        log2n(33 - __builtin_clz(n)),\n\
    \        log2m(33 - __builtin_clz(m)) {\n    spT.assign(n, vvvi(log2n, vvi(m,\
    \ vi(log2m))));\n\n    F0R (ir, n) {\n      F0R (ic, m)\n        spT[ir][0][ic][0]\
    \ = A[ir][ic];\n      for (int jc = 1; (1 << jc) <= m; ++jc)\n        for (int\
    \ ic = 0; ic + (1 << jc) <= m; ++ic)\n          spT[ir][0][ic][jc] =\n       \
    \       min(spT[ir][0][ic][jc - 1],\n                  spT[ir][0][ic + (1 << (jc\
    \ - 1))][jc - 1]);\n    }\n    for (int jr = 1; (1 << jr) <= n; ++jr)\n      for\
    \ (int ir = 0; ir + (1 << jr) <= n; ++ir)\n        for (int jc = 0; (1 << jc)\
    \ <= m; ++jc)\n          for (int ic = 0; ic + (1 << jc) <= m; ++ic)\n       \
    \     spT[ir][jr][ic][jc] =\n                min(spT[ir][jr - 1][ic][jc],\n  \
    \                  spT[ir + (1 << (jr - 1))][jr - 1][ic][jc]);\n  }\n\n  int query(int\
    \ r1, int r2, int c1, int c2) { //r2, c2 are exclusive\n    int rk = 31 - __builtin_clz(r2\
    \ - r1);\n    int ck = 31 - __builtin_clz(c2 - c1);\n\n    int cc = c2 - (1 <<\
    \ ck);\n    int rr = r2 - (1 << rk);\n    return min({spT[r1][rk][c1][ck], spT[r1][rk][cc][ck],\n\
    \                spT[rr][rk][c1][ck], spT[rr][rk][cc][ck]});\n  }\n};\n"
  code: "#include \"../template.hh\"\n\ntypedef vector<vvi> vvvi;\ntypedef vector<vvvi>\
    \ vvvvi;\nstruct SPT2D {\n  vvvvi spT;\n  int n, m, log2n, log2m;\n\n  SPT2D(vvi&\
    \ A) : n(SZ(A)), m(SZ(A[0])),\n        log2n(33 - __builtin_clz(n)),\n       \
    \ log2m(33 - __builtin_clz(m)) {\n    spT.assign(n, vvvi(log2n, vvi(m, vi(log2m))));\n\
    \n    F0R (ir, n) {\n      F0R (ic, m)\n        spT[ir][0][ic][0] = A[ir][ic];\n\
    \      for (int jc = 1; (1 << jc) <= m; ++jc)\n        for (int ic = 0; ic + (1\
    \ << jc) <= m; ++ic)\n          spT[ir][0][ic][jc] =\n              min(spT[ir][0][ic][jc\
    \ - 1],\n                  spT[ir][0][ic + (1 << (jc - 1))][jc - 1]);\n    }\n\
    \    for (int jr = 1; (1 << jr) <= n; ++jr)\n      for (int ir = 0; ir + (1 <<\
    \ jr) <= n; ++ir)\n        for (int jc = 0; (1 << jc) <= m; ++jc)\n          for\
    \ (int ic = 0; ic + (1 << jc) <= m; ++ic)\n            spT[ir][jr][ic][jc] =\n\
    \                min(spT[ir][jr - 1][ic][jc],\n                    spT[ir + (1\
    \ << (jr - 1))][jr - 1][ic][jc]);\n  }\n\n  int query(int r1, int r2, int c1,\
    \ int c2) { //r2, c2 are exclusive\n    int rk = 31 - __builtin_clz(r2 - r1);\n\
    \    int ck = 31 - __builtin_clz(c2 - c1);\n\n    int cc = c2 - (1 << ck);\n \
    \   int rr = r2 - (1 << rk);\n    return min({spT[r1][rk][c1][ck], spT[r1][rk][cc][ck],\n\
    \                spT[rr][rk][c1][ck], spT[rr][rk][cc][ck]});\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/dataStructures/SPT2D.cc
  requiredBy: []
  timestamp: '2020-10-29 09:01:05+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/dataStructures/SPT2D.cc
layout: document
redirect_from:
- /library/code/dataStructures/SPT2D.cc
- /library/code/dataStructures/SPT2D.cc.html
title: code/dataStructures/SPT2D.cc
---

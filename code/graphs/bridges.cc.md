---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/brides.brides.test.cpp
    title: tests/aoj/brides.brides.test.cpp
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
    \ << \"] \"\n#line 2 \"code/graphs/bridges.cc\"\nvvi adj;\nvi dfsNum, low;\nint\
    \ dfsCounter = 0;\nint bridgeDfs(int v, vii& b, int p = -1) {\n  dfsNum[v] = low[v]\
    \ = dfsCounter++;\n  for (int u : adj[v]) {\n    if (dfsNum[u] == -1) {\n    \
    \  ckmin(low[v], bridgeDfs(u, b, v));\n      if (low[u] > dfsNum[v]) b.eb(v, u);\n\
    \    } else if (u != p)\n      ckmin(low[v], dfsNum[u]);\n  }\n  return low[v];\n\
    }\nvii findBridges() {\n  vii bridges;\n  dfsNum.assign(SZ(adj), -1);\n  low.assign(SZ(adj),\
    \ -1);\n  F0R (v, SZ(adj))\n    if (dfsNum[v] == -1) bridgeDfs(v, bridges);\n\
    \  return bridges;\n}\n"
  code: "#include \"../template.hh\"\nvvi adj;\nvi dfsNum, low;\nint dfsCounter =\
    \ 0;\nint bridgeDfs(int v, vii& b, int p = -1) {\n  dfsNum[v] = low[v] = dfsCounter++;\n\
    \  for (int u : adj[v]) {\n    if (dfsNum[u] == -1) {\n      ckmin(low[v], bridgeDfs(u,\
    \ b, v));\n      if (low[u] > dfsNum[v]) b.eb(v, u);\n    } else if (u != p)\n\
    \      ckmin(low[v], dfsNum[u]);\n  }\n  return low[v];\n}\nvii findBridges()\
    \ {\n  vii bridges;\n  dfsNum.assign(SZ(adj), -1);\n  low.assign(SZ(adj), -1);\n\
    \  F0R (v, SZ(adj))\n    if (dfsNum[v] == -1) bridgeDfs(v, bridges);\n  return\
    \ bridges;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/bridges.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/brides.brides.test.cpp
documentation_of: code/graphs/bridges.cc
layout: document
redirect_from:
- /library/code/graphs/bridges.cc
- /library/code/graphs/bridges.cc.html
title: code/graphs/bridges.cc
---

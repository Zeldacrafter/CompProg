---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/aoj/articulation_points.articulation_points.test.cpp
    title: tests/aoj/articulation_points.articulation_points.test.cpp
  _pathExtension: cc
  _verificationStatusIcon: ':x:'
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
    \ << \"] \"\n#line 2 \"code/graphs/articulationPoints.cc\"\nvi dfsNum, low;\n\
    int dfsCounter = 0;\nvvi adj;\nint artiDfs(int v, vi& a, int p = -1) {\n  dfsNum[v]\
    \ = low[v] = dfsCounter++;\n  int children = 0;\n  bool aP = false;\n  for (int\
    \ u : adj[v]) {\n    if (dfsNum[u] == -1) {\n      ckmin(low[v], artiDfs(u, a,\
    \ v));\n      if (low[u] >= dfsNum[v] && p != -1 && !aP) {\n        a.pb(v);\n\
    \        aP = true;\n      }\n      children++;\n    } else if (u != p)\n    \
    \  ckmin(low[v], dfsNum[u]);\n  }\n  if (p == -1 && children > 1) a.pb(v);\n \
    \ return low[v];\n}\nvi findArtiPoints() {\n  dfsNum.assign(SZ(adj), -1);\n  low.assign(SZ(adj),\
    \ -1);\n  dfsCounter = 0;\n  vi res;\n  F0R (v, SZ(adj))\n    if (dfsNum[v] ==\
    \ -1) artiDfs(v, res);\n  return res;\n}\n"
  code: "#include \"../template.hh\"\nvi dfsNum, low;\nint dfsCounter = 0;\nvvi adj;\n\
    int artiDfs(int v, vi& a, int p = -1) {\n  dfsNum[v] = low[v] = dfsCounter++;\n\
    \  int children = 0;\n  bool aP = false;\n  for (int u : adj[v]) {\n    if (dfsNum[u]\
    \ == -1) {\n      ckmin(low[v], artiDfs(u, a, v));\n      if (low[u] >= dfsNum[v]\
    \ && p != -1 && !aP) {\n        a.pb(v);\n        aP = true;\n      }\n      children++;\n\
    \    } else if (u != p)\n      ckmin(low[v], dfsNum[u]);\n  }\n  if (p == -1 &&\
    \ children > 1) a.pb(v);\n  return low[v];\n}\nvi findArtiPoints() {\n  dfsNum.assign(SZ(adj),\
    \ -1);\n  low.assign(SZ(adj), -1);\n  dfsCounter = 0;\n  vi res;\n  F0R (v, SZ(adj))\n\
    \    if (dfsNum[v] == -1) artiDfs(v, res);\n  return res;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/articulationPoints.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/aoj/articulation_points.articulation_points.test.cpp
documentation_of: code/graphs/articulationPoints.cc
layout: document
redirect_from:
- /library/code/graphs/articulationPoints.cc
- /library/code/graphs/articulationPoints.cc.html
title: code/graphs/articulationPoints.cc
---

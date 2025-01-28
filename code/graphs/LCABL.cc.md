---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/binary_lifting.lca.test.cpp
    title: tests/yosupo/binary_lifting.lca.test.cpp
  _isVerificationFailed: false
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
    \ << \"] \"\n#line 2 \"code/graphs/LCABL.cc\"\nstruct LCA {\n  int n, logN, root;\n\
    \  vvi up;\n  vi h;\n  LCA(vvi& adj, int r = 0)\n      : n{SZ(adj)}, logN{31 -\
    \ __builtin_clz(n)},\n        root{r}, up(n, vi(logN + 1, root)),\n        h(n,\
    \ -1) { \n    build(adj);\n  }\n  void build(vvi& adj) {\n    queue<int> q;\n\
    \    q.push(root);\n    h[root] = 0;\n    while (SZ(q)) {\n      int v = q.front();\n\
    \      q.pop();\n      for (int u : adj[v])\n        if (h[u] == -1) {\n     \
    \     h[u] = h[v] + 1;\n          q.push(u);\n          up[u][0] = v;\n      \
    \  }\n    }\n    FOR (exp, 1, logN + 1)\n      F0R (v, n)\n        if (up[v][exp\
    \ - 1] != -1)\n          up[v][exp] = up[up[v][exp - 1]][exp - 1];\n  }\n  int\
    \ jumpUp(int v, int amt) {\n    for (int i = 0; v != -1 && (1 << i) <= amt; ++i)\n\
    \      if (amt & (1 << i)) \n        v = up[v][i];\n    return v;\n  }\n  int\
    \ query(int v, int u) {\n    v = jumpUp(v, max(0, h[v] - h[u]));\n    u = jumpUp(u,\
    \ max(0, h[u] - h[v]));\n    if (u == v) return u;\n    for (int l = logN; ~l;\
    \ --l) {\n      int jmpU = up[u][l], jmpV = up[v][l];\n      if (jmpU == -1 ||\
    \ jmpV == -1) continue;\n      if (jmpU != jmpV) {\n        u = jmpU;\n      \
    \  v = jmpV;\n      }\n    }\n    return up[v][0];\n  }\n};\n"
  code: "#include \"../template.hh\"\nstruct LCA {\n  int n, logN, root;\n  vvi up;\n\
    \  vi h;\n  LCA(vvi& adj, int r = 0)\n      : n{SZ(adj)}, logN{31 - __builtin_clz(n)},\n\
    \        root{r}, up(n, vi(logN + 1, root)),\n        h(n, -1) { \n    build(adj);\n\
    \  }\n  void build(vvi& adj) {\n    queue<int> q;\n    q.push(root);\n    h[root]\
    \ = 0;\n    while (SZ(q)) {\n      int v = q.front();\n      q.pop();\n      for\
    \ (int u : adj[v])\n        if (h[u] == -1) {\n          h[u] = h[v] + 1;\n  \
    \        q.push(u);\n          up[u][0] = v;\n        }\n    }\n    FOR (exp,\
    \ 1, logN + 1)\n      F0R (v, n)\n        if (up[v][exp - 1] != -1)\n        \
    \  up[v][exp] = up[up[v][exp - 1]][exp - 1];\n  }\n  int jumpUp(int v, int amt)\
    \ {\n    for (int i = 0; v != -1 && (1 << i) <= amt; ++i)\n      if (amt & (1\
    \ << i)) \n        v = up[v][i];\n    return v;\n  }\n  int query(int v, int u)\
    \ {\n    v = jumpUp(v, max(0, h[v] - h[u]));\n    u = jumpUp(u, max(0, h[u] -\
    \ h[v]));\n    if (u == v) return u;\n    for (int l = logN; ~l; --l) {\n    \
    \  int jmpU = up[u][l], jmpV = up[v][l];\n      if (jmpU == -1 || jmpV == -1)\
    \ continue;\n      if (jmpU != jmpV) {\n        u = jmpU;\n        v = jmpV;\n\
    \      }\n    }\n    return up[v][0];\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/LCABL.cc
  requiredBy: []
  timestamp: '2020-10-28 23:44:21+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/binary_lifting.lca.test.cpp
documentation_of: code/graphs/LCABL.cc
layout: document
redirect_from:
- /library/code/graphs/LCABL.cc
- /library/code/graphs/LCABL.cc.html
title: code/graphs/LCABL.cc
---

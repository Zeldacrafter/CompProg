---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/LCABL.cc
    title: code/graphs/LCABL.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"tests/yosupo/binary_lifting.lca.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"code/template.cc\"\n//\
    \ this line is here for a reason\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef\
    \ vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define\
    \ fi first\n#define se second\n#define eb emplace_back\n#define pb push_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define endl '\\n'\n#define ALL(x)\
    \ (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x)\
    \ (int)(x).size()\n#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))\n\
    #define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename T>\nbool ckmin(T& a, const\
    \ T& b) { return a > b ? a = b, true : false; }\ntemplate <typename T>\nbool ckmax(T&\
    \ a, const T& b) { return a < b ? a = b, true : false; }\n#ifndef DEBUG\n#define\
    \ DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__\
    \ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/graphs/LCABL.cc\"\nstruct\
    \ LCA {\n  int n, logN, root;\n  vvi up;\n  vi h;\n  LCA(vvi& adj, int r = 0)\n\
    \      : n{SZ(adj)}, logN{31 - __builtin_clz(n)},\n        root{r}, up(n, vi(logN\
    \ + 1, root)),\n        h(n, -1) { \n    build(adj);\n  }\n  void build(vvi& adj)\
    \ {\n    queue<int> q;\n    q.push(root);\n    h[root] = 0;\n    while (SZ(q))\
    \ {\n      int v = q.front();\n      q.pop();\n      for (int u : adj[v])\n  \
    \      if (h[u] == -1) {\n          h[u] = h[v] + 1;\n          q.push(u);\n \
    \         up[u][0] = v;\n        }\n    }\n    FOR (exp, 1, logN + 1)\n      F0R\
    \ (v, n)\n        if (up[v][exp - 1] != -1)\n          up[v][exp] = up[up[v][exp\
    \ - 1]][exp - 1];\n  }\n  int jumpUp(int v, int amt) {\n    for (int i = 0; v\
    \ != -1 && (1 << i) <= amt; ++i)\n      if (amt & (1 << i)) \n        v = up[v][i];\n\
    \    return v;\n  }\n  int query(int v, int u) {\n    v = jumpUp(v, max(0, h[v]\
    \ - h[u]));\n    u = jumpUp(u, max(0, h[u] - h[v]));\n    if (u == v) return u;\n\
    \    for (int l = logN; ~l; --l) {\n      int jmpU = up[u][l], jmpV = up[v][l];\n\
    \      if (jmpU == -1 || jmpV == -1) continue;\n      if (jmpU != jmpV) {\n  \
    \      u = jmpU;\n        v = jmpV;\n      }\n    }\n    return up[v][0];\n  }\n\
    };\n#line 4 \"tests/yosupo/binary_lifting.lca.test.cpp\"\n\nint main() {\n   \
    \ cin.tie(0);\n    ios_base::sync_with_stdio(0);\n\n    int n, q;\n    cin >>\
    \ n >> q;\n\n    vvi adj(n);\n    F0R(i, n - 1) {\n        int u;\n        cin\
    \ >> u;\n        adj[i + 1].pb(u);\n        adj[u].pb(i + 1);\n    }\n    \n \
    \   LCA lca(adj);\n    while(q--) {\n        int u, v;\n        cin >> u >> v;\n\
    \        cout << lca.query(u, v) << endl;\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../code/graphs/LCABL.cc\"\
    \n\nint main() {\n    cin.tie(0);\n    ios_base::sync_with_stdio(0);\n\n    int\
    \ n, q;\n    cin >> n >> q;\n\n    vvi adj(n);\n    F0R(i, n - 1) {\n        int\
    \ u;\n        cin >> u;\n        adj[i + 1].pb(u);\n        adj[u].pb(i + 1);\n\
    \    }\n    \n    LCA lca(adj);\n    while(q--) {\n        int u, v;\n       \
    \ cin >> u >> v;\n        cout << lca.query(u, v) << endl;\n    }\n}\n\n"
  dependsOn:
  - code/graphs/LCABL.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/yosupo/binary_lifting.lca.test.cpp
  requiredBy: []
  timestamp: '2020-10-28 23:44:21+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/binary_lifting.lca.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/binary_lifting.lca.test.cpp
- /verify/tests/yosupo/binary_lifting.lca.test.cpp.html
title: tests/yosupo/binary_lifting.lca.test.cpp
---

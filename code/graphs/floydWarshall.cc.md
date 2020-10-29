---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp
    title: tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp
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
    \ << \"] \"\n#line 2 \"code/graphs/floydWarshall.cc\"\nconst ll INF = 1e18;\n\
    vector<vector<ll>> adj;  // adjacency matrix\nbool negCycle = false;\nvoid floydWarshall()\
    \ {\n  F0R (k, SZ(adj)) F0R (i, SZ(adj)) F0R (j, SZ(adj))\n    if(adj[i][k] !=\
    \ INF && adj[k][j] != INF)\n      ckmin(adj[i][j], adj[i][k] + adj[k][j]);\n \
    \ F0R (k, SZ(adj)) if(adj[k][k] < 0) negCycle = true;\n}\n"
  code: "#include \"../template.hh\"\nconst ll INF = 1e18;\nvector<vector<ll>> adj;\
    \  // adjacency matrix\nbool negCycle = false;\nvoid floydWarshall() {\n  F0R\
    \ (k, SZ(adj)) F0R (i, SZ(adj)) F0R (j, SZ(adj))\n    if(adj[i][k] != INF && adj[k][j]\
    \ != INF)\n      ckmin(adj[i][j], adj[i][k] + adj[k][j]);\n  F0R (k, SZ(adj))\
    \ if(adj[k][k] < 0) negCycle = true;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/floydWarshall.cc
  requiredBy: []
  timestamp: '2020-10-29 16:39:06+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/aoj/floyd_warshall.all_pairs_shortest_path.test.cpp
documentation_of: code/graphs/floydWarshall.cc
layout: document
redirect_from:
- /library/code/graphs/floydWarshall.cc
- /library/code/graphs/floydWarshall.cc.html
title: code/graphs/floydWarshall.cc
---

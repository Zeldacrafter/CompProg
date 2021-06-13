---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp
    title: tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp
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
    \ << \"] \"\n#line 2 \"code/graphs/bellmanFord.cc\"\nconst int inf = 1e9;\n//\
    \ vertex a, vertex b, distance\nvector<tuple<int, int, int>> edges;\nint V;\n\
    // Returns empty vector on negative cycle\nvi bellmanFord(int start) {\n  vi dist(V,\
    \ inf);\n  dist[start] = 0;\n  bool negCycle = false;\n  F0R (i, V) {\n    negCycle\
    \ = false;\n    for (auto [a, b, d] : edges)\n      if (dist[a] < inf && ckmin(dist[b],\
    \ dist[a] + d))\n          negCycle = true;\n  }\n  return negCycle ? vi() : dist;\n\
    }\n"
  code: "#include \"../template.hh\"\nconst int inf = 1e9;\n// vertex a, vertex b,\
    \ distance\nvector<tuple<int, int, int>> edges;\nint V;\n// Returns empty vector\
    \ on negative cycle\nvi bellmanFord(int start) {\n  vi dist(V, inf);\n  dist[start]\
    \ = 0;\n  bool negCycle = false;\n  F0R (i, V) {\n    negCycle = false;\n    for\
    \ (auto [a, b, d] : edges)\n      if (dist[a] < inf && ckmin(dist[b], dist[a]\
    \ + d))\n          negCycle = true;\n  }\n  return negCycle ? vi() : dist;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/bellmanFord.cc
  requiredBy: []
  timestamp: '2020-10-29 15:18:02+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp
documentation_of: code/graphs/bellmanFord.cc
layout: document
redirect_from:
- /library/code/graphs/bellmanFord.cc
- /library/code/graphs/bellmanFord.cc.html
title: code/graphs/bellmanFord.cc
---

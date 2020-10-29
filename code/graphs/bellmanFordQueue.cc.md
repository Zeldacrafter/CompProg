---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp
    title: tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp
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
    \ << \"] \"\n#line 2 \"code/graphs/bellmanFordQueue.cc\"\nconst int inf = 1e9;\n\
    vvii adj;\n// returns empty vector if there's a neg cycle\nvi bellmanFordQueue(int\
    \ start) {\n  vi dist(SZ(adj), inf);\n  queue<int> q;\n  vector<bool> inQ(SZ(adj),\
    \ false);\n  vi cnt(SZ(adj), 0); // cnt number of relaxations for neg cycles\n\
    \  q.push(start);\n  dist[start] = 0; inQ[start] = true;\n  while (!q.empty())\
    \ {\n    int v = q.front(); q.pop();\n    inQ[v] = false;\n    for (auto [u, d]\
    \ : adj[v])\n      if (ckmin(dist[u], dist[v] + d)) {\n        if (++cnt[u] >\
    \ SZ(adj)) return vi();\n        if (!inQ[u]) q.push(u), inQ[u] = true;\n    \
    \  }\n  }\n  return dist;\n}\n"
  code: "#include \"../template.hh\"\nconst int inf = 1e9;\nvvii adj;\n// returns\
    \ empty vector if there's a neg cycle\nvi bellmanFordQueue(int start) {\n  vi\
    \ dist(SZ(adj), inf);\n  queue<int> q;\n  vector<bool> inQ(SZ(adj), false);\n\
    \  vi cnt(SZ(adj), 0); // cnt number of relaxations for neg cycles\n  q.push(start);\n\
    \  dist[start] = 0; inQ[start] = true;\n  while (!q.empty()) {\n    int v = q.front();\
    \ q.pop();\n    inQ[v] = false;\n    for (auto [u, d] : adj[v])\n      if (ckmin(dist[u],\
    \ dist[v] + d)) {\n        if (++cnt[u] > SZ(adj)) return vi();\n        if (!inQ[u])\
    \ q.push(u), inQ[u] = true;\n      }\n  }\n  return dist;\n}\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/bellmanFordQueue.cc
  requiredBy: []
  timestamp: '2020-10-29 11:30:05+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp
documentation_of: code/graphs/bellmanFordQueue.cc
layout: document
redirect_from:
- /library/code/graphs/bellmanFordQueue.cc
- /library/code/graphs/bellmanFordQueue.cc.html
title: code/graphs/bellmanFordQueue.cc
---

---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/flowedge.cc
    title: code/graphs/flowedge.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/aoj/dinic.maximum_flow.test.cpp
    title: tests/aoj/dinic.maximum_flow.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/dinic.bipartitematching.test.cpp
    title: tests/yosupo/dinic.bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"code/graphs/dinic.cc\"\n\n#line 1 \"code/template.cc\"\n\
    // this line is here for a reason\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/graphs/flowedge.cc\"\ntemplate\
    \ <typename F>\nstruct edge {\n  edge(int from, int to, F capacity, F flow = 0)\n\
    \      : mfrom(from), mto(to), mcapacity(capacity), mflow(flow) {}\n  int mfrom,\
    \ mto;\n  F mcapacity, mflow;\n  int other(int v) { return v == mfrom ? mto :\
    \ mfrom; }\n  F capacity(int v) { return v == mfrom ? mcapacity : 0; }\n  F flow(int\
    \ v) { return v == mfrom ? mflow : -mflow; }\n  void adjust(int v, F amount) {\n\
    \    mflow += v == mfrom ? amount : -amount;\n  }\n};\ntemplate <typename F>\n\
    ostream& operator<<(ostream& o, const edge<F>& e) {\n  return o << e.mfrom <<\
    \ \"-- \" << e.mflow << '/'\n           << e.mcapacity << \" -->\" << e.mto;\n\
    }\n#line 3 \"code/graphs/dinic.cc\"\ntemplate <typename F = ll>\nstruct DC {\n\
    \  vector<edge<F>> edges;\n  vvi adj;\n  vi dist, ptr;\n  int S, T, N;\n  DC(int\
    \ n, int m = 0, int s = -1, int t = -1) {\n    reset(n, m, s, t);\n  }\n  void\
    \ buildMatchingEdges(int m) {\n    F0R (i, N) add(S, i, 1);\n    F0R (i, m) add(N\
    \ + i, T, 1);\n  }\n  int add(int from, int to, F c = numeric_limits<F>::max(),\
    \ F f = 0) {\n    edges.eb(from, to, c, f);\n    adj[from].pb(SZ(edges) - 1);\n\
    \    adj[to].pb(SZ(edges) - 1);\n    return SZ(edges) - 1;\n  }\n  int match(int\
    \ from, int to) { return add(from, N + to, 1);}\n  vii matching() {\n    vii res;\
    \ res.reserve(maxflow());\n    for (const auto& e : edges)\n      if (e.mflow\
    \ == 1 and e.mfrom != S and e.mto != T)\n        res.eb(e.mfrom, e.mto - N);\n\
    \    return res;\n  }\n  void clear() { edges.clear(); adj.clear(); }\n  void\
    \ reset(int n, int m = 0, int s = -1, int t = -1) {\n    clear();\n    adj.resize((N\
    \ = n) + m + (s == -1) + (t == -1));\n    S = s == -1 ? n + m : s;\n    T = t\
    \ == -1 ? n + m + (s == -1) : t;\n    if (m != 0) buildMatchingEdges(m);\n  }\n\
    \  bool bfs(int s, int t) {\n    dist.assign(SZ(adj), SZ(adj));\n    queue<int>\
    \ q;\n    q.push(s);\n    dist[s] = 0;\n    while (SZ(q)) {\n      int v = q.front();\
    \ q.pop();\n      for (int i : adj[v]) {\n        auto& e = edges[i];\n      \
    \  if (dist[e.other(v)] == SZ(adj) && e.flow(v) < e.capacity(v)) {\n         \
    \ dist[e.other(v)] = dist[v] + 1;\n          q.push(e.other(v));\n        }\n\
    \      }\n    }\n    return dist[t] < SZ(adj);\n  }\n  F dfs(int v, int t, F available)\
    \ {\n    if (v == t || !available) return available;\n    F pushed = 0;\n    for\
    \ (; ptr[v] < SZ(adj[v]); ++ptr[v]) {\n      auto& e = edges[adj[v][ptr[v]]];\n\
    \      if (dist[v] + 1 != dist[e.other(v)])\n        continue;\n      F wasPushed\
    \ = dfs(e.other(v), t,\n                        min(available - pushed, e.capacity(v)\
    \ - e.flow(v)));\n      pushed += wasPushed;\n      e.adjust(v, wasPushed);\n\
    \      if (pushed == available) return pushed;\n    }\n    return pushed;\n  }\n\
    \  F maxflow() {\n    return maxflow(S, T);\n  }\n  F maxflow(int s, int t) {\n\
    \    F f = 0;\n    for (;;) {\n      if (!bfs(s, t)) return f;\n      ptr.assign(SZ(adj),\
    \ 0);\n      f += dfs(s, t, numeric_limits<F>::max());\n    }\n  }\n};\nusing\
    \ BM = DC<int>;\n"
  code: "\n#include \"flowedge.cc\"\ntemplate <typename F = ll>\nstruct DC {\n  vector<edge<F>>\
    \ edges;\n  vvi adj;\n  vi dist, ptr;\n  int S, T, N;\n  DC(int n, int m = 0,\
    \ int s = -1, int t = -1) {\n    reset(n, m, s, t);\n  }\n  void buildMatchingEdges(int\
    \ m) {\n    F0R (i, N) add(S, i, 1);\n    F0R (i, m) add(N + i, T, 1);\n  }\n\
    \  int add(int from, int to, F c = numeric_limits<F>::max(), F f = 0) {\n    edges.eb(from,\
    \ to, c, f);\n    adj[from].pb(SZ(edges) - 1);\n    adj[to].pb(SZ(edges) - 1);\n\
    \    return SZ(edges) - 1;\n  }\n  int match(int from, int to) { return add(from,\
    \ N + to, 1);}\n  vii matching() {\n    vii res; res.reserve(maxflow());\n   \
    \ for (const auto& e : edges)\n      if (e.mflow == 1 and e.mfrom != S and e.mto\
    \ != T)\n        res.eb(e.mfrom, e.mto - N);\n    return res;\n  }\n  void clear()\
    \ { edges.clear(); adj.clear(); }\n  void reset(int n, int m = 0, int s = -1,\
    \ int t = -1) {\n    clear();\n    adj.resize((N = n) + m + (s == -1) + (t ==\
    \ -1));\n    S = s == -1 ? n + m : s;\n    T = t == -1 ? n + m + (s == -1) : t;\n\
    \    if (m != 0) buildMatchingEdges(m);\n  }\n  bool bfs(int s, int t) {\n   \
    \ dist.assign(SZ(adj), SZ(adj));\n    queue<int> q;\n    q.push(s);\n    dist[s]\
    \ = 0;\n    while (SZ(q)) {\n      int v = q.front(); q.pop();\n      for (int\
    \ i : adj[v]) {\n        auto& e = edges[i];\n        if (dist[e.other(v)] ==\
    \ SZ(adj) && e.flow(v) < e.capacity(v)) {\n          dist[e.other(v)] = dist[v]\
    \ + 1;\n          q.push(e.other(v));\n        }\n      }\n    }\n    return dist[t]\
    \ < SZ(adj);\n  }\n  F dfs(int v, int t, F available) {\n    if (v == t || !available)\
    \ return available;\n    F pushed = 0;\n    for (; ptr[v] < SZ(adj[v]); ++ptr[v])\
    \ {\n      auto& e = edges[adj[v][ptr[v]]];\n      if (dist[v] + 1 != dist[e.other(v)])\n\
    \        continue;\n      F wasPushed = dfs(e.other(v), t,\n                 \
    \       min(available - pushed, e.capacity(v) - e.flow(v)));\n      pushed +=\
    \ wasPushed;\n      e.adjust(v, wasPushed);\n      if (pushed == available) return\
    \ pushed;\n    }\n    return pushed;\n  }\n  F maxflow() {\n    return maxflow(S,\
    \ T);\n  }\n  F maxflow(int s, int t) {\n    F f = 0;\n    for (;;) {\n      if\
    \ (!bfs(s, t)) return f;\n      ptr.assign(SZ(adj), 0);\n      f += dfs(s, t,\
    \ numeric_limits<F>::max());\n    }\n  }\n};\nusing BM = DC<int>;\n"
  dependsOn:
  - code/graphs/flowedge.cc
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/dinic.cc
  requiredBy: []
  timestamp: '2021-06-13 18:08:42+02:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/dinic.maximum_flow.test.cpp
  - tests/yosupo/dinic.bipartitematching.test.cpp
documentation_of: code/graphs/dinic.cc
layout: document
redirect_from:
- /library/code/graphs/dinic.cc
- /library/code/graphs/dinic.cc.html
title: code/graphs/dinic.cc
---

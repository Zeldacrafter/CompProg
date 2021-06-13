---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/bellmanFordQueue.cc
    title: code/graphs/bellmanFordQueue.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#line 1 \"code/template.cc\"\n// this line is here for a reason\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef pair<int,\
    \ int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii> vii;\ntypedef vector<vi>\
    \ vvi;\ntypedef vector<vii> vvii;\n#define fi first\n#define se second\n#define\
    \ eb emplace_back\n#define pb push_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(),\
    \ (x).rend()\n#define SZ(x) (int)(x).size()\n#define FOR(a, b, c) for (auto a\
    \ = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a, 0, (b))\ntemplate <typename\
    \ T>\nbool ckmin(T& a, const T& b) { return a > b ? a = b, true : false; }\ntemplate\
    \ <typename T>\nbool ckmax(T& a, const T& b) { return a < b ? a = b, true : false;\
    \ }\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n#define dout if (DEBUG) cerr\n#define\
    \ dvar(...) \" [\" << #__VA_ARGS__ \": \" << (__VA_ARGS__) << \"] \"\n#line 2\
    \ \"code/graphs/bellmanFordQueue.cc\"\nconst int inf = 1e9;\nvvii adj;\n// returns\
    \ empty vector if there's a neg cycle\nvi bellmanFordQueue(int start) {\n  vi\
    \ dist(SZ(adj), inf);\n  queue<int> q;\n  vector<bool> inQ(SZ(adj), false);\n\
    \  vi cnt(SZ(adj), 0); // cnt number of relaxations for neg cycles\n  q.push(start);\n\
    \  dist[start] = 0; inQ[start] = true;\n  while (!q.empty()) {\n    int v = q.front();\
    \ q.pop();\n    inQ[v] = false;\n    for (auto [u, d] : adj[v])\n      if (ckmin(dist[u],\
    \ dist[v] + d)) {\n        if (++cnt[u] > SZ(adj)) return vi();\n        if (!inQ[u])\
    \ q.push(u), inQ[u] = true;\n      }\n  }\n  return dist;\n}\n#line 4 \"tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int V, E,\
    \ r;\n  cin >> V >> E >> r;\n\n  adj.resize(V);\n\n  F0R(i, E) {\n      int u,\
    \ v, d;\n      cin >> u >> v >> d;\n      adj[u].eb(v, d);\n  }\n\n  vi res =\
    \ bellmanFordQueue(r);\n  if(!SZ(res)) {\n      cout << \"NEGATIVE CYCLE\\n\"\
    ;\n  } else {\n      for(int d : res) {\n          if(d == inf)\n            \
    \  cout << \"INF\\n\";\n          else\n              cout << d << endl;\n   \
    \   }\n  }\n}\n\n\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include \"../../code/graphs/bellmanFordQueue.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int V, E, r;\n  cin >> V >> E >> r;\n\n\
    \  adj.resize(V);\n\n  F0R(i, E) {\n      int u, v, d;\n      cin >> u >> v >>\
    \ d;\n      adj[u].eb(v, d);\n  }\n\n  vi res = bellmanFordQueue(r);\n  if(!SZ(res))\
    \ {\n      cout << \"NEGATIVE CYCLE\\n\";\n  } else {\n      for(int d : res)\
    \ {\n          if(d == inf)\n              cout << \"INF\\n\";\n          else\n\
    \              cout << d << endl;\n      }\n  }\n}\n\n\n\n\n\n"
  dependsOn:
  - code/graphs/bellmanFordQueue.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 14:58:23+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp
- /verify/tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp.html
title: tests/aoj/bellman_ford_queue.single_source_shortest_path_negative_edges.test.cpp
---

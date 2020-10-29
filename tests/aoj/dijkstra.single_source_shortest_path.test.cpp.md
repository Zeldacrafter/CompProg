---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/dijkstra.cc
    title: code/graphs/dijkstra.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"tests/aoj/dijkstra.single_source_shortest_path.test.cpp\"\
    \n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
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
    \ \"code/graphs/dijkstra.cc\"\nconst int inf = 1e9;\nvvii adj;\nvi dijkstra(int\
    \ start) {\n  vi dist(SZ(adj), inf);\n  set<ii> q;\n  q.emplace(0, start);\n \
    \ dist[start] = 0;\n  while (!q.empty()) {\n    auto [d, v] = *q.begin(); q.erase(q.begin());\n\
    \    if (dist[v] < d) continue;\n    for (auto [u, du] : adj[v])\n      if (ckmin(dist[u],\
    \ d + du)) q.emplace(d + du, u);\n  }\n  return dist;\n}\n#line 4 \"tests/aoj/dijkstra.single_source_shortest_path.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int V, E,\
    \ r;\n  cin >> V >> E >> r;\n\n  adj.resize(V);\n\n  F0R(i, E) {\n      int u,\
    \ v, d;\n      cin >> u >> v >> d;\n      adj[u].eb(v, d);\n  }\n\n  vi res =\
    \ dijkstra(r);\n  for(int d : res) {\n      if(d == inf)\n          cout << \"\
    INF\\n\";\n      else\n          cout << d << endl;\n  }\n}\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../code/graphs/dijkstra.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int V, E, r;\n  cin >> V >> E >> r;\n\n\
    \  adj.resize(V);\n\n  F0R(i, E) {\n      int u, v, d;\n      cin >> u >> v >>\
    \ d;\n      adj[u].eb(v, d);\n  }\n\n  vi res = dijkstra(r);\n  for(int d : res)\
    \ {\n      if(d == inf)\n          cout << \"INF\\n\";\n      else\n         \
    \ cout << d << endl;\n  }\n}\n\n\n\n"
  dependsOn:
  - code/graphs/dijkstra.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/dijkstra.single_source_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 11:06:03+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/dijkstra.single_source_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/dijkstra.single_source_shortest_path.test.cpp
- /verify/tests/aoj/dijkstra.single_source_shortest_path.test.cpp.html
title: tests/aoj/dijkstra.single_source_shortest_path.test.cpp
---

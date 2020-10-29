---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: code/graphs/bellmanFord.cc
    title: code/graphs/bellmanFord.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp\"\
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
    \ \"code/graphs/bellmanFord.cc\"\nconst int inf = 1e9;\n// vertex a, vertex b,\
    \ distance\nvector<tuple<int, int, int>> edges;\nint V;\n// Returns empty vector\
    \ on negative cycle\nvi bellmanFord(int start) {\n  vi dist(V, inf);\n  dist[start]\
    \ = 0;\n  bool negCycle = false;\n  F0R (i, V) {\n    negCycle = false;\n    for\
    \ (auto [a, b, d] : edges)\n      if (ckmin(dist[b], dist[a] + d))\n         \
    \ negCycle = true;\n  }\n  return negCycle ? vi() : dist;\n}\n#line 4 \"tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp\"\
    \n\nint main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int E, r;\n\
    \  cin >> V >> E >> r;\n\n  edges.resize(E);\n\n  F0R(i, E) {\n      int u, v,\
    \ d;\n      cin >> u >> v >> d;\n      edges.eb(u, v, d);\n  }\n\n  vi res = bellmanFord(r);\n\
    \  if(!SZ(res)) {\n      cout << \"NEGATIVE CYCLE\\n\";\n  } else {\n      for(int\
    \ d : res) {\n          if(d == inf)\n              cout << \"INF\\n\";\n    \
    \      else\n              cout << d << endl;\n      }\n  }\n}\n\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../code/graphs/bellmanFord.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int E, r;\n  cin >> V >> E >> r;\n\n  edges.resize(E);\n\
    \n  F0R(i, E) {\n      int u, v, d;\n      cin >> u >> v >> d;\n      edges.eb(u,\
    \ v, d);\n  }\n\n  vi res = bellmanFord(r);\n  if(!SZ(res)) {\n      cout << \"\
    NEGATIVE CYCLE\\n\";\n  } else {\n      for(int d : res) {\n          if(d ==\
    \ inf)\n              cout << \"INF\\n\";\n          else\n              cout\
    \ << d << endl;\n      }\n  }\n}\n\n\n\n\n"
  dependsOn:
  - code/graphs/bellmanFord.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 11:30:05+01:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp
- /verify/tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp.html
title: tests/aoj/bellman_ford.single_source_shortest_path_negative_edges.test.cpp
---

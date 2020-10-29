---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/dinic.cc
    title: code/graphs/dinic.cc
  - icon: ':heavy_check_mark:'
    path: code/graphs/flowedge.cc
    title: code/graphs/flowedge.cc
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"tests/aoj/dinic.maximum_flow.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\n\n#line\
    \ 1 \"code/graphs/dinic.cc\"\n\n#line 1 \"code/template.cc\"\n// this line is\
    \ here for a reason\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long\
    \ long ll;\ntypedef pair<int, int> ii;\ntypedef vector<int> vi;\ntypedef vector<ii>\
    \ vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii> vvii;\n#define fi first\n\
    #define se second\n#define eb emplace_back\n#define pb push_back\n#define mp make_pair\n\
    #define mt make_tuple\n#define endl '\\n'\n#define ALL(x) (x).begin(), (x).end()\n\
    #define RALL(x) (x).rbegin(), (x).rend()\n#define SZ(x) (int)(x).size()\n#define\
    \ FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))\n#define F0R(a, b) FOR (a,\
    \ 0, (b))\ntemplate <typename T>\nbool ckmin(T& a, const T& b) { return a > b\
    \ ? a = b, true : false; }\ntemplate <typename T>\nbool ckmax(T& a, const T& b)\
    \ { return a < b ? a = b, true : false; }\n#ifndef DEBUG\n#define DEBUG 0\n#endif\n\
    #define dout if (DEBUG) cerr\n#define dvar(...) \" [\" << #__VA_ARGS__ \": \"\
    \ << (__VA_ARGS__) << \"] \"\n#line 2 \"code/graphs/flowedge.cc\"\nstruct edge\
    \ {\n  edge(int from, int to, ll capacity, ll flow = 0)\n      : mfrom(from),\
    \ mto(to), mcapacity(capacity), mflow(flow) {}\n  int mfrom, mto;\n  ll mcapacity,\
    \ mflow;\n  int other(int v) { return v == mfrom ? mto : mfrom; }\n  ll capacity(int\
    \ v) { return v == mfrom ? mcapacity : 0; }\n  ll flow(int v) { return v == mfrom\
    \ ? mflow : -mflow; }\n  void adjust(int v, ll amount) {\n    mflow += v == mfrom\
    \ ? amount : -amount;\n  }\n};\nvector<edge> edges;\nvvi adj;\nvoid addEdge(int\
    \ from, int to, ll c, ll f = 0) {\n  edges.eb(from, to, c, f);\n  adj[from].pb(SZ(edges)\
    \ - 1);\n  adj[to].pb(SZ(edges) - 1);\n}\nostream& operator<<(ostream& o, const\
    \ edge& e) {\n  return o << e.mfrom << \"-- \" << e.mflow << '/'\n           <<\
    \ e.mcapacity << \" -->\" << e.mto;\n}\n#line 3 \"code/graphs/dinic.cc\"\nvi dist,\
    \ ptr;\nconst ll inf = 1e16;\nbool dinic_bfs(int s, int t) {\n  dist.assign(SZ(adj),\
    \ SZ(adj));\n  queue<int> q;\n  q.push(s);\n  dist[s] = 0;\n  while (SZ(q)) {\n\
    \    int v = q.front(); q.pop();\n    for (int i : adj[v]) {\n      edge& e =\
    \ edges[i];\n      if (dist[e.other(v)] == SZ(adj) && e.flow(v) < e.capacity(v))\
    \ {\n        dist[e.other(v)] = dist[v] + 1;\n        q.push(e.other(v));\n  \
    \    }\n    }\n  }\n  return dist[t] < SZ(adj);\n}\nll dinic_dfs(int v, int t,\
    \ ll available) {\n  if (v == t || !available) return available;\n  ll pushed\
    \ = 0;\n  for (; ptr[v] < SZ(adj[v]); ++ptr[v]) {\n    edge& e = edges[adj[v][ptr[v]]];\n\
    \    if (dist[v] + 1 != dist[e.other(v)])\n      continue;\n    ll wasPushed =\n\
    \        dinic_dfs(e.other(v), t,\n                  min(available - pushed, e.capacity(v)\
    \ - e.flow(v)));\n    pushed += wasPushed;\n    e.adjust(v, wasPushed);\n    if\
    \ (pushed == available) return pushed;\n  }\n  return pushed;\n}\nll maxflow(int\
    \ s, int t) {\n  ll f = 0;\n  while (1) {\n    if (!dinic_bfs(s, t)) return f;\n\
    \    ptr.assign(SZ(adj), 0);\n    f += dinic_dfs(s, t, inf);\n  }\n}\n#line 4\
    \ \"tests/aoj/dinic.maximum_flow.test.cpp\"\n\nint main() {\n  cin.tie(0);\n \
    \ ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin >> V >> E;\n\n  adj.resize(V);\n\
    \n  F0R(i, E) {\n      int u, v, c;\n      cin >> u >> v >> c;\n      addEdge(u,\
    \ v, c);\n  }\n\n  cout << maxflow(0, V - 1) << endl;\n}\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"../../code/graphs/dinic.cc\"\n\nint main() {\n  cin.tie(0);\n \
    \ ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin >> V >> E;\n\n  adj.resize(V);\n\
    \n  F0R(i, E) {\n      int u, v, c;\n      cin >> u >> v >> c;\n      addEdge(u,\
    \ v, c);\n  }\n\n  cout << maxflow(0, V - 1) << endl;\n}\n\n\n"
  dependsOn:
  - code/graphs/dinic.cc
  - code/graphs/flowedge.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/dinic.maximum_flow.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 09:47:03+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/dinic.maximum_flow.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/dinic.maximum_flow.test.cpp
- /verify/tests/aoj/dinic.maximum_flow.test.cpp.html
title: tests/aoj/dinic.maximum_flow.test.cpp
---

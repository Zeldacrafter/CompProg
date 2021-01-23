---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: code/graphs/edmondsKarp.cc
    title: code/graphs/edmondsKarp.cc
  - icon: ':heavy_check_mark:'
    path: code/graphs/flowedge.cc
    title: code/graphs/flowedge.cc
  - icon: ':heavy_check_mark:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"tests/aoj/edmonds_karp.maximum_flow.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#line 1 \"code/graphs/edmondsKarp.cc\"\n\n#line 1 \"code/template.cc\"\n//\
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
    \ \": \" << (__VA_ARGS__) << \"] \"\n#line 2 \"code/graphs/flowedge.cc\"\nstruct\
    \ edge {\n  edge(int from, int to, ll capacity, ll flow = 0)\n      : mfrom(from),\
    \ mto(to), mcapacity(capacity), mflow(flow) {}\n  int mfrom, mto;\n  ll mcapacity,\
    \ mflow;\n  int other(int v) { return v == mfrom ? mto : mfrom; }\n  ll capacity(int\
    \ v) { return v == mfrom ? mcapacity : 0; }\n  ll flow(int v) { return v == mfrom\
    \ ? mflow : -mflow; }\n  void adjust(int v, ll amount) {\n    mflow += v == mfrom\
    \ ? amount : -amount;\n  }\n};\nvector<edge> edges;\nvvi adj;\nvoid addEdge(int\
    \ from, int to, ll c, ll f = 0) {\n  edges.eb(from, to, c, f);\n  adj[from].pb(SZ(edges)\
    \ - 1);\n  adj[to].pb(SZ(edges) - 1);\n}\nostream& operator<<(ostream& o, const\
    \ edge& e) {\n  return o << e.mfrom << \"-- \" << e.mflow << '/'\n           <<\
    \ e.mcapacity << \" -->\" << e.mto;\n}\n#line 3 \"code/graphs/edmondsKarp.cc\"\
    \nconst ll inf = 10e16;\nll augment(int s, int t) {\n  vii p(SZ(adj), mp(-1, -1));\n\
    \  queue<int> q;\n  p[s] = mp(-2, 0);\n  q.push(s);\n  while (!q.empty()) {\n\
    \    int v = q.front();\n    if (v == t) break;\n    q.pop();\n    for (int i\
    \ : adj[v]) {\n      edge& e = edges[i];\n      if (p[e.other(v)] == mp(-1, -1)\
    \ && e.flow(v) < e.capacity(v)) {\n\tp[e.other(v)] = mp(v, i); q.push(e.other(v));\n\
    \      }\n    }\n  }\n  if (p[t] == mp(-1, -1)) return 0;\n  ll mf = inf;\n  for\
    \ (ii c = p[t]; c.fi != -2; c = p[c.fi])\n    ckmin(mf, edges[c.se].capacity(c.fi)\
    \ - edges[c.se].flow(c.fi));\n  for (ii c = p[t]; c.fi != -2; c = p[c.fi])\n \
    \   edges[c.se].adjust(c.fi, mf);\n  return mf;\n}\nll maxflow(int s, int t) {\n\
    \  ll maxflow = 0;\n  while (ll plus = augment(s, t)) maxflow += plus;\n  return\
    \ maxflow;\n}\n#line 4 \"tests/aoj/edmonds_karp.maximum_flow.test.cpp\"\n\nint\
    \ main() {\n  cin.tie(0);\n  ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin\
    \ >> V >> E;\n\n  adj.resize(V);\n\n  F0R(i, E) {\n      int u, v, c;\n      cin\
    \ >> u >> v >> c;\n      addEdge(u, v, c);\n  }\n\n  cout << maxflow(0, V - 1)\
    \ << endl;\n}\n\n\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"../../code/graphs/edmondsKarp.cc\"\n\nint main() {\n  cin.tie(0);\n\
    \  ios_base::sync_with_stdio(0);\n\n  int V, E;\n  cin >> V >> E;\n\n  adj.resize(V);\n\
    \n  F0R(i, E) {\n      int u, v, c;\n      cin >> u >> v >> c;\n      addEdge(u,\
    \ v, c);\n  }\n\n  cout << maxflow(0, V - 1) << endl;\n}\n\n\n\n"
  dependsOn:
  - code/graphs/edmondsKarp.cc
  - code/graphs/flowedge.cc
  - code/template.cc
  isVerificationFile: true
  path: tests/aoj/edmonds_karp.maximum_flow.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 09:47:03+01:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/aoj/edmonds_karp.maximum_flow.test.cpp
layout: document
redirect_from:
- /verify/tests/aoj/edmonds_karp.maximum_flow.test.cpp
- /verify/tests/aoj/edmonds_karp.maximum_flow.test.cpp.html
title: tests/aoj/edmonds_karp.maximum_flow.test.cpp
---

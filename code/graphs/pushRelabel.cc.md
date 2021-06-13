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
    path: tests/aoj/push_relabel.maximum_flow.test.cpp
    title: tests/aoj/push_relabel.maximum_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: cc
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"code/graphs/pushRelabel.cc\"\n\n#line 1 \"code/template.cc\"\
    \n// this line is here for a reason\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef pair<int, int> ii;\ntypedef vector<int>\
    \ vi;\ntypedef vector<ii> vii;\ntypedef vector<vi> vvi;\ntypedef vector<vii> vvii;\n\
    #define fi first\n#define se second\n#define eb emplace_back\n#define pb push_back\n\
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
    }\n#line 3 \"code/graphs/pushRelabel.cc\"\ntemplate <typename F = ll>\nstruct\
    \ PR {\n  vi label, currentEdge;\n  vector<F> excess;\n  queue<int> active;\n\
    \  vvi adj;\n  vector<edge<F>> edges;\n  int S, T;\n  PR(int n, int s = -1, int\
    \ t = -1) { reset(n, s, t); }\n  int add(int from, int to, F c = numeric_limits<F>::max(),\
    \ F f = 0) {\n    edges.eb(from, to, c, f);\n    adj[from].pb(SZ(edges) - 1);\n\
    \    adj[to].pb(SZ(edges) - 1);\n    return SZ(edges) - 1;\n  }\n  void clear()\
    \ { edges.clear(); adj.clear(); }\n  void reset(int n, int s = -1, int t = -1)\
    \ {\n    clear();\n    adj.resize(n + (s == -1) + (t == -1));\n    S = s == -1\
    \ ? n : s;\n    T = t == -1 ? n + (s == -1) : t;\n  }\n  void push(int v, edge<F>&\
    \ e) {\n    F more = min(excess[v], e.capacity(v) - e.flow(v));\n    excess[e.other(v)]\
    \ += more;\n    excess[v] -= more;\n    e.adjust(v, more);\n    if (more && excess[e.other(v)]\
    \ == more) active.push(e.other(v));\n  }\n  void relabel(int v) {\n    int m =\
    \ numeric_limits<int>::max();\n    for (int i : adj[v]) {\n      auto& e = edges[i];\n\
    \      if (e.flow(v) < e.capacity(v)) ckmin(m, label[edges[i].other(v)]);\n  \
    \  }\n    if (m < numeric_limits<int>::max()) label[v] = m + 1;\n  }\n  void discharge(int\
    \ v) {\n    while (excess[v]) {\n      auto& e = edges[adj[v][currentEdge[v]]];\n\
    \      if (label[v] - 1 == label[e.other(v)] &&\n          e.flow(v) < e.capacity(v))\n\
    \        push(v, e);\n      else if (SZ(adj[v]) == ++currentEdge[v]) {\n     \
    \   currentEdge[v] = 0;\n        relabel(v);\n      }\n    }\n  }\n  F maxflow(int\
    \ s, int t) {\n    currentEdge.assign(SZ(adj), 0);\n    label.assign(SZ(adj),\
    \ 0);\n    excess.assign(SZ(adj), 0);\n    excess[s] = numeric_limits<F>::max();\n\
    \    label[s] = SZ(adj);\n    for (int i : adj[s]) push(s, edges[i]);\n    while\
    \ (!active.empty()) {\n      if (active.front() != s && active.front() != t)\n\
    \        discharge(active.front());\n      active.pop();\n    }\n    F maxflow\
    \ = 0;\n    for (int i : adj[s]) maxflow += edges[i].flow(s);\n    return maxflow;\n\
    \  }\n};\n"
  code: "\n#include \"flowedge.cc\"\ntemplate <typename F = ll>\nstruct PR {\n  vi\
    \ label, currentEdge;\n  vector<F> excess;\n  queue<int> active;\n  vvi adj;\n\
    \  vector<edge<F>> edges;\n  int S, T;\n  PR(int n, int s = -1, int t = -1) {\
    \ reset(n, s, t); }\n  int add(int from, int to, F c = numeric_limits<F>::max(),\
    \ F f = 0) {\n    edges.eb(from, to, c, f);\n    adj[from].pb(SZ(edges) - 1);\n\
    \    adj[to].pb(SZ(edges) - 1);\n    return SZ(edges) - 1;\n  }\n  void clear()\
    \ { edges.clear(); adj.clear(); }\n  void reset(int n, int s = -1, int t = -1)\
    \ {\n    clear();\n    adj.resize(n + (s == -1) + (t == -1));\n    S = s == -1\
    \ ? n : s;\n    T = t == -1 ? n + (s == -1) : t;\n  }\n  void push(int v, edge<F>&\
    \ e) {\n    F more = min(excess[v], e.capacity(v) - e.flow(v));\n    excess[e.other(v)]\
    \ += more;\n    excess[v] -= more;\n    e.adjust(v, more);\n    if (more && excess[e.other(v)]\
    \ == more) active.push(e.other(v));\n  }\n  void relabel(int v) {\n    int m =\
    \ numeric_limits<int>::max();\n    for (int i : adj[v]) {\n      auto& e = edges[i];\n\
    \      if (e.flow(v) < e.capacity(v)) ckmin(m, label[edges[i].other(v)]);\n  \
    \  }\n    if (m < numeric_limits<int>::max()) label[v] = m + 1;\n  }\n  void discharge(int\
    \ v) {\n    while (excess[v]) {\n      auto& e = edges[adj[v][currentEdge[v]]];\n\
    \      if (label[v] - 1 == label[e.other(v)] &&\n          e.flow(v) < e.capacity(v))\n\
    \        push(v, e);\n      else if (SZ(adj[v]) == ++currentEdge[v]) {\n     \
    \   currentEdge[v] = 0;\n        relabel(v);\n      }\n    }\n  }\n  F maxflow(int\
    \ s, int t) {\n    currentEdge.assign(SZ(adj), 0);\n    label.assign(SZ(adj),\
    \ 0);\n    excess.assign(SZ(adj), 0);\n    excess[s] = numeric_limits<F>::max();\n\
    \    label[s] = SZ(adj);\n    for (int i : adj[s]) push(s, edges[i]);\n    while\
    \ (!active.empty()) {\n      if (active.front() != s && active.front() != t)\n\
    \        discharge(active.front());\n      active.pop();\n    }\n    F maxflow\
    \ = 0;\n    for (int i : adj[s]) maxflow += edges[i].flow(s);\n    return maxflow;\n\
    \  }\n};\n"
  dependsOn:
  - code/graphs/flowedge.cc
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/pushRelabel.cc
  requiredBy: []
  timestamp: '2021-06-13 18:08:42+02:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/aoj/push_relabel.maximum_flow.test.cpp
documentation_of: code/graphs/pushRelabel.cc
layout: document
redirect_from:
- /library/code/graphs/pushRelabel.cc
- /library/code/graphs/pushRelabel.cc.html
title: code/graphs/pushRelabel.cc
---

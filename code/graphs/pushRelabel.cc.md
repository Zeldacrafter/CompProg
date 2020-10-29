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
  _extendedVerifiedWith: []
  _pathExtension: cc
  _verificationStatusIcon: ':warning:'
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
    \ e.mcapacity << \" -->\" << e.mto;\n}\n#line 3 \"code/graphs/pushRelabel.cc\"\
    \nconst ll inf = 10e16;\nvi label;\nvi currentEdge;\nvector<ll> excess;\nqueue<int>\
    \ active;\nvoid push(int v, edge& e) {\n  ll more = min(excess[v], e.capacity(v)\
    \ - e.flow(v));\n  excess[e.other(v)] += more;\n  excess[v] -= more;\n  e.adjust(v,\
    \ more);\n  if (more && excess[e.other(v)] == more) active.push(e.other(v));\n\
    }\nvoid relabel(int v) {\n  int m = numeric_limits<int>::max();\n  for (int i\
    \ : adj[v]) {\n    auto& e = edges[i];\n    if (e.flow(v) < e.capacity(v)) ckmin(m,\
    \ label[edges[i].other(v)]);\n  }\n  if (m < numeric_limits<int>::max()) label[v]\
    \ = m + 1;\n}\nvoid discharge(int v) {\n  while (excess[v]) {\n    auto& e = edges[adj[v][currentEdge[v]]];\n\
    \    if (label[v] - 1 == label[e.other(v)] &&\n        e.flow(v) < e.capacity(v))\n\
    \      push(v, e);\n    else if (SZ(adj[v]) == ++currentEdge[v]) {\n      currentEdge[v]\
    \ = 0;\n      relabel(v);\n    }\n  }\n}\nll maxflow(int s, int t) {\n  currentEdge.assign(SZ(adj),\
    \ 0);\n  label.assign(SZ(adj), 0);\n  excess.assign(SZ(adj), 0);\n  excess[s]\
    \ = inf;\n  label[s] = SZ(adj);\n  for (int i : adj[s]) push(s, edges[i]);\n \
    \ while (!active.empty()) {\n    if (active.front() != s && active.front() !=\
    \ t)\n      discharge(active.front());\n    active.pop();\n  }\n  ll maxflow =\
    \ 0;\n  for (int i : adj[s]) maxflow += edges[i].flow(s);\n  return maxflow;\n\
    }\n"
  code: "\n#include \"flowedge.cc\"\nconst ll inf = 10e16;\nvi label;\nvi currentEdge;\n\
    vector<ll> excess;\nqueue<int> active;\nvoid push(int v, edge& e) {\n  ll more\
    \ = min(excess[v], e.capacity(v) - e.flow(v));\n  excess[e.other(v)] += more;\n\
    \  excess[v] -= more;\n  e.adjust(v, more);\n  if (more && excess[e.other(v)]\
    \ == more) active.push(e.other(v));\n}\nvoid relabel(int v) {\n  int m = numeric_limits<int>::max();\n\
    \  for (int i : adj[v]) {\n    auto& e = edges[i];\n    if (e.flow(v) < e.capacity(v))\
    \ ckmin(m, label[edges[i].other(v)]);\n  }\n  if (m < numeric_limits<int>::max())\
    \ label[v] = m + 1;\n}\nvoid discharge(int v) {\n  while (excess[v]) {\n    auto&\
    \ e = edges[adj[v][currentEdge[v]]];\n    if (label[v] - 1 == label[e.other(v)]\
    \ &&\n        e.flow(v) < e.capacity(v))\n      push(v, e);\n    else if (SZ(adj[v])\
    \ == ++currentEdge[v]) {\n      currentEdge[v] = 0;\n      relabel(v);\n    }\n\
    \  }\n}\nll maxflow(int s, int t) {\n  currentEdge.assign(SZ(adj), 0);\n  label.assign(SZ(adj),\
    \ 0);\n  excess.assign(SZ(adj), 0);\n  excess[s] = inf;\n  label[s] = SZ(adj);\n\
    \  for (int i : adj[s]) push(s, edges[i]);\n  while (!active.empty()) {\n    if\
    \ (active.front() != s && active.front() != t)\n      discharge(active.front());\n\
    \    active.pop();\n  }\n  ll maxflow = 0;\n  for (int i : adj[s]) maxflow +=\
    \ edges[i].flow(s);\n  return maxflow;\n}\n"
  dependsOn:
  - code/graphs/flowedge.cc
  - code/template.cc
  isVerificationFile: false
  path: code/graphs/pushRelabel.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: code/graphs/pushRelabel.cc
layout: document
redirect_from:
- /library/code/graphs/pushRelabel.cc
- /library/code/graphs/pushRelabel.cc.html
title: code/graphs/pushRelabel.cc
---

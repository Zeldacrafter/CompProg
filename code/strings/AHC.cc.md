---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/hackerrank/aho_corasick.two_two.test.cpp
    title: tests/hackerrank/aho_corasick.two_two.test.cpp
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
    \ << \"] \"\n#line 2 \"code/strings/AHC.cc\"\n\ntemplate <typename T, int E =\
    \ 26, typename V = char, V base = 'a'>\nstruct AHC {\n  using str = basic_string<V>;\n\
    \  T e;\n  vector<array<int, E>> nxt;\n  vi fail;\n  vector<T> val;\n  AHC(T _e)\
    \ : e{_e}, nxt(1, array<int, E>()), fail(1, 0), val(1, e) {}\n  AHC(T _e, const\
    \ vector<pair<str, T>>& strs) \n      : e{_e}, nxt(1, array<int, E>()), fail(1,\
    \ 0), val(1, e) {\n    for (const auto& [s, v] : strs) insert(s, v);\n    build();\n\
    \  }\n  void reserve(size_t sz) {\n    nxt.reserve(sz);\n    fail.reserve(sz);\n\
    \    val.reserve(sz);\n  }\n  void insert(const str& s, T v) {\n    int curr =\
    \ 0;\n    for (V c : s) {\n      if (!nxt[curr][c - base]) {\n        nxt[curr][c\
    \ - base] = SZ(nxt);\n        nxt.eb();\n        val.pb(e);\n      }\n      curr\
    \ = nxt[curr][c - base];\n    }\n    val[curr] += v;\n  }\n  void build() {\n\
    \    fail.assign(SZ(nxt), 0);\n    queue<int> q;\n    F0R (i, E)\n      if (nxt[0][i])\
    \ q.push(nxt[0][i]);\n    while (!q.empty()) {\n      int curr = q.front();\n\
    \      q.pop();\n      F0R (i, E) {\n        if (nxt[curr][i]) {\n          fail[nxt[curr][i]]\
    \ = nxt[fail[curr]][i];\n          val[nxt[curr][i]] += val[nxt[fail[curr]][i]];\n\
    \          q.push(nxt[curr][i]);\n        } else\n          nxt[curr][i] = nxt[fail[curr]][i];\n\
    \      }\n    }\n  }\n  T query(const str& s) {\n    int curr = 0;\n    T res\
    \ = e;\n    for (V c : s) {\n      if (nxt[curr][c - base])\n        curr = nxt[curr][c\
    \ - base];\n      else\n        while (curr && !nxt[curr][c - base]) curr = fail[curr];\n\
    \      res += val[curr];\n    }\n    return res;\n  }\n};\n"
  code: "#include \"../template.hh\"\n\ntemplate <typename T, int E = 26, typename\
    \ V = char, V base = 'a'>\nstruct AHC {\n  using str = basic_string<V>;\n  T e;\n\
    \  vector<array<int, E>> nxt;\n  vi fail;\n  vector<T> val;\n  AHC(T _e) : e{_e},\
    \ nxt(1, array<int, E>()), fail(1, 0), val(1, e) {}\n  AHC(T _e, const vector<pair<str,\
    \ T>>& strs) \n      : e{_e}, nxt(1, array<int, E>()), fail(1, 0), val(1, e) {\n\
    \    for (const auto& [s, v] : strs) insert(s, v);\n    build();\n  }\n  void\
    \ reserve(size_t sz) {\n    nxt.reserve(sz);\n    fail.reserve(sz);\n    val.reserve(sz);\n\
    \  }\n  void insert(const str& s, T v) {\n    int curr = 0;\n    for (V c : s)\
    \ {\n      if (!nxt[curr][c - base]) {\n        nxt[curr][c - base] = SZ(nxt);\n\
    \        nxt.eb();\n        val.pb(e);\n      }\n      curr = nxt[curr][c - base];\n\
    \    }\n    val[curr] += v;\n  }\n  void build() {\n    fail.assign(SZ(nxt), 0);\n\
    \    queue<int> q;\n    F0R (i, E)\n      if (nxt[0][i]) q.push(nxt[0][i]);\n\
    \    while (!q.empty()) {\n      int curr = q.front();\n      q.pop();\n     \
    \ F0R (i, E) {\n        if (nxt[curr][i]) {\n          fail[nxt[curr][i]] = nxt[fail[curr]][i];\n\
    \          val[nxt[curr][i]] += val[nxt[fail[curr]][i]];\n          q.push(nxt[curr][i]);\n\
    \        } else\n          nxt[curr][i] = nxt[fail[curr]][i];\n      }\n    }\n\
    \  }\n  T query(const str& s) {\n    int curr = 0;\n    T res = e;\n    for (V\
    \ c : s) {\n      if (nxt[curr][c - base])\n        curr = nxt[curr][c - base];\n\
    \      else\n        while (curr && !nxt[curr][c - base]) curr = fail[curr];\n\
    \      res += val[curr];\n    }\n    return res;\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/strings/AHC.cc
  requiredBy: []
  timestamp: '2020-10-29 00:25:40+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/hackerrank/aho_corasick.two_two.test.cpp
documentation_of: code/strings/AHC.cc
layout: document
redirect_from:
- /library/code/strings/AHC.cc
- /library/code/strings/AHC.cc.html
title: code/strings/AHC.cc
---

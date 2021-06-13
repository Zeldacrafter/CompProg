---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: code/template.cc
    title: code/template.cc
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/yosupo/suffix_array.suffix_array.test.cpp
    title: tests/yosupo/suffix_array.suffix_array.test.cpp
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
    \ << \"] \"\n#line 2 \"code/strings/SA.cc\"\nvii SA_ns, SA_bs;\nusing vit = vi::iterator;\n\
    template<int B = 'a', int S = 26, int N = 3>\nstruct SA {\n  vi sa, rank, lcp;\n\
    \  SA(const string& s) {\n    SA_bs.resize(max(S, SZ(s)) + 2);\n    SA_ns.resize(max(S,\
    \ SZ(s)) + 2);\n    vi ra(SZ(s) + 1 + N);\n    F0R (i, SZ(s)) ra[i] = s[i] - B\
    \ + 2;\n    ra[SZ(s)] = 1;\n    sa = build(ra);\n  }\n  void buildRank() {\n \
    \   rank.resize(SZ(sa));\n    F0R (i, SZ(sa)) rank[sa[i]] = i;\n  }\n  void buildLcp(const\
    \ string& s) {\n    if(rank.empty()) buildRank();\n    lcp.resize(SZ(sa) - 1);\n\
    \    int k = 0;\n    F0R (i, SZ(sa)) {\n      if (rank[i] == SZ(sa) - 1) {\n \
    \       k = 0; continue;\n      }\n      for (int j = sa[rank[i] + 1]; max(i,\
    \ j) + k < SZ(s) && s[i + k] == s[j + k]; ++k);\n      lcp[rank[i]] = k;\n   \
    \   if (k) --k;\n    }\n  }\n  vi build(const vi& prefRank) {\n    int n = SZ(prefRank)\
    \ - N;\n    int offset = n / N + !!(n % N);\n    vi arr; arr.reserve(n);\n   \
    \ array<int, N> offs;\n    F0R (j, N) {\n      offs[j] = SZ(arr) - offset;\n \
    \     for (int i = j; i < n; i += N) arr.pb(i);\n    }\n    rsort(offset + ALL(arr),\
    \ N, [&](int i, int it) { return prefRank[i + it]; });\n    vi ra(n - offset +\
    \ N);\n    int r = 1;\n    FOR (i, offset, n) {\n      ra[offs[arr[i] % N] + arr[i]\
    \ / N] = r;\n      if (i + 1 < n)\n        F0R (j, N)\n          if (prefRank[arr[i]\
    \ + j] != prefRank[arr[i + 1] + j]) {\n            r++; break;\n          }\n\
    \    }\n    if (r < n - offset) {\n      vi got(build(ra));\n      F0R (i, SZ(got))\
    \ ra[got[i]] = i;\n      FOR (j, 1, N) for (int i = 0; j + i * N < n; ++i)\n \
    \       arr[offset + ra[offs[j] + i]] = j + i * N;\n    }\n    rsort(arr.begin(),\
    \ arr.begin() + offset, 2, [&](int i, int it) {\n      return it ? ra[offs[(i\
    \ + 1) % N] + (i + 1) / N] : prefRank[i];\n    });\n    vi tmp(arr.begin(), arr.begin()\
    \ + offset);\n    int o = 0, m = offset, i = 0;\n    while (o < offset && m <\
    \ n) {\n      int c = 0;\n      for (int k = 0; !c; ++k) {\n        int a = tmp[o]\
    \ + k, b = arr[m] + k;\n        c = (a % N && b % N) \n          ? cmp(ra[offs[a\
    \ % N] + a / N], ra[offs[b % N] + b / N]) \n            : cmp(prefRank[a], prefRank[b]);\n\
    \      }\n      arr[i++] = c < 0 ? tmp[o++] : arr[m++];\n    }\n    while (o <\
    \ offset) arr[i++] = tmp[o++];\n    return arr;\n  }\n  static inline int cmp(int\
    \ a, int b) { return (a > b) - (a < b); }\n  template<typename F>\n  static void\
    \ rsort(vit vb, vit ve, int iters, F bf) {\n    for (int d = iters - 1; ~d; --d)\
    \ {\n      int mx = 0;\n      F0R (i, distance(vb, ve)) {\n        int b = bf(*(vb\
    \ + i), d);\n        for (; mx <= b; ++mx) SA_bs[mx].fi = -1;\n        if (SA_bs[b].fi\
    \ == -1) SA_bs[b] = mp(i, i);\n        SA_ns[SA_bs[b].se].se = i;\n        SA_ns[i]\
    \ = mp(*(vb + i), -1);\n        SA_bs[b].se = i;\n      }\n      vit j = vb;\n\
    \      F0R (i, mx)\n        for (int it = SA_bs[i].fi; ~it; it = SA_ns[it].se,\
    \ ++j)\n          *j = SA_ns[it].fi;\n    }\n  }\n};\n"
  code: "#include \"../template.hh\"\nvii SA_ns, SA_bs;\nusing vit = vi::iterator;\n\
    template<int B = 'a', int S = 26, int N = 3>\nstruct SA {\n  vi sa, rank, lcp;\n\
    \  SA(const string& s) {\n    SA_bs.resize(max(S, SZ(s)) + 2);\n    SA_ns.resize(max(S,\
    \ SZ(s)) + 2);\n    vi ra(SZ(s) + 1 + N);\n    F0R (i, SZ(s)) ra[i] = s[i] - B\
    \ + 2;\n    ra[SZ(s)] = 1;\n    sa = build(ra);\n  }\n  void buildRank() {\n \
    \   rank.resize(SZ(sa));\n    F0R (i, SZ(sa)) rank[sa[i]] = i;\n  }\n  void buildLcp(const\
    \ string& s) {\n    if(rank.empty()) buildRank();\n    lcp.resize(SZ(sa) - 1);\n\
    \    int k = 0;\n    F0R (i, SZ(sa)) {\n      if (rank[i] == SZ(sa) - 1) {\n \
    \       k = 0; continue;\n      }\n      for (int j = sa[rank[i] + 1]; max(i,\
    \ j) + k < SZ(s) && s[i + k] == s[j + k]; ++k);\n      lcp[rank[i]] = k;\n   \
    \   if (k) --k;\n    }\n  }\n  vi build(const vi& prefRank) {\n    int n = SZ(prefRank)\
    \ - N;\n    int offset = n / N + !!(n % N);\n    vi arr; arr.reserve(n);\n   \
    \ array<int, N> offs;\n    F0R (j, N) {\n      offs[j] = SZ(arr) - offset;\n \
    \     for (int i = j; i < n; i += N) arr.pb(i);\n    }\n    rsort(offset + ALL(arr),\
    \ N, [&](int i, int it) { return prefRank[i + it]; });\n    vi ra(n - offset +\
    \ N);\n    int r = 1;\n    FOR (i, offset, n) {\n      ra[offs[arr[i] % N] + arr[i]\
    \ / N] = r;\n      if (i + 1 < n)\n        F0R (j, N)\n          if (prefRank[arr[i]\
    \ + j] != prefRank[arr[i + 1] + j]) {\n            r++; break;\n          }\n\
    \    }\n    if (r < n - offset) {\n      vi got(build(ra));\n      F0R (i, SZ(got))\
    \ ra[got[i]] = i;\n      FOR (j, 1, N) for (int i = 0; j + i * N < n; ++i)\n \
    \       arr[offset + ra[offs[j] + i]] = j + i * N;\n    }\n    rsort(arr.begin(),\
    \ arr.begin() + offset, 2, [&](int i, int it) {\n      return it ? ra[offs[(i\
    \ + 1) % N] + (i + 1) / N] : prefRank[i];\n    });\n    vi tmp(arr.begin(), arr.begin()\
    \ + offset);\n    int o = 0, m = offset, i = 0;\n    while (o < offset && m <\
    \ n) {\n      int c = 0;\n      for (int k = 0; !c; ++k) {\n        int a = tmp[o]\
    \ + k, b = arr[m] + k;\n        c = (a % N && b % N) \n          ? cmp(ra[offs[a\
    \ % N] + a / N], ra[offs[b % N] + b / N]) \n            : cmp(prefRank[a], prefRank[b]);\n\
    \      }\n      arr[i++] = c < 0 ? tmp[o++] : arr[m++];\n    }\n    while (o <\
    \ offset) arr[i++] = tmp[o++];\n    return arr;\n  }\n  static inline int cmp(int\
    \ a, int b) { return (a > b) - (a < b); }\n  template<typename F>\n  static void\
    \ rsort(vit vb, vit ve, int iters, F bf) {\n    for (int d = iters - 1; ~d; --d)\
    \ {\n      int mx = 0;\n      F0R (i, distance(vb, ve)) {\n        int b = bf(*(vb\
    \ + i), d);\n        for (; mx <= b; ++mx) SA_bs[mx].fi = -1;\n        if (SA_bs[b].fi\
    \ == -1) SA_bs[b] = mp(i, i);\n        SA_ns[SA_bs[b].se].se = i;\n        SA_ns[i]\
    \ = mp(*(vb + i), -1);\n        SA_bs[b].se = i;\n      }\n      vit j = vb;\n\
    \      F0R (i, mx)\n        for (int it = SA_bs[i].fi; ~it; it = SA_ns[it].se,\
    \ ++j)\n          *j = SA_ns[it].fi;\n    }\n  }\n};\n"
  dependsOn:
  - code/template.cc
  isVerificationFile: false
  path: code/strings/SA.cc
  requiredBy: []
  timestamp: '2020-10-28 19:21:59+01:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/yosupo/suffix_array.suffix_array.test.cpp
documentation_of: code/strings/SA.cc
layout: document
redirect_from:
- /library/code/strings/SA.cc
- /library/code/strings/SA.cc.html
title: code/strings/SA.cc
---
